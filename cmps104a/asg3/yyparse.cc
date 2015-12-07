
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"



#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"



/* Line 189 of yacc.c  */
#line 86 "yyparse.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


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


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 180 "yyparse.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   680

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,     2,     2,    58,     2,     2,
      62,    66,    56,    54,    67,    55,    61,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    64,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,    63,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    23,
      26,    30,    34,    38,    41,    44,    48,    51,    55,    57,
      59,    61,    63,    65,    67,    72,    77,    80,    85,    90,
      95,   100,   104,   107,   110,   113,   115,   118,   121,   123,
     125,   127,   129,   131,   134,   139,   145,   151,   159,   162,
     166,   168,   170,   172,   174,   178,   180,   182,   186,   190,
     194,   198,   202,   206,   210,   214,   218,   222,   226,   230,
     233,   236,   239,   242,   245,   250,   256,   262,   266,   268,
     271,   274,   278,   280,   285,   289,   291,   293,   295,   297,
     299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    71,    -1,    71,    72,    -1,    71,    78,
      -1,    71,    83,    -1,    71,     1,    63,    -1,    71,     1,
      64,    -1,    -1,    73,    63,    -1,    73,    74,    63,    -1,
      24,    36,    65,    -1,    74,    76,    64,    -1,    76,    64,
      -1,    77,    36,    -1,    77,    50,    36,    -1,    77,    36,
      -1,    77,    50,    36,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    12,    -1,    75,    62,    66,
      64,    -1,    75,    80,    66,    64,    -1,    79,    63,    -1,
      75,    62,    66,    65,    -1,    75,    62,    66,    82,    -1,
      75,    80,    66,    65,    -1,    75,    80,    66,    82,    -1,
      80,    67,    75,    -1,    62,    75,    -1,    65,    63,    -1,
      82,    63,    -1,    64,    -1,    82,    83,    -1,    65,    83,
      -1,    81,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    64,    -1,    75,    53,    88,    64,    -1,    22,
      62,    88,    66,    83,    -1,    20,    62,    88,    66,    83,
      -1,    20,    62,    88,    66,    83,    21,    83,    -1,    23,
      64,    -1,    23,    88,    64,    -1,    89,    -1,    90,    -1,
      91,    -1,    94,    -1,    62,    88,    66,    -1,    95,    -1,
      96,    -1,    88,    53,    88,    -1,    88,    30,    88,    -1,
      88,    31,    88,    -1,    88,    32,    88,    -1,    88,    33,
      88,    -1,    88,    34,    88,    -1,    88,    35,    88,    -1,
      88,    54,    88,    -1,    88,    55,    88,    -1,    88,    56,
      88,    -1,    88,    57,    88,    -1,    88,    58,    88,    -1,
      54,    88,    -1,    55,    88,    -1,    59,    88,    -1,    40,
      88,    -1,    41,    88,    -1,    28,    36,    62,    66,    -1,
      28,    19,    62,    88,    66,    -1,    28,    77,    60,    88,
      68,    -1,    92,    67,    88,    -1,    88,    -1,    36,    62,
      -1,    93,    66,    -1,    93,    92,    66,    -1,    36,    -1,
      88,    60,    88,    68,    -1,    88,    61,    36,    -1,    37,
      -1,    38,    -1,    39,    -1,    25,    -1,    26,    -1,    27,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    50,    51,    52,    53,    54,    55,    59,
      60,    63,    67,    68,    71,    72,    76,    77,    81,    82,
      83,    84,    85,    86,    89,    92,    94,    97,   102,   106,
     110,   116,   117,   120,   121,   122,   125,   126,   129,   130,
     131,   132,   133,   134,   137,   142,   146,   148,   153,   155,
     158,   159,   160,   161,   162,   163,   164,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   181,
     182,   183,   184,   185,   188,   190,   192,   196,   197,   200,
     203,   204,   207,   208,   210,   214,   215,   216,   217,   218,
     219
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_ALLOCATOR", "TOK_BASETYPE",
  "TOK_VAR", "TOK_CONSTANT", "TOK_FUNCTION", "TOK_TYPE", "TOK_PROTOTYPE",
  "TOK_BINOP", "TOK_UNOP", "TOK_DECLID", "TOK_VARDECL", "TOK_RETURNVOID",
  "TOK_VOID", "TOK_BOOL", "TOK_CHAR", "TOK_INT", "TOK_STRING", "TOK_IF",
  "TOK_ELSE", "TOK_WHILE", "TOK_RETURN", "TOK_STRUCT", "TOK_FALSE",
  "TOK_TRUE", "TOK_NULL", "TOK_NEW", "TOK_ARRAY", "TOK_EQ", "TOK_NE",
  "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE", "TOK_IDENT", "TOK_INTCON",
  "TOK_CHARCON", "TOK_STRINGCON", "TOK_ORD", "TOK_CHR", "TOK_ROOT",
  "TOK_PARAMLIST", "TOK_BLOCK", "TOK_CALL", "TOK_IFELSE", "TOK_INITDECL",
  "TOK_POS", "TOK_NEG", "TOK_NEWARRAY", "TOK_TYPEID", "TOK_FIELD", "'='",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'['", "'.'", "'('", "'}'",
  "';'", "'{'", "')'", "','", "']'", "$accept", "start", "program",
  "structdef", "structh", "fields", "gendecl", "fielddecl", "basetype",
  "function", "sub", "params", "block", "blocks", "statement", "vardecl",
  "while", "ifelse", "return", "expr", "binop", "unop", "allocator",
  "exprs", "callfront", "call", "variable", "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    61,    43,    45,    42,    47,    37,    33,
      91,    46,    40,   125,    59,   123,    41,    44,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    71,    71,    71,    72,
      72,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    84,    85,    86,    86,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    91,    91,    91,    92,    92,    93,
      94,    94,    95,    95,    95,    96,    96,    96,    96,    96,
      96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     2,
       3,     3,     3,     2,     2,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     4,     4,     2,     4,     4,     4,
       4,     3,     2,     2,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     2,     4,     5,     5,     7,     2,     3,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     4,     5,     5,     3,     1,     2,
       2,     3,     1,     4,     3,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    23,    18,    19,    20,    21,
      22,     0,     0,     0,     0,    88,    89,    90,     0,    82,
      85,    86,    87,     0,     0,     0,     0,     0,     0,    35,
       0,     3,     0,     0,     0,     4,     0,    38,     0,     5,
      39,    40,    41,    42,     0,    50,    51,    52,     0,    53,
      55,    56,     6,     7,     0,     0,    48,     0,     0,    22,
       0,     0,    79,    72,    73,    69,    70,    71,     0,    33,
       0,    37,     9,     0,     0,     0,     0,     0,     0,    14,
       0,    26,    34,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    80,
      78,     0,     0,     0,    49,    11,     0,     0,     0,    54,
      10,     0,    13,    16,     0,     0,     0,    32,     0,     0,
      15,    58,    59,    60,    61,    62,    63,    57,    64,    65,
      66,    67,    68,     0,    84,    81,     0,     0,     0,     0,
      74,     0,    12,    17,    44,    24,    27,    28,    25,    29,
      30,    31,    83,    77,    46,    45,    75,    76,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    31,    32,    73,    70,    74,    34,    35,
      36,    78,    37,    38,    71,    40,    41,    42,    43,    44,
      45,    46,    47,   101,    48,    49,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
     -78,     1,   142,   -78,   -10,   -78,   -78,   -78,   -78,   -78,
     -78,   -57,   -34,   342,    14,   -78,   -78,   -78,    15,   -22,
     -78,   -78,   -78,   423,   423,   423,   423,   423,   423,   -78,
     193,   -78,     7,   -33,   -15,   -78,    31,   -78,   247,   -78,
     -78,   -78,   -78,   -78,   537,   -78,   -78,   -78,    64,   -78,
     -78,   -78,   -78,   -78,   423,   423,   -78,   572,    -7,    45,
      46,    36,   -78,    -5,    -5,    -5,    -5,    -5,   435,   -78,
      61,   -78,   -78,    30,    51,     2,   423,    -9,     5,   -78,
      80,   -78,   -78,   -78,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,    81,   -78,   -78,
     619,    21,   472,   486,   -78,   -78,   423,    54,   423,   -78,
     -78,    57,   -78,   -78,    86,   584,     4,   -78,    34,    94,
     -78,     6,     6,     6,     6,     6,     6,   619,   115,   115,
      -5,    -5,    -5,   354,   -78,   -78,   423,   301,   301,   523,
     -78,   386,   -78,   -78,   -78,   -78,   301,   301,   -78,   301,
     301,   -78,   -78,   619,   103,   -78,   -78,   -78,   301,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   -78,   -78,   -78,     9,    56,   -14,   -78,
     -78,   -78,   -78,   -77,    -2,   -78,   -78,   -78,   -78,   -11,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      39,     3,    57,     5,    61,    54,     6,     7,     8,     9,
      10,    33,    63,    64,    65,    66,    67,    68,    75,     5,
      76,    79,     6,     7,     8,     9,    10,     5,    55,    77,
       6,     7,     8,     9,    59,    80,    83,   100,   113,   147,
      62,   150,     5,   102,   103,     6,     7,     8,     9,    10,
      58,    60,   114,    52,    53,    96,    97,   116,   105,    75,
      91,    92,    93,    94,    95,   115,    96,    97,   145,   146,
      72,   118,   119,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   117,   135,   136,    15,
      16,    17,    18,   110,    81,   139,   108,   141,   148,   149,
      19,    20,    21,    22,    23,    24,     5,   106,   107,     6,
       7,     8,     9,    10,    76,   112,   120,   134,    25,    26,
     140,   142,   143,    27,   158,   153,    28,     0,   151,   111,
      99,     0,     0,     0,     0,   154,   155,     0,     0,     0,
       0,     0,    -2,     4,     0,    83,     0,     0,    83,     0,
       0,     0,     0,     0,     5,     0,   159,     6,     7,     8,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    93,    94,    95,     0,    96,    97,     0,    19,    20,
      21,    22,    23,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    27,     0,     0,    28,     5,    29,    30,     6,     7,
       8,     9,    10,    11,     0,    12,    13,     0,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,    19,
      20,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,    27,     0,     0,    28,    69,    29,    30,     5,
       0,     0,     6,     7,     8,     9,    10,    11,     0,    12,
      13,     0,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,    27,     0,     0,    28,
      82,    29,    30,     5,     0,     0,     6,     7,     8,     9,
      10,    11,     0,    12,    13,     0,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,    19,    20,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
      27,     0,     0,    28,     0,    29,    30,    15,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,    19,    20,
      21,    22,    23,    24,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    27,     0,     0,    28,     0,    56,    90,    91,    92,
      93,    94,    95,     0,    96,    97,    84,    85,    86,    87,
      88,    89,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,     0,    96,    97,    15,    16,
      17,    18,     0,     0,   157,     0,     0,     0,     0,    19,
      20,    21,    22,    23,    24,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,    27,     0,     0,    28,     0,     0,    90,    91,
      92,    93,    94,    95,     0,    96,    97,     0,     0,     0,
       0,   109,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     0,    96,    97,     0,     0,     0,     0,   137,    90,
      91,    92,    93,    94,    95,     0,    96,    97,     0,     0,
       0,     0,   138,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,    91,    92,    93,
      94,    95,     0,    96,    97,     0,     0,     0,     0,   156,
      90,    91,    92,    93,    94,    95,     0,    96,    97,     0,
       0,    98,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     0,    96,    97,     0,     0,   104,    90,    91,    92,
      93,    94,    95,     0,    96,    97,     0,     0,   144,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,     0,    96,
      97
};

static const yytype_int16 yycheck[] =
{
       2,     0,    13,    12,    18,    62,    15,    16,    17,    18,
      19,     2,    23,    24,    25,    26,    27,    28,    32,    12,
      53,    36,    15,    16,    17,    18,    19,    12,    62,    62,
      15,    16,    17,    18,    19,    50,    38,    48,    36,   116,
      62,   118,    12,    54,    55,    15,    16,    17,    18,    19,
      36,    36,    50,    63,    64,    60,    61,    66,    65,    73,
      54,    55,    56,    57,    58,    76,    60,    61,    64,    65,
      63,    66,    67,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    77,    66,    67,    25,
      26,    27,    28,    63,    63,   106,    60,   108,    64,    65,
      36,    37,    38,    39,    40,    41,    12,    62,    62,    15,
      16,    17,    18,    19,    53,    64,    36,    36,    54,    55,
      66,    64,    36,    59,    21,   136,    62,    -1,   119,    73,
      66,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,   147,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    12,    -1,   158,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    56,    57,    58,    -1,    60,    61,    -1,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    59,    -1,    -1,    62,    12,    64,    65,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    59,    -1,    -1,    62,    63,    64,    65,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    -1,    -1,    -1,    59,    -1,    -1,    62,
      63,    64,    65,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      59,    -1,    -1,    62,    -1,    64,    65,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    59,    -1,    -1,    62,    -1,    64,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    30,    31,    32,    33,
      34,    35,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    25,    26,
      27,    28,    -1,    -1,    68,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    59,    -1,    -1,    62,    -1,    -1,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    -1,    -1,    -1,
      -1,    66,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    -1,    -1,    -1,    -1,    66,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    -1,    -1,
      -1,    -1,    66,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    -1,    60,    61,    -1,    -1,    -1,    -1,    66,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    -1,
      -1,    64,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    -1,    -1,    64,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    -1,    -1,    64,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    58,    -1,    60,
      61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    71,     0,     1,    12,    15,    16,    17,    18,
      19,    20,    22,    23,    24,    25,    26,    27,    28,    36,
      37,    38,    39,    40,    41,    54,    55,    59,    62,    64,
      65,    72,    73,    75,    77,    78,    79,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    93,    94,
      95,    96,    63,    64,    62,    62,    64,    88,    36,    19,
      36,    77,    62,    88,    88,    88,    88,    88,    88,    63,
      75,    83,    63,    74,    76,    77,    53,    62,    80,    36,
      50,    63,    63,    83,    30,    31,    32,    33,    34,    35,
      53,    54,    55,    56,    57,    58,    60,    61,    64,    66,
      88,    92,    88,    88,    64,    65,    62,    62,    60,    66,
      63,    76,    64,    36,    50,    88,    66,    75,    66,    67,
      36,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    36,    66,    67,    66,    66,    88,
      66,    88,    64,    36,    64,    64,    65,    82,    64,    65,
      82,    75,    68,    88,    83,    83,    66,    68,    21,    83
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 47 "parser.y"
    { yyparse_astree = (yyvsp[(1) - (1)]); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 50 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 51 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 52 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 53 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 54 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 55 "parser.y"
    { (yyval) = new_parseroot(); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 59 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); free_ast ((yyvsp[(2) - (2)])); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 60 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); free_ast((yyvsp[(3) - (3)])); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 63 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), 
          TOK_TYPEID); free_ast ((yyvsp[(3) - (3)])); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); free_ast ((yyvsp[(3) - (3)])); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); free_ast ((yyvsp[(2) - (2)])); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    { 
          (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_FIELD) ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    { 
            (yyval) = adopt2sym ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), TOK_FIELD); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_VOID; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_BOOL; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_CHAR; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_INT; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_STRING; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_DECLID; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { free_ast2 ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); 
           (yyvsp[(2) - (4)])->symbol = TOK_PARAMLIST; 
           (yyval) = adopt2 (new_function ((yyvsp[(1) - (4)])), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)])); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    { free_ast2 ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); 
           (yyval) = adopt2 (new_function((yyvsp[(1) - (4)])), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)])); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); free_ast ((yyvsp[(2) - (2)])); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_PARAMLIST;
        (yyvsp[(4) - (4)])->symbol = TOK_BLOCK;
        (yyval) = adopt3 (new_function ((yyvsp[(1) - (4)])), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
        free_ast ((yyvsp[(3) - (4)])); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_PARAMLIST;
        (yyval) = adopt3 (new_function ((yyvsp[(1) - (4)])), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
        free_ast ((yyvsp[(3) - (4)])); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { (yyvsp[(4) - (4)])->symbol = TOK_BLOCK;
        (yyval) = adopt3 (new_function ((yyvsp[(1) - (4)])), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
        free_ast ((yyvsp[(3) - (4)])); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    { (yyval) = adopt3 (new_function ((yyvsp[(1) - (4)])), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
        free_ast ((yyvsp[(3) - (4)])); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); free_ast((yyvsp[(2) - (3)])); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { adopt1sym((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_PARAMLIST); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); (yyvsp[(1) - (2)])->symbol = TOK_BLOCK; free_ast ((yyvsp[(2) - (2)])); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { free_ast ((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]) ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_BLOCK; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_BLOCK);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    { free_ast ((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { (yyval) = adopt1 (adopt1sym ((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), TOK_VARDECL), (yyvsp[(3) - (4)]));
            free_ast ((yyvsp[(4) - (4)])); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); free_ast2 ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); free_ast2 ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    { (yyval) = adopt2 (adopt1sym ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), TOK_IFELSE), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
         free_ast3 ((yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(6) - (7)])); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]), (yyvsp[(1) - (2)])->symbol = TOK_RETURNVOID; 
         free_ast ((yyvsp[(2) - (2)])); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); free_ast ((yyvsp[(3) - (3)])); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    { free_ast2 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_POS); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_NEG); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), 
                             TOK_TYPEID); free_ast2 ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (5)]),
                           (yyvsp[(4) - (5)]), TOK_STRING); free_ast3 ((yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    { (yyval) = adopt1 (adopt1sym((yyvsp[(1) - (5)]),
                         (yyvsp[(2) - (5)]), TOK_NEWARRAY), (yyvsp[(4) - (5)])); free_ast2 ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    { free_ast((yyvsp[(2) - (3)])); (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_CALL); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); free_ast ((yyvsp[(2) - (2)])); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    { free_ast ((yyvsp[(3) - (3)])); (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), 
                                TOK_VARDECL); free_ast2 ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    { (yyval) = adopt2sym ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 
                                 TOK_VARDECL); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_INTCON; ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_CHARCON; ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_STRINGCON; ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_FALSE; ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_TRUE; ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyvsp[(1) - (1)])->symbol = TOK_NULL; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2278 "yyparse.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 224 "parser.y"


const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}









































