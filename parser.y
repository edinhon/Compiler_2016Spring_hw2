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

program:	statement
		|	statement program
		;
		
program_in_func:
			statement_in_func
		|	statement_in_func program_in_func
		;

statement:	declare
		|	func_invocation ';'
		|	simple_statement
		;

statement_in_func:	
			declare_in_func
		|	func_invocation ';'
		|	simple_statement
		|	if_else_statement
		|	switch_statement
		|	KEY_BREAK ';'
		|	KEY_CONTINUE ';'
		|	return_statement
		;

declare:	TYPE declare_ID ';'
		|	KEY_CONST TYPE declare_const ';'
		|	TYPE declare_function
		|	TYPE_VOID declare_function
		;

declare_in_func:	
			TYPE declare_ID ';'
		|	KEY_CONST TYPE declare_const ';'
		;

declare_ID:	scalar
		|	array
		|	scalar ',' declare_ID
		|	array ',' declare_ID
		;

declare_const:
			ID '=' expr
		|	ID '=' expr ',' declare_const
		;

declare_function:
			ID '(' ')' ';'
		|	ID '(' paras ')' ';'
		|	ID '(' ')' '{' '}'
		|	ID '(' paras ')' '{' '}'
		|	ID '(' ')' '{' program_in_func '}'
		|	ID '(' paras ')' '{' program_in_func '}'
		;
		
scalar:		ID
		|	ID '=' expr
		;
		
array:		ID arr_state_index
		|	ID arr_state_index '=' '{' arr_content '}'
		|	ID arr_state_index '=' '{' '}'
		;

arr_state_index:	
			'[' INT ']'
		|	'[' INT ']' arr_state_index
		;

arr_content:
			exprs
		;

paras:		para
		|	para  ',' paras
		;

para:		TYPE ID
		|	TYPE ID arr_state_index
		;

var:		ID
		|	ID arr_expr_index
		;

simple_statement:
			var '=' expr ';'
		;

if_else_statement:
			KEY_IF '(' expr ')' '{' program_in_func '}' 
		KEY_ELSE '{' program_in_func '}'
		|	KEY_IF '(' expr ')' '{' '}' 
		KEY_ELSE '{' program_in_func '}'
		|	KEY_IF '(' expr ')' '{' program_in_func '}' 
		KEY_ELSE '{' '}'
		|	KEY_IF '(' expr ')' '{' '}' 
		KEY_ELSE '{' '}'
		|	KEY_IF '(' expr ')' '{' program_in_func '}'
		|	KEY_IF '(' expr ')' '{' '}'
		;

switch_statement:
			KEY_SWTICH '(' ID ')' '{' case_statements '}'
		|	KEY_SWTICH '(' ID ')' '{' case_statements default_statement '}'
		;
		
case_const:	INT
		|	CHAR
		;
		
case_statements:
			KEY_CASE case_const ':' program_in_func
		|	KEY_CASE case_const ':' program_in_func case_statements
		|	KEY_CASE case_const ':'
		|	KEY_CASE case_const ':' case_statements
		;

default_statement:
			KEY_DEFAULT ':' program_in_func
		|	KEY_DEFAULT ':'
		;
		
return_statement:
			KEY_RETURN expr ';'
		
exprs:		expr
		|	expr ',' exprs
		;

expr: 		var
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
		|	val
		|	ID '(' ')'
		|	ID '(' exprs ')'
		;

val:		SCI
		|	INT
		|	DOUBLE
		|	CHAR
		|	STR
		|	KEY_NULL
		|	KEY_TRUE
		|	KEY_FALSE
		;

arr_expr_index: 
			'[' expr ']'
		| 	'[' expr ']' arr_expr_index
		;

func_invocation:
			ID '(' ')'
		|	ID '(' exprs ')'
		;


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

