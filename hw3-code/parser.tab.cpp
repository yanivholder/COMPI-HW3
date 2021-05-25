/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.ypp"

    #include "hw3-output.hpp"
    #include "sym_tables.hpp"
    #include "structs.hpp"

	using namespace output;

    typedef enum ops {
        PASSIGN,
        PRELOP,
        PAND,
        POR,
        PNOT,
        PBINOP,
    } ops;

	extern int yylineno;
	int yyerror(const char * message);
    extern int yylex();
    extern char* yytext;

    Exp* do_op(Exp* var1, Exp* var2, ops op);
    void vaildate_type(string x, string y);
    FuncSymbol* get_func(string name, std::vector<string> type_list);
    void validate_func(std::vector<string> expected, std::vector<string> current, string name);
    void validate_assign(string var1, string var2);
    string get_var_type(string var_name);

    SymbolTable symbolTable = SymbolTable();
    string curr_func_ret_type("");
    int during_while = 0;
    int during_switch = 0;




#line 108 "parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_BYTE = 5,                       /* BYTE  */
  YYSYMBOL_B = 6,                          /* B  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_FALSE = 9,                      /* FALSE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 14,                  /* CONTINUE  */
  YYSYMBOL_SWITCH = 15,                    /* SWITCH  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_COLON = 18,                     /* COLON  */
  YYSYMBOL_SC = 19,                        /* SC  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_LBRACE = 21,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_ID = 23,                        /* ID  */
  YYSYMBOL_NUM = 24,                       /* NUM  */
  YYSYMBOL_STRING = 25,                    /* STRING  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_RELOP_EQ = 29,                  /* RELOP_EQ  */
  YYSYMBOL_RELOP_REL = 30,                 /* RELOP_REL  */
  YYSYMBOL_BINOP_ADD = 31,                 /* BINOP_ADD  */
  YYSYMBOL_BINOP_MUL = 32,                 /* BINOP_MUL  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_RPAREN = 34,                    /* RPAREN  */
  YYSYMBOL_LPAREN = 35,                    /* LPAREN  */
  YYSYMBOL_ELSE = 36,                      /* ELSE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_Program = 38,                   /* Program  */
  YYSYMBOL_Funcs = 39,                     /* Funcs  */
  YYSYMBOL_FuncDecl = 40,                  /* FuncDecl  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_42_2 = 42,                      /* $@2  */
  YYSYMBOL_RetType = 43,                   /* RetType  */
  YYSYMBOL_Formals = 44,                   /* Formals  */
  YYSYMBOL_FormalsList = 45,               /* FormalsList  */
  YYSYMBOL_FormalDecl = 46,                /* FormalDecl  */
  YYSYMBOL_Statements = 47,                /* Statements  */
  YYSYMBOL_Statement = 48,                 /* Statement  */
  YYSYMBOL_49_3 = 49,                      /* $@3  */
  YYSYMBOL_50_4 = 50,                      /* $@4  */
  YYSYMBOL_Call = 51,                      /* Call  */
  YYSYMBOL_ExpList = 52,                   /* ExpList  */
  YYSYMBOL_Type = 53,                      /* Type  */
  YYSYMBOL_Exp = 54,                       /* Exp  */
  YYSYMBOL_CaseList = 55,                  /* CaseList  */
  YYSYMBOL_CaseDecl = 56,                  /* CaseDecl  */
  YYSYMBOL_OpenScope = 57,                 /* OpenScope  */
  YYSYMBOL_CloseScope = 58                 /* CloseScope  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    97,    97,    99,   104,   106,   108,   106,   119,   120,
     122,   123,   125,   129,   135,   137,   138,   140,   141,   142,
     146,   150,   151,   152,   153,   154,   156,   156,   164,   165,
     166,   166,   172,   176,   181,   185,   191,   192,   193,   195,
     196,   197,   198,   203,   204,   205,   212,   213,   214,   215,
     216,   217,   218,   219,   221,   222,   223,   225,   227,   229
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "BYTE",
  "B", "BOOL", "TRUE", "FALSE", "RETURN", "IF", "WHILE", "BREAK",
  "CONTINUE", "SWITCH", "CASE", "DEFAULT", "COLON", "SC", "COMMA",
  "LBRACE", "RBRACE", "ID", "NUM", "STRING", "ASSIGN", "OR", "AND",
  "RELOP_EQ", "RELOP_REL", "BINOP_ADD", "BINOP_MUL", "NOT", "RPAREN",
  "LPAREN", "ELSE", "$accept", "Program", "Funcs", "FuncDecl", "$@1",
  "$@2", "RetType", "Formals", "FormalsList", "FormalDecl", "Statements",
  "Statement", "$@3", "$@4", "Call", "ExpList", "Type", "Exp", "CaseList",
  "CaseDecl", "OpenScope", "CloseScope", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
#endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      56,   -79,   -79,   -79,   -79,    18,   -79,    56,     2,   -79,
     -79,   -79,   -16,    98,    -8,   -79,     9,    12,   -79,    98,
     -79,    15,   -79,   -79,   159,    -3,     5,    10,    28,    50,
      37,   -79,   -25,   119,   -79,    54,    16,   -79,   -79,   -79,
      46,    78,   -79,    92,    92,   -79,   156,    92,    92,   -79,
     -79,    92,   159,    92,    74,   -79,   -79,   -79,   -12,   -79,
     -79,   182,   -79,    92,    92,    92,    92,    92,    92,   190,
     198,   206,   139,   162,   -79,    51,    47,   -79,    92,   -79,
      82,    20,    88,   105,    57,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,    92,   176,   159,   159,    70,   -79,   -79,   -79,
     -79,   -79,   -79,    58,    -4,   -79,    71,    86,    84,    -4,
     159,   103,   159,   -79,   -79,   -79,   159,   159,   -79,   -79,
     159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     9,    36,    37,    38,     0,     2,     3,     0,     8,
       1,     4,     0,    11,     0,    10,    12,     0,     5,     0,
      14,     0,    13,     6,     0,     0,     0,     0,     0,     0,
       0,    58,     0,     0,    15,     0,     0,    47,    48,    22,
      42,    44,    46,     0,     0,    43,     0,     0,     0,    28,
      29,     0,     0,     0,     0,     7,    16,    21,     0,    45,
      49,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,    34,    18,     0,    39,
      51,    50,    52,    53,    40,    41,    58,    26,    30,    59,
      20,    32,     0,     0,     0,     0,     0,    17,    35,    19,
      59,    27,    58,    24,     0,    58,     0,     0,     0,    55,
       0,     0,     0,    59,    54,    59,     0,    56,    31,    25,
      57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,   115,   -79,   -79,   -79,   -79,   -79,   109,   -79,
     -50,   -30,   -79,   -79,   -24,    53,     4,   -10,    29,   -79,
     -78,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    21,    24,     8,    14,    15,    16,
      33,    34,    95,    96,    45,    75,    36,    76,   108,   109,
      52,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      35,    53,    72,    56,     9,    37,    38,    77,    94,    35,
      54,     9,   106,   107,    78,    46,    39,    17,    10,    13,
      40,    41,    42,    17,   104,    12,    18,   110,    35,    19,
      43,   103,    44,    60,    61,    20,    23,    69,    70,    58,
      47,    71,    56,    73,   118,    48,   119,    49,    35,    65,
      66,    67,    68,    80,    81,    82,    83,    84,    85,     1,
       2,     3,   117,     4,   100,   101,   120,    92,    93,    50,
      35,    35,    51,    57,    63,    64,    65,    66,    67,    68,
     115,    54,    37,    38,    59,    91,    35,    56,    35,    68,
      56,   102,    35,    35,   105,   111,    35,    40,    41,    42,
      37,    38,     2,     3,   112,     4,   113,    43,    74,    44,
      64,    65,    66,    67,    68,    40,    41,    42,    66,    67,
      68,   116,    11,     2,     3,    43,     4,    44,    22,    25,
      26,    27,    28,    29,    30,    -1,    67,    68,   114,     0,
      31,    55,    32,     2,     3,    98,     4,     0,     0,    25,
      26,    27,    28,    29,    30,     0,     0,     0,     0,     0,
      31,    89,    32,     2,     3,     0,     4,     0,     0,    25,
      26,    27,    28,    29,    30,    62,     0,     0,     0,     0,
      31,    90,    32,    63,    64,    65,    66,    67,    68,    63,
      64,    65,    66,    67,    68,    99,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    63,
      64,    65,    66,    67,    68,     0,    79,    63,    64,    65,
      66,    67,    68,     0,    86,    63,    64,    65,    66,    67,
      68,     0,    87,    63,    64,    65,    66,    67,    68,     0,
      88
};

static const yytype_int8 yycheck[] =
{
      24,    26,    52,    33,     0,     8,     9,    19,    86,    33,
      35,     7,    16,    17,    26,    25,    19,    13,     0,    35,
      23,    24,    25,    19,   102,    23,    34,   105,    52,    20,
      33,   100,    35,    43,    44,    23,    21,    47,    48,    23,
      35,    51,    72,    53,   113,    35,   115,    19,    72,    29,
      30,    31,    32,    63,    64,    65,    66,    67,    68,     3,
       4,     5,   112,     7,    94,    95,   116,    20,    78,    19,
      94,    95,    35,    19,    27,    28,    29,    30,    31,    32,
     110,    35,     8,     9,     6,    34,   110,   117,   112,    32,
     120,    21,   116,   117,    36,    24,   120,    23,    24,    25,
       8,     9,     4,     5,    18,     7,    22,    33,    34,    35,
      28,    29,    30,    31,    32,    23,    24,    25,    30,    31,
      32,    18,     7,     4,     5,    33,     7,    35,    19,    10,
      11,    12,    13,    14,    15,    30,    31,    32,   109,    -1,
      21,    22,    23,     4,     5,    92,     7,    -1,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,     4,     5,    -1,     7,    -1,    -1,    10,
      11,    12,    13,    14,    15,    19,    -1,    -1,    -1,    -1,
      21,    19,    23,    27,    28,    29,    30,    31,    32,    27,
      28,    29,    30,    31,    32,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    27,
      28,    29,    30,    31,    32,    -1,    34,    27,    28,    29,
      30,    31,    32,    -1,    34,    27,    28,    29,    30,    31,
      32,    -1,    34,    27,    28,    29,    30,    31,    32,    -1,
      34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,    38,    39,    40,    43,    53,
       0,    39,    23,    35,    44,    45,    46,    53,    34,    20,
      23,    41,    45,    21,    42,    10,    11,    12,    13,    14,
      15,    21,    23,    47,    48,    51,    53,     8,     9,    19,
      23,    24,    25,    33,    35,    51,    54,    35,    35,    19,
      19,    35,    57,    26,    35,    22,    48,    19,    23,     6,
      54,    54,    19,    27,    28,    29,    30,    31,    32,    54,
      54,    54,    47,    54,    34,    52,    54,    19,    26,    34,
      54,    54,    54,    54,    54,    54,    34,    34,    34,    22,
      19,    34,    20,    54,    57,    49,    50,    58,    52,    19,
      48,    48,    21,    58,    57,    36,    16,    17,    55,    56,
      57,    24,    18,    22,    55,    48,    18,    47,    58,    58,
      47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    41,    42,    40,    43,    43,
      44,    44,    45,    45,    46,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49,    48,    48,    48,
      50,    48,    51,    51,    52,    52,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    56,    57,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,    10,     1,     1,
       1,     0,     1,     3,     2,     1,     2,     5,     3,     5,
       4,     2,     2,     3,     7,    11,     0,     6,     2,     2,
       0,    10,     4,     3,     1,     3,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     2,     1,     1,     1,     2,
       3,     3,     3,     3,     2,     1,     3,     4,     0,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: Funcs  */
#line 97 "parser.ypp"
                                                                            { symbolTable.close_global_scope(); }
#line 1263 "parser.tab.cpp"
    break;

  case 3: /* Funcs: %empty  */
#line 99 "parser.ypp"
                                                                            {
                                                                                if(string(yytext) != "") {
                                                                                    yyerror(nullptr);
                                                                                }
                                                                            }
#line 1273 "parser.tab.cpp"
    break;

  case 4: /* Funcs: FuncDecl Funcs  */
#line 104 "parser.ypp"
                                                                            { }
#line 1279 "parser.tab.cpp"
    break;

  case 5: /* $@1: %empty  */
#line 106 "parser.ypp"
                                                                            { symbolTable.add_func_symbol((yyvsp[-3].id)->m_name, (yyvsp[-4].exp)->m_type, (yyvsp[-1].funcArgsList)->m_argsList); }
#line 1285 "parser.tab.cpp"
    break;

  case 6: /* $@2: %empty  */
#line 108 "parser.ypp"
                                                                            {
                                                                              symbolTable.open_scope();
                                                                              curr_func_ret_type = (yyvsp[-6].exp)->m_type;
                                                                              symbolTable.add_func_args((yyvsp[-3].funcArgsList)->m_argsList);
                                                                            }
#line 1295 "parser.tab.cpp"
    break;

  case 7: /* FuncDecl: RetType ID LPAREN Formals RPAREN $@1 LBRACE $@2 Statements RBRACE  */
#line 114 "parser.ypp"
                                                                            {
                                                                                curr_func_ret_type = "";
                                                                                symbolTable.close_scope();
                                                                            }
#line 1304 "parser.tab.cpp"
    break;

  case 8: /* RetType: Type  */
#line 119 "parser.ypp"
                                                                            { (yyval.exp) = new Exp((yyvsp[0].exp)->m_type); }
#line 1310 "parser.tab.cpp"
    break;

  case 9: /* RetType: VOID  */
#line 120 "parser.ypp"
                                                                            { (yyval.exp) = new Exp("VOID"); }
#line 1316 "parser.tab.cpp"
    break;

  case 10: /* Formals: FormalsList  */
#line 122 "parser.ypp"
                                                                            { (yyval.funcArgsList)->m_argsList = (yyvsp[0].funcArgsList)->m_argsList; }
#line 1322 "parser.tab.cpp"
    break;

  case 11: /* Formals: %empty  */
#line 123 "parser.ypp"
                                                                            { (yyval.funcArgsList) = new FuncArgsList(); }
#line 1328 "parser.tab.cpp"
    break;

  case 12: /* FormalsList: FormalDecl  */
#line 125 "parser.ypp"
                                                                            {
                                                                              (yyval.funcArgsList) = new FuncArgsList();
                                                                              (yyval.funcArgsList)->m_argsList.push_back((yyvsp[0].funcArg)->m_arg);
                                                                            }
#line 1337 "parser.tab.cpp"
    break;

  case 13: /* FormalsList: FormalDecl COMMA FormalsList  */
#line 129 "parser.ypp"
                                                                            {
                                                                                (yyval.funcArgsList) = new FuncArgsList();
                                                                                (yyval.funcArgsList)->m_argsList = (yyvsp[0].funcArgsList)->m_argsList;
                                                                                (yyval.funcArgsList)->m_argsList.push_back((yyvsp[-2].funcArg)->m_arg);
                                                                            }
#line 1347 "parser.tab.cpp"
    break;

  case 14: /* FormalDecl: Type ID  */
#line 135 "parser.ypp"
                                                                            { (yyval.funcArg) = new FuncArg((yyvsp[-1].exp)->m_type, (yyvsp[0].id)->m_name); }
#line 1353 "parser.tab.cpp"
    break;

  case 15: /* Statements: Statement  */
#line 137 "parser.ypp"
                                                                            { }
#line 1359 "parser.tab.cpp"
    break;

  case 16: /* Statements: Statements Statement  */
#line 138 "parser.ypp"
                                                                            { }
#line 1365 "parser.tab.cpp"
    break;

  case 17: /* Statement: LBRACE OpenScope Statements RBRACE CloseScope  */
#line 140 "parser.ypp"
                                                                            { }
#line 1371 "parser.tab.cpp"
    break;

  case 18: /* Statement: Type ID SC  */
#line 141 "parser.ypp"
                                                                            { symbolTable.add_var_symbol((yyvsp[-1].id)->m_name, (yyvsp[-2].exp)->m_type); }
#line 1377 "parser.tab.cpp"
    break;

  case 19: /* Statement: Type ID ASSIGN Exp SC  */
#line 142 "parser.ypp"
                                                                            {
                                                                                validate_assign((yyvsp[-4].exp)->m_type, (yyvsp[-1].exp)->m_type);
                                                                                symbolTable.add_var_symbol((yyvsp[-3].id)->m_name, (yyvsp[-4].exp)->m_type);
                                                                            }
#line 1386 "parser.tab.cpp"
    break;

  case 20: /* Statement: ID ASSIGN Exp SC  */
#line 146 "parser.ypp"
                                                                            {
                                                                                string type = get_var_type((yyvsp[-3].id)->m_name);
                                                                                validate_assign(type, (yyvsp[-1].exp)->m_type);
                                                                            }
#line 1395 "parser.tab.cpp"
    break;

  case 21: /* Statement: Call SC  */
#line 150 "parser.ypp"
                                                                            { }
#line 1401 "parser.tab.cpp"
    break;

  case 22: /* Statement: RETURN SC  */
#line 151 "parser.ypp"
                                                                            { vaildate_type(curr_func_ret_type, "VOID"); }
#line 1407 "parser.tab.cpp"
    break;

  case 23: /* Statement: RETURN Exp SC  */
#line 152 "parser.ypp"
                                                                            { validate_assign(curr_func_ret_type, (yyvsp[-1].exp)->m_type); }
#line 1413 "parser.tab.cpp"
    break;

  case 24: /* Statement: IF LPAREN Exp RPAREN OpenScope Statement CloseScope  */
#line 153 "parser.ypp"
                                                                            { vaildate_type((yyvsp[-4].exp)->m_type, "BOOL"); }
#line 1419 "parser.tab.cpp"
    break;

  case 25: /* Statement: IF LPAREN Exp RPAREN OpenScope Statement CloseScope ELSE OpenScope Statement CloseScope  */
#line 155 "parser.ypp"
                                                                            { vaildate_type((yyvsp[-8].exp)->m_type, "BOOL"); }
#line 1425 "parser.tab.cpp"
    break;

  case 26: /* $@3: %empty  */
#line 156 "parser.ypp"
                                                                            {
                                                                                vaildate_type((yyvsp[-1].exp)->m_type, "BOOL");
                                                                                during_while++;
                                                                                symbolTable.open_scope(); }
#line 1434 "parser.tab.cpp"
    break;

  case 27: /* Statement: WHILE LPAREN Exp RPAREN $@3 Statement  */
#line 160 "parser.ypp"
                                                                            {
                                                                                symbolTable.close_scope();
                                                                                during_while--;
                                                                            }
#line 1443 "parser.tab.cpp"
    break;

  case 28: /* Statement: BREAK SC  */
#line 164 "parser.ypp"
                                                                            {   if(!during_while && !during_switch) {errorUnexpectedBreak(yylineno); exit(1);} }
#line 1449 "parser.tab.cpp"
    break;

  case 29: /* Statement: CONTINUE SC  */
#line 165 "parser.ypp"
                                                                            {   if(!during_while) {errorUnexpectedContinue(yylineno); exit(1);} }
#line 1455 "parser.tab.cpp"
    break;

  case 30: /* $@4: %empty  */
#line 166 "parser.ypp"
                                                                            {
                                                                                validate_assign("INT", (yyvsp[-1].exp)->m_type);
                                                                                during_switch++;
                                                                            }
#line 1464 "parser.tab.cpp"
    break;

  case 31: /* Statement: SWITCH LPAREN Exp RPAREN $@4 LBRACE OpenScope CaseList RBRACE CloseScope  */
#line 170 "parser.ypp"
                                                                            {   during_switch--; }
#line 1470 "parser.tab.cpp"
    break;

  case 32: /* Call: ID LPAREN ExpList RPAREN  */
#line 172 "parser.ypp"
                                                                            {
                                                                                FuncSymbol* f = get_func((yyvsp[-3].id)->m_name, (yyvsp[-1].typeList)->m_typeList);
                                                                                (yyval.exp) = new Exp(f->return_type);
                                                                            }
#line 1479 "parser.tab.cpp"
    break;

  case 33: /* Call: ID LPAREN RPAREN  */
#line 176 "parser.ypp"
                                                                            {
                                                                                FuncSymbol* f = get_func((yyvsp[-2].id)->m_name, std::vector<string>());
                                                                                (yyval.exp) = new Exp(f->return_type);
                                                                            }
#line 1488 "parser.tab.cpp"
    break;

  case 34: /* ExpList: Exp  */
#line 181 "parser.ypp"
                                                                            {
                                                                              (yyval.typeList) = new TypeList();
                                                                              (yyval.typeList)->m_typeList.push_back((yyvsp[0].exp)->m_type);
                                                                            }
#line 1497 "parser.tab.cpp"
    break;

  case 35: /* ExpList: Exp COMMA ExpList  */
#line 185 "parser.ypp"
                                                                            {
                                                                                (yyval.typeList) = new TypeList();
                                                                                (yyval.typeList)->m_typeList = (yyvsp[0].typeList)->m_typeList;
                                                                                (yyval.typeList)->m_typeList.push_back((yyvsp[-2].exp)->m_type);
                                                                            }
#line 1507 "parser.tab.cpp"
    break;

  case 36: /* Type: INT  */
#line 191 "parser.ypp"
                                                                            { (yyval.exp) = new Exp("INT"); }
#line 1513 "parser.tab.cpp"
    break;

  case 37: /* Type: BYTE  */
#line 192 "parser.ypp"
                                                                            { (yyval.exp) = new Exp("BYTE"); }
#line 1519 "parser.tab.cpp"
    break;

  case 38: /* Type: BOOL  */
#line 193 "parser.ypp"
                                                                            { (yyval.exp) = new Exp("BOOL"); }
#line 1525 "parser.tab.cpp"
    break;

  case 39: /* Exp: LPAREN Exp RPAREN  */
#line 195 "parser.ypp"
                                                                            { (yyval.exp) = new Exp((yyvsp[-1].exp)->m_type); }
#line 1531 "parser.tab.cpp"
    break;

  case 40: /* Exp: Exp BINOP_ADD Exp  */
#line 196 "parser.ypp"
                                                                            { (yyval.exp) = do_op((yyvsp[-2].exp), (yyvsp[0].exp), PBINOP);}
#line 1537 "parser.tab.cpp"
    break;

  case 41: /* Exp: Exp BINOP_MUL Exp  */
#line 197 "parser.ypp"
                                                                            { (yyval.exp) = do_op((yyvsp[-2].exp), (yyvsp[0].exp), PBINOP);}
#line 1543 "parser.tab.cpp"
    break;

  case 42: /* Exp: ID  */
#line 198 "parser.ypp"
                                                                            {
                                                                              string type = get_var_type((yyvsp[0].id)->m_name);
                                                                              (yyval.exp) = new Exp(type);
                                                                              (yyval.exp)->m_varName = (yyvsp[0].id)->m_name;
                                                                            }
#line 1553 "parser.tab.cpp"
    break;

  case 43: /* Exp: Call  */
#line 203 "parser.ypp"
                                                                            { (yyval.exp) = new Exp((yyvsp[0].exp)->m_type); }
#line 1559 "parser.tab.cpp"
    break;

  case 44: /* Exp: NUM  */
#line 204 "parser.ypp"
                                                                            { (yyval.exp) = new Exp("INT"); }
#line 1565 "parser.tab.cpp"
    break;

  case 45: /* Exp: NUM B  */
#line 205 "parser.ypp"
                                                                            {
                                                                                if (yylval.val > 255) {
                                                                                    errorByteTooLarge(yylineno, to_string(yylval.val));
                                                                                    exit(1);
                                                                                }
                                                                                (yyval.exp) = new Exp("BYTE");
                                                                            }
#line 1577 "parser.tab.cpp"
    break;

  case 46: /* Exp: STRING  */
#line 212 "parser.ypp"
                                                                            { (yyval.exp) = new Exp("STRING"); }
#line 1583 "parser.tab.cpp"
    break;

  case 47: /* Exp: TRUE  */
#line 213 "parser.ypp"
                                                                            { (yyval.exp) = new Exp("BOOL"); }
#line 1589 "parser.tab.cpp"
    break;

  case 48: /* Exp: FALSE  */
#line 214 "parser.ypp"
                                                                            { (yyval.exp) = new Exp("BOOL"); }
#line 1595 "parser.tab.cpp"
    break;

  case 49: /* Exp: NOT Exp  */
#line 215 "parser.ypp"
                                                                            { (yyval.exp) = do_op((yyvsp[0].exp), (yyvsp[0].exp), PNOT); }
#line 1601 "parser.tab.cpp"
    break;

  case 50: /* Exp: Exp AND Exp  */
#line 216 "parser.ypp"
                                                                            { (yyval.exp) = do_op((yyvsp[-2].exp), (yyvsp[0].exp), PAND); }
#line 1607 "parser.tab.cpp"
    break;

  case 51: /* Exp: Exp OR Exp  */
#line 217 "parser.ypp"
                                                                            { (yyval.exp) = do_op((yyvsp[-2].exp), (yyvsp[0].exp), POR); }
#line 1613 "parser.tab.cpp"
    break;

  case 52: /* Exp: Exp RELOP_EQ Exp  */
#line 218 "parser.ypp"
                                                                            { (yyval.exp) = do_op((yyvsp[-2].exp), (yyvsp[0].exp), PRELOP); }
#line 1619 "parser.tab.cpp"
    break;

  case 53: /* Exp: Exp RELOP_REL Exp  */
#line 219 "parser.ypp"
                                                                            { (yyval.exp) = do_op((yyvsp[-2].exp), (yyvsp[0].exp), PRELOP); }
#line 1625 "parser.tab.cpp"
    break;

  case 54: /* CaseList: CaseDecl CaseList  */
#line 221 "parser.ypp"
                                                                            { }
#line 1631 "parser.tab.cpp"
    break;

  case 55: /* CaseList: CaseDecl  */
#line 222 "parser.ypp"
                                                                            { }
#line 1637 "parser.tab.cpp"
    break;

  case 56: /* CaseList: DEFAULT COLON Statements  */
#line 223 "parser.ypp"
                                                                            { }
#line 1643 "parser.tab.cpp"
    break;

  case 57: /* CaseDecl: CASE NUM COLON Statements  */
#line 225 "parser.ypp"
                                                                            { }
#line 1649 "parser.tab.cpp"
    break;

  case 58: /* OpenScope: %empty  */
#line 227 "parser.ypp"
                                                                            { symbolTable.open_scope(); }
#line 1655 "parser.tab.cpp"
    break;

  case 59: /* CloseScope: %empty  */
#line 229 "parser.ypp"
                                                                            { symbolTable.close_scope(); }
#line 1661 "parser.tab.cpp"
    break;


#line 1665 "parser.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 232 "parser.ypp"


int main() {
	return yyparse();
}

int yyerror(const char* message) {
	errorSyn(yylineno);
	exit(1);
}

bool is_number(Exp* var){
    if (var->m_type == "INT" || var->m_type == "BYTE")
        return true;
    else
        return false;
}

void validate_assign(string var1, string var2) {
    if(!(var1 == var2 || (var1 == "INT" && var2 == "BYTE"))) {
        errorMismatch(yylineno);
        exit(1);
    }
}

string get_var_type(string var_name) {
    VarSymbol* var = (VarSymbol*)symbolTable.search_symbol(var_name, false);
    if(var == nullptr) {
        errorUndef(yylineno, var_name);
        exit(1);
    }
    return var->type;
}

Exp* do_op(Exp* var1, Exp* var2, ops op) {
    if(var1->m_type == "STRING" || var2->m_type == "STRING") {
        goto err;
    }
    switch(op){
        case(PASSIGN):
            validate_assign(var1->m_type, var2->m_type);
            return var1;

        case(PRELOP):
            if (is_number(var1) && is_number(var2))
                return new Exp("BOOL");
            break;

         case(PAND): case(POR):
            if (var1->m_type == "BOOL" && var2->m_type == "BOOL")
                return new Exp("BOOL");
            break;

        case(PNOT):
            if (var1->m_type == "BOOL")
                return new Exp("BOOL");
            break;

        case(PBINOP):
            if (is_number(var1) && is_number(var2)){
                if(var1->m_type == "INT" || var2->m_type == "INT")
                    return new Exp("INT");
                else
                    return new Exp("BYTE");
            }
            break;
    }
err:
    errorMismatch(yylineno);
    exit(1);
}

void vaildate_type(string x, string y){
    if (x != y)
    {
        output::errorMismatch(yylineno);
        exit(0);
    }
}

FuncSymbol* get_func(string name, std::vector<string> type_list){
    FuncSymbol* f = (FuncSymbol*)(symbolTable.search_symbol(name, true));
    if (f == nullptr) {
        errorUndefFunc(yylineno, name);
        exit(0);
    }
    validate_func(f->args_type, type_list, f->name);
    return f;
}

void validate_func(std::vector<string> expected, std::vector<string> current, string name) {
    if (expected.size() != current.size())
    {
        errorPrototypeMismatch(yylineno, name, expected);
        exit(1);
    }
    int size = expected.size();
    for(int i=0; i < size; i++){
        if(expected[i] != current[size-i-1] && !(expected[i] == "INT" && current[size-i-1] == "BYTE")){
            errorPrototypeMismatch(yylineno, name, expected);
            exit(1);
        }
    }
}
