#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
extern int num_line;
extern char srcBuf[2048];
extern char* yytext;

#line 27 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KEY_FOR 257
#define KEY_WHILE 258
#define KEY_DO 259
#define KEY_IF 260
#define KEY_ELSE 261
#define KEY_SWTICH 262
#define KEY_RETURN 263
#define KEY_BREAK 264
#define KEY_CONTINUE 265
#define KEY_STRUCT 266
#define KEY_CASE 267
#define KEY_DEFAULT 268
#define KEY_NULL 269
#define KEY_TRUE 270
#define KEY_FALSE 271
#define KEY_CONST 272
#define TYPE 273
#define TYPE_VOID 274
#define OPER_PP 275
#define OPER_SS 276
#define OPER_AA 277
#define OPER_OO 278
#define OPER_CMP 279
#define ID 280
#define SCI 281
#define INT 282
#define DOUBLE 283
#define CHAR 284
#define STR 285
#define UMINUS 286
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,    2,    2,    2,
    2,    2,    2,    2,    1,    1,
};
static const short yylen[] = {                            2,
    2,    2,    2,    2,    3,    3,    3,    3,    3,    3,
    2,    3,    3,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    4,
};
static const short yydefred[] = {                         0,
   22,   23,   24,    0,   17,   18,   19,   20,   21,    0,
    0,    0,    0,   16,    2,    3,    0,    1,    0,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   14,    0,    0,    0,    0,    0,    5,    6,    7,    0,
   26,
};
static const short yydgoto[] = {                         13,
   18,   14,
};
static const short yysindex[] = {                       -33,
    0,    0,    0,  -89,    0,    0,    0,    0,    0,  -33,
  -33,  -33,   25,    0,    0,    0,  -33,    0,   39,    0,
  -17,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -10,
    0,   39,   32,   48,  -32,  -32,    0,    0,    0,  -88,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   22,   23,   19,   11,   16,    0,    0,    0,    8,
    0,
};
static const short yygindex[] = {                        96,
  -36,    0,
};
#define YYTABLESIZE 318
static const short yytable[] = {                         10,
   15,   17,   17,   41,   29,   11,   12,   25,    0,   27,
    8,   11,    0,    0,   28,    9,    0,    0,   10,   29,
    0,   12,   13,   31,   27,   25,   29,   26,    0,   28,
    0,   27,   25,    0,   26,    0,   28,   15,    0,    0,
    0,   15,   15,   15,   25,   15,   11,   15,   25,   25,
   25,    8,   25,    8,   25,    8,    9,    0,    9,   10,
    9,   29,   12,   13,    0,    0,   27,   25,   29,   26,
    0,   28,    0,   27,   25,   29,   26,    0,   28,    0,
   27,   25,   40,   26,   29,   28,    0,    0,    0,   27,
   25,    0,   26,   15,   28,    0,    0,    0,   11,    0,
   25,    0,    0,    8,    0,   19,   20,   21,    9,    0,
    0,   10,   30,    0,   12,   13,    0,   32,   33,   34,
   35,   36,   37,   38,   39,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   15,   16,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    2,    3,    0,    0,
    0,    0,    0,    0,    0,    0,    4,    5,    6,    7,
    8,    9,    0,    0,    0,    0,    0,    0,    0,   22,
   23,   24,    0,    0,    0,    0,   22,   23,   24,    0,
    0,    0,    0,    0,    0,    0,    0,   15,   15,   15,
    0,    0,   11,   11,   25,   25,   25,    8,    8,    8,
    0,    0,    9,    9,    9,   10,   10,   10,   12,   12,
   13,   22,   23,   24,    0,    0,    0,    0,   22,    0,
   24,    0,    0,    0,    0,    0,    0,   24,
};
static const short yycheck[] = {                         33,
    0,   91,   91,   40,   37,    0,   40,    0,   -1,   42,
    0,   45,   -1,   -1,   47,    0,   -1,   -1,    0,   37,
   -1,    0,    0,   41,   42,   43,   37,   45,   -1,   47,
   -1,   42,   43,   -1,   45,   -1,   47,   37,   -1,   -1,
   -1,   41,   42,   43,   37,   45,   41,   47,   41,   42,
   43,   41,   45,   43,   47,   45,   41,   -1,   43,   41,
   45,   37,   41,   41,   -1,   -1,   42,   43,   37,   45,
   -1,   47,   -1,   42,   43,   37,   45,   -1,   47,   -1,
   42,   43,   93,   45,   37,   47,   -1,   -1,   -1,   42,
   43,   -1,   45,   93,   47,   -1,   -1,   -1,   93,   -1,
   93,   -1,   -1,   93,   -1,   10,   11,   12,   93,   -1,
   -1,   93,   17,   -1,   93,   93,   -1,   22,   23,   24,
   25,   26,   27,   28,   29,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  275,  276,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  269,  270,  271,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  280,  281,  282,  283,
  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  277,
  278,  279,   -1,   -1,   -1,   -1,  277,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  277,  278,  279,
   -1,   -1,  277,  278,  277,  278,  279,  277,  278,  279,
   -1,   -1,  277,  278,  279,  277,  278,  279,  277,  278,
  278,  277,  278,  279,   -1,   -1,   -1,   -1,  277,   -1,
  279,   -1,   -1,   -1,   -1,   -1,   -1,  279,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,
"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"KEY_FOR","KEY_WHILE","KEY_DO","KEY_IF","KEY_ELSE","KEY_SWTICH",
"KEY_RETURN","KEY_BREAK","KEY_CONTINUE","KEY_STRUCT","KEY_CASE","KEY_DEFAULT",
"KEY_NULL","KEY_TRUE","KEY_FALSE","KEY_CONST","TYPE","TYPE_VOID","OPER_PP",
"OPER_SS","OPER_AA","OPER_OO","OPER_CMP","ID","SCI","INT","DOUBLE","CHAR","STR",
"UMINUS","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : expr",
"expr : ID arr_index",
"expr : ID OPER_PP",
"expr : ID OPER_SS",
"expr : '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr OPER_CMP expr",
"expr : '!' expr",
"expr : expr OPER_AA expr",
"expr : expr OPER_OO expr",
"expr : '(' expr ')'",
"expr : ID",
"expr : val",
"val : SCI",
"val : INT",
"val : DOUBLE",
"val : CHAR",
"val : STR",
"val : KEY_NULL",
"val : KEY_TRUE",
"val : KEY_FALSE",
"arr_index : '[' expr ']'",
"arr_index : '[' expr ']' arr_index",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 67 "parser.y"


int main(void){
	yyparse();
	fprintf(stdout, "%s\n", "No syntax error!");
	return 0;
}

int yyerror(char *s){
	fprintf( stderr, "*** Error at line %d: %s\n", num_line, srcBuf );
	fprintf( stderr, "\n" );
	fprintf( stderr, "Unmatched token: %s\n", yytext );
	fprintf( stderr, "*** syntax error\n");
	exit(-1);
}

#line 304 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
