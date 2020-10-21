/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "SemanticParser.y"

#include <stdlib.h>
#include <stdio.h>

#include "symboltable.h"
#include "lex.yy.c"

int yyerror(char *msg);
extern table_entry** constant_table;

int cur_dtype;

table_t symbol_table_list[MAX_SCOPE];

int is_declaration = 0, is_loop = 0, is_func = 0, func_type, p_idx = 0, p=0, rhs = 0;
extern int yylinno;
int param_list[10];

void type_check(int,int,int);


/* Line 371 of yacc.c  */
#line 90 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     DEC_CONSTANT = 259,
     HEX_CONSTANT = 260,
     CHAR_CONSTANT = 261,
     FLOAT_CONSTANT = 262,
     STRING = 263,
     LOGICAL_AND = 264,
     LOGICAL_OR = 265,
     LS_EQ = 266,
     GR_EQ = 267,
     EQ = 268,
     NOT_EQ = 269,
     MUL_ASSIGN = 270,
     DIV_ASSIGN = 271,
     MOD_ASSIGN = 272,
     ADD_ASSIGN = 273,
     SUB_ASSIGN = 274,
     INCREMENT = 275,
     DECREMENT = 276,
     SHORT = 277,
     INT = 278,
     LONG = 279,
     LONG_LONG = 280,
     SIGNED = 281,
     UNSIGNED = 282,
     CONST = 283,
     VOID = 284,
     CHAR = 285,
     FLOAT = 286,
     DOUBLE = 287,
     IF = 288,
     FOR = 289,
     WHILE = 290,
     CONTINUE = 291,
     BREAK = 292,
     RETURN = 293,
     UMINUS = 294,
     LOWER_THAN_ELSE = 295,
     ELSE = 296
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define DEC_CONSTANT 259
#define HEX_CONSTANT 260
#define CHAR_CONSTANT 261
#define FLOAT_CONSTANT 262
#define STRING 263
#define LOGICAL_AND 264
#define LOGICAL_OR 265
#define LS_EQ 266
#define GR_EQ 267
#define EQ 268
#define NOT_EQ 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define MOD_ASSIGN 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define INCREMENT 275
#define DECREMENT 276
#define SHORT 277
#define INT 278
#define LONG 279
#define LONG_LONG 280
#define SIGNED 281
#define UNSIGNED 282
#define CONST 283
#define VOID 284
#define CHAR 285
#define FLOAT 286
#define DOUBLE 287
#define IF 288
#define FOR 289
#define WHILE 290
#define CONTINUE 291
#define BREAK 292
#define RETURN 293
#define UMINUS 294
#define LOWER_THAN_ELSE 295
#define ELSE 296



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 24 "SemanticParser.y"

	int data_type;
	table_entry* entry;


/* Line 387 of yacc.c  */
#line 221 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 249 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   495

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,     2,    47,     2,     2,
      52,    53,    45,    43,    39,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
      41,    40,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      35,    36,    37,    38,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    13,    14,    23,
      26,    28,    31,    33,    36,    38,    40,    42,    44,    47,
      49,    51,    54,    56,    59,    61,    63,    65,    67,    69,
      70,    74,    76,    79,    81,    83,    84,    89,    92,    93,
      95,    97,    99,   101,   104,   107,   110,   113,   117,   118,
     126,   127,   136,   142,   150,   151,   158,   162,   165,   168,
     172,   174,   176,   178,   180,   183,   185,   189,   191,   195,
     199,   203,   207,   211,   215,   219,   223,   226,   228,   230,
     232,   236,   240,   244,   248,   252,   255,   258,   261,   264,
     266,   268,   270,   272,   274,   276,   278,   280,   282,   286,
     290,   294,   298,   302,   306,   309,   311,   313,   315,   317,
     319,   321,   326,   328,   330,   335,   339,   343,   345,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    60,    61,    -1,    61,    -1,    62,    -1,
      84,    -1,    -1,    -1,    65,    93,    63,    52,    70,    53,
      64,    74,    -1,    67,    66,    -1,    67,    -1,    45,    66,
      -1,    45,    -1,    68,    69,    -1,    69,    -1,    26,    -1,
      27,    -1,    23,    -1,    22,    23,    -1,    22,    -1,    24,
      -1,    24,    23,    -1,    25,    -1,    25,    23,    -1,    30,
      -1,    31,    -1,    32,    -1,    29,    -1,    71,    -1,    -1,
      71,    39,    72,    -1,    72,    -1,    65,    93,    -1,    74,
      -1,    77,    -1,    -1,    54,    75,    76,    55,    -1,    76,
      73,    -1,    -1,    81,    -1,    78,    -1,    82,    -1,    84,
      -1,    99,    56,    -1,    38,    56,    -1,    36,    56,    -1,
      37,    56,    -1,    38,    89,    56,    -1,    -1,    34,    52,
      87,    87,    53,    79,    73,    -1,    -1,    34,    52,    87,
      87,    88,    53,    80,    73,    -1,    33,    52,    88,    53,
      73,    -1,    33,    52,    88,    53,    73,    51,    73,    -1,
      -1,    35,    52,    88,    53,    83,    73,    -1,    65,    85,
      56,    -1,    85,    56,    -1,    91,    56,    -1,    85,    39,
      86,    -1,    86,    -1,    90,    -1,    93,    -1,    97,    -1,
      88,    56,    -1,    56,    -1,    88,    39,    89,    -1,    89,
      -1,    89,    42,    89,    -1,    89,    41,    89,    -1,    89,
      13,    89,    -1,    89,    14,    89,    -1,    89,    11,    89,
      -1,    89,    12,    89,    -1,    89,     9,    89,    -1,    89,
      10,    89,    -1,    48,    89,    -1,    95,    -1,    90,    -1,
      91,    -1,    92,    94,    95,    -1,    92,    94,    97,    -1,
      92,    94,    99,    -1,    92,    94,    91,    -1,    91,    94,
      91,    -1,    93,    20,    -1,    93,    21,    -1,    21,    93,
      -1,    20,    93,    -1,    93,    -1,    97,    -1,     3,    -1,
      40,    -1,    18,    -1,    19,    -1,    15,    -1,    16,    -1,
      17,    -1,    95,    43,    95,    -1,    95,    44,    95,    -1,
      95,    45,    95,    -1,    95,    46,    95,    -1,    95,    47,
      95,    -1,    52,    95,    53,    -1,    44,    95,    -1,    93,
      -1,    96,    -1,     4,    -1,     5,    -1,     6,    -1,     7,
      -1,    93,    57,    98,    58,    -1,    96,    -1,    93,    -1,
      93,    52,   100,    53,    -1,    93,    52,    53,    -1,   100,
      39,   101,    -1,   101,    -1,    89,    -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    67,    70,    71,    76,    82,    75,    96,
      98,   102,   103,   106,   107,   110,   111,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   129,   130,
     133,   134,   138,   142,   143,   148,   148,   158,   159,   163,
     164,   165,   166,   167,   168,   177,   178,   180,   190,   190,
     191,   191,   194,   195,   198,   198,   201,   203,   204,   207,
     208,   211,   212,   213,   217,   218,   221,   222,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     242,   243,   244,   245,   246,   249,   250,   251,   252,   254,
     255,   258,   274,   275,   276,   277,   278,   279,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   293,   294,   295,
     296,   299,   330,   331,   334,   340,   348,   349,   352,   353
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DEC_CONSTANT",
  "HEX_CONSTANT", "CHAR_CONSTANT", "FLOAT_CONSTANT", "STRING",
  "LOGICAL_AND", "LOGICAL_OR", "LS_EQ", "GR_EQ", "EQ", "NOT_EQ",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "INCREMENT", "DECREMENT", "SHORT", "INT", "LONG", "LONG_LONG", "SIGNED",
  "UNSIGNED", "CONST", "VOID", "CHAR", "FLOAT", "DOUBLE", "IF", "FOR",
  "WHILE", "CONTINUE", "BREAK", "RETURN", "','", "'='", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "LOWER_THAN_ELSE",
  "ELSE", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'", "$accept",
  "starter", "builder", "function", "$@1", "$@2", "type", "pointer",
  "data_type", "sign_specifier", "type_specifier", "argument_list",
  "arguments", "arg", "stmt", "compound_stmt", "$@3", "statements",
  "single_stmt", "for_block", "$@4", "$@5", "if_block", "while_block",
  "$@6", "declaration", "declaration_list", "sub_decl", "expression_stmt",
  "expression", "sub_expr", "assignment_expr", "unary_expr", "lhs",
  "identifier", "assign_op", "arithmetic_expr", "constant", "array_access",
  "array_index", "function_call", "parameter_list", "parameter", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    44,
      61,    60,    62,    43,    45,    42,    47,    37,    33,   294,
     295,   296,    40,    41,   123,   125,    59,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    63,    64,    62,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    75,    74,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    79,    78,
      80,    78,    81,    81,    83,    82,    84,    84,    84,    85,
      85,    86,    86,    86,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    91,    91,    91,    91,    92,
      92,    93,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    97,    98,    98,    99,    99,   100,   100,   101,   101
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     0,     8,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     1,     1,     0,     4,     2,     0,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     0,     7,
       0,     8,     5,     7,     0,     6,     3,     2,     2,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1,     1,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     4,     3,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    91,     0,     0,    19,    17,    20,    22,    15,    16,
      27,    24,    25,    26,     0,     3,     4,     0,    10,     0,
      14,     5,     0,    60,    61,     0,     0,    89,    90,    88,
      87,    18,    21,    23,     1,     2,     0,     0,    89,    12,
       9,    13,     0,    57,    95,    96,    97,    93,    94,    92,
      58,     0,     0,    85,    86,     0,    56,     0,    11,    59,
      84,     0,   107,   108,   109,   110,     0,     0,    83,   105,
      80,   106,    81,    82,   113,   112,     0,    29,   105,   104,
       0,     0,     0,     0,     0,     0,     0,   111,     0,     0,
      28,    31,   103,   119,     0,   115,   118,    78,    79,   105,
      77,    90,     0,   117,    98,    99,   100,   101,   102,    32,
       7,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,    30,    74,    75,    72,    73,    70,
      71,    69,    68,   116,    35,     8,    38,     0,     0,     0,
       0,     0,     0,     0,    36,     0,    37,    33,    34,    40,
      39,    41,    42,    89,     0,     0,     0,     0,    45,    46,
      44,     0,    43,     0,    67,    65,     0,     0,     0,    47,
       0,     0,     0,    64,    54,    66,    52,    48,     0,     0,
       0,     0,    50,    55,    53,    49,     0,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    57,   123,   145,    40,    18,    19,
      20,    89,    90,    91,   146,   147,   136,   137,   148,   149,
     181,   186,   150,   151,   179,   152,    22,    23,   166,   167,
     164,    97,    98,    26,    99,    51,   100,    71,   101,    76,
     154,   102,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
     430,  -132,    16,    16,     9,  -132,    20,    38,  -132,  -132,
    -132,  -132,  -132,  -132,   414,  -132,  -132,    17,   -22,   452,
    -132,  -132,   -29,  -132,  -132,    61,   392,   119,    60,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,   108,   392,    -8,   -22,
    -132,  -132,    17,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,    17,   100,  -132,  -132,   419,  -132,   -12,  -132,  -132,
    -132,    -5,  -132,  -132,  -132,  -132,     2,     2,  -132,   103,
     447,  -132,  -132,  -132,  -132,  -132,   -13,   441,  -132,  -132,
     442,   295,     2,     2,     2,     2,     2,  -132,    16,   -19,
      26,  -132,  -132,  -132,   330,  -132,   374,  -132,   392,   340,
     447,  -132,   -18,  -132,    96,    96,  -132,  -132,  -132,  -132,
    -132,   441,  -132,   330,   330,   330,   330,   330,   330,   330,
     330,   320,  -132,    14,  -132,   407,   389,  -132,  -132,    18,
      18,  -132,  -132,  -132,  -132,  -132,  -132,   222,    46,    48,
      50,    13,    15,   105,  -132,    17,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,   178,    62,   330,   217,   330,  -132,  -132,
    -132,   121,  -132,    19,   374,  -132,   217,   112,    34,  -132,
     330,   259,   301,  -132,  -132,   374,     5,  -132,    74,   259,
     259,   259,  -132,  -132,  -132,  -132,   259,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,   122,  -132,  -132,  -132,     4,    83,  -132,  -132,
     131,  -132,  -132,    27,    47,    31,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,   114,   -16,   123,     3,  -131,
     -24,    33,    11,  -132,     0,   140,   310,   117,    22,  -132,
     132,  -132,    52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -90
static const yytype_int16 yytable[] =
{
      27,    36,    29,    30,    17,     1,    62,    63,    64,    65,
      42,    25,    53,    54,    27,    53,    54,    38,    17,     1,
       1,   121,    28,    39,   163,    25,   168,    43,    37,   115,
     116,   -62,    31,    24,   110,   122,    28,     2,     3,    28,
      77,   178,    27,    32,    -6,    87,    66,    24,   -62,    55,
      24,    61,    69,    37,    67,    74,   180,    96,   170,   119,
     120,    33,    60,    68,    28,   111,    78,    78,   134,   158,
     112,   159,   171,   170,    72,    24,    44,    45,    46,    47,
      48,    88,    78,    78,    78,    78,    78,   174,   109,   125,
     126,   127,   128,   129,   130,   131,   132,    96,   155,   -63,
     156,    49,   157,     1,    62,    63,    64,    65,     1,    62,
      63,    64,    65,   170,    21,    88,   -63,    50,   162,   161,
       2,     3,    58,    53,    54,     2,     3,   182,    21,    36,
     113,   114,   115,   116,   117,   118,    35,   153,   124,    53,
      54,    84,    85,    86,    66,    27,   175,    42,    25,    66,
      41,   170,    67,    94,   135,    81,    37,    67,   -62,    28,
      55,   160,   119,   120,    56,    59,    52,    28,   173,   172,
      24,   153,    75,   133,     0,   -62,    55,   169,    24,   153,
     153,   153,    25,     0,    73,     0,   153,     0,     0,     0,
      25,    25,    25,    28,     0,     0,     0,    25,    53,    54,
       0,    28,    28,    28,    24,     0,     0,     0,    28,     0,
       0,     0,    24,    24,    24,     0,     0,   -62,   176,    24,
       1,    62,    63,    64,    65,     1,   183,   184,   185,     0,
      81,     0,     0,   187,   -62,    55,     0,     2,     3,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,    13,   138,   139,   140,   141,   142,
     143,    66,     1,     0,     0,    94,     0,     0,     0,    67,
       0,     0,     0,   165,     0,     0,   134,   144,     0,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,    13,   138,   139,   140,   141,   142,   143,     1,    62,
      63,    64,    65,    93,     1,    62,    63,    64,    65,     0,
       0,     0,     0,   134,     0,     2,     3,     0,     0,     0,
       0,     2,     3,     1,    62,    63,    64,    65,    93,     0,
       0,     0,     0,     1,    62,    63,    64,    65,     0,    66,
       2,     3,     0,    94,     0,    66,     0,    67,    95,    94,
       2,     3,     0,    67,   177,   -89,   -89,   -89,   -89,   -89,
      53,    54,    70,     0,    66,     0,     0,     0,    94,     0,
       0,     0,    67,     0,    66,     0,    79,    80,    94,     0,
     -89,     0,    67,   113,   114,   115,   116,   117,   118,     0,
       0,     0,   104,   105,   106,   107,   108,    55,   113,     0,
     115,   116,   117,   118,     0,     0,     0,    44,    45,    46,
      47,    48,     0,     0,    34,   119,   120,     1,   115,   116,
     117,   118,     1,    62,    63,    64,    65,     0,     0,     0,
     119,   120,    49,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,    13,     0,   119,   120,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,    13,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,    13,     4,     5,     6,     7,     0,     0,
       0,    10,    11,    12,    13,    82,    83,    84,    85,    86,
      82,    83,    84,    85,    86,    92
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-132)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    17,     2,     3,     0,     3,     4,     5,     6,     7,
      39,     0,    20,    21,    14,    20,    21,    17,    14,     3,
       3,    39,     0,    45,   155,    14,   157,    56,    17,    11,
      12,    39,    23,     0,    53,    53,    14,    20,    21,    17,
      52,   172,    42,    23,    52,    58,    44,    14,    56,    57,
      17,    51,    52,    42,    52,    55,    51,    81,    39,    41,
      42,    23,    51,    52,    42,    39,    66,    67,    54,    56,
      94,    56,    53,    39,    52,    42,    15,    16,    17,    18,
      19,    77,    82,    83,    84,    85,    86,    53,    88,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    52,    39,
      52,    40,    52,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    39,     0,   111,    56,    56,    56,   143,
      20,    21,    39,    20,    21,    20,    21,    53,    14,   145,
       9,    10,    11,    12,    13,    14,    14,   137,   111,    20,
      21,    45,    46,    47,    44,   145,   170,    39,   137,    44,
      19,    39,    52,    48,   123,    52,   145,    52,    39,   137,
      57,    56,    41,    42,    56,    42,    26,   145,    56,   166,
     137,   171,    55,   121,    -1,    56,    57,    56,   145,   179,
     180,   181,   171,    -1,    52,    -1,   186,    -1,    -1,    -1,
     179,   180,   181,   171,    -1,    -1,    -1,   186,    20,    21,
      -1,   179,   180,   181,   171,    -1,    -1,    -1,   186,    -1,
      -1,    -1,   179,   180,   181,    -1,    -1,    39,   171,   186,
       3,     4,     5,     6,     7,     3,   179,   180,   181,    -1,
      52,    -1,    -1,   186,    56,    57,    -1,    20,    21,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    44,     3,    -1,    -1,    48,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    54,    55,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    54,    -1,    20,    21,    -1,    -1,    -1,
      -1,    20,    21,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    44,
      20,    21,    -1,    48,    -1,    44,    -1,    52,    53,    48,
      20,    21,    -1,    52,    53,    15,    16,    17,    18,    19,
      20,    21,    52,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    -1,    44,    -1,    66,    67,    48,    -1,
      40,    -1,    52,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    57,     9,    -1,
      11,    12,    13,    14,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    -1,    -1,     0,    41,    42,     3,    11,    12,
      13,    14,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      41,    42,    40,     3,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    -1,    41,    42,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    30,    31,    32,    43,    44,    45,    46,    47,
      43,    44,    45,    46,    47,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    21,    22,    23,    24,    25,    26,    27,
      29,    30,    31,    32,    60,    61,    62,    65,    67,    68,
      69,    84,    85,    86,    90,    91,    92,    93,    97,    93,
      93,    23,    23,    23,     0,    61,    85,    91,    93,    45,
      66,    69,    39,    56,    15,    16,    17,    18,    19,    40,
      56,    94,    94,    20,    21,    57,    56,    63,    66,    86,
      91,    93,     4,     5,     6,     7,    44,    52,    91,    93,
      95,    96,    97,    99,    93,    96,    98,    52,    93,    95,
      95,    52,    43,    44,    45,    46,    47,    58,    65,    70,
      71,    72,    53,     8,    48,    53,    89,    90,    91,    93,
      95,    97,   100,   101,    95,    95,    95,    95,    95,    93,
      53,    39,    89,     9,    10,    11,    12,    13,    14,    41,
      42,    39,    53,    64,    72,    89,    89,    89,    89,    89,
      89,    89,    89,   101,    54,    74,    75,    76,    33,    34,
      35,    36,    37,    38,    55,    65,    73,    74,    77,    78,
      81,    82,    84,    93,    99,    52,    52,    52,    56,    56,
      56,    89,    56,    88,    89,    56,    87,    88,    88,    56,
      39,    53,    87,    56,    53,    89,    73,    53,    88,    83,
      51,    79,    53,    73,    73,    73,    80,    73
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 6:
/* Line 1792 of yacc.c  */
#line 76 "SemanticParser.y"
    {
																						func_type = cur_dtype;
																						is_declaration = 0;
																						current_scope = create_new_scope();
																					}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 82 "SemanticParser.y"
    {
																						is_declaration = 0;
																						fill_parameter_list((yyvsp[(2) - (6)].entry),param_list,p_idx);
																						p_idx = 0;
																						is_func = 1;
																						p=1;
																					}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 90 "SemanticParser.y"
    {
																						is_func = 0;
																					}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 97 "SemanticParser.y"
    {is_declaration = 1; }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 99 "SemanticParser.y"
    {is_declaration = 1; }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 114 "SemanticParser.y"
    {cur_dtype = INT;}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 115 "SemanticParser.y"
    {cur_dtype = SHORT;}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 116 "SemanticParser.y"
    {cur_dtype = SHORT;}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 117 "SemanticParser.y"
    {cur_dtype = LONG;}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 118 "SemanticParser.y"
    {cur_dtype = LONG;}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 119 "SemanticParser.y"
    {cur_dtype = LONG_LONG;}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 120 "SemanticParser.y"
    {cur_dtype = LONG_LONG;}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 121 "SemanticParser.y"
    {cur_dtype = CHAR;}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 122 "SemanticParser.y"
    {cur_dtype = FLOAT;}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 123 "SemanticParser.y"
    {cur_dtype = DOUBLE;}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 124 "SemanticParser.y"
    {cur_dtype = VOID;}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 138 "SemanticParser.y"
    {param_list[p_idx++] = (yyvsp[(2) - (2)].entry)->data_type;}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 148 "SemanticParser.y"
    {
																		if(!p)current_scope = create_new_scope();
																		else p = 0;
																}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 155 "SemanticParser.y"
    {current_scope = exit_scope();}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 168 "SemanticParser.y"
    {
																	if(is_func)
																	{
																		if(func_type != VOID)
																			yyerror("return type (VOID) does not match function type");
																	}
																  else yyerror("return statement not inside function definition");
																}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 177 "SemanticParser.y"
    {if(!is_loop) {yyerror("Illegal use of continue");}}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 178 "SemanticParser.y"
    {if(!is_loop) {yyerror("Illegal use of break");}}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 180 "SemanticParser.y"
    {
																	if(is_func)
																	{
																		if(func_type != (yyvsp[(2) - (3)].data_type))
																			yyerror("return type does not match function type");
																	}
																	else yyerror("return statement not in function definition");
															 }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 190 "SemanticParser.y"
    {is_loop = 1;}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 190 "SemanticParser.y"
    {is_loop = 0;}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 191 "SemanticParser.y"
    {is_loop = 1;}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 191 "SemanticParser.y"
    {is_loop = 0;}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 198 "SemanticParser.y"
    {is_loop = 1;}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 198 "SemanticParser.y"
    {is_loop = 0;}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 202 "SemanticParser.y"
    {is_declaration = 0; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 226 "SemanticParser.y"
    {type_check(2,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type)); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 227 "SemanticParser.y"
    {type_check(2,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type)); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 228 "SemanticParser.y"
    {type_check(2,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type)); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 229 "SemanticParser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 230 "SemanticParser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 231 "SemanticParser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 232 "SemanticParser.y"
    {type_check(2,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type)); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 233 "SemanticParser.y"
    {type_check(2,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type)); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 234 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(2) - (2)].data_type);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 235 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].data_type);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 236 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].data_type);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 237 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].data_type);}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 242 "SemanticParser.y"
    {type_check(1,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type)); (yyval.data_type) = (yyvsp[(3) - (3)].data_type); rhs=0;}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 243 "SemanticParser.y"
    {type_check(1,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type)); (yyval.data_type) = (yyvsp[(3) - (3)].data_type);rhs=0;}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 244 "SemanticParser.y"
    {type_check(1,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type)); (yyval.data_type) = (yyvsp[(3) - (3)].data_type);rhs=0;}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 245 "SemanticParser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),1); (yyval.data_type) = (yyvsp[(3) - (3)].data_type);rhs=0;}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 246 "SemanticParser.y"
    {type_check(1,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type)); (yyval.data_type) = (yyvsp[(3) - (3)].data_type);rhs=0;}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 249 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(1) - (2)].entry)->data_type;}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 250 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(1) - (2)].entry)->data_type;}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 251 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(2) - (2)].entry)->data_type;}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 252 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(2) - (2)].entry)->data_type;}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 254 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].entry)->data_type;}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 255 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].data_type);}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 258 "SemanticParser.y"
    {
                                                                    if(is_declaration
                                                                    && !rhs) 
                                                                    {
									(yyvsp[(1) - (1)].entry) = insert(symbol_table_list[current_scope].symbol_table,yytext,INT_MAX,cur_dtype);
                                                                        if((yyvsp[(1) - (1)].entry) == NULL) yyerror("Redeclaration of variable");
                                                                    }
                                                                    else
                                                                    {
								        (yyvsp[(1) - (1)].entry) = rec_search(yytext);
                                                                        if((yyvsp[(1) - (1)].entry) == NULL) yyerror("Variable not declared");
                                                                    }
                                                                    (yyval.entry) = (yyvsp[(1) - (1)].entry);
                                                            }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 274 "SemanticParser.y"
    {rhs=1;}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 275 "SemanticParser.y"
    {rhs=1;}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 276 "SemanticParser.y"
    {rhs=1;}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 277 "SemanticParser.y"
    {rhs=1;}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 278 "SemanticParser.y"
    {rhs=1;}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 279 "SemanticParser.y"
    {rhs=1;}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 282 "SemanticParser.y"
    {type_check(0,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type));}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 283 "SemanticParser.y"
    {type_check(0,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type));}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 284 "SemanticParser.y"
    {type_check(0,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type));}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 285 "SemanticParser.y"
    {type_check(0,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type));}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 286 "SemanticParser.y"
    {type_check(0,(yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type));}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 287 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(2) - (3)].data_type);}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 288 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(2) - (2)].data_type);}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 289 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].entry)->data_type;}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 290 "SemanticParser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].entry)->data_type;}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 293 "SemanticParser.y"
    {(yyvsp[(1) - (1)].entry)->is_constant=1; (yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 294 "SemanticParser.y"
    {(yyvsp[(1) - (1)].entry)->is_constant=1; (yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 295 "SemanticParser.y"
    {(yyvsp[(1) - (1)].entry)->is_constant=1; (yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 296 "SemanticParser.y"
    {(yyvsp[(1) - (1)].entry)->is_constant=1; (yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 299 "SemanticParser.y"
    {
																															if(is_declaration)
																															{
																																if((yyvsp[(3) - (4)].entry)->value <= 0)
																																	yyerror("size of array is not positive");

																																else
                                                                                                                                if((yyvsp[(3) - (4)].entry)->is_constant && !rhs)
																																	(yyvsp[(1) - (4)].entry)->array_dimension = (yyvsp[(3) - (4)].entry)->value;
																																	else if(rhs){
																																	{
																																if((yyvsp[(3) - (4)].entry)->value > (yyvsp[(1) - (4)].entry)->array_dimension)
																																	yyerror("Array index out of bound");

																																if((yyvsp[(3) - (4)].entry)->value < 0)
																																	yyerror("Array index cannot be negative");
																															}
																															}
																															}

																															else if((yyvsp[(3) - (4)].entry)->is_constant)
																															{
																																if((yyvsp[(3) - (4)].entry)->value > (yyvsp[(1) - (4)].entry)->array_dimension)
																																	yyerror("Array index out of bound");

																																if((yyvsp[(3) - (4)].entry)->value < 0)
																																	yyerror("Array index cannot be negative");
																															}
																															(yyval.data_type) = (yyvsp[(1) - (4)].entry)->data_type;
																														}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 330 "SemanticParser.y"
    {(yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 331 "SemanticParser.y"
    {(yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 334 "SemanticParser.y"
    {
																													(yyval.data_type) = (yyvsp[(1) - (4)].entry)->data_type;
																													check_parameter_list((yyvsp[(1) - (4)].entry),param_list,p_idx);
																													p_idx = 0;
																												}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 340 "SemanticParser.y"
    {
							 																						 (yyval.data_type) = (yyvsp[(1) - (3)].entry)->data_type;
																													 check_parameter_list((yyvsp[(1) - (3)].entry),param_list,p_idx);
																													 p_idx = 0;
																												}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 352 "SemanticParser.y"
    {param_list[p_idx++] = (yyvsp[(1) - (1)].data_type);}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 353 "SemanticParser.y"
    {param_list[p_idx++] = STRING;}
    break;


/* Line 1792 of yacc.c  */
#line 2245 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 355 "SemanticParser.y"


#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"
#define ANSI_COLOR_CYAN		"\x1b[36m"
#define ANSI_COLOR_RESET	"\x1b[0m"

void type_check(int type, int left, int right)
{
	if(left != right)
	{
		switch(type)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
		}
	}
}

int main(int argc, char *argv[])
{

	yyin = fopen(argv[1], "r");
	int itr;
	for(itr = 0; itr <MAX_SCOPE; itr++){
		symbol_table_list[itr].symbol_table = NULL;
		symbol_table_list[itr].parent = -1;
	}

	constant_table = create_table();
	symbol_table_list[0].symbol_table = create_table();

	if(!yyparse())
	{
		printf(ANSI_COLOR_GREEN "\nStatus: PARSING COMPLETE\n" ANSI_COLOR_RESET "\n");
	}
	else
	{
		printf(ANSI_COLOR_RED "\nStatus: PARSING FAILED!\n" ANSI_COLOR_RESET "\n");
	}

	printf( ANSI_COLOR_CYAN "\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* STRUCTURE TABLE *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n" ANSI_COLOR_RESET);
	display_symbol_table();

	printf( ANSI_COLOR_CYAN "\n\n\n*-*-*-*-*-*-*-*-*-*-* CONSTANT TABLE *-*-*-*-*-*-*-*-*-*-*\n\n" ANSI_COLOR_RESET);
	display_constant_table(constant_table);


	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf(ANSI_COLOR_YELLOW "\nLine %d : %s Token: %s\n" ANSI_COLOR_RESET, yylineno, msg, yytext);
	printf(ANSI_COLOR_RED "\nStatus: PARSING FAILED!" ANSI_COLOR_RESET "\n");

	printf( ANSI_COLOR_CYAN "\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* STRUCTURE TABLE *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n" ANSI_COLOR_RESET);
	display_symbol_table();

	printf( ANSI_COLOR_CYAN "\n\n\n*-*-*-*-*-*-*-*-*-*-* CONSTANT TABLE *-*-*-*-*-*-*-*-*-*-*\n\n" ANSI_COLOR_RESET);
	display_constant_table(constant_table);

	exit(0);
}
