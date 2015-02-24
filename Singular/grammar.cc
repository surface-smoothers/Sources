
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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 7 "grammar.y"


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <kernel/mod2.h>
#include <misc/auxiliary.h>

#include <misc/mylimits.h>
#include <omalloc/omalloc.h>
#include <Singular/tok.h>
#include <misc/options.h>
#include <Singular/stype.h>
#include <Singular/fehelp.h>
#include <Singular/ipid.h>
#include <misc/intvec.h>
#include <kernel/oswrapper/feread.h>
#include <Singular/fevoices.h>
#include <polys/matpol.h>
#include <polys/monomials/ring.h>
#include <kernel/GBEngine/kstd1.h>
#include <Singular/subexpr.h>
#include <Singular/ipshell.h>
#include <Singular/ipconv.h>
#include <Singular/sdb.h>
#include <kernel/ideals.h>
#include <coeffs/numbers.h>
#include <kernel/polys.h>
#include <kernel/combinatorics/stairc.h>
#include <kernel/oswrapper/timer.h>
#include <Singular/cntrlc.h>
#include <polys/monomials/maps.h>
#include <kernel/GBEngine/syz.h>
#include <Singular/lists.h>
#include <Singular/libparse.h>
#include <coeffs/bigintmat.h>

#if 0
void debug_list(leftv v)
{
  idhdl r=basePackHdl;
  idhdl h;
  BOOLEAN found=FALSE;
  const char *nn=v->name;
  h=IDROOT->get(nn,myynest);
  if (h!=NULL)
  {
     Print("Curr::%s, (%s)\n",nn,Tok2Cmdname((int)IDTYP(h)));
     found=TRUE;
  }
  else         Print("`%s` not found in IDROOT\n",nn);
  while (r!=NULL)
  {
    if ((IDTYP(r)==PACKAGE_CMD)
    || (IDTYP(r)==RING_CMD)
    || (IDTYP(r)==QRING_CMD))
    {
      h=IDPACKAGE(r)->idroot->get(nn,myynest);
      if (h!=NULL)
      {
        Print("%s::%s, (%s)\n",r->id,nn,Tok2Cmdname((int)IDTYP(h)));
        found=TRUE;
      }
      else         Print("%s::%s not found\n",r->id,nn);
    }
    if (r==basePackHdl) r=IDPACKAGE(r)->idroot;
    r=r->next;
   if (r==basePackHdl) break;
  }
  if (!found)
  {
    listall(TRUE);
  }
}
#endif

/* From the bison docu:

     By defining the macro `YYMAXDEPTH', you can control how deep the
parser stack can become before a stack overflow occurs.  Define the
macro with a value that is an integer.  This value is the maximum number
of tokens that can be shifted (and not reduced) before overflow.  It
must be a constant expression whose value is known at compile time.

   The stack space allowed is not necessarily allocated.  If you
specify a large value for `YYMAXDEPTH', the parser actually allocates a
small stack at first, and then makes it bigger by stages as needed.
This increasing allocation happens automatically and silently.
Therefore, you do not need to make `YYMAXDEPTH' painfully small merely
to save space for ordinary inputs that do not need much stack.

   The default value of `YYMAXDEPTH', if you do not define it, is 10000.
*/
#define YYMAXDEPTH MAX_INT_VAL

extern int   yylineno;
extern FILE* yyin;

const  char *  currid;
BOOLEAN    yyInRingConstruction=FALSE;
BOOLEAN    expected_parms;
int        cmdtok;
int        inerror = 0;

#define TESTSETINT(a,i)                                \
   if ((a).Typ() != INT_CMD)                           \
   {                                                   \
     WerrorS("no int expression");                     \
     YYERROR;                                          \
   }                                                   \
   (i) = (int)((long)(a).Data());(a).CleanUp()

#define MYYERROR(a) { WerrorS(a); YYERROR; }

void yyerror(const char * fmt)
{

  BOOLEAN old_errorreported=errorreported;
  errorreported = TRUE;
  if (currid!=NULL)
  {
    killid(currid,&IDROOT);
    currid = NULL;
  }
  if(inerror==0)
  {
    {
      if ((strlen(fmt)>1)
      && (strncmp(fmt,"parse",5)!=0)
      && (strncmp(fmt,"syntax",6)!=0))
        WerrorS(fmt);
      Werror( "error occurred in or before %s line %d: `%s`"
             ,VoiceName(), yylineno, my_yylinebuf);
    }
    if (cmdtok!=0)
    {
      const char *s=Tok2Cmdname(cmdtok);
      if (expected_parms)
      {
        Werror("expected %s-expression. type \'help %s;\'",s,s);
      }
      else
      {
        Werror("wrong type declaration. type \'help %s;\'",s);
      }
    }
    if (!old_errorreported && (lastreserved!=NULL))
    {
      Werror("last reserved name was `%s`",lastreserved);
    }
    inerror=1;
  }
  if ((currentVoice!=NULL)
  && (currentVoice->prev!=NULL)
  && (myynest>0)
#ifdef HAVE_SDB
  && ((sdb_flags &1)==0)
#endif
  )
  {
    Werror("leaving %s",VoiceName());
  }
}



/* Line 189 of yacc.c  */
#line 243 "grammar.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DOTDOT = 258,
     EQUAL_EQUAL = 259,
     GE = 260,
     LE = 261,
     MINUSMINUS = 262,
     NOT = 263,
     NOTEQUAL = 264,
     PLUSPLUS = 265,
     COLONCOLON = 266,
     ARROW = 267,
     GRING_CMD = 268,
     BIGINTMAT_CMD = 269,
     INTMAT_CMD = 270,
     PROC_CMD = 271,
     RING_CMD = 272,
     BEGIN_RING = 273,
     IDEAL_CMD = 274,
     MAP_CMD = 275,
     MATRIX_CMD = 276,
     MODUL_CMD = 277,
     NUMBER_CMD = 278,
     POLY_CMD = 279,
     RESOLUTION_CMD = 280,
     VECTOR_CMD = 281,
     BETTI_CMD = 282,
     COEFFS_CMD = 283,
     COEF_CMD = 284,
     CONTRACT_CMD = 285,
     DEGREE_CMD = 286,
     DEG_CMD = 287,
     DIFF_CMD = 288,
     DIM_CMD = 289,
     DIVISION_CMD = 290,
     ELIMINATION_CMD = 291,
     E_CMD = 292,
     FAREY_CMD = 293,
     FETCH_CMD = 294,
     FREEMODULE_CMD = 295,
     KEEPRING_CMD = 296,
     HILBERT_CMD = 297,
     HOMOG_CMD = 298,
     IMAP_CMD = 299,
     INDEPSET_CMD = 300,
     INTERRED_CMD = 301,
     INTERSECT_CMD = 302,
     JACOB_CMD = 303,
     JET_CMD = 304,
     KBASE_CMD = 305,
     KOSZUL_CMD = 306,
     LEADCOEF_CMD = 307,
     LEADEXP_CMD = 308,
     LEAD_CMD = 309,
     LEADMONOM_CMD = 310,
     LIFTSTD_CMD = 311,
     LIFT_CMD = 312,
     MAXID_CMD = 313,
     MINBASE_CMD = 314,
     MINOR_CMD = 315,
     MINRES_CMD = 316,
     MODULO_CMD = 317,
     MONOM_CMD = 318,
     MRES_CMD = 319,
     MULTIPLICITY_CMD = 320,
     ORD_CMD = 321,
     PAR_CMD = 322,
     PARDEG_CMD = 323,
     PREIMAGE_CMD = 324,
     QUOTIENT_CMD = 325,
     QHWEIGHT_CMD = 326,
     REDUCE_CMD = 327,
     REGULARITY_CMD = 328,
     RES_CMD = 329,
     SBA_CMD = 330,
     SIMPLIFY_CMD = 331,
     SORTVEC_CMD = 332,
     SRES_CMD = 333,
     STD_CMD = 334,
     SUBST_CMD = 335,
     SYZYGY_CMD = 336,
     VAR_CMD = 337,
     VDIM_CMD = 338,
     WEDGE_CMD = 339,
     WEIGHT_CMD = 340,
     VALTVARS = 341,
     VMAXDEG = 342,
     VMAXMULT = 343,
     VNOETHER = 344,
     VMINPOLY = 345,
     END_RING = 346,
     CMD_1 = 347,
     CMD_2 = 348,
     CMD_3 = 349,
     CMD_12 = 350,
     CMD_13 = 351,
     CMD_23 = 352,
     CMD_123 = 353,
     CMD_M = 354,
     ROOT_DECL = 355,
     ROOT_DECL_LIST = 356,
     RING_DECL = 357,
     RING_DECL_LIST = 358,
     EXAMPLE_CMD = 359,
     EXPORT_CMD = 360,
     HELP_CMD = 361,
     KILL_CMD = 362,
     LIB_CMD = 363,
     LISTVAR_CMD = 364,
     SETRING_CMD = 365,
     TYPE_CMD = 366,
     STRINGTOK = 367,
     BLOCKTOK = 368,
     INT_CONST = 369,
     UNKNOWN_IDENT = 370,
     RINGVAR = 371,
     PROC_DEF = 372,
     APPLY = 373,
     ASSUME_CMD = 374,
     BREAK_CMD = 375,
     CONTINUE_CMD = 376,
     ELSE_CMD = 377,
     EVAL = 378,
     QUOTE = 379,
     FOR_CMD = 380,
     IF_CMD = 381,
     SYS_BREAK = 382,
     WHILE_CMD = 383,
     RETURN = 384,
     PARAMETER = 385,
     SYSVAR = 386,
     UMINUS = 387
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 416 "grammar.cc"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2611

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  175
/* YYNRULES -- Number of states.  */
#define YYNSTATES  399

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   387

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   143,     2,
     146,   147,     2,   135,   141,   136,   148,   137,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   144,   142,
     133,   132,   134,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   138,     2,   139,   140,     2,   149,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   145
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    17,    19,
      21,    24,    26,    28,    30,    32,    34,    36,    38,    40,
      43,    45,    47,    49,    51,    53,    55,    57,    59,    61,
      64,    66,    68,    72,    76,    80,    85,    89,    91,    93,
      95,   100,   105,   110,   114,   119,   124,   128,   133,   138,
     143,   148,   155,   162,   169,   176,   185,   194,   203,   212,
     216,   221,   230,   235,   244,   249,   253,   257,   259,   261,
     263,   267,   274,   279,   286,   293,   300,   307,   314,   321,
     325,   331,   337,   345,   346,   352,   355,   358,   360,   363,
     366,   370,   374,   378,   382,   386,   390,   394,   398,   402,
     406,   409,   412,   415,   418,   420,   424,   427,   430,   433,
     436,   445,   448,   452,   455,   457,   459,   465,   467,   469,
     474,   476,   480,   482,   486,   488,   490,   492,   494,   495,
     500,   504,   507,   511,   514,   517,   521,   526,   531,   536,
     541,   546,   551,   556,   561,   568,   575,   582,   589,   596,
     603,   610,   614,   616,   625,   628,   633,   636,   638,   640,
     643,   646,   648,   654,   657,   663,   665,   667,   671,   677,
     681,   685,   690,   693,   696,   701
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     151,     0,    -1,    -1,   151,   152,    -1,   153,    -1,   155,
     142,    -1,   167,   142,    -1,   194,    -1,   127,    -1,   142,
      -1,     1,   142,    -1,   189,    -1,   190,    -1,   154,    -1,
     191,    -1,   192,    -1,   176,    -1,   178,    -1,   179,    -1,
     104,   113,    -1,   156,    -1,   180,    -1,   181,    -1,   182,
      -1,   193,    -1,   184,    -1,   185,    -1,   187,    -1,   188,
      -1,   165,   158,    -1,   116,    -1,   166,    -1,   157,    11,
     157,    -1,   159,   148,   157,    -1,   157,   146,   147,    -1,
     157,   146,   158,   147,    -1,   138,   158,   139,    -1,   114,
      -1,   131,    -1,   168,    -1,    16,   146,   159,   147,    -1,
     100,   146,   159,   147,    -1,   101,   146,   158,   147,    -1,
     101,   146,   147,    -1,   102,   146,   159,   147,    -1,   103,
     146,   158,   147,    -1,   103,   146,   147,    -1,    92,   146,
     159,   147,    -1,    95,   146,   159,   147,    -1,    96,   146,
     159,   147,    -1,    98,   146,   159,   147,    -1,    93,   146,
     159,   141,   159,   147,    -1,    95,   146,   159,   141,   159,
     147,    -1,    97,   146,   159,   141,   159,   147,    -1,    98,
     146,   159,   141,   159,   147,    -1,    94,   146,   159,   141,
     159,   141,   159,   147,    -1,    96,   146,   159,   141,   159,
     141,   159,   147,    -1,    97,   146,   159,   141,   159,   141,
     159,   147,    -1,    98,   146,   159,   141,   159,   141,   159,
     147,    -1,    99,   146,   147,    -1,    99,   146,   158,   147,
      -1,   175,   146,   159,   141,   159,   141,   159,   147,    -1,
     175,   146,   159,   147,    -1,    17,   146,   169,   141,   169,
     141,   173,   147,    -1,    17,   146,   159,   147,    -1,   166,
      12,   113,    -1,   158,   141,   159,    -1,   159,    -1,   164,
      -1,   157,    -1,   146,   158,   147,    -1,   159,   138,   159,
     141,   159,   139,    -1,   159,   138,   159,   139,    -1,   118,
     146,   159,   141,    92,   147,    -1,   118,   146,   159,   141,
      95,   147,    -1,   118,   146,   159,   141,    96,   147,    -1,
     118,   146,   159,   141,    98,   147,    -1,   118,   146,   159,
     141,    99,   147,    -1,   118,   146,   159,   141,   159,   147,
      -1,   161,   159,   163,    -1,   161,   159,   132,   159,   163,
      -1,   162,   159,   141,   159,   163,    -1,   162,   159,   141,
     159,   141,   159,   163,    -1,    -1,   123,   146,   160,   159,
     147,    -1,   124,   146,    -1,   119,   146,    -1,   147,    -1,
     159,    10,    -1,   159,     7,    -1,   159,   135,   159,    -1,
     159,   136,   159,    -1,   159,   137,   159,    -1,   159,   140,
     159,    -1,   159,   133,   159,    -1,   159,   143,   159,    -1,
     159,     9,   159,    -1,   159,     4,   159,    -1,   159,     3,
     159,    -1,   159,   144,   159,    -1,     8,   159,    -1,   136,
     159,    -1,   167,   174,    -1,   158,   132,    -1,   115,    -1,
     149,   159,   149,    -1,   100,   157,    -1,   101,   157,    -1,
     102,   157,    -1,   103,   157,    -1,   175,   157,   138,   159,
     139,   138,   159,   139,    -1,   175,   157,    -1,   167,   141,
     157,    -1,    16,   157,    -1,   112,    -1,   159,    -1,   146,
     159,   141,   158,   147,    -1,   115,    -1,   170,    -1,   170,
     146,   158,   147,    -1,   171,    -1,   171,   141,   172,    -1,
     171,    -1,   146,   172,   147,    -1,   132,    -1,    21,    -1,
      15,    -1,    14,    -1,    -1,   133,   168,   177,   142,    -1,
     106,   112,   142,    -1,   106,   142,    -1,   104,   112,   142,
      -1,   105,   158,    -1,   107,   157,    -1,   181,   141,   157,
      -1,   109,   146,   100,   147,    -1,   109,   146,   101,   147,
      -1,   109,   146,   102,   147,    -1,   109,   146,   103,   147,
      -1,   109,   146,    17,   147,    -1,   109,   146,   175,   147,
      -1,   109,   146,    16,   147,    -1,   109,   146,   157,   147,
      -1,   109,   146,   157,   141,   100,   147,    -1,   109,   146,
     157,   141,   101,   147,    -1,   109,   146,   157,   141,   102,
     147,    -1,   109,   146,   157,   141,   103,   147,    -1,   109,
     146,   157,   141,    17,   147,    -1,   109,   146,   157,   141,
     175,   147,    -1,   109,   146,   157,   141,    16,   147,    -1,
     109,   146,   147,    -1,    17,    -1,   183,   157,   174,   169,
     141,   169,   141,   173,    -1,   183,   157,    -1,   183,   157,
     174,   157,    -1,   131,   168,    -1,   110,    -1,    41,    -1,
     186,   159,    -1,   111,   159,    -1,   158,    -1,   126,   146,
     159,   147,   113,    -1,   122,   113,    -1,   126,   146,   159,
     147,   120,    -1,   120,    -1,   121,    -1,   128,   112,   113,
      -1,   125,   112,   112,   112,   113,    -1,    16,   166,   113,
      -1,   117,   112,   113,    -1,   117,   112,   112,   113,    -1,
     130,   167,    -1,   130,   159,    -1,   129,   146,   158,   147,
      -1,   129,   146,   147,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   363,   363,   365,   399,   400,   402,   404,   408,   413,
     415,   466,   467,   468,   469,   470,   471,   472,   473,   477,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   491,
     498,   503,   507,   511,   515,   519,   532,   560,   584,   590,
     596,   600,   604,   608,   612,   616,   620,   624,   628,   632,
     636,   640,   644,   648,   652,   656,   660,   664,   668,   672,
     676,   682,   686,   690,   694,   698,   705,   716,   722,   727,
     728,   729,   733,   737,   741,   745,   749,   753,   757,   761,
     765,   782,   788,   796,   795,   813,   821,   829,   838,   842,
     846,   850,   854,   858,   862,   866,   870,   874,   878,   882,
     886,   898,   905,   906,   925,   926,   938,   943,   948,   952,
     956,   996,  1022,  1043,  1051,  1055,  1056,  1070,  1078,  1087,
    1132,  1133,  1142,  1143,  1149,  1156,  1158,  1160,  1170,  1169,
    1177,  1182,  1189,  1197,  1209,  1225,  1244,  1248,  1252,  1257,
    1261,  1265,  1269,  1273,  1278,  1284,  1290,  1296,  1302,  1308,
    1314,  1326,  1333,  1337,  1374,  1381,  1389,  1395,  1395,  1398,
    1470,  1474,  1503,  1516,  1533,  1542,  1547,  1555,  1567,  1586,
    1596,  1615,  1638,  1644,  1656,  1662
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOTDOT", "EQUAL_EQUAL", "GE", "LE",
  "MINUSMINUS", "NOT", "NOTEQUAL", "PLUSPLUS", "COLONCOLON", "ARROW",
  "GRING_CMD", "BIGINTMAT_CMD", "INTMAT_CMD", "PROC_CMD", "RING_CMD",
  "BEGIN_RING", "IDEAL_CMD", "MAP_CMD", "MATRIX_CMD", "MODUL_CMD",
  "NUMBER_CMD", "POLY_CMD", "RESOLUTION_CMD", "VECTOR_CMD", "BETTI_CMD",
  "COEFFS_CMD", "COEF_CMD", "CONTRACT_CMD", "DEGREE_CMD", "DEG_CMD",
  "DIFF_CMD", "DIM_CMD", "DIVISION_CMD", "ELIMINATION_CMD", "E_CMD",
  "FAREY_CMD", "FETCH_CMD", "FREEMODULE_CMD", "KEEPRING_CMD",
  "HILBERT_CMD", "HOMOG_CMD", "IMAP_CMD", "INDEPSET_CMD", "INTERRED_CMD",
  "INTERSECT_CMD", "JACOB_CMD", "JET_CMD", "KBASE_CMD", "KOSZUL_CMD",
  "LEADCOEF_CMD", "LEADEXP_CMD", "LEAD_CMD", "LEADMONOM_CMD",
  "LIFTSTD_CMD", "LIFT_CMD", "MAXID_CMD", "MINBASE_CMD", "MINOR_CMD",
  "MINRES_CMD", "MODULO_CMD", "MONOM_CMD", "MRES_CMD", "MULTIPLICITY_CMD",
  "ORD_CMD", "PAR_CMD", "PARDEG_CMD", "PREIMAGE_CMD", "QUOTIENT_CMD",
  "QHWEIGHT_CMD", "REDUCE_CMD", "REGULARITY_CMD", "RES_CMD", "SBA_CMD",
  "SIMPLIFY_CMD", "SORTVEC_CMD", "SRES_CMD", "STD_CMD", "SUBST_CMD",
  "SYZYGY_CMD", "VAR_CMD", "VDIM_CMD", "WEDGE_CMD", "WEIGHT_CMD",
  "VALTVARS", "VMAXDEG", "VMAXMULT", "VNOETHER", "VMINPOLY", "END_RING",
  "CMD_1", "CMD_2", "CMD_3", "CMD_12", "CMD_13", "CMD_23", "CMD_123",
  "CMD_M", "ROOT_DECL", "ROOT_DECL_LIST", "RING_DECL", "RING_DECL_LIST",
  "EXAMPLE_CMD", "EXPORT_CMD", "HELP_CMD", "KILL_CMD", "LIB_CMD",
  "LISTVAR_CMD", "SETRING_CMD", "TYPE_CMD", "STRINGTOK", "BLOCKTOK",
  "INT_CONST", "UNKNOWN_IDENT", "RINGVAR", "PROC_DEF", "APPLY",
  "ASSUME_CMD", "BREAK_CMD", "CONTINUE_CMD", "ELSE_CMD", "EVAL", "QUOTE",
  "FOR_CMD", "IF_CMD", "SYS_BREAK", "WHILE_CMD", "RETURN", "PARAMETER",
  "SYSVAR", "'='", "'<'", "'>'", "'+'", "'-'", "'/'", "'['", "']'", "'^'",
  "','", "';'", "'&'", "':'", "UMINUS", "'('", "')'", "'.'", "'`'",
  "$accept", "lines", "pprompt", "flowctrl", "example_dummy", "command",
  "assign", "elemexpr", "exprlist", "expr", "$@1", "quote_start",
  "assume_start", "quote_end", "expr_arithmetic", "left_value",
  "extendedid", "declare_ip_variable", "stringexpr", "rlist", "ordername",
  "orderelem", "OrderingList", "ordering", "cmdeq", "mat_cmd", "filecmd",
  "$@2", "helpcmd", "examplecmd", "exportcmd", "killcmd", "listcmd",
  "ringcmd1", "ringcmd", "scriptcmd", "setrings", "setringcmd", "typecmd",
  "ifcmd", "whilecmd", "forcmd", "proccmd", "parametercmd", "returncmd", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,    61,    60,    62,    43,    45,    47,    91,    93,
      94,    44,    59,    38,    58,   387,    40,    41,    46,    96
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   150,   151,   151,   152,   152,   152,   152,   152,   152,
     152,   153,   153,   153,   153,   153,   153,   153,   153,   154,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   156,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   158,   158,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   160,   159,   161,   162,   163,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   165,   165,   166,   166,   167,   167,   167,   167,
     167,   167,   167,   167,   168,   169,   169,   170,   171,   171,
     172,   172,   173,   173,   174,   175,   175,   175,   177,   176,
     178,   178,   179,   180,   181,   181,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   183,   184,   184,   184,   185,   186,   186,   187,
     188,   188,   189,   189,   189,   189,   189,   190,   191,   192,
     192,   192,   193,   193,   194,   194
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     3,     3,     4,     3,     1,     1,     1,
       4,     4,     4,     3,     4,     4,     3,     4,     4,     4,
       4,     6,     6,     6,     6,     8,     8,     8,     8,     3,
       4,     8,     4,     8,     4,     3,     3,     1,     1,     1,
       3,     6,     4,     6,     6,     6,     6,     6,     6,     3,
       5,     5,     7,     0,     5,     2,     2,     1,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     1,     3,     2,     2,     2,     2,
       8,     2,     3,     2,     1,     1,     5,     1,     1,     4,
       1,     3,     1,     3,     1,     1,     1,     1,     0,     4,
       3,     2,     3,     2,     2,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     6,     6,     6,
       6,     3,     1,     8,     2,     4,     2,     1,     1,     2,
       2,     1,     5,     2,     5,     1,     1,     3,     5,     3,
       3,     4,     2,     2,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,   127,   126,     0,   152,   125,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,     0,
     114,    37,   104,    30,     0,     0,     0,   165,   166,     0,
       0,     0,     0,     0,     8,     0,     0,     0,    38,     0,
       0,     0,     9,     0,     0,     3,     4,    13,     0,    20,
      69,   161,    67,     0,     0,    68,     0,    31,     0,    39,
       0,    16,    17,    18,    21,    22,    23,     0,    25,    26,
       0,    27,    28,    11,    12,    14,    15,    24,     7,    10,
       0,     0,     0,     0,     0,     0,    38,   100,     0,     0,
      69,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,    69,     0,    69,     0,    69,
       0,    19,   133,     0,   131,    69,     0,   160,     0,     0,
      86,   163,    83,    85,     0,     0,     0,     0,     0,   173,
     172,   156,   128,   101,     0,     0,     0,     5,     0,     0,
     103,     0,     0,     0,    89,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
     124,     0,     6,   102,     0,    69,     0,    69,   159,     0,
       0,     0,     0,     0,     0,    67,   169,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,    59,     0,    67,
      43,     0,    67,    46,     0,   132,   130,     0,     0,     0,
       0,     0,     0,   151,    69,     0,     0,   170,     0,     0,
       0,     0,   167,   175,     0,     0,    36,    70,   105,    32,
      34,     0,    66,    98,    97,    96,    94,    90,    91,    92,
       0,    93,    95,    99,    33,     0,    87,    79,     0,    65,
      69,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,    40,    67,    64,     0,    47,     0,     0,     0,    48,
       0,    49,     0,     0,    50,    60,    41,    42,    44,    45,
     142,   140,   136,   137,   138,   139,     0,   143,   141,   171,
       0,     0,     0,     0,   174,   129,    35,    72,     0,     0,
       0,     0,    62,     0,    69,   115,     0,    42,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,   168,   162,   164,     0,    80,     0,    81,     0,     0,
       0,     0,     0,    51,     0,    52,     0,     0,    53,     0,
      54,   150,   148,   144,   145,   146,   147,   149,    73,    74,
      75,    76,    77,    78,    71,     0,     0,     0,     0,   116,
     117,     0,   118,   122,     0,     0,     0,     0,     0,    82,
       0,     0,     0,   120,     0,     0,    63,    55,    56,    57,
      58,    61,   110,   153,     0,   123,     0,   121,   119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    55,    56,    57,    58,    59,    60,   145,    62,
     219,    63,    64,   247,    65,    66,    67,    68,    69,   189,
     372,   373,   384,   374,   173,    98,    71,   225,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -367
static const yytype_int16 yypact[] =
{
    -367,   330,  -367,  -120,  1932,  -367,  -367,  1990,  -105,  -367,
    -367,   -83,   -71,   -69,   -58,   -54,   -48,   -37,   -35,  2050,
    2108,  2168,  2226,   -80,  1932,   -96,  1932,   -32,  -367,  1932,
    -367,  -367,  -367,  -367,   -64,   -16,   -11,  -367,  -367,    39,
      17,    19,   -45,    40,  -367,    62,    48,  2286,    86,    86,
    1932,  1932,  -367,  1932,  1932,  -367,  -367,  -367,    57,  -367,
      -5,  -112,  1381,  1932,  1932,  -367,  1932,   189,  -115,  -367,
    2344,  -367,  -367,  -367,  -367,    65,  -367,  1932,  -367,  -367,
    1932,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
      75,  -105,    79,    81,    91,   102,  -367,    29,   104,  1932,
     101,  1381,   -10,  2404,  1932,  1932,  1932,  1932,  1932,  1932,
    1932,  1526,  1932,   191,  1584,   224,  1932,   227,  1696,   376,
     111,  -367,   113,   116,  -367,    43,  1754,  1381,   -33,  1932,
    -367,  -367,  -367,  -367,   143,  1932,   150,  1814,  1990,  1381,
     128,  -367,  -367,    29,   -86,  -117,   124,  -367,  1932,  1872,
    -367,  1932,  1932,  1932,  -367,  1932,  -367,  1932,  1932,  1932,
    1932,  1932,  1932,  1932,  1932,  1932,   242,   589,   113,   152,
    -367,  1932,  -367,  -367,  1932,   138,  1932,    76,  1381,  1932,
    1932,  1584,  1932,  1696,  1932,   603,  -367,  1932,   659,   133,
     745,   761,   775,   345,   399,   801,   487,  -367,  -110,   815,
    -367,  -107,   831,  -367,   -98,  -367,  -367,   -63,   -61,   -56,
     -46,   -42,   -39,  -367,    50,   -28,   162,  -367,   847,  1932,
     165,   861,  -367,  -367,   -90,   136,  -367,  -367,  -367,  -367,
    -367,   -89,  1381,  1433,  1557,  1557,    35,     5,     5,    29,
     503,    28,  1523,     5,  -367,  1932,  -367,  -367,  1932,  -367,
     427,   517,  1932,    78,  2404,   603,   815,   -81,   831,   -79,
     517,  -367,   917,  -367,  2404,  -367,  1932,  1932,  1932,  -367,
    1932,  -367,  1932,  1932,  -367,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,    -7,  -367,  -367,  -367,
    2462,  1003,   168,   -95,  -367,  -367,  -367,  -367,  1932,  1019,
     541,  1932,  -367,  1035,     8,  1381,   141,  -367,  -367,  1932,
     144,  1059,  1075,  1089,  1105,   557,   573,   140,   145,   146,
     148,   149,   151,   154,   -26,   -23,    46,    83,    94,  1119,
    -367,  -367,  -367,  -367,  1177,  -367,  1932,  -367,  1261,   153,
    2404,   -77,  -102,  -367,  1932,  -367,  1932,  1932,  -367,  1932,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  1019,  1932,  1932,   147,  -367,
    -367,   175,   156,  -367,   158,  1275,  1291,  1319,  1335,  -367,
    1351,  1367,  -102,   166,   163,  1932,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,   175,  -367,   -65,  -367,  -367
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -367,  -367,  -367,  -367,  -367,  -367,  -367,   118,    -1,    52,
    -367,  -367,  -367,  -296,  -367,  -367,   292,   256,    98,  -243,
    -367,  -366,   -85,   -70,   134,     0,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -156
static const yytype_int16 yytable[] =
{
      61,    70,   169,   335,   337,   383,   148,     5,     6,   317,
     318,   306,   154,   370,     9,   156,   123,   170,   332,   148,
     150,   310,    89,   122,   151,   333,   171,   172,   383,   151,
     227,   151,   120,   121,   151,   154,   154,   275,   156,   156,
     277,   103,   154,   151,   371,   156,   124,    70,   128,   279,
     144,   151,   151,   226,   148,   151,    97,   294,   296,   101,
     151,   148,   151,   104,   151,   168,   307,   134,   308,   379,
     369,   101,   101,   101,   101,   105,   151,   106,   101,   216,
     217,   127,   398,   179,   280,   103,   281,   148,   107,   148,
     180,   282,   108,   319,   320,   321,   322,   368,   109,   139,
     181,   283,   143,   186,   182,   284,   146,   183,   285,   110,
     198,   111,   148,   201,   126,   166,   167,   204,   184,   288,
     104,   358,   101,   107,   359,   100,   215,   152,   153,   101,
     129,   154,   178,   155,   156,   130,   224,   113,   115,   117,
     119,   149,   160,   161,   125,   162,   141,   142,   231,   148,
    -155,   185,   131,   165,   149,   188,   190,   191,   192,   193,
     194,   195,   196,   132,   199,   133,   161,   161,   202,   162,
     158,   159,   160,   161,   136,   162,   165,   165,   101,   164,
     257,   218,   259,   165,  -134,  -134,   135,   221,   175,   149,
     101,   286,   108,   360,   137,   177,   149,   287,    30,   147,
     101,   169,   148,   232,   233,   234,   176,   235,   170,   236,
     237,   238,   239,   240,   241,   242,   243,   101,  -154,  -135,
    -135,   179,   149,   101,   149,   180,   251,   181,   101,   110,
     361,   255,   256,  -113,   258,   148,   260,   182,   148,   262,
     111,   362,  -113,  -113,   214,   152,   153,   149,   183,   154,
     184,   155,   156,   205,   151,   220,   100,   157,   206,   158,
     159,   160,   161,   222,   162,   249,   229,   163,   164,   171,
    -111,   291,   165,   228,   264,   289,   252,   292,   295,  -111,
    -111,   331,   340,   244,   149,   342,   323,   351,   382,   250,
     370,   367,   352,   353,   253,   354,   355,   299,   356,   102,
     300,   357,   385,   140,   303,   386,   305,   394,   341,   397,
     395,   254,   393,     0,     0,     0,   305,     0,   311,   312,
     313,     0,   314,  -106,   315,   316,     0,     0,     0,     0,
       2,     3,  -106,  -106,     0,     0,     0,   149,     4,     0,
       0,     0,   329,     0,     5,     6,     7,     8,   152,   153,
     334,     9,   154,   338,   155,   156,  -107,     0,     0,  -108,
       0,     0,     0,     0,     0,  -107,  -107,     0,  -108,  -108,
     149,    10,   304,   149,   245,   157,     0,   158,   159,   160,
     161,     0,   162,     0,   396,   163,   164,   148,   365,   246,
     165,     0,   305,     0,     0,     0,   375,     0,   376,   377,
       0,   378,   152,   153,     0,     0,   154,     0,   155,   156,
       0,     0,     0,     0,     0,     0,     0,     0,   380,   381,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   148,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,     0,     0,    50,     0,    51,     0,
       0,     0,    52,     0,     0,     0,    53,     0,   157,    54,
     158,   159,   160,   161,     0,   162,   268,     0,   163,   164,
     152,   153,   269,   165,   154,     0,   155,   156,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   153,  -109,     0,
     154,     0,   155,   156,     0,     0,     0,  -109,  -109,     0,
     152,   153,   149,     0,   154,     0,   155,   156,     0,     0,
       0,     0,   157,     0,   158,   159,   160,   161,     0,   162,
     270,     0,   163,   164,   152,   153,   271,   165,   154,     0,
     155,   156,     0,     0,     0,     0,     0,     0,     0,  -112,
     152,   153,     0,     0,   154,     0,   155,   156,  -112,  -112,
       0,     0,     0,   149,     0,     0,   152,   153,     0,     0,
     154,     0,   155,   156,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   153,     0,     0,   154,     0,   155,   156,
       0,     0,     0,     0,     0,     0,   152,   153,     0,     0,
     154,     0,   155,   156,     0,     0,     0,     0,     0,     0,
     157,     0,   158,   159,   160,   161,     0,   162,   273,     0,
     163,   164,     0,     0,   274,   165,   157,     0,   158,   159,
     160,   161,   297,   162,   298,     0,   163,   164,     0,     0,
     157,   165,   158,   159,   160,   161,     0,   162,   301,     0,
     163,   164,   152,   153,   302,   165,   154,     0,   155,   156,
       0,     0,     0,     0,   157,     0,   158,   159,   160,   161,
       0,   162,   336,     0,   163,   164,     0,     0,   246,   165,
     157,     0,   158,   159,   160,   161,     0,   162,   347,     0,
     163,   164,     0,     0,   348,   165,   157,     0,   158,   159,
     160,   161,     0,   162,   349,     0,   163,   164,     0,     0,
     350,   165,   157,     0,   158,   159,   160,   161,     0,   162,
     248,     0,   163,   164,     0,     0,   157,   165,   158,   159,
     160,   161,     0,   162,     0,     0,   163,   164,   152,   153,
     261,   165,   154,     0,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   153,     0,     0,   154,     0,
     155,   156,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,   154,     0,   155,   156,     0,     0,     0,     0,
       0,     0,   157,     0,   158,   159,   160,   161,     0,   162,
       0,     0,   163,   164,   152,   153,   263,   165,   154,     0,
     155,   156,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,   154,     0,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   153,     0,     0,   154,     0,
     155,   156,     0,     0,     0,     0,     0,     0,     0,     0,
     152,   153,     0,     0,   154,     0,   155,   156,     0,     0,
       0,     0,     0,     0,   152,   153,     0,     0,   154,     0,
     155,   156,     0,     0,     0,     0,     0,     0,   157,     0,
     158,   159,   160,   161,     0,   162,     0,     0,   163,   164,
       0,     0,   265,   165,   157,     0,   158,   159,   160,   161,
       0,   162,   266,     0,   163,   164,     0,     0,   157,   165,
     158,   159,   160,   161,     0,   162,   267,     0,   163,   164,
     152,   153,     0,   165,   154,     0,   155,   156,     0,     0,
       0,     0,     0,     0,   157,     0,   158,   159,   160,   161,
       0,   162,   272,     0,   163,   164,     0,     0,   157,   165,
     158,   159,   160,   161,     0,   162,     0,     0,   163,   164,
       0,     0,   276,   165,   157,     0,   158,   159,   160,   161,
       0,   162,     0,     0,   163,   164,     0,     0,   278,   165,
     157,     0,   158,   159,   160,   161,     0,   162,   290,     0,
     163,   164,     0,     0,   157,   165,   158,   159,   160,   161,
       0,   162,     0,     0,   163,   164,   152,   153,   293,   165,
     154,     0,   155,   156,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   153,     0,     0,   154,     0,   155,   156,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,   154,     0,   155,   156,     0,     0,     0,     0,
     157,     0,   158,   159,   160,   161,     0,   162,   309,     0,
     163,   164,   152,   153,     0,   165,   154,     0,   155,   156,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,   154,     0,   155,   156,     0,     0,     0,     0,
       0,     0,   152,   153,     0,     0,   154,     0,   155,   156,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,   154,     0,   155,   156,     0,     0,     0,     0,
       0,     0,   152,   153,     0,     0,   154,     0,   155,   156,
       0,     0,     0,     0,     0,     0,   157,     0,   158,   159,
     160,   161,     0,   162,     0,     0,   163,   164,     0,     0,
     330,   165,   157,     0,   158,   159,   160,   161,     0,   162,
       0,     0,   163,   164,     0,     0,   246,   165,   157,     0,
     158,   159,   160,   161,   339,   162,     0,     0,   163,   164,
     152,   153,     0,   165,   154,     0,   155,   156,     0,     0,
       0,     0,   157,     0,   158,   159,   160,   161,     0,   162,
       0,     0,   163,   164,     0,     0,   343,   165,   157,     0,
     158,   159,   160,   161,     0,   162,   344,     0,   163,   164,
       0,     0,   157,   165,   158,   159,   160,   161,     0,   162,
       0,     0,   163,   164,     0,     0,   345,   165,   157,     0,
     158,   159,   160,   161,     0,   162,   346,     0,   163,   164,
       0,     0,   157,   165,   158,   159,   160,   161,     0,   162,
       0,     0,   163,   164,   152,   153,   363,   165,   154,     0,
     155,   156,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,   154,     0,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   153,     0,     0,   154,     0,
     155,   156,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,   158,   159,   160,   161,   364,   162,     0,     0,
     163,   164,   152,   153,     0,   165,   154,     0,   155,   156,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,   154,     0,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   153,     0,     0,   154,     0,
     155,   156,     0,     0,     0,     0,     0,     0,     0,     0,
     152,   153,     0,     0,   154,     0,   155,   156,     0,     0,
       0,     0,     0,     0,   152,   153,     0,     0,   154,     0,
     155,   156,     0,     0,   157,     0,   158,   159,   160,   161,
       0,   162,   366,     0,   163,   164,     0,     0,   157,   165,
     158,   159,   160,   161,     0,   162,     0,     0,   163,   164,
       0,     0,   387,   165,   157,     0,   158,   159,   160,   161,
       0,   162,     0,     0,   163,   164,  -156,   153,   388,   165,
     154,     0,   155,   156,     0,     0,     0,     0,     0,     0,
       0,     0,   157,     0,   158,   159,   160,   161,     0,   162,
       0,     0,   163,   164,     0,     0,   389,   165,   157,     0,
     158,   159,   160,   161,     0,   162,     0,     0,   163,   164,
       0,     0,   390,   165,   157,     0,   158,   159,   160,   161,
       0,   162,     0,     0,   163,   164,     0,     0,   391,   165,
     157,     0,   158,   159,   160,   161,   392,   162,     0,     0,
     163,   164,     0,     0,   157,   165,   158,   159,   160,   161,
       0,   162,     0,     0,   163,   164,     0,   153,     0,   165,
     154,     0,   155,   156,     4,     0,     0,     0,     0,     0,
       5,     6,    90,    91,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,     0,   157,   156,   158,   159,
     160,   161,     0,   162,     0,     0,   163,   164,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     0,     5,     6,
      90,    91,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      31,    32,    33,     0,    35,    36,     0,     0,     0,    40,
      41,     0,     0,     0,     0,     0,   157,    96,   158,   159,
     160,   161,    50,   162,    51,     0,     0,   164,     0,     0,
       0,   165,    53,   197,     0,    54,    11,    12,    13,    14,
      15,    16,    17,    18,    92,    93,    94,    95,     0,     0,
     157,     0,   158,   159,   160,   161,    30,   162,    31,    32,
      33,   164,    35,    36,     4,   165,     0,    40,    41,     0,
       5,     6,    90,    91,     0,    96,     0,     9,     0,     0,
      50,     0,    51,     0,     0,     0,     0,     0,     0,     0,
      53,   200,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     0,     5,     6,
     207,   208,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      31,    32,    33,     0,    35,    36,     0,     0,     0,    40,
      41,     0,     4,     0,     0,     0,     0,    96,     5,     6,
      90,    91,    50,     0,    51,     9,     0,     0,     0,     0,
       0,     0,    53,   203,     0,    54,    11,    12,    13,    14,
      15,    16,    17,    18,   209,   210,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    31,    32,
      33,     0,    35,    36,     0,     0,     0,    40,    41,     0,
       4,     0,     0,     0,     0,    96,     5,     6,    90,    91,
      50,     0,    51,     9,     0,     0,     0,     0,     0,     0,
      53,   213,     0,    54,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    31,    32,
      33,     0,    35,    36,     0,     0,     0,    40,    41,     0,
       4,     0,     0,     0,     0,    96,     5,     6,    90,    91,
      50,     0,    51,     9,     0,     0,     0,     0,     0,     0,
      53,   223,     0,    54,    11,    12,    13,    14,    15,    16,
      17,    18,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    31,    32,    33,     0,
      35,    36,     0,     0,     0,    40,    41,     0,     4,     0,
       0,     0,     0,    96,     5,     6,    90,    91,    50,     0,
      51,     9,     0,     0,     0,     0,     0,     0,    53,   230,
       0,    54,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    31,    32,    33,     0,
      35,    36,     0,     0,     0,    40,    41,     0,     4,     0,
       0,     0,     0,    96,     5,     6,    90,    91,    50,     0,
      51,     9,     0,     0,     0,     0,     0,     0,    53,     0,
       0,    54,    11,    12,    13,    14,    15,    16,    17,    18,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,    31,    32,    33,     0,    35,    36,
       0,     0,     0,    40,    41,     0,     4,     0,     0,     0,
       0,    96,     5,     6,    90,    91,    50,     0,    51,     9,
       0,     0,     0,     0,     0,     0,    99,     0,     0,    54,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,    31,    32,    33,     0,    35,    36,
       0,     0,     0,    40,    41,     0,     4,     0,     0,     0,
       0,    96,     5,     6,    90,    91,    50,     0,    51,     9,
       0,     0,     0,     0,     0,     0,   112,     0,     0,    54,
      11,    12,    13,    14,    15,    16,    17,    18,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,    31,    32,    33,     0,    35,    36,     0,     0,
       0,    40,    41,     0,     4,     0,     0,     0,     0,    96,
       5,     6,    90,    91,    50,     0,    51,     9,     0,     0,
       0,     0,     0,     0,   114,     0,     0,    54,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,    31,    32,    33,     0,    35,    36,     0,     0,
       0,    40,    41,     0,     4,     0,     0,     0,     0,    96,
       5,     6,   138,    91,    50,     0,    51,     9,     0,     0,
       0,     0,     0,     0,   116,     0,     0,    54,    11,    12,
      13,    14,    15,    16,    17,    18,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      31,    32,    33,     0,    35,    36,     0,     0,     0,    40,
      41,     0,     4,     0,     0,     0,     0,    96,     5,     6,
      90,    91,    50,     0,    51,     9,     0,     0,     0,     0,
       0,     0,   118,     0,     0,    54,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      31,    32,    33,     0,    35,    36,     0,     0,     0,    40,
      41,     0,     4,     0,     0,     0,     0,    96,     5,     6,
      90,    91,    50,     0,    51,     9,     0,     0,     0,     0,
       0,     0,    53,     0,     0,    54,    11,    12,    13,    14,
      15,    16,    17,    18,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    31,    32,
      33,     0,    35,    36,     0,     0,     0,    40,    41,     0,
       4,     0,     0,     0,     0,    96,     5,     6,    90,    91,
      50,     0,    51,     9,     0,     0,     0,     0,     0,     0,
     174,     0,     0,    54,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    31,    32,
      33,     0,    35,    36,     0,     0,     0,    40,    41,     0,
       0,     0,     0,     0,     0,    96,     0,     0,     0,     0,
      50,     0,    51,     0,     0,     0,     0,     0,     0,     0,
     187,     0,     0,    54,   324,    12,    13,   325,   326,    16,
     327,   328,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    31,    32,    33,     0,
      35,    36,     0,     0,     0,    40,    41,     0,     0,     0,
       0,     0,     0,    96,     0,     0,     0,     0,    50,     0,
      51,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,    54
};

static const yytype_int16 yycheck[] =
{
       1,     1,    12,   299,   300,   371,    11,    14,    15,    16,
      17,   254,     7,   115,    21,    10,   112,   132,   113,    11,
     132,   264,   142,    24,   141,   120,   141,   142,   394,   141,
     147,   141,   112,   113,   141,     7,     7,   147,    10,    10,
     147,   146,     7,   141,   146,    10,   142,    47,   112,   147,
      51,   141,   141,   139,    11,   141,     4,   147,   147,     7,
     141,    11,   141,   146,   141,    66,   147,   112,   147,   365,
     147,    19,    20,    21,    22,   146,   141,   146,    26,   112,
     113,    29,   147,   146,   147,   146,   147,    11,   146,    11,
     146,   147,   146,   100,   101,   102,   103,   340,   146,    47,
     146,   147,    50,   113,   146,   147,    54,   146,   147,   146,
     111,   146,    11,   114,   146,    63,    64,   118,   146,   147,
     146,   147,    70,   146,   147,     7,   126,     3,     4,    77,
     146,     7,    80,     9,    10,   146,   137,    19,    20,    21,
      22,   146,   137,   138,    26,   140,    48,    49,   149,    11,
     142,    99,   113,   148,   146,   103,   104,   105,   106,   107,
     108,   109,   110,   146,   112,   146,   138,   138,   116,   140,
     135,   136,   137,   138,   112,   140,   148,   148,   126,   144,
     181,   129,   183,   148,   141,   142,   146,   135,    70,   146,
     138,   141,   146,   147,   146,    77,   146,   147,   112,   142,
     148,    12,    11,   151,   152,   153,   141,   155,   132,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   142,   141,
     142,   146,   146,   171,   146,   146,   174,   146,   176,   146,
     147,   179,   180,   132,   182,    11,   184,   146,    11,   187,
     146,   147,   141,   142,   126,     3,     4,   146,   146,     7,
     146,     9,    10,   142,   141,   112,   138,   133,   142,   135,
     136,   137,   138,   113,   140,   113,   148,   143,   144,   141,
     132,   219,   148,   149,   141,   113,   138,   112,   142,   141,
     142,   113,   141,   165,   146,   141,   286,   147,   141,   171,
     115,   138,   147,   147,   176,   147,   147,   245,   147,     7,
     248,   147,   146,    47,   252,   147,   254,   141,   309,   394,
     147,   177,   382,    -1,    -1,    -1,   264,    -1,   266,   267,
     268,    -1,   270,   132,   272,   273,    -1,    -1,    -1,    -1,
       0,     1,   141,   142,    -1,    -1,    -1,   146,     8,    -1,
      -1,    -1,   290,    -1,    14,    15,    16,    17,     3,     4,
     298,    21,     7,   301,     9,    10,   132,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,   141,   142,    -1,   141,   142,
     146,    41,   254,   146,   132,   133,    -1,   135,   136,   137,
     138,    -1,   140,    -1,   385,   143,   144,    11,   336,   147,
     148,    -1,   340,    -1,    -1,    -1,   344,    -1,   346,   347,
      -1,   349,     3,     4,    -1,    -1,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,   367,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    11,   109,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,    -1,   138,    -1,
      -1,    -1,   142,    -1,    -1,    -1,   146,    -1,   133,   149,
     135,   136,   137,   138,    -1,   140,   141,    -1,   143,   144,
       3,     4,   147,   148,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,   132,    -1,
       7,    -1,     9,    10,    -1,    -1,    -1,   141,   142,    -1,
       3,     4,   146,    -1,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,   133,    -1,   135,   136,   137,   138,    -1,   140,
     141,    -1,   143,   144,     3,     4,   147,   148,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
       3,     4,    -1,    -1,     7,    -1,     9,    10,   141,   142,
      -1,    -1,    -1,   146,    -1,    -1,     3,     4,    -1,    -1,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
     133,    -1,   135,   136,   137,   138,    -1,   140,   141,    -1,
     143,   144,    -1,    -1,   147,   148,   133,    -1,   135,   136,
     137,   138,   139,   140,   141,    -1,   143,   144,    -1,    -1,
     133,   148,   135,   136,   137,   138,    -1,   140,   141,    -1,
     143,   144,     3,     4,   147,   148,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,   133,    -1,   135,   136,   137,   138,
      -1,   140,   141,    -1,   143,   144,    -1,    -1,   147,   148,
     133,    -1,   135,   136,   137,   138,    -1,   140,   141,    -1,
     143,   144,    -1,    -1,   147,   148,   133,    -1,   135,   136,
     137,   138,    -1,   140,   141,    -1,   143,   144,    -1,    -1,
     147,   148,   133,    -1,   135,   136,   137,   138,    -1,   140,
     141,    -1,   143,   144,    -1,    -1,   133,   148,   135,   136,
     137,   138,    -1,   140,    -1,    -1,   143,   144,     3,     4,
     147,   148,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,   135,   136,   137,   138,    -1,   140,
      -1,    -1,   143,   144,     3,     4,   147,   148,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,
     135,   136,   137,   138,    -1,   140,    -1,    -1,   143,   144,
      -1,    -1,   147,   148,   133,    -1,   135,   136,   137,   138,
      -1,   140,   141,    -1,   143,   144,    -1,    -1,   133,   148,
     135,   136,   137,   138,    -1,   140,   141,    -1,   143,   144,
       3,     4,    -1,   148,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,   135,   136,   137,   138,
      -1,   140,   141,    -1,   143,   144,    -1,    -1,   133,   148,
     135,   136,   137,   138,    -1,   140,    -1,    -1,   143,   144,
      -1,    -1,   147,   148,   133,    -1,   135,   136,   137,   138,
      -1,   140,    -1,    -1,   143,   144,    -1,    -1,   147,   148,
     133,    -1,   135,   136,   137,   138,    -1,   140,   141,    -1,
     143,   144,    -1,    -1,   133,   148,   135,   136,   137,   138,
      -1,   140,    -1,    -1,   143,   144,     3,     4,   147,   148,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
     133,    -1,   135,   136,   137,   138,    -1,   140,   141,    -1,
     143,   144,     3,     4,    -1,   148,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,   135,   136,
     137,   138,    -1,   140,    -1,    -1,   143,   144,    -1,    -1,
     147,   148,   133,    -1,   135,   136,   137,   138,    -1,   140,
      -1,    -1,   143,   144,    -1,    -1,   147,   148,   133,    -1,
     135,   136,   137,   138,   139,   140,    -1,    -1,   143,   144,
       3,     4,    -1,   148,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,   133,    -1,   135,   136,   137,   138,    -1,   140,
      -1,    -1,   143,   144,    -1,    -1,   147,   148,   133,    -1,
     135,   136,   137,   138,    -1,   140,   141,    -1,   143,   144,
      -1,    -1,   133,   148,   135,   136,   137,   138,    -1,   140,
      -1,    -1,   143,   144,    -1,    -1,   147,   148,   133,    -1,
     135,   136,   137,   138,    -1,   140,   141,    -1,   143,   144,
      -1,    -1,   133,   148,   135,   136,   137,   138,    -1,   140,
      -1,    -1,   143,   144,     3,     4,   147,   148,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     133,    -1,   135,   136,   137,   138,   139,   140,    -1,    -1,
     143,   144,     3,     4,    -1,   148,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,     7,    -1,
       9,    10,    -1,    -1,   133,    -1,   135,   136,   137,   138,
      -1,   140,   141,    -1,   143,   144,    -1,    -1,   133,   148,
     135,   136,   137,   138,    -1,   140,    -1,    -1,   143,   144,
      -1,    -1,   147,   148,   133,    -1,   135,   136,   137,   138,
      -1,   140,    -1,    -1,   143,   144,     3,     4,   147,   148,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,   135,   136,   137,   138,    -1,   140,
      -1,    -1,   143,   144,    -1,    -1,   147,   148,   133,    -1,
     135,   136,   137,   138,    -1,   140,    -1,    -1,   143,   144,
      -1,    -1,   147,   148,   133,    -1,   135,   136,   137,   138,
      -1,   140,    -1,    -1,   143,   144,    -1,    -1,   147,   148,
     133,    -1,   135,   136,   137,   138,   139,   140,    -1,    -1,
     143,   144,    -1,    -1,   133,   148,   135,   136,   137,   138,
      -1,   140,    -1,    -1,   143,   144,    -1,     4,    -1,   148,
       7,    -1,     9,    10,     8,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,   133,    10,   135,   136,
     137,   138,    -1,   140,    -1,    -1,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
     114,   115,   116,    -1,   118,   119,    -1,    -1,    -1,   123,
     124,    -1,    -1,    -1,    -1,    -1,   133,   131,   135,   136,
     137,   138,   136,   140,   138,    -1,    -1,   144,    -1,    -1,
      -1,   148,   146,   147,    -1,   149,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
     133,    -1,   135,   136,   137,   138,   112,   140,   114,   115,
     116,   144,   118,   119,     8,   148,    -1,   123,   124,    -1,
      14,    15,    16,    17,    -1,   131,    -1,    21,    -1,    -1,
     136,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
     114,   115,   116,    -1,   118,   119,    -1,    -1,    -1,   123,
     124,    -1,     8,    -1,    -1,    -1,    -1,   131,    14,    15,
      16,    17,   136,    -1,   138,    21,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,    -1,   149,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,   115,
     116,    -1,   118,   119,    -1,    -1,    -1,   123,   124,    -1,
       8,    -1,    -1,    -1,    -1,   131,    14,    15,    16,    17,
     136,    -1,   138,    21,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,    -1,   149,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,   115,
     116,    -1,   118,   119,    -1,    -1,    -1,   123,   124,    -1,
       8,    -1,    -1,    -1,    -1,   131,    14,    15,    16,    17,
     136,    -1,   138,    21,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,    -1,   149,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,   114,   115,   116,    -1,
     118,   119,    -1,    -1,    -1,   123,   124,    -1,     8,    -1,
      -1,    -1,    -1,   131,    14,    15,    16,    17,   136,    -1,
     138,    21,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
      -1,   149,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,   114,   115,   116,    -1,
     118,   119,    -1,    -1,    -1,   123,   124,    -1,     8,    -1,
      -1,    -1,    -1,   131,    14,    15,    16,    17,   136,    -1,
     138,    21,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,   149,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,   114,   115,   116,    -1,   118,   119,
      -1,    -1,    -1,   123,   124,    -1,     8,    -1,    -1,    -1,
      -1,   131,    14,    15,    16,    17,   136,    -1,   138,    21,
      -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,   149,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,   114,   115,   116,    -1,   118,   119,
      -1,    -1,    -1,   123,   124,    -1,     8,    -1,    -1,    -1,
      -1,   131,    14,    15,    16,    17,   136,    -1,   138,    21,
      -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,   149,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,   114,   115,   116,    -1,   118,   119,    -1,    -1,
      -1,   123,   124,    -1,     8,    -1,    -1,    -1,    -1,   131,
      14,    15,    16,    17,   136,    -1,   138,    21,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    -1,    -1,   149,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,   114,   115,   116,    -1,   118,   119,    -1,    -1,
      -1,   123,   124,    -1,     8,    -1,    -1,    -1,    -1,   131,
      14,    15,    16,    17,   136,    -1,   138,    21,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    -1,    -1,   149,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
     114,   115,   116,    -1,   118,   119,    -1,    -1,    -1,   123,
     124,    -1,     8,    -1,    -1,    -1,    -1,   131,    14,    15,
      16,    17,   136,    -1,   138,    21,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,   149,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
     114,   115,   116,    -1,   118,   119,    -1,    -1,    -1,   123,
     124,    -1,     8,    -1,    -1,    -1,    -1,   131,    14,    15,
      16,    17,   136,    -1,   138,    21,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,   149,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,   115,
     116,    -1,   118,   119,    -1,    -1,    -1,   123,   124,    -1,
       8,    -1,    -1,    -1,    -1,   131,    14,    15,    16,    17,
     136,    -1,   138,    21,    -1,    -1,    -1,    -1,    -1,    -1,
     146,    -1,    -1,   149,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,   115,
     116,    -1,   118,   119,    -1,    -1,    -1,   123,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
     136,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,    -1,    -1,   149,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,   114,   115,   116,    -1,
     118,   119,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,   149
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   151,     0,     1,     8,    14,    15,    16,    17,    21,
      41,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   109,   110,   111,
     112,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   133,
     136,   138,   142,   146,   149,   152,   153,   154,   155,   156,
     157,   158,   159,   161,   162,   164,   165,   166,   167,   168,
     175,   176,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   142,
      16,    17,   100,   101,   102,   103,   131,   159,   175,   146,
     157,   159,   166,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   157,   146,   157,   146,   157,   146,   157,
     112,   113,   158,   112,   142,   157,   146,   159,   112,   146,
     146,   113,   146,   146,   112,   146,   112,   146,    16,   159,
     167,   168,   168,   159,   158,   158,   159,   142,    11,   146,
     132,   141,     3,     4,     7,     9,    10,   133,   135,   136,
     137,   138,   140,   143,   144,   148,   159,   159,   158,    12,
     132,   141,   142,   174,   146,   157,   141,   157,   159,   146,
     146,   146,   146,   146,   146,   159,   113,   146,   159,   169,
     159,   159,   159,   159,   159,   159,   159,   147,   158,   159,
     147,   158,   159,   147,   158,   142,   142,    16,    17,   100,
     101,   102,   103,   147,   157,   175,   112,   113,   159,   160,
     112,   159,   113,   147,   158,   177,   139,   147,   149,   157,
     147,   158,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   157,   132,   147,   163,   141,   113,
     157,   159,   138,   157,   174,   159,   159,   158,   159,   158,
     159,   147,   159,   147,   141,   147,   141,   141,   141,   147,
     141,   147,   141,   141,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   141,   147,   147,   113,
     141,   159,   112,   147,   147,   142,   147,   139,   141,   159,
     159,   141,   147,   159,   157,   159,   169,   147,   147,   141,
     169,   159,   159,   159,   159,   159,   159,    16,    17,   100,
     101,   102,   103,   175,    92,    95,    96,    98,    99,   159,
     147,   113,   113,   120,   159,   163,   141,   163,   159,   139,
     141,   158,   141,   147,   141,   147,   141,   141,   147,   141,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   139,   159,   141,   138,   169,   147,
     115,   146,   170,   171,   173,   159,   159,   159,   159,   163,
     159,   159,   141,   171,   172,   146,   147,   147,   147,   147,
     147,   147,   139,   173,   141,   147,   158,   172,   147
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

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
        case 3:

/* Line 1455 of yacc.c  */
#line 366 "grammar.y"
    {
            if (timerv)
            {
              writeTime("used time:");
              startTimer();
            }
            if (rtimerv)
            {
              writeRTime("used real time:");
              startRTimer();
            }
            prompt_char = '>';
#ifdef HAVE_SDB
            if (sdb_flags & 2) { sdb_flags=1; YYERROR; }
#endif
            if(siCntrlc)
            {
              WerrorS("abort...");
              while((currentVoice!=NULL) && (currentVoice->prev!=NULL)) exitVoice();
              if (currentVoice!=NULL) currentVoice->ifsw=0;
            }
            if (errorreported) /* also catches abort... */
            {
              yyerror("");
            }
            if (inerror==2) PrintLn();
            errorreported = inerror = cmdtok = 0;
            lastreserved = currid = NULL;
            expected_parms = siCntrlc = FALSE;
          ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 401 "grammar.y"
    {currentVoice->ifsw=0;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 403 "grammar.y"
    { (yyvsp[(1) - (2)].lv).CleanUp(); currentVoice->ifsw=0;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 405 "grammar.y"
    {
            YYACCEPT;
          ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 409 "grammar.y"
    {
            currentVoice->ifsw=0;
            iiDebug();
          ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 414 "grammar.y"
    {currentVoice->ifsw=0;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 416 "grammar.y"
    {
            #ifdef SIQ
            siq=0;
            #endif
            yyInRingConstruction = FALSE;
            currentVoice->ifsw=0;
            if (inerror)
            {
/*  bison failed here*/
              if ((inerror!=3) && ((yyvsp[(1) - (2)].i)<UMINUS) && ((yyvsp[(1) - (2)].i)>' '))
              {
                // 1: yyerror called
                // 2: scanner put actual string
                // 3: error rule put token+\n
                inerror=3;
                Print(" error at token `%s`\n",iiTwoOps((yyvsp[(1) - (2)].i)));
              }
/**/

            }
            if (!errorreported) WerrorS("...parse error");
            yyerror("");
            yyerrok;
#ifdef HAVE_SDB
            if ((sdb_flags & 1) && currentVoice->pi!=NULL)
            {
              currentVoice->pi->trace_flag |=1;
            }
            else
#endif
            if (myynest>0)
            {
              feBufferTypes t=currentVoice->Typ();
              //PrintS("leaving yyparse\n");
              exitBuffer(BT_proc);
              if (t==BT_example)
                YYACCEPT;
              else
                YYABORT;
            }
            else if (currentVoice->prev!=NULL)
            {
              exitVoice();
            }
#ifdef HAVE_SDB
            if (sdb_flags &2) sdb_flags=1;
#endif
          ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 474 "grammar.y"
    {if (currentVoice!=NULL) currentVoice->ifsw=0;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 477 "grammar.y"
    { omFree((ADDRESS)(yyvsp[(2) - (2)].name)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 492 "grammar.y"
    {
            if(iiAssign(&(yyvsp[(1) - (2)].lv),&(yyvsp[(2) - (2)].lv))) YYERROR;
          ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 499 "grammar.y"
    {
            if (currRing==NULL) MYYERROR("no ring active");
            syMake(&(yyval.lv),omStrDup((yyvsp[(1) - (1)].name)));
          ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 504 "grammar.y"
    {
            syMake(&(yyval.lv),(yyvsp[(1) - (1)].name));
          ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 508 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv), &(yyvsp[(1) - (3)].lv), COLONCOLON, &(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 512 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv), &(yyvsp[(1) - (3)].lv), '.', &(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 516 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(1) - (3)].lv),'(')) YYERROR;
          ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 520 "grammar.y"
    {
            if ((yyvsp[(1) - (4)].lv).rtyp==UNKNOWN)
            { // for x(i)(j)
              if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (4)].lv),'(',&(yyvsp[(3) - (4)].lv))) YYERROR;
            }
            else
            {
              (yyvsp[(1) - (4)].lv).next=(leftv)omAllocBin(sleftv_bin);
              memcpy((yyvsp[(1) - (4)].lv).next,&(yyvsp[(3) - (4)].lv),sizeof(sleftv));
              if(iiExprArithM(&(yyval.lv),&(yyvsp[(1) - (4)].lv),'(')) YYERROR;
            }
          ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 533 "grammar.y"
    {
            if (currRingHdl==NULL) MYYERROR("no ring active");
            int j = 0;
            memset(&(yyval.lv),0,sizeof(sleftv));
            (yyval.lv).rtyp=VECTOR_CMD;
            leftv v = &(yyvsp[(2) - (3)].lv);
            while (v!=NULL)
            {
              int i,t;
              sleftv tmp;
              memset(&tmp,0,sizeof(tmp));
              i=iiTestConvert((t=v->Typ()),POLY_CMD);
              if((i==0) || (iiConvert(t /*v->Typ()*/,POLY_CMD,i,v,&tmp)))
              {
                pDelete((poly *)&(yyval.lv).data);
                (yyvsp[(2) - (3)].lv).CleanUp();
                MYYERROR("expected '[poly,...'");
              }
              poly p = (poly)tmp.CopyD(POLY_CMD);
              pSetCompP(p,++j);
              (yyval.lv).data = (void *)pAdd((poly)(yyval.lv).data,p);
              v->next=tmp.next;tmp.next=NULL;
              tmp.CleanUp();
              v=v->next;
            }
            (yyvsp[(2) - (3)].lv).CleanUp();
          ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 561 "grammar.y"
    {
            memset(&(yyval.lv),0,sizeof((yyval.lv)));
            int i = atoi((yyvsp[(1) - (1)].name));
            /*remember not to omFree($1)
            *because it is a part of the scanner buffer*/
            (yyval.lv).rtyp  = INT_CMD;
            (yyval.lv).data = (void *)(long)i;

            /* check: out of range input */
            int l = strlen((yyvsp[(1) - (1)].name))+2;
            number n;
            if (l >= MAX_INT_LEN)
            {
              char tmp[MAX_INT_LEN+5];
              sprintf(tmp,"%d",i);
              if (strcmp(tmp,(yyvsp[(1) - (1)].name))!=0)
              {
                n_Read((yyvsp[(1) - (1)].name),&n,coeffs_BIGINT);
                (yyval.lv).rtyp=BIGINT_CMD;
                (yyval.lv).data = n;
              }
            }
          ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 585 "grammar.y"
    {
            memset(&(yyval.lv),0,sizeof((yyval.lv)));
            (yyval.lv).rtyp = (yyvsp[(1) - (1)].i);
            (yyval.lv).data = (yyval.lv).Data();
          ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 591 "grammar.y"
    {
            memset(&(yyval.lv),0,sizeof((yyval.lv)));
            (yyval.lv).rtyp  = STRING_CMD;
            (yyval.lv).data = (yyvsp[(1) - (1)].name);
          ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 597 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 601 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 605 "grammar.y"
    {
            if(iiExprArithM(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 609 "grammar.y"
    {
            if(iiExprArithM(&(yyval.lv),NULL,(yyvsp[(1) - (3)].i))) YYERROR;
          ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 613 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 617 "grammar.y"
    {
            if(iiExprArithM(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 621 "grammar.y"
    {
            if(iiExprArithM(&(yyval.lv),NULL,(yyvsp[(1) - (3)].i))) YYERROR;
          ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 625 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 629 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 633 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 637 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 641 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(3) - (6)].lv),(yyvsp[(1) - (6)].i),&(yyvsp[(5) - (6)].lv),TRUE)) YYERROR;
          ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 645 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(3) - (6)].lv),(yyvsp[(1) - (6)].i),&(yyvsp[(5) - (6)].lv),TRUE)) YYERROR;
          ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 649 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(3) - (6)].lv),(yyvsp[(1) - (6)].i),&(yyvsp[(5) - (6)].lv),TRUE)) YYERROR;
          ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 653 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(3) - (6)].lv),(yyvsp[(1) - (6)].i),&(yyvsp[(5) - (6)].lv),TRUE)) YYERROR;
          ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 657 "grammar.y"
    {
            if(iiExprArith3(&(yyval.lv),(yyvsp[(1) - (8)].i),&(yyvsp[(3) - (8)].lv),&(yyvsp[(5) - (8)].lv),&(yyvsp[(7) - (8)].lv))) YYERROR;
          ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 661 "grammar.y"
    {
            if(iiExprArith3(&(yyval.lv),(yyvsp[(1) - (8)].i),&(yyvsp[(3) - (8)].lv),&(yyvsp[(5) - (8)].lv),&(yyvsp[(7) - (8)].lv))) YYERROR;
          ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 665 "grammar.y"
    {
            if(iiExprArith3(&(yyval.lv),(yyvsp[(1) - (8)].i),&(yyvsp[(3) - (8)].lv),&(yyvsp[(5) - (8)].lv),&(yyvsp[(7) - (8)].lv))) YYERROR;
          ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 669 "grammar.y"
    {
            if(iiExprArith3(&(yyval.lv),(yyvsp[(1) - (8)].i),&(yyvsp[(3) - (8)].lv),&(yyvsp[(5) - (8)].lv),&(yyvsp[(7) - (8)].lv))) YYERROR;
          ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 673 "grammar.y"
    {
            if(iiExprArithM(&(yyval.lv),NULL,(yyvsp[(1) - (3)].i))) YYERROR;
          ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 677 "grammar.y"
    {
            int b=iiExprArithM(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i)); // handle branchTo
            if (b==TRUE) YYERROR;
            if (b==2) YYACCEPT;
          ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 683 "grammar.y"
    {
            if(iiExprArith3(&(yyval.lv),(yyvsp[(1) - (8)].i),&(yyvsp[(3) - (8)].lv),&(yyvsp[(5) - (8)].lv),&(yyvsp[(7) - (8)].lv))) YYERROR;
          ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 687 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(3) - (4)].lv),(yyvsp[(1) - (4)].i))) YYERROR;
          ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 691 "grammar.y"
    {
            if(iiExprArith3(&(yyval.lv),RING_CMD,&(yyvsp[(3) - (8)].lv),&(yyvsp[(5) - (8)].lv),&(yyvsp[(7) - (8)].lv))) YYERROR;
          ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 695 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(3) - (4)].lv),RING_CMD)) YYERROR;
          ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 699 "grammar.y"
    {
            if (iiARROW(&(yyval.lv),(yyvsp[(1) - (3)].name),(yyvsp[(3) - (3)].name))) YYERROR;
          ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 706 "grammar.y"
    {
            leftv v = &(yyvsp[(1) - (3)].lv);
            while (v->next!=NULL)
            {
              v=v->next;
            }
            v->next = (leftv)omAllocBin(sleftv_bin);
            memcpy(v->next,&((yyvsp[(3) - (3)].lv)),sizeof(sleftv));
            (yyval.lv) = (yyvsp[(1) - (3)].lv);
          ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 717 "grammar.y"
    {
            (yyval.lv) = (yyvsp[(1) - (1)].lv);
          ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 723 "grammar.y"
    {
            /*if ($1.typ == eunknown) YYERROR;*/
            (yyval.lv) = (yyvsp[(1) - (1)].lv);
          ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 727 "grammar.y"
    { (yyval.lv) = (yyvsp[(1) - (1)].lv); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 728 "grammar.y"
    { (yyval.lv) = (yyvsp[(2) - (3)].lv); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 730 "grammar.y"
    {
            if(iiExprArith3(&(yyval.lv),'[',&(yyvsp[(1) - (6)].lv),&(yyvsp[(3) - (6)].lv),&(yyvsp[(5) - (6)].lv))) YYERROR;
          ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 734 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (4)].lv),'[',&(yyvsp[(3) - (4)].lv))) YYERROR;
          ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 738 "grammar.y"
    {
            if (iiApply(&(yyval.lv), &(yyvsp[(3) - (6)].lv), (yyvsp[(5) - (6)].i), NULL)) YYERROR;
          ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 742 "grammar.y"
    {
            if (iiApply(&(yyval.lv), &(yyvsp[(3) - (6)].lv), (yyvsp[(5) - (6)].i), NULL)) YYERROR;
          ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 746 "grammar.y"
    {
            if (iiApply(&(yyval.lv), &(yyvsp[(3) - (6)].lv), (yyvsp[(5) - (6)].i), NULL)) YYERROR;
          ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 750 "grammar.y"
    {
            if (iiApply(&(yyval.lv), &(yyvsp[(3) - (6)].lv), (yyvsp[(5) - (6)].i), NULL)) YYERROR;
          ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 754 "grammar.y"
    {
            if (iiApply(&(yyval.lv), &(yyvsp[(3) - (6)].lv), (yyvsp[(5) - (6)].i), NULL)) YYERROR;
          ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 758 "grammar.y"
    {
            if (iiApply(&(yyval.lv), &(yyvsp[(3) - (6)].lv), 0, &(yyvsp[(5) - (6)].lv))) YYERROR;
          ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 762 "grammar.y"
    {
            (yyval.lv)=(yyvsp[(2) - (3)].lv);
          ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 766 "grammar.y"
    {
            #ifdef SIQ
            siq++;
            if (siq>0)
            { if (iiExprArith2(&(yyval.lv),&(yyvsp[(2) - (5)].lv),'=',&(yyvsp[(4) - (5)].lv))) YYERROR; }
            else
            #endif
            {
              memset(&(yyval.lv),0,sizeof((yyval.lv)));
              (yyval.lv).rtyp=NONE;
              if (iiAssign(&(yyvsp[(2) - (5)].lv),&(yyvsp[(4) - (5)].lv))) YYERROR;
            }
            #ifdef SIQ
            siq--;
            #endif
          ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 783 "grammar.y"
    {
            iiTestAssume(&(yyvsp[(2) - (5)].lv),&(yyvsp[(4) - (5)].lv));
            memset(&(yyval.lv),0,sizeof((yyval.lv)));
            (yyval.lv).rtyp=NONE;
          ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 789 "grammar.y"
    {            
            jjTestMAssume(&(yyvsp[(2) - (7)].lv),&(yyvsp[(4) - (7)].lv),&(yyvsp[(6) - (7)].lv));
            memset(&(yyval.lv),0,sizeof((yyval.lv)));
            (yyval.lv).rtyp=NONE;
          ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 796 "grammar.y"
    {
            #ifdef SIQ
            siq--;
            #endif
          ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 802 "grammar.y"
    {
            #ifdef SIQ
            if (siq<=0) (yyvsp[(4) - (5)].lv).Eval();
            #endif
            (yyval.lv)=(yyvsp[(4) - (5)].lv);
            #ifdef SIQ
            siq++;
            #endif
          ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 814 "grammar.y"
    {
            #ifdef SIQ
            siq++;
            #endif
          ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 822 "grammar.y"
    {
            #ifdef SIQ
            siq++;
            #endif
          ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 830 "grammar.y"
    {
            #ifdef SIQ
            siq--;
            #endif
          ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 839 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(1) - (2)].lv),PLUSPLUS)) YYERROR;
          ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 843 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(1) - (2)].lv),MINUSMINUS)) YYERROR;
          ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 847 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),'+',&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 851 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),'-',&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 855 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),(yyvsp[(2) - (3)].i),&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 859 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),'^',&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 863 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),(yyvsp[(2) - (3)].i),&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 867 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),(yyvsp[(2) - (3)].i),&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 871 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),NOTEQUAL,&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 875 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),EQUAL_EQUAL,&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 879 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),DOTDOT,&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 883 "grammar.y"
    {
            if(iiExprArith2(&(yyval.lv),&(yyvsp[(1) - (3)].lv),':',&(yyvsp[(3) - (3)].lv))) YYERROR;
          ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 887 "grammar.y"
    {
            if (siq>0)
            { if (iiExprArith1(&(yyval.lv),&(yyvsp[(2) - (2)].lv),NOT)) YYERROR; }
            else
            {
              memset(&(yyval.lv),0,sizeof((yyval.lv)));
              int i; TESTSETINT((yyvsp[(2) - (2)].lv),i);
              (yyval.lv).rtyp  = INT_CMD;
              (yyval.lv).data = (void *)(long)(i == 0 ? 1 : 0);
            }
          ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 899 "grammar.y"
    {
            if(iiExprArith1(&(yyval.lv),&(yyvsp[(2) - (2)].lv),'-')) YYERROR;
          ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 905 "grammar.y"
    { (yyval.lv) = (yyvsp[(1) - (2)].lv); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 907 "grammar.y"
    {
            if ((yyvsp[(1) - (2)].lv).rtyp==0)
            {
              Werror("`%s` is undefined",(yyvsp[(1) - (2)].lv).Fullname());
              YYERROR;
            }
            else if (((yyvsp[(1) - (2)].lv).rtyp==MODUL_CMD)
            // matrix m; m[2]=...
            && ((yyvsp[(1) - (2)].lv).e!=NULL) && ((yyvsp[(1) - (2)].lv).e->next==NULL))
            {
              MYYERROR("matrix must have 2 indices");
            }
            (yyval.lv) = (yyvsp[(1) - (2)].lv);
          ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 927 "grammar.y"
    {
            if ((yyvsp[(2) - (3)].lv).Typ()!=STRING_CMD)
            {
              MYYERROR("string expression expected");
            }
            (yyval.name) = (char *)(yyvsp[(2) - (3)].lv).CopyD(STRING_CMD);
            (yyvsp[(2) - (3)].lv).CleanUp();
          ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 939 "grammar.y"
    {
            if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (2)].lv),myynest,(yyvsp[(1) - (2)].i),&((yyvsp[(2) - (2)].lv).req_packhdl->idroot)))
              YYERROR;
          ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 944 "grammar.y"
    {
            if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (2)].lv),myynest,(yyvsp[(1) - (2)].i),&((yyvsp[(2) - (2)].lv).req_packhdl->idroot)))
              YYERROR;
          ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 949 "grammar.y"
    {
            if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (2)].lv),myynest,(yyvsp[(1) - (2)].i),&(currRing->idroot), TRUE)) YYERROR;
          ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 953 "grammar.y"
    {
            if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (2)].lv),myynest,(yyvsp[(1) - (2)].i),&(currRing->idroot), TRUE)) YYERROR;
          ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 957 "grammar.y"
    {
            int r; TESTSETINT((yyvsp[(4) - (8)].lv),r);
            int c; TESTSETINT((yyvsp[(7) - (8)].lv),c);
            if (r < 1)
              MYYERROR("rows must be greater than 0");
            if (c < 0)
              MYYERROR("cols must be greater than -1");
            leftv v;
            idhdl h;
            if ((yyvsp[(1) - (8)].i) == MATRIX_CMD)
            {
              if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (8)].lv),myynest,(yyvsp[(1) - (8)].i),&(currRing->idroot), TRUE)) YYERROR;
              v=&(yyval.lv);
              h=(idhdl)v->data;
              idDelete(&IDIDEAL(h));
              IDMATRIX(h) = mpNew(r,c);
              if (IDMATRIX(h)==NULL) YYERROR;
            }
            else if ((yyvsp[(1) - (8)].i) == INTMAT_CMD)
            {
              if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (8)].lv),myynest,(yyvsp[(1) - (8)].i),&((yyvsp[(2) - (8)].lv).req_packhdl->idroot)))
                YYERROR;
              v=&(yyval.lv);
              h=(idhdl)v->data;
              delete IDINTVEC(h);
              IDINTVEC(h) = new intvec(r,c,0);
              if (IDINTVEC(h)==NULL) YYERROR;
            }
            else /* BIGINTMAT_CMD */
            {
              if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (8)].lv),myynest,(yyvsp[(1) - (8)].i),&((yyvsp[(2) - (8)].lv).req_packhdl->idroot)))
                YYERROR;
              v=&(yyval.lv);
              h=(idhdl)v->data;
              delete IDBIMAT(h);
              IDBIMAT(h) = new bigintmat(r, c, coeffs_BIGINT);
              if (IDBIMAT(h)==NULL) YYERROR;
            }
          ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 997 "grammar.y"
    {
            if ((yyvsp[(1) - (2)].i) == MATRIX_CMD)
            {
              if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (2)].lv),myynest,(yyvsp[(1) - (2)].i),&(currRing->idroot), TRUE)) YYERROR;
            }
            else if ((yyvsp[(1) - (2)].i) == INTMAT_CMD)
            {
              if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (2)].lv),myynest,(yyvsp[(1) - (2)].i),&((yyvsp[(2) - (2)].lv).req_packhdl->idroot)))
                YYERROR;
              leftv v=&(yyval.lv);
              idhdl h;
              do
              {
                 h=(idhdl)v->data;
                 delete IDINTVEC(h);
                 IDINTVEC(h) = new intvec(1,1,0);
                 v=v->next;
              } while (v!=NULL);
            }
            else /* BIGINTMAT_CMD */
            {
              if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (2)].lv),myynest,(yyvsp[(1) - (2)].i),&((yyvsp[(2) - (2)].lv).req_packhdl->idroot)))
                YYERROR;
            }
          ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1023 "grammar.y"
    {
            int t=(yyvsp[(1) - (3)].lv).Typ();
            sleftv r;
            memset(&r,0,sizeof(sleftv));
            if ((BEGIN_RING<t) && (t<END_RING))
            {
              if (iiDeclCommand(&r,&(yyvsp[(3) - (3)].lv),myynest,t,&(currRing->idroot), TRUE))
                YYERROR;
            }
            else
            {
              if (iiDeclCommand(&r,&(yyvsp[(3) - (3)].lv),myynest,t,&((yyvsp[(3) - (3)].lv).req_packhdl->idroot)))
                YYERROR;
            }
            leftv v=&(yyvsp[(1) - (3)].lv);
            while (v->next!=NULL) v=v->next;
            v->next=(leftv)omAllocBin(sleftv_bin);
            memcpy(v->next,&r,sizeof(sleftv));
            (yyval.lv)=(yyvsp[(1) - (3)].lv);
          ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1044 "grammar.y"
    {
            if (iiDeclCommand(&(yyval.lv),&(yyvsp[(2) - (2)].lv),myynest,(yyvsp[(1) - (2)].i),&((yyvsp[(2) - (2)].lv).req_packhdl->idroot)))
              YYERROR;
          ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1057 "grammar.y"
    {
            leftv v = &(yyvsp[(2) - (5)].lv);
            while (v->next!=NULL)
            {
              v=v->next;
            }
            v->next = (leftv)omAllocBin(sleftv_bin);
            memcpy(v->next,&((yyvsp[(4) - (5)].lv)),sizeof(sleftv));
            (yyval.lv) = (yyvsp[(2) - (5)].lv);
          ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1071 "grammar.y"
    {
          // let rInit take care of any errors
          (yyval.i)=rOrderName((yyvsp[(1) - (1)].name));
        ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1079 "grammar.y"
    {
            memset(&(yyval.lv),0,sizeof((yyval.lv)));
            intvec *iv = new intvec(2);
            (*iv)[0] = 1;
            (*iv)[1] = (yyvsp[(1) - (1)].i);
            (yyval.lv).rtyp = INTVEC_CMD;
            (yyval.lv).data = (void *)iv;
          ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1088 "grammar.y"
    {
            memset(&(yyval.lv),0,sizeof((yyval.lv)));
            leftv sl = &(yyvsp[(3) - (4)].lv);
            int slLength;
            {
              slLength =  exprlist_length(sl);
              int l = 2 +  slLength;
              intvec *iv = new intvec(l);
              (*iv)[0] = slLength;
              (*iv)[1] = (yyvsp[(1) - (4)].i);

              int i = 2;
              while ((i<l) && (sl!=NULL))
              {
                if (sl->Typ() == INT_CMD)
                {
                  (*iv)[i++] = (int)((long)(sl->Data()));
                }
                else if ((sl->Typ() == INTVEC_CMD)
                ||(sl->Typ() == INTMAT_CMD))
                {
                  intvec *ivv = (intvec *)(sl->Data());
                  int ll = 0,l = ivv->length();
                  for (; l>0; l--)
                  {
                    (*iv)[i++] = (*ivv)[ll++];
                  }
                }
                else
                {
                  delete iv;
                  (yyvsp[(3) - (4)].lv).CleanUp();
                  MYYERROR("wrong type in ordering");
                }
                sl = sl->next;
              }
              (yyval.lv).rtyp = INTVEC_CMD;
              (yyval.lv).data = (void *)iv;
            }
            (yyvsp[(3) - (4)].lv).CleanUp();
          ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1134 "grammar.y"
    {
            (yyval.lv) = (yyvsp[(1) - (3)].lv);
            (yyval.lv).next = (sleftv *)omAllocBin(sleftv_bin);
            memcpy((yyval.lv).next,&(yyvsp[(3) - (3)].lv),sizeof(sleftv));
          ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1144 "grammar.y"
    {
            (yyval.lv) = (yyvsp[(2) - (3)].lv);
          ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1150 "grammar.y"
    {
            expected_parms = TRUE;
          ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1157 "grammar.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1159 "grammar.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1161 "grammar.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1170 "grammar.y"
    { if ((yyvsp[(1) - (2)].i) != '<') YYERROR;
            if((feFilePending=feFopen((yyvsp[(2) - (2)].name),"r",NULL,TRUE))==NULL) YYERROR; ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1173 "grammar.y"
    { newFile((yyvsp[(2) - (4)].name),feFilePending); ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1178 "grammar.y"
    {
            feHelp((yyvsp[(2) - (3)].name));
            omFree((ADDRESS)(yyvsp[(2) - (3)].name));
          ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1183 "grammar.y"
    {
            feHelp(NULL);
          ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1190 "grammar.y"
    {
            singular_example((yyvsp[(2) - (3)].name));
            omFree((ADDRESS)(yyvsp[(2) - (3)].name));
          ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1198 "grammar.y"
    {
          if (basePack!=(yyvsp[(2) - (2)].lv).req_packhdl)
          {
            if(iiExport(&(yyvsp[(2) - (2)].lv),0,currPack)) YYERROR;
          }
          else
            if (iiExport(&(yyvsp[(2) - (2)].lv),0)) YYERROR;
        ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1210 "grammar.y"
    {
          leftv v=&(yyvsp[(2) - (2)].lv);
          if (v->rtyp!=IDHDL)
          {
            if (v->name!=NULL)
            {
               Werror("`%s` is undefined in kill",v->name);
            }
            else               WerrorS("kill what ?");
          }
          else
          {
            killhdl((idhdl)v->data,v->req_packhdl);
          }
        ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1226 "grammar.y"
    {
          leftv v=&(yyvsp[(3) - (3)].lv);
          if (v->rtyp!=IDHDL)
          {
            if (v->name!=NULL)
            {
               Werror("`%s` is undefined in kill",v->name);
            }
            else               WerrorS("kill what ?");
          }
          else
          {
            killhdl((idhdl)v->data,v->req_packhdl);
          }
        ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1245 "grammar.y"
    {
            list_cmd((yyvsp[(3) - (4)].i),NULL,"// ",TRUE);
          ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1249 "grammar.y"
    {
            list_cmd((yyvsp[(3) - (4)].i),NULL,"// ",TRUE);
          ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1253 "grammar.y"
    {
            if ((yyvsp[(3) - (4)].i)==QRING_CMD) (yyvsp[(3) - (4)].i)=RING_CMD;
            list_cmd((yyvsp[(3) - (4)].i),NULL,"// ",TRUE);
          ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1258 "grammar.y"
    {
            list_cmd((yyvsp[(3) - (4)].i),NULL,"// ",TRUE);
          ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1262 "grammar.y"
    {
            list_cmd(RING_CMD,NULL,"// ",TRUE);
          ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1266 "grammar.y"
    {
            list_cmd((yyvsp[(3) - (4)].i),NULL,"// ",TRUE);
           ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1270 "grammar.y"
    {
            list_cmd(PROC_CMD,NULL,"// ",TRUE);
          ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1274 "grammar.y"
    {
            list_cmd(0,(yyvsp[(3) - (4)].lv).Fullname(),"// ",TRUE);
            (yyvsp[(3) - (4)].lv).CleanUp();
          ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1279 "grammar.y"
    {
            if((yyvsp[(3) - (6)].lv).Typ() == PACKAGE_CMD)
              list_cmd((yyvsp[(5) - (6)].i),NULL,"// ",TRUE);
            (yyvsp[(3) - (6)].lv).CleanUp();
          ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1285 "grammar.y"
    {
            if((yyvsp[(3) - (6)].lv).Typ() == PACKAGE_CMD)
              list_cmd((yyvsp[(5) - (6)].i),NULL,"// ",TRUE);
            (yyvsp[(3) - (6)].lv).CleanUp();
          ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1291 "grammar.y"
    {
            if((yyvsp[(3) - (6)].lv).Typ() == PACKAGE_CMD)
              list_cmd((yyvsp[(5) - (6)].i),NULL,"// ",TRUE);
            (yyvsp[(3) - (6)].lv).CleanUp();
          ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1297 "grammar.y"
    {
            if((yyvsp[(3) - (6)].lv).Typ() == PACKAGE_CMD)
              list_cmd((yyvsp[(5) - (6)].i),NULL,"// ",TRUE);
            (yyvsp[(3) - (6)].lv).CleanUp();
          ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1303 "grammar.y"
    {
            if((yyvsp[(3) - (6)].lv).Typ() == PACKAGE_CMD)
              list_cmd((yyvsp[(5) - (6)].i),NULL,"// ",TRUE);
            (yyvsp[(3) - (6)].lv).CleanUp();
          ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1309 "grammar.y"
    {
            if((yyvsp[(3) - (6)].lv).Typ() == PACKAGE_CMD)
              list_cmd((yyvsp[(5) - (6)].i),NULL,"// ",TRUE);
            (yyvsp[(3) - (6)].lv).CleanUp();
          ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1315 "grammar.y"
    {
            if((yyvsp[(3) - (6)].lv).Typ() == PACKAGE_CMD)
              list_cmd((yyvsp[(5) - (6)].i),NULL,"// ",TRUE);
            (yyvsp[(3) - (6)].lv).CleanUp();
          ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1327 "grammar.y"
    {
            list_cmd(-1,NULL,"// ",TRUE);
          ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1333 "grammar.y"
    { yyInRingConstruction = TRUE; ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1342 "grammar.y"
    {
            const char *ring_name = (yyvsp[(2) - (8)].lv).name;
            ring b=
            rInit(&(yyvsp[(4) - (8)].lv),            /* characteristik and list of parameters*/
                  &(yyvsp[(6) - (8)].lv),            /* names of ringvariables */
                  &(yyvsp[(8) - (8)].lv));            /* ordering */
            idhdl newRingHdl=NULL;

            if (b!=NULL)
            {
              newRingHdl=enterid(ring_name, myynest, RING_CMD,
                                   &((yyvsp[(2) - (8)].lv).req_packhdl->idroot),FALSE);
              (yyvsp[(2) - (8)].lv).CleanUp();
              if (newRingHdl!=NULL)
              {
                IDRING(newRingHdl)=b;
              }
              else
              {
                rKill(b);
              }
            }
            yyInRingConstruction = FALSE;
            if (newRingHdl==NULL)
            {
              MYYERROR("cannot make ring");
            }
            else
            {
              rSetHdl(newRingHdl);
            }
          ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1375 "grammar.y"
    {
            const char *ring_name = (yyvsp[(2) - (2)].lv).name;
            if (!inerror) rDefault(ring_name);
            yyInRingConstruction = FALSE;
            (yyvsp[(2) - (2)].lv).CleanUp();
          ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1382 "grammar.y"
    {
            yyInRingConstruction = FALSE;
            if (iiAssignCR(&(yyvsp[(2) - (4)].lv),&(yyvsp[(4) - (4)].lv))) YYERROR;
          ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1390 "grammar.y"
    {
            if (((yyvsp[(1) - (2)].i)!=LIB_CMD)||(jjLOAD((yyvsp[(2) - (2)].name),TRUE))) YYERROR;
          ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1399 "grammar.y"
    {
            if (((yyvsp[(1) - (2)].i)==KEEPRING_CMD) && (myynest==0))
               MYYERROR("only inside a proc allowed");
            const char * n=(yyvsp[(2) - (2)].lv).Name();
            if ((((yyvsp[(2) - (2)].lv).Typ()==RING_CMD)||((yyvsp[(2) - (2)].lv).Typ()==QRING_CMD))
            && ((yyvsp[(2) - (2)].lv).rtyp==IDHDL))
            {
              idhdl h=(idhdl)(yyvsp[(2) - (2)].lv).data;
              if ((yyvsp[(2) - (2)].lv).e!=NULL) h=rFindHdl((ring)(yyvsp[(2) - (2)].lv).Data(),NULL);
              //Print("setring %s lev %d (ptr:%x)\n",IDID(h),IDLEV(h),IDRING(h));
              if ((yyvsp[(1) - (2)].i)==KEEPRING_CMD)
              {
                if (h!=NULL)
                {
                  if (IDLEV(h)!=0)
                  {
                    if (iiExport(&(yyvsp[(2) - (2)].lv),myynest-1)) YYERROR;
#if 1
                    idhdl p=IDRING(h)->idroot;
                    idhdl root=p;
                    int prevlev=myynest-1;
                    while (p!=NULL)
                    {
                      if (IDLEV(p)==myynest)
                      {
                        idhdl old=root->get(IDID(p),prevlev);
                        if (old!=NULL)
                        {
                          if (BVERBOSE(V_REDEFINE))
                            Warn("redefining %s",IDID(p));
                          killhdl2(old,&root,IDRING(h));
                          IDRING(h)->idroot=root;
                        }
                        IDLEV(p)=prevlev;
                      }
                      p=IDNEXT(p);
                    }
#endif
                  }
#ifdef USE_IILOCALRING
                  iiLocalRing[myynest-1]=IDRING(h);
#endif
                  procstack->cRing=IDRING(h);
                  procstack->cRingHdl=h;
                }
                else
                {
                  Werror("%s is no identifier",n);
                  (yyvsp[(2) - (2)].lv).CleanUp();
                  YYERROR;
                }
              }
              if (h!=NULL) rSetHdl(h);
              else
              {
                Werror("cannot find the name of the basering %s",n);
                (yyvsp[(2) - (2)].lv).CleanUp();
                YYERROR;
              }
              (yyvsp[(2) - (2)].lv).CleanUp();
            }
            else
            {
              Werror("%s is no name of a ring/qring",n);
              (yyvsp[(2) - (2)].lv).CleanUp();
              YYERROR;
            }
          ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1471 "grammar.y"
    {
            type_cmd(&((yyvsp[(2) - (2)].lv)));
          ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1475 "grammar.y"
    {
            //Print("typ is %d, rtyp:%d\n",$1.Typ(),$1.rtyp);
            #ifdef SIQ
            if ((yyvsp[(1) - (1)].lv).rtyp!=COMMAND)
            {
            #endif
              if ((yyvsp[(1) - (1)].lv).Typ()==UNKNOWN)
              {
                if ((yyvsp[(1) - (1)].lv).name!=NULL)
                {
                  Werror("`%s` is undefined",(yyvsp[(1) - (1)].lv).name);
                  omFree((ADDRESS)(yyvsp[(1) - (1)].lv).name);
                }
                YYERROR;
              }
            #ifdef SIQ
            }
            #endif
            (yyvsp[(1) - (1)].lv).Print(&sLastPrinted);
            (yyvsp[(1) - (1)].lv).CleanUp(currRing);
            if (errorreported) YYERROR;
          ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1504 "grammar.y"
    {
            int i; TESTSETINT((yyvsp[(3) - (5)].lv),i);
            if (i!=0)
            {
              newBuffer( (yyvsp[(5) - (5)].name), BT_if);
            }
            else
            {
              omFree((ADDRESS)(yyvsp[(5) - (5)].name));
              currentVoice->ifsw=1;
            }
          ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1517 "grammar.y"
    {
            if (currentVoice->ifsw==1)
            {
              currentVoice->ifsw=0;
              newBuffer( (yyvsp[(2) - (2)].name), BT_else);
            }
            else
            {
              if (currentVoice->ifsw!=2)
              {
                Warn("`else` without `if` in level %d",myynest);
              }
              omFree((ADDRESS)(yyvsp[(2) - (2)].name));
            }
            currentVoice->ifsw=0;
          ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1534 "grammar.y"
    {
            int i; TESTSETINT((yyvsp[(3) - (5)].lv),i);
            if (i)
            {
              if (exitBuffer(BT_break)) YYERROR;
            }
            currentVoice->ifsw=0;
          ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1543 "grammar.y"
    {
            if (exitBuffer(BT_break)) YYERROR;
            currentVoice->ifsw=0;
          ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1548 "grammar.y"
    {
            if (contBuffer(BT_break)) YYERROR;
            currentVoice->ifsw=0;
          ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1556 "grammar.y"
    {
            /* -> if(!$2) break; $3; continue;*/
            char * s = (char *)omAlloc( strlen((yyvsp[(2) - (3)].name)) + strlen((yyvsp[(3) - (3)].name)) + 36);
            sprintf(s,"whileif (!(%s)) break;\n%scontinue;\n " ,(yyvsp[(2) - (3)].name),(yyvsp[(3) - (3)].name));
            newBuffer(s,BT_break);
            omFree((ADDRESS)(yyvsp[(2) - (3)].name));
            omFree((ADDRESS)(yyvsp[(3) - (3)].name));
          ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1568 "grammar.y"
    {
            /* $2 */
            /* if (!$3) break; $5; $4; continue; */
            char * s = (char *)omAlloc( strlen((yyvsp[(3) - (5)].name))+strlen((yyvsp[(4) - (5)].name))+strlen((yyvsp[(5) - (5)].name))+36);
            sprintf(s,"forif (!(%s)) break;\n%s%s;\ncontinue;\n "
                   ,(yyvsp[(3) - (5)].name),(yyvsp[(5) - (5)].name),(yyvsp[(4) - (5)].name));
            omFree((ADDRESS)(yyvsp[(3) - (5)].name));
            omFree((ADDRESS)(yyvsp[(4) - (5)].name));
            omFree((ADDRESS)(yyvsp[(5) - (5)].name));
            newBuffer(s,BT_break);
            s = (char *)omAlloc( strlen((yyvsp[(2) - (5)].name)) + 3);
            sprintf(s,"%s;\n",(yyvsp[(2) - (5)].name));
            omFree((ADDRESS)(yyvsp[(2) - (5)].name));
            newBuffer(s,BT_if);
          ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1587 "grammar.y"
    {
            idhdl h = enterid((yyvsp[(2) - (3)].name),myynest,PROC_CMD,&IDROOT,TRUE);
            if (h==NULL) {omFree((ADDRESS)(yyvsp[(2) - (3)].name));omFree((ADDRESS)(yyvsp[(3) - (3)].name)); YYERROR;}
            iiInitSingularProcinfo(IDPROC(h),"", (yyvsp[(2) - (3)].name), 0, 0);
            IDPROC(h)->data.s.body = (char *)omAlloc(strlen((yyvsp[(3) - (3)].name))+31);;
            sprintf(IDPROC(h)->data.s.body,"parameter list #;\n%s;return();\n\n",(yyvsp[(3) - (3)].name));
            omFree((ADDRESS)(yyvsp[(3) - (3)].name));
            omFree((ADDRESS)(yyvsp[(2) - (3)].name));
          ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1597 "grammar.y"
    {
            idhdl h = enterid((yyvsp[(1) - (3)].name),myynest,PROC_CMD,&IDROOT,TRUE);
            if (h==NULL)
            {
              omFree((ADDRESS)(yyvsp[(1) - (3)].name));
              omFree((ADDRESS)(yyvsp[(2) - (3)].name));
              omFree((ADDRESS)(yyvsp[(3) - (3)].name));
              YYERROR;
            }
            char *args=iiProcArgs((yyvsp[(2) - (3)].name),FALSE);
            omFree((ADDRESS)(yyvsp[(2) - (3)].name));
            iiInitSingularProcinfo(IDPROC(h),"", (yyvsp[(1) - (3)].name), 0, 0);
            IDPROC(h)->data.s.body = (char *)omAlloc(strlen((yyvsp[(3) - (3)].name))+strlen(args)+14);;
            sprintf(IDPROC(h)->data.s.body,"%s\n%s;return();\n\n",args,(yyvsp[(3) - (3)].name));
            omFree((ADDRESS)args);
            omFree((ADDRESS)(yyvsp[(3) - (3)].name));
            omFree((ADDRESS)(yyvsp[(1) - (3)].name));
          ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1616 "grammar.y"
    {
            omFree((ADDRESS)(yyvsp[(3) - (4)].name));
            idhdl h = enterid((yyvsp[(1) - (4)].name),myynest,PROC_CMD,&IDROOT,TRUE);
            if (h==NULL)
            {
              omFree((ADDRESS)(yyvsp[(1) - (4)].name));
              omFree((ADDRESS)(yyvsp[(2) - (4)].name));
              omFree((ADDRESS)(yyvsp[(4) - (4)].name));
              YYERROR;
            }
            char *args=iiProcArgs((yyvsp[(2) - (4)].name),FALSE);
            omFree((ADDRESS)(yyvsp[(2) - (4)].name));
            iiInitSingularProcinfo(IDPROC(h),"", (yyvsp[(1) - (4)].name), 0, 0);
            omFree((ADDRESS)(yyvsp[(1) - (4)].name));
            IDPROC(h)->data.s.body = (char *)omAlloc(strlen((yyvsp[(4) - (4)].name))+strlen(args)+14);;
            sprintf(IDPROC(h)->data.s.body,"%s\n%s;return();\n\n",args,(yyvsp[(4) - (4)].name));
            omFree((ADDRESS)args);
            omFree((ADDRESS)(yyvsp[(4) - (4)].name));
          ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1639 "grammar.y"
    {
            // decl. of type proc p(int i)
            if ((yyvsp[(1) - (2)].i)==PARAMETER)  { if (iiParameter(&(yyvsp[(2) - (2)].lv))) YYERROR; }
            else                { if (iiAlias(&(yyvsp[(2) - (2)].lv))) YYERROR; }
          ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1645 "grammar.y"
    {
            // decl. of type proc p(i)
            sleftv tmp_expr;
            if ((yyvsp[(1) - (2)].i)==ALIAS_CMD) MYYERROR("alias requires a type");
            if ((iiDeclCommand(&tmp_expr,&(yyvsp[(2) - (2)].lv),myynest,DEF_CMD,&IDROOT))
            || (iiParameter(&tmp_expr)))
              YYERROR;
          ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1657 "grammar.y"
    {
            iiRETURNEXPR.Copy(&(yyvsp[(3) - (4)].lv));
            (yyvsp[(3) - (4)].lv).CleanUp();
            if (exitBuffer(BT_proc)) YYERROR;
          ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1663 "grammar.y"
    {
            if ((yyvsp[(1) - (3)].i)==RETURN)
            {
              iiRETURNEXPR.Init();
              iiRETURNEXPR.rtyp=NONE;
              if (exitBuffer(BT_proc)) YYERROR;
            }
          ;}
    break;



/* Line 1455 of yacc.c  */
#line 4339 "grammar.cc"
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



