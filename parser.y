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

program:	program statement

statement:	scalar

scalar:		TYPE ID '=' expr ';'

array:		

expr: 		ID arr_index
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

arr_index: 	'[' expr ']'
		| 	'[' expr ']' arr_index





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

