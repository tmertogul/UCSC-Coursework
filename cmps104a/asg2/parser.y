%{


#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

%}
 
%debug
%defines
%error-verbose
%token-table

%token TOK_ALLOCATOR TOK_BASETYPE TOK_VAR TOK_CONSTANT 
%token TOK_FUNCTION TOK_TYPE TOK_PROTOTYPE

%token TOK_BINOP TOK_UNOP TOK_DECLID TOK_VARDECL TOK_RETURNVOID
%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING 
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW TOK_ARRAY
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON
%token TOK_ORD TOK_CHR TOK_ROOT TOK_PARAMLIST TOK_TIM TOK_TIMER
%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD

%right     TOK_IF TOK_ELSE
%right     '=' 
%left      TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left      '+' '-' 
%left      '*' '/' '%'
%right     TOK_POS TOK_NEG '!' TOK_ORD TOK_CHR
%left      '[' '.' TOK_CALL
%nonassoc  TOK_NEW
%nonassoc  '('

%verbose

%start start

%%

start    : program    { yyparse_astree = $1; }
        ;

program : program structdef        { $$ = adopt1($1, $2); }
        | program function         { $$ = adopt1($1, $2); }
        | program statement        { $$ = adopt1($1, $2); }
        | program error '}'        { $$ = $1; }
        | program error ';'        { $$ = $1; }
        |                            { $$ = new_parseroot(); }
        ;
        
structdef : structh '}' { $$ = $1; free_ast($2); }
          | structh strdecl ';' '}' { $$ = adopt1 ($1, $2); 
                                      free_ast2($3, $4); }
          ;

structh : TOK_STRUCT TOK_IDENT '{' { $$ = adopt1sym ($1, $2, 
          TOK_STRUCT); free_ast ($3); }
        ;

strdecl : strdecl ';' decl { $$ = adopt1 ($1, $3); free_ast ($2); }
        | decl { $$ = $1; } 
        ;
        
decl : type declid { $$ = adopt1 ($1, $2) }
     | type TOK_NEWARRAY declid { $$ = adopt2 ($2, $1, $3); }
     ;

declid : TOK_IDENT { $$ = adoptsym ($1, TOK_DECLID); }
       ;

type : basetype '[]' { $$ = adopt1 ($1, $2); }
     | basetype { $$ = $1; }
     ; 

basetype : TOK_VOID      { $$ = $1; }
         | TOK_BOOL      { $$ = $1; }
         | TOK_CHAR      { $$ = $1; }
         | TOK_INT       { $$ = $1; }
         | TOK_STRING    { $$ = $1; }
         | TOK_IDENT     { $$ = adoptsym ($1, TOK_TYPEID); }
         ;

params : params ',' decl { adopt1sym($1, $3, TOK_PARAMLIST);
                              free_ast($2); }
       | '(' decl { adopt1sym($1, $2, TOK_PARAMLIST); }
       | '(' { $$ = adoptsym ($1, TOK_PARAMLIST); }
       ;

function : decl params ')' block { 
                   $$ = adopt3 (new_function($1), $1, $2, $4); }
         | decl params ')' ';' { 
              $$ = adopt2 (new_prototype($1), $1, $2); free_ast($4); }
         ;

block : '{' '}' { $$ = adopt1sym ($$, $1, TOK_BLOCK); free_ast ($2); }
      | '{' stmts '}' { $$ = adoptsym(stealkids ($1, $2), TOK_BLOCK); 
                          free_ast ($3); }
      ;

stmts : stmts statement { $$ = adopt1($1, $2); }
      | statement { $$ = adopt1(new_block($1), $1); }
      ;

statement : block        { $$ = $1; }
          | vardecl      { $$ = $1; }
          | while        { $$ = $1; }
          | ifelse       { $$ = $1; }
          | return       { $$ = $1; }
          | expr ';'     { $$ = $1; free_ast ($2); }
          | ';'          { $$ = adoptsym ($1, TOK_BLOCK); }
;
        
vardecl : decl '=' expr ';' 
          { $$ = adoptsym (adopt2($2, $1, $3), TOK_VARDECL);
                 free_ast ($4); }
         ;

while : TOK_WHILE '(' expr ')' statement 
        { $$ = adopt2 ($1, $3, $5); free_ast2 ($2, $4); }
        ;

ifelse : TOK_IF '(' expr ')' statement %prec TOK_ELSE
         { $$ = adopt2 ($1, $3, $5); free_ast2 ($2, $4); }
       | TOK_IF '(' expr ')' statement TOK_ELSE statement
         { $$ = adopt2 (adopt1sym ($1, $3, TOK_IFELSE), $5, $7);
         free_ast3 ($2, $4, $6); }
        ;

return : TOK_RETURN ';' { $$ = adoptsym ($1, TOK_RETURNVOID); 
         free_ast ($2); } 
       | TOK_RETURN expr ';' { $$ = adopt1 ($1, $2); free_ast ($3); }
       ;

expr : binop             { $$ = $1; }
     | unop              { $$ = $1; }
     | allocator         { $$ = $1; }
     | call              { $$ = $1; }
     | '(' expr ')'      { free_ast2 ($1, $3); $$ = $2; }
     | variable          { $$ = $1; }
     | constant          { $$ = $1; }
     ;

binop : expr '=' expr       { $$ = adopt2 ($2, $1, $3); }
      | expr TOK_EQ expr    { $$ = adopt2 ($2, $1, $3); }
      | expr TOK_NE expr    { $$ = adopt2 ($2, $1, $3); }
      | expr TOK_LT expr    { $$ = adopt2 ($2, $1, $3); }
      | expr TOK_LE expr    { $$ = adopt2 ($2, $1, $3); }
      | expr TOK_GT expr    { $$ = adopt2 ($2, $1, $3); }
      | expr TOK_GE expr    { $$ = adopt2 ($2, $1, $3); }
      | expr '+' expr       { $$ = adopt2 ($2, $1, $3); }
      | expr '-' expr       { $$ = adopt2 ($2, $1, $3); }
      | expr '*' expr       { $$ = adopt2 ($2, $1, $3); }
      | expr '/' expr       { $$ = adopt2 ($2, $1, $3); }
      | expr '%' expr       { $$ = adopt2 ($2, $1, $3); }
      ;

unop : '+' expr %prec TOK_POS   { $$ = adopt1sym ($1, $2, TOK_POS); }
     | '-' expr %prec TOK_NEG   { $$ = adopt1sym ($1, $2, TOK_NEG); }
     | '!' expr                 { $$ = adopt1 ($1, $2); }
     | TOK_ORD expr             { $$ = adopt1 ($1, $2); }
     | TOK_CHR expr             { $$ = adopt1 ($1, $2); }
     ;

allocator : TOK_NEW TOK_IDENT '(' ')' { $$ = adopt1sym ($1, $2, 
                             TOK_TYPEID); free_ast2 ($3, $4); }  
          | TOK_NEW TOK_STRING '(' expr ')' { $$ = adopt1sym ($1,
                           $4, TOK_STRING); free_ast3 ($2, $3, $5); }
          | TOK_NEW basetype '[' expr ']' { $$ = adopt1 (adopt1sym($1,
                         $2, TOK_NEWARRAY), $4); free_ast2 ($3, $5); }
          | basetype '[' expr ']' { $$ = adopt1sym($1, $3, 
                                  TOK_NEWARRAY); free_ast2 ($2, $4); }
          ;
        
exprs : exprs ',' expr { free_ast($2); $$ = adopt1($1, $3); }
      | expr { $$ = $1; }
      ;

callfront : TOK_IDENT '(' { $$ = adopt1sym ($2, $1, TOK_CALL); }
          ;

call : callfront ')' { $$ = $1; free_ast($2); }
     | callfront exprs ')' { free_ast ($3); $$ = adopt1($1, $2); }
     ;
            
variable : TOK_IDENT           { $$ = $1; }
         | expr '[' expr ']' %prec '['  { $$ = adopt1sym ($1, $3, 
                                TOK_VARDECL); free_ast2 ($2, $4); }
         | expr '.' TOK_IDENT   { $$ = adopt2sym ($2, $1, $3, 
                                 TOK_VARDECL); }
         ;            
                    
constant : TOK_INTCON         { $$ = adoptsym ($1, TOK_INTCON); }
         | TOK_CHARCON        { $$ = adoptsym ($1, TOK_CHARCON); }
         | TOK_STRINGCON      { $$ = adoptsym ($1, TOK_STRINGCON); }
         | TOK_FALSE          { $$ = adoptsym ($1, TOK_FALSE); }
         | TOK_TRUE           { $$ = adoptsym ($1, TOK_TRUE); }
         | TOK_NULL           { $$ = adoptsym ($1, TOK_NULL); }
         ;
                


%%

const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}








































