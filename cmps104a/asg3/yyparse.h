
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_ALLOCATOR = 258,
     TOK_BASETYPE = 259,
     TOK_VAR = 260,
     TOK_CONSTANT = 261,
     TOK_FUNCTION = 262,
     TOK_TYPE = 263,
     TOK_PROTOTYPE = 264,
     TOK_BINOP = 265,
     TOK_UNOP = 266,
     TOK_DECLID = 267,
     TOK_VARDECL = 268,
     TOK_RETURNVOID = 269,
     TOK_VOID = 270,
     TOK_BOOL = 271,
     TOK_CHAR = 272,
     TOK_INT = 273,
     TOK_STRING = 274,
     TOK_IF = 275,
     TOK_ELSE = 276,
     TOK_WHILE = 277,
     TOK_RETURN = 278,
     TOK_STRUCT = 279,
     TOK_FALSE = 280,
     TOK_TRUE = 281,
     TOK_NULL = 282,
     TOK_NEW = 283,
     TOK_ARRAY = 284,
     TOK_EQ = 285,
     TOK_NE = 286,
     TOK_LT = 287,
     TOK_LE = 288,
     TOK_GT = 289,
     TOK_GE = 290,
     TOK_IDENT = 291,
     TOK_INTCON = 292,
     TOK_CHARCON = 293,
     TOK_STRINGCON = 294,
     TOK_ORD = 295,
     TOK_CHR = 296,
     TOK_ROOT = 297,
     TOK_PARAMLIST = 298,
     TOK_BLOCK = 299,
     TOK_CALL = 300,
     TOK_IFELSE = 301,
     TOK_INITDECL = 302,
     TOK_POS = 303,
     TOK_NEG = 304,
     TOK_NEWARRAY = 305,
     TOK_TYPEID = 306,
     TOK_FIELD = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


