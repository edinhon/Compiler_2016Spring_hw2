%{
#include <stdio.h>
#include <stdlib.h>
extern int num_line;
extern char srcBuf[2048];
extern char* yytext;

%}

%start program

%token KEY_FOR KEY_WHILE KEY_DO KEY_IF KEY_ELSE KEY_SWTICH KEY_RETURN KEY_BREAK KEY_CONTINUE KEY_STRUCT KEY_CASE KEY_DEFAULT
%token KEY_NULL KEY_TRUE KEY_FALSE
%token KEY_CONST
%token TYPE TYPE_VOID
%token OPER_PP OPER_SS OPER_AA OPER_OO OPER_CMP
%token ID
%token SCI INT DOUBLE CHAR STR


%left OPER_OO
%left OPER_AA
%right '!'
%left OPER_CMP
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS
%left OPER_PP OPER_SS
%left '[' ']'


%%

program:	statement program

statement:	declare

declare:	TYPE declare_ID ';'
		|	KEY_CONST TYPE declare_const ';'

declare_ID:	scalar
		|	array
		|	scalar ',' declare_ID
		|	array ',' declare_ID

declare_const:
			ID '=' expr
		|	ID '=' expr ',' declare_const
		
scalar:		ID
		|	ID '=' expr
		
array:		ID arr_state_index
		|	ID arr_state_index '=' '{' arr_content '}'
		|	ID arr_state_index '=' '{' '}'

arr_state_index:	
			'[' INT ']'
		|	'[' INT ']' arr_state_index

arr_content:
			expr
		|	expr ',' arr_content

expr: 		ID arr_expr_index
		|	ID OPER_PP
		|	ID OPER_SS
		|	'-' expr %prec UMINUS
		|	expr '*' expr
		|	expr '/' expr
		|	expr '%' expr
		|	expr '+' expr
		|	expr '-' expr
		|	expr OPER_CMP expr
		|	'!' expr
		|	expr OPER_AA expr
		|	expr OPER_OO expr
		|	'(' expr ')'
		|	ID
		|	val

val:		SCI
		|	INT
		|	DOUBLE
		|	CHAR
		|	STR
		|	KEY_NULL
		|	KEY_TRUE
		|	KEY_FALSE

arr_expr_index: 
			'[' expr ']'
		| 	'[' expr ']' arr_expr_index





%%

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

