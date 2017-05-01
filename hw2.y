
/* This is a simpled gcc grammar */
/* Copyright (C) 1987 Free Software Foundation, Inc. */
/* BISON parser for a simplied C by Jenq-kuen Lee  Sep 20, 1993    */

%{
#include <stdio.h>
#include "SymbolTable.h"
extern int lineno;
extern FILE *f_asm;
char   *install_symbol();
%}

%start program
%union { 
         int       token ;
         char      charv ;
         char      *ident;
       }
/* all identifiers   that are not reserved words
   and are not declared typedefs in the current block */
%token IDENTIFIER INTEGER FLOAT

/* reserved words that specify storage class.
   yylval contains an IDENTIFIER_NODE which indicates which one.  */
%token SCSPEC

/* reserved words that specify type.
   yylval contains an IDENTIFIER_NODE which indicates which one.  */
%token TYPESPEC

/* reserved words that modify type: "const" or "volatile".
   yylval contains an IDENTIFIER_NODE which indicates which one.  */
%token TYPEMOD

%token CONSTANT

/* the reserved words */
%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT_TOKEN
%token BREAK CONTINUE RETURN

%type <ident> notype_declarator IDENTIFIER primary expr_no_commas

%type <token> CONSTANT

/* Define the operator tokens and their precedences.
   The value is an integer because, if used, it is the tree code
   to use in the expression made from the operator.  */
%left  <charv> ';'
%left IDENTIFIER  SCSPEC TYPESPEC TYPEMOD
%left  <charv> ','
%right <charv> '='
%right <token> ASSIGN 
%left <charv> OROR
%left <charv> ANDAND
%left <token> EQCOMPARE
%left <token> ARITHCOMPARE  '>' '<' 
%left <charv> '+' '-'
%left <token> '*' '/' '%'
%right <token> UNARY 


%{
/* external function is defined here */
void error();
int TRACEON = 100;
%}     


%%

program: /* empty */
          { if (TRACEON) printf("1\n ");}
	| extdefs
          { if (TRACEON) printf("2\n ");}
	;

extdefs:
          extdef
          { if (TRACEON) printf("3\n ");}
	| extdefs  extdef
          { if (TRACEON) printf("4\n ");}
	;

extdef:
	 TYPESPEC notype_declarator ';'
	  { if (TRACEON) printf("7 ");
          }
        | notype_declarator
          	  { if (TRACEON) printf("10 ");
                  }
          '{'  xdecls 
          	  { if (TRACEON) printf("10.5 ");

                  }
               stmts
		{
                  if (TRACEON) printf("11 ");
                }
           '}'
        | error ';'
	  { if (TRACEON) printf("8 "); }
	| ';'
	  { if (TRACEON) printf("9 "); }
	;

/* Must appear precede expr for resolve precedence problem */
/* A nonempty list of identifiers.  */

/* modified */
expr_no_commas:
	primary
           { if (TRACEON) printf("15 ") ;
 	     $$= $1;
           }
	| expr_no_commas '+' expr_no_commas
		{ 
                  if (TRACEON) printf("16 ") ; 
                }
	| expr_no_commas '=' expr_no_commas
		{ char *s;
		  int index;

		  if (TRACEON) printf("17 ") ;
                }
	| expr_no_commas '*' expr_no_commas
		{ if (TRACEON) printf("18 ") ;

                }
	| expr_no_commas ARITHCOMPARE expr_no_commas
		{ if (TRACEON) printf("19 ") ; }
	;


/* modified */
primary:
        IDENTIFIER
  	{    	  int index;

                  if (TRACEON) printf("20 ") ;
         }
	| CONSTANT
                { if (TRACEON) printf("21 ") ;

                }
        ;

notype_declarator:
	  notype_declarator '(' parmlist ')'  %prec '.'
		{   if (TRACEON) printf("22 ") ;
                }                  
        | IDENTIFIER
		{   if (TRACEON) printf("23 ") ;
                }                  
	;

/* This is what appears inside the parens in a function declarator.
   Is value is represented in the format that grokdeclarator expects.  */
parmlist:  /* empty */
               { if (TRACEON) printf("24 ") ; }
		
	| parms
  		{ if (TRACEON) printf("25 ") ;  }
		
	;

/* A nonempty list of parameter declarations or type names.  */
parms:	
	parm
  		{ if (TRACEON) printf("26 ") ;  }
	| parms ',' parm
  		{ if (TRACEON) printf("27 ") ;  }
	;

parm:
	  TYPESPEC notype_declarator
  		{ if (TRACEON) printf("28 ") ;  }
   ;


/* at least one statement, the first of which parses without error.  */
/* stmts is used only after decls, so an invalid first statement
   is actually regarded as an invalid decl and part of the decls.  */

stmts:
	stmt
               { if (TRACEON) printf("29 ") ;  }
	| stmts stmt
               { if (TRACEON) printf("30 ") ;  }
	;


/* modified */
stmt:
	 expr_no_commas ';'
	{
        }
	;


xdecls:
	/* empty */
           { if (TRACEON) printf("102 ") ; }
	| decls
           { if (TRACEON) printf("103 ") ; }
	;

decls:
	decl
           { if (TRACEON) printf("104 ") ;
           }
	| decls decl
           { if (TRACEON) printf("106 ") ;
           }
	;

decl:	 TYPESPEC notype_declarator ';'
            { if (TRACEON) printf("110 ") ;}

%%

int main(void)
{
    yyparse();
    return 0;
}

/*
 *	  s - the error message to be printed
 */
void 
yyerror(s)
	char   *s;
{
	err(s);
}

