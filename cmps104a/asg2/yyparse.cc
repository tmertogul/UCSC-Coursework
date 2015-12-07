
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
     TOK_TIM = 299,
     TOK_TIMER = 300,
     TOK_BLOCK = 301,
     TOK_CALL = 302,
     TOK_IFELSE = 303,
     TOK_INITDECL = 304,
     TOK_POS = 305,
     TOK_NEG = 306,
     TOK_NEWARRAY = 307,
     TOK_TYPEID = 308,
     TOK_FIELD = 309
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
#line 182 "yyparse.cc"

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
#define YYLAST   757

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    60,     2,     2,
      64,    69,    58,    56,    68,    57,    63,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    66,
       2,    55,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,    65,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    23,
      26,    31,    35,    39,    41,    44,    48,    50,    53,    55,
      57,    59,    61,    63,    65,    67,    71,    74,    76,    81,
      86,    89,    93,    96,    98,   100,   102,   104,   106,   108,
     111,   113,   118,   124,   130,   138,   141,   145,   147,   149,
     151,   153,   157,   159,   161,   165,   169,   173,   177,   181,
     185,   189,   193,   197,   201,   205,   209,   212,   215,   218,
     221,   224,   229,   235,   241,   246,   250,   252,   255,   258,
     262,   264,   269,   273,   275,   277,   279,   281,   283
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      72,     0,    -1,    73,    -1,    73,    74,    -1,    73,    82,
      -1,    73,    85,    -1,    73,     1,    65,    -1,    73,     1,
      66,    -1,    -1,    75,    65,    -1,    75,    76,    66,    65,
      -1,    24,    36,    67,    -1,    76,    66,    77,    -1,    77,
      -1,    79,    78,    -1,    79,    52,    78,    -1,    36,    -1,
      80,    62,    -1,    80,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    36,    -1,    81,    68,    77,
      -1,    64,    77,    -1,    64,    -1,    77,    81,    69,    83,
      -1,    77,    81,    69,    66,    -1,    67,    65,    -1,    67,
      84,    65,    -1,    84,    85,    -1,    85,    -1,    83,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,    66,
      -1,    66,    -1,    77,    55,    90,    66,    -1,    22,    64,
      90,    69,    85,    -1,    20,    64,    90,    69,    85,    -1,
      20,    64,    90,    69,    85,    21,    85,    -1,    23,    66,
      -1,    23,    90,    66,    -1,    91,    -1,    92,    -1,    93,
      -1,    96,    -1,    64,    90,    69,    -1,    97,    -1,    98,
      -1,    90,    55,    90,    -1,    90,    30,    90,    -1,    90,
      31,    90,    -1,    90,    32,    90,    -1,    90,    33,    90,
      -1,    90,    34,    90,    -1,    90,    35,    90,    -1,    90,
      56,    90,    -1,    90,    57,    90,    -1,    90,    58,    90,
      -1,    90,    59,    90,    -1,    90,    60,    90,    -1,    56,
      90,    -1,    57,    90,    -1,    61,    90,    -1,    40,    90,
      -1,    41,    90,    -1,    28,    36,    64,    69,    -1,    28,
      19,    64,    90,    69,    -1,    28,    80,    62,    90,    70,
      -1,    80,    62,    90,    70,    -1,    94,    68,    90,    -1,
      90,    -1,    36,    64,    -1,    95,    69,    -1,    95,    94,
      69,    -1,    36,    -1,    90,    62,    90,    70,    -1,    90,
      63,    36,    -1,    37,    -1,    38,    -1,    39,    -1,    25,
      -1,    26,    -1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    50,    51,    52,    53,    54,    55,    58,
      59,    63,    67,    68,    71,    72,    75,    78,    79,    82,
      83,    84,    85,    86,    87,    90,    92,    93,    96,    98,
     102,   103,   107,   108,   111,   112,   113,   114,   115,   116,
     117,   120,   125,   129,   131,   136,   138,   141,   142,   143,
     144,   145,   146,   147,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   164,   165,   166,   167,
     168,   171,   173,   175,   177,   181,   182,   185,   188,   189,
     192,   193,   195,   199,   200,   201,   202,   203,   204
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
  "TOK_PARAMLIST", "TOK_TIM", "TOK_TIMER", "TOK_BLOCK", "TOK_CALL",
  "TOK_IFELSE", "TOK_INITDECL", "TOK_POS", "TOK_NEG", "TOK_NEWARRAY",
  "TOK_TYPEID", "TOK_FIELD", "'='", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "'['", "'.'", "'('", "'}'", "';'", "'{'", "','", "')'", "']'",
  "$accept", "start", "program", "structdef", "structh", "strdecl", "decl",
  "declid", "type", "basetype", "params", "function", "block", "stmts",
  "statement", "vardecl", "while", "ifelse", "return", "expr", "binop",
  "unop", "allocator", "exprs", "callfront", "call", "variable",
  "constant", 0
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
     305,   306,   307,   308,   309,    61,    43,    45,    42,    47,
      37,    33,    91,    46,    40,   125,    59,   123,    44,    41,
      93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    76,    76,    77,    77,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    86,    87,    88,    88,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    94,    94,    95,    96,    96,
      97,    97,    97,    98,    98,    98,    98,    98,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     2,
       4,     3,     3,     1,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     4,     4,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     4,     5,     5,     7,     2,     3,     1,     1,     1,
       1,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     4,     5,     5,     4,     3,     1,     2,     2,     3,
       1,     4,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    19,    20,    21,    22,    23,
       0,     0,     0,     0,    86,    87,    88,     0,    80,    83,
      84,    85,     0,     0,     0,     0,     0,     0,    40,     0,
       3,     0,     0,     0,    18,     4,    34,     5,    35,    36,
      37,    38,     0,    47,    48,    49,     0,    50,    52,    53,
       6,     7,     0,     0,    45,     0,     0,     0,    23,    24,
       0,    77,    69,    70,    66,    67,    68,     0,    30,     0,
       0,    33,    24,     9,     0,    13,    18,     0,    27,     0,
      16,     0,    14,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    78,
      76,     0,     0,     0,     0,    46,    11,     0,     0,     0,
      51,    31,    32,     0,    17,     0,    26,     0,     0,    15,
       0,    55,    56,    57,    58,    59,    60,    54,    61,    62,
      63,    64,    65,     0,    82,     0,    79,     0,     0,     0,
      71,     0,    10,    12,    41,    25,    29,    28,    74,    81,
      75,    43,    42,    72,    73,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    30,    31,    74,    69,    82,    33,    55,
      79,    35,    36,    70,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   101,    46,    47,    48,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const yytype_int16 yypact[] =
{
     -62,     2,   124,   -62,   -61,   -62,   -62,   -62,   -62,   -62,
     -51,   -42,   391,   -10,   -62,   -62,   -62,    76,   -11,   -62,
     -62,   -62,   443,   443,   443,   443,   443,   443,   -62,   232,
     -62,    -8,   -52,   -22,   -38,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   608,   -62,   -62,   -62,   177,   -62,   -62,   -62,
     -62,   -62,   443,   443,   -62,   -23,   645,   -17,   -19,     0,
       5,   -62,   -31,   -31,   -31,   -31,   -31,   498,   -62,     1,
     285,   -62,   -62,   -62,     4,   -62,     7,   443,   139,   -25,
     -62,    36,   -62,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,    38,   -62,   -62,
     694,   -20,   538,   553,   443,   -62,   -62,   443,     6,   443,
     -62,   -62,   -62,   101,   -62,   657,   -62,   139,   -12,   -62,
       3,   111,   111,   111,   111,   111,   111,   694,   148,   148,
     -31,   -31,   -31,   455,   -62,   443,   -62,   338,   338,   593,
     -62,   489,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     694,    75,   -62,   -62,   -62,   338,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -62,   -62,   -62,   -62,    21,    16,   -62,    -2,
     -62,   -62,   -18,   -62,   -28,   -62,   -62,   -62,   -62,    -6,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -25
static const yytype_int16 yytable[] =
{
      34,    71,     3,    77,    50,    51,    56,     5,     6,     7,
       8,     9,    78,    52,    80,    60,    62,    63,    64,    65,
      66,    67,    53,    32,    83,   -24,    57,    34,    72,    76,
      81,    96,    97,    84,    85,    86,    87,    88,    89,   104,
     100,   -24,   112,   117,   118,   107,   102,   103,   135,   136,
     106,   -24,    75,    61,   146,    29,    77,    73,    90,    91,
      92,    93,    94,    95,   108,    96,    97,   109,    34,   114,
     113,   115,    80,   148,   134,   140,    76,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,     5,     6,     7,     8,    58,   155,   119,   120,   116,
     147,   139,     0,   141,     0,     0,     0,     0,     0,   151,
     152,    76,    59,     0,     0,    76,     5,     6,     7,     8,
       9,     0,     0,     0,    -2,     4,     0,   156,     0,   150,
       0,     0,     0,     0,   143,    34,    34,    72,   145,     5,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,    16,    17,    34,     5,     6,     7,     8,     9,     0,
      18,    19,    20,    21,    22,    23,   142,    91,    92,    93,
      94,    95,     0,    96,    97,    72,     0,     0,     0,     0,
      24,    25,     0,     0,     0,    26,     0,     0,    27,     0,
      28,    29,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    14,    15,    16,    17,    93,    94,    95,     0,
      96,    97,     0,    18,    19,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,     0,     0,     0,    26,     0,
       0,    27,     0,     0,     0,     0,    99,     5,     6,     7,
       8,     9,    10,     0,    11,    12,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
       0,     0,     0,    26,     0,     0,    27,    68,    28,    29,
       5,     6,     7,     8,     9,    10,     0,    11,    12,     0,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,     0,     0,     0,    26,     0,     0,    27,
     111,    28,    29,     5,     6,     7,     8,     9,    10,     0,
      11,    12,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,     0,     0,     0,    26,
       0,     0,    27,     0,    28,    29,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,     0,
       0,     0,    26,     0,     0,    27,     0,    54,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,     0,     0,     0,    26,     0,     0,    27,     0,     0,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    84,
      85,    86,    87,    88,    89,   149,     0,     0,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
       0,    96,    97,    90,    91,    92,    93,    94,    95,   154,
      96,    97,     0,     0,     0,     0,     0,   110,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,     0,
      96,    97,     0,     0,     0,     0,     0,   137,    90,    91,
      92,    93,    94,    95,     0,    96,    97,     0,     0,     0,
       0,     0,   138,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,    96,    97,     0,     0,     0,
       0,     0,   153,    90,    91,    92,    93,    94,    95,     0,
      96,    97,     0,     0,    98,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     0,    96,    97,     0,
       0,   105,    90,    91,    92,    93,    94,    95,     0,    96,
      97,     0,     0,   144,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,     0,    96,    97
};

static const yytype_int16 yycheck[] =
{
       2,    29,     0,    55,    65,    66,    12,    15,    16,    17,
      18,    19,    64,    64,    36,    17,    22,    23,    24,    25,
      26,    27,    64,     2,    62,    36,    36,    29,    36,    31,
      52,    62,    63,    30,    31,    32,    33,    34,    35,    62,
      46,    52,    70,    68,    69,    64,    52,    53,    68,    69,
      67,    62,    31,    64,    66,    67,    55,    65,    55,    56,
      57,    58,    59,    60,    64,    62,    63,    62,    70,    62,
      66,    77,    36,    70,    36,    69,    78,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    15,    16,    17,    18,    19,    21,    81,   104,    78,
     118,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,   137,
     138,   113,    36,    -1,    -1,   117,    15,    16,    17,    18,
      19,    -1,    -1,    -1,     0,     1,    -1,   155,    -1,   135,
      -1,    -1,    -1,    -1,   113,   137,   138,    36,   117,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,   155,    15,    16,    17,    18,    19,    -1,
      36,    37,    38,    39,    40,    41,    65,    56,    57,    58,
      59,    60,    -1,    62,    63,    36,    -1,    -1,    -1,    -1,
      56,    57,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,
      66,    67,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    58,    59,    60,    -1,
      62,    63,    -1,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    69,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      -1,    -1,    -1,    61,    -1,    -1,    64,    65,    66,    67,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    -1,    -1,    61,    -1,    -1,    64,
      65,    66,    67,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    61,
      -1,    -1,    64,    -1,    66,    67,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    -1,
      -1,    -1,    61,    -1,    -1,    64,    -1,    66,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    30,
      31,    32,    33,    34,    35,    70,    -1,    -1,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    55,    56,    57,    58,    59,    60,    70,
      62,    63,    -1,    -1,    -1,    -1,    -1,    69,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    -1,    -1,    -1,    -1,    -1,    69,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    69,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    69,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    -1,    -1,    66,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    -1,
      -1,    66,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    -1,    -1,    66,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    -1,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,    73,     0,     1,    15,    16,    17,    18,    19,
      20,    22,    23,    24,    25,    26,    27,    28,    36,    37,
      38,    39,    40,    41,    56,    57,    61,    64,    66,    67,
      74,    75,    77,    79,    80,    82,    83,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    95,    96,    97,    98,
      65,    66,    64,    64,    66,    80,    90,    36,    19,    36,
      80,    64,    90,    90,    90,    90,    90,    90,    65,    77,
      84,    85,    36,    65,    76,    77,    80,    55,    64,    81,
      36,    52,    78,    62,    30,    31,    32,    33,    34,    35,
      55,    56,    57,    58,    59,    60,    62,    63,    66,    69,
      90,    94,    90,    90,    62,    66,    67,    64,    64,    62,
      69,    65,    85,    66,    62,    90,    77,    68,    69,    78,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    36,    68,    69,    69,    69,    90,
      69,    90,    65,    77,    66,    77,    66,    83,    70,    70,
      90,    85,    85,    69,    70,    21,    85
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
#line 58 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); free_ast((yyvsp[(2) - (2)])); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 59 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)])); 
                                      free_ast2((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 63 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), 
          TOK_STRUCT); free_ast ((yyvsp[(3) - (3)])); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); free_ast ((yyvsp[(2) - (3)])); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])) ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_DECLID); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 87 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_TYPEID); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    { adopt1sym((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), TOK_PARAMLIST);
                              free_ast((yyvsp[(2) - (3)])); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    { adopt1sym((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_PARAMLIST); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_PARAMLIST); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    { 
                   (yyval) = adopt3 (new_function((yyvsp[(1) - (4)])), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    { 
              (yyval) = adopt2 (new_prototype((yyvsp[(1) - (4)])), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)])); free_ast((yyvsp[(4) - (4)])); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    { (yyval) = adopt1sym ((yyval), (yyvsp[(1) - (2)]), TOK_BLOCK); free_ast ((yyvsp[(2) - (2)])); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { (yyval) = adoptsym(stealkids ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), TOK_BLOCK); 
                          free_ast ((yyvsp[(3) - (3)])); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { (yyval) = adopt1(new_block((yyvsp[(1) - (1)])), (yyvsp[(1) - (1)])); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); free_ast ((yyvsp[(2) - (2)])); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_BLOCK); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { (yyval) = adoptsym (adopt2((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])), TOK_VARDECL);
                 free_ast ((yyvsp[(4) - (4)])); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); free_ast2 ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); free_ast2 ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    { (yyval) = adopt2 (adopt1sym ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), TOK_IFELSE), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
         free_ast3 ((yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(6) - (7)])); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (2)]), TOK_RETURNVOID); 
         free_ast ((yyvsp[(2) - (2)])); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); free_ast ((yyvsp[(3) - (3)])); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { free_ast2 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_POS); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_NEG); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), 
                             TOK_TYPEID); free_ast2 ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (5)]),
                           (yyvsp[(4) - (5)]), TOK_STRING); free_ast3 ((yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    { (yyval) = adopt1 (adopt1sym((yyvsp[(1) - (5)]),
                         (yyvsp[(2) - (5)]), TOK_NEWARRAY), (yyvsp[(4) - (5)])); free_ast2 ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    { (yyval) = adopt1sym((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), 
                                  TOK_NEWARRAY); free_ast2 ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    { free_ast((yyvsp[(2) - (3)])); (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]), TOK_CALL); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); free_ast((yyvsp[(2) - (2)])); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    { free_ast ((yyvsp[(3) - (3)])); (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), 
                                TOK_VARDECL); free_ast2 ((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    { (yyval) = adopt2sym ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 
                                 TOK_VARDECL); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_INTCON); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_CHARCON); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_STRINGCON); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_FALSE); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_TRUE); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    { (yyval) = adoptsym ((yyvsp[(1) - (1)]), TOK_NULL); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2269 "yyparse.cc"
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
#line 209 "parser.y"


const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}









































