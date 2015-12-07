(* $Id: bigint.ml,v 1.5 2014-11-11 15:06:24-08 - - $ *)
(*  *)
(* Tim Mertogul *)
(* tmertogu@ucsc.edu *)
(* Sean McGrath *)
(* ssmcgrat@ucsc.edu *)
(*  *)
(* ocaml dc *) 
(*  *)

open Printf
open List

module Bigint = struct

    type sign     = Pos | Neg
    type bigint   = Bigint of sign * int list
    let  radix    = 10
    let  radixlen =  1

    let car       = List.hd
    let cdr       = List.tl
    let map       = List.map
    let reverse   = List.rev
    let strcat    = String.concat
    let strlen    = String.length
    let strsub    = String.sub
    let zero      = Bigint (Pos, [])

    let charlist_of_string str = 
        let last = strlen str - 1
        in  let rec charlist pos result =
            if pos < 0
            then result
            else charlist (pos - 1) (str.[pos] :: result)
        in  charlist last []

    let bigint_of_string str =
        let len = strlen str
        in  let to_intlist first =
                let substr = strsub str first (len - first) in
                let digit char = int_of_char char - int_of_char '0' in
                map digit (reverse (charlist_of_string substr))
            in  if   len = 0
                then zero
                else if   str.[0] = '_'
                     then Bigint (Neg, to_intlist 1)
                     else Bigint (Pos, to_intlist 0)

    let string_of_bigint (Bigint (sign, value)) =
        match value with
        | []    -> "0"
        | value -> let reversed = reverse value
                   in  strcat ""
                        ((if sign = Pos then "" else "-") ::
                        (map string_of_int reversed))

    (* trim zeros function, modified from ocaml examples *)
    let tz list =
    let rec tz' list' = match list' with
        | []       -> []
        | [0]      -> []
        | car::cdr ->
             let cdr' = tz' cdr
             in  match car, cdr' with
                 | 0, [] -> []
                 | car, cdr' -> car::cdr'
    in tz' list

    (* compares the absolute value of 2 lists, returns 1 if list1>list2
       returns -1 if list1<list2 and returns 0 if list1=list2 *) 
    let cmp list1 list2 = 
       (* compare lengths *)
       if (length list1) < (length list2)
       then -1 
       else if (length list1) > (length list2)
       then 1
       (* compare each individual value when equal length *)
       else (let rev1 = rev list1
             in let rev2 = rev list2
                in if rev1 > rev2
                   then 1
                   else if rev2 > rev1
                   then -1
                   else 0)  

    let rec add' list1 list2 carry = match (list1, list2, carry) with
        (* base cases *)
        | list1, [], 0       -> list1
        | [], list2, 0       -> list2
        | list1, [], carry   -> add' list1 [carry] 0
        | [], list2, carry   -> add' [carry] list2 0
        | car1::cdr1, car2::cdr2, carry ->
        (* add up the two digits plus the carry *)
          let sum = car1 + car2 + carry
          in  sum mod radix :: add' cdr1 cdr2 (sum / radix)

    let rec sub' list1 list2 carry = match (list1, list2, carry) with
        (* base cases *)
        | list1, [], 0       -> list1
        | [], list2, 0       -> list2
        | list1, [], carry   -> tz (sub' list1 [carry] 0)
        | [], list2, carry   -> tz (sub' [carry] list2 0)
        | car1::cdr1, car2::cdr2, carry ->
        (* calc difference between two digits *)
          if (car1 - carry) < car2
          (* if the top digit < bottom, get from next collumn *)
          then let dif = (10 + car1) - (car2 + carry)
               in  dif mod radix :: tz (sub' cdr1 cdr2 1)
          (* else just subtract bottom from top *)
          else let dif = car1 - car2 - carry
               in  dif mod radix :: tz (sub' cdr1 cdr2 0)

    (* quick way to multiply a number by 2 *)
    let double number = add' number number 0

    (* modified from mathfunction examples *)
    let rec mul' (multiplier, po2, multiplicand') = 
        if (cmp po2 multiplier) > 0
        then multiplier, [0]
        else let remainder, product = 
                mul' (multiplier, double po2, double multiplicand')
            in if (cmp po2 remainder) > 0
                then remainder, product
                else tz (sub' remainder po2 0), 
                                       add' product multiplicand' 0
 
    let add (Bigint (neg1, value1)) (Bigint (neg2, value2)) =

        (* if signs are equal, add the values keep the sign*)
        if neg1 = neg2  
        then Bigint (neg1, add' value1 value2 0)
       
        (* second number is negative, first pos *)
        else if neg2 = Neg
        then (if (cmp value1 value2) >= 0
              then Bigint (Pos, tz (sub' value1 value2 0))
              else Bigint (Neg, tz (sub' value2 value1 0)))  

        (* first number is negative, second pos *)
        else if neg1 = Neg
        then (if (cmp value2 value1) >= 0
              then Bigint (Pos, tz (sub' value2 value1 0))
              else Bigint (Neg, tz (sub' value1 value2 0))) 
        else zero

    let sub (Bigint (neg1, value1)) (Bigint (neg2, value2)) = 
        (* always cmp to have larger value first *)
        if neg1 = neg2
        then (if (cmp value1 value2) >= 0
             then Bigint (Pos, tz (sub' value1 value2 0))
             else Bigint (Neg, tz (sub' value2 value1 0)))
        (* verify proper sign for mis matched signs *) 
        else if neg2 = Neg
             then Bigint (Pos, add' value1 value2 0)
        (* verify proper sign for mis matched signs *) 
        else if neg1 = Neg
             then Bigint (Neg, add' value1 value2 0)
        else zero
   
    (* call egyption multuplication on two lists, return the product *)
    let egy (multiplier, multiplicand) = 
        let _, product = mul' (multiplier, [1], multiplicand)
        in product
  
    (* modified from mathfunction examples *)
    let mul (Bigint (neg1, multiplier)) (Bigint (neg2, multiplicand)) =
        (* properly compute positive or negative *)
        if neg1 = neg2
        then (if (cmp multiplier multiplicand) >= 0
             then Bigint (Pos, egy (multiplier, multiplicand))
             else Bigint (Pos, egy (multiplicand, multiplier)))
        else (if (cmp multiplier multiplicand) >= 0
             then Bigint (Neg, egy (multiplier, multiplicand))
             else Bigint (Neg, egy (multiplicand, multiplier)))

    (* modified from mathfunction examples *)
    let rec divrem' (dividend, po2, divisor') =
        if (cmp divisor' dividend) > 0
        then [0], dividend
        else let quotient, remainder = 
                divrem' (dividend, double po2, double divisor')
            in if (cmp divisor' remainder) > 0
                then quotient, remainder
                else add' quotient po2 0, tz (sub' remainder divisor' 0)
 
    let divrem (dividend, divisor') = divrem' (dividend, [1], divisor')

    let div_egy (dividend, divisor) = 
        let quotient, _ = divrem (dividend, divisor)
        in quotient
 
     (* modified from mathfunction examples *)
   let div (Bigint (neg1, dividend)) (Bigint (neg2, divisor)) =
        (* properly compute positive or negative *)
        if neg1 = neg2
        then (if (cmp dividend divisor) >= 0
             then Bigint (Pos, div_egy (dividend, divisor))
             else Bigint (Pos, div_egy (dividend, divisor)))
        else (if (cmp dividend divisor) >= 0
             then Bigint (Neg, div_egy (dividend, divisor))
             else Bigint (Neg, div_egy (dividend, divisor)))

    let rem_egy (dividend, divisor) =
       let  _, remainder = divrem (dividend, divisor)
     in remainder

     (* modified from mathfunction examples *)
   let rem (Bigint (neg1, dividend)) (Bigint (neg2, divisor)) =
        if neg1 = neg2
        then (if (cmp dividend divisor) >= 0
             then Bigint (Pos, rem_egy (dividend, divisor))
             else Bigint (Pos, rem_egy (dividend, divisor)))
        else (if (cmp dividend divisor) >= 0
             then Bigint (Neg, rem_egy (dividend, divisor))
             else Bigint (Neg, rem_egy (dividend, divisor)))
    
    (* returns true if a list is even, false otherwise *)
    let even number = 
       let remainder = tz (rem_egy (number, [2])) in
       if cmp remainder [] = 0 
       then true
       else false  
    
    (* modified from mathfunction examples *)
    let rec pow'(base, expt, result) = 
       if cmp expt [0] = 0
       then result      
       else if even expt
            then pow'(egy(base, base), div_egy(expt, [2]), result) 
       else pow'(base, sub' expt [1] 0, egy(base, result))  

    (* checks for positive or negative exponential expressions *)
    let pow (Bigint (neg1, base)) (Bigint (neg2, expt)) =
        (* if raising to a negative number, return zero *)
        if neg2 = Neg
        then zero  
        else if neg1 = Pos
             then Bigint (Pos, pow'(base, expt, [1]))
        else if even expt
             then Bigint (Pos, pow'(base, expt, [1]))
        else Bigint (Neg, pow'(base, expt, [1]))

end




