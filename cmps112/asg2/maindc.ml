(* $Id: maindc.ml,v 1.4 2012-02-16 17:47:43-08 - - $ *)
(*  *)
(* Tim Mertogul *)
(* tmertogu@ucsc.edu *)
(* Sean McGrath *)
(* ssmcgrat@ucsc.edu *)
(*  *)
(* ocaml dc *)
(*  *)

include Scanner
include Bigint

open Bigint
open Printf
open Scanner

type stack_t = Bigint.bigint Stack.t
let push = Stack.push
let pop = Stack.pop

let reg_array = Array.make 256(false, Bigint.zero)

let ord thechar = int_of_char thechar
type binop_t = bigint -> bigint -> bigint

(* print the list, properly formatted to <72 chars per line *)
let rec print_number number = 
    let num = string_of_bigint number in
    (* if number fits on single line <70 chars, print*)
    if (String.length num) < 70
    then ( printf "%s\n%!" num)
    (* if number needs multiple singles line <70 chars, print *)
    else ( printf "%s\\\n%!" (String.sub num 0 69);
           print_number (bigint_of_string (String.sub num 69 
                                        ((String.length num) - 69) )))

(* throws an error if the stack is empty *)
let print_stackempty () = eprintf "dc: stack empty\n%!"

(* loads and stores into reg_array, the array of registers *)
let executereg (thestack: stack_t) (oper: char) (reg: int) =
    try match oper with
        | 'l' -> let car, _ = Array.get reg_array reg in
                 let _, cdr = Array.get reg_array reg in
                 if car = true
                 then push (cdr) thestack
                 else printf "dc: register '%d' () empty\n" reg 
        | 's' -> Array.set reg_array reg (true, (pop thestack))  
        | _   -> printf "0%o 0%o is unimplemented\n%!" (ord oper) reg
    with Stack.Empty -> print_stackempty()

let executebinop (thestack: stack_t) (oper: binop_t) =
    try let right = pop thestack
        in  try let left = pop thestack
                in  push (oper left right) thestack
            with Stack.Empty -> (print_stackempty ();
                                 push right thestack)
    with Stack.Empty -> print_stackempty () 

let execute (thestack: stack_t) (oper: char) =
    try match oper with
        | '+'  -> executebinop thestack Bigint.add
        | '-'  -> executebinop thestack Bigint.sub
        | '*'  -> executebinop thestack Bigint.mul
        | '/'  -> executebinop thestack Bigint.div
        | '%'  -> executebinop thestack Bigint.rem
        | '^'  -> executebinop thestack Bigint.pow
        | 'c'  -> Stack.clear thestack
        | 'd'  -> push (Stack.top thestack) thestack
        | 'f'  -> Stack.iter print_number thestack
        | 'l'  -> failwith "operator l scanned with no register"
        | 'p'  -> print_number (Stack.top thestack)
        | 's'  -> failwith "operator s scanned with no register" 
        | '\n' -> ()
        | ' '  -> ()
        | _    -> printf "0%o is unimplemented\n%!" (ord oper)
    with Stack.Empty -> print_stackempty()

let toploop (thestack: stack_t) inputchannel =
    let scanbuf = Lexing.from_channel inputchannel in
    let rec toploop () = 
        try  let nexttoken = Scanner.scanner scanbuf
             in  (match nexttoken with
                 | Number number       -> push number thestack
                 | Regoper (oper, reg) -> executereg thestack oper reg
                 | Operator oper       -> execute thestack oper
                 );
             toploop ()
        with End_of_file -> printf "%!";
    in  toploop ()

let readfiles () =
    let thestack : bigint Stack.t = Stack.create ()
    in  ((if Array.length Sys.argv > 1 
         then try  let thefile = open_in Sys.argv.(1)
                   in  toploop thestack thefile
              with Sys_error message -> (
                   printf "%s: %s\n%!" Sys.argv.(0) message;
                   exit 1));
        toploop thestack stdin)

let interact () =
    let thestack : bigint Stack.t = Stack.create ()
    in  toploop thestack stdin

let _ = if not !Sys.interactive then readfiles ()

