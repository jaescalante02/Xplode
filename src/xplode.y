%require "2.4.1"
%skeleton "lalr1.cc"
%defines
%define namespace "Xplode"
%define parser_class_name "BisonParser"
%parse-param { int *program } //int momentaneo, clase por crear 
%parse-param { Xplode::FlexScanner &scanner }
%lex-param   { Xplode::FlexScanner &scanner }
%union {

Token *tok;

}

%code requires {
	// Forward-declare the Scanner class; the Parser needs to be assigned a 
	// Scanner, but the Scanner can't be declared without the Parser
	namespace Xplode {
		class FlexScanner;
	}
	#include <stdio.h>
	#include "Token.h"
}

%code {
	// Prototype for the yylex function
	static int yylex(Xplode::BisonParser::semantic_type * yylval, Xplode::FlexScanner &scanner);
}

%token<tok> INTEGER
%token FLOAT

//Reserved words
%token x_PROGRAM
%token x_BEGIN
%token x_END
%token x_FUNCTION
%token x_RETURN
%token x_BREAK
%token x_CONTINUE
%token x_EXIT

%token x_ID
%token x_INT
%token x_CHAR
%token x_BOOL
%token x_FLOAT
%token x_VOID

%token x_TRUE
%token x_FALSE

%token x_WRITE
%token x_READ

%token x_FOR
%token x_WHILE
%token x_IF
%token x_ELSE
%token x_CASE
%token x_TYPE
%token x_UNION

//Single characters
%token x_LPAR
%token x_RPAR
%token x_LBRACKET
%token x_RBRACKET
%token x_LBRACE
%token x_RBRACE
%token x_SEMICOLON
%token x_COMMA
%token x_DOT

//Operators
%token x_PLUS
%token x_MINUS
%token x_MULT
%token x_DIV
%token<tok> x_POWER

%token x_ASSIGN
%token x_EQ
%token x_NEQ
%token x_AND
%token x_OR
%token x_NOT

%token x_LESS
%token x_LESSEQ
%token x_GREATER
%token x_GREATEREQ

%token x_EXTEND
%token x_PROC
%token x_SLEEP

//Precedence and associativity
%nonassoc x_EQ x_NEQ
%nonassoc x_LESS x_LESSEQ x_GREATER x_GREATEREQ
%left x_AND x_OR
%left	x_PLUS x_MINUS
%left x_MULT x_DIV   
%left x_POWER
%left	x_UMINUS

%%

// Grammar for classic version
start
  : x_PROGRAM main { std::cout << "I'm a very basic program\n"; *program=12345; }
  | x_PROGRAM definition_list main { std::cout << "I've got at least a definition \n"; }
  ;

main
  : x_BEGIN statement_list x_END
  | x_BEGIN declaration_list statement_list x_END;
  

definition_list
  : definition
  | definition_list definition
  ;
definition
  : def_union
  | def_proc 
  | def_type 
  | def_function
  ;

def_union
  :   x_UNION x_ID x_LBRACE attributes x_RBRACE {std::cout << "I'm a basic union";}
  ;

def_type 
  :   x_TYPE x_ID x_LBRACE attributes x_RBRACE
  ; 

attributes
  : type x_ID x_SEMICOLON
  | attributes type x_ID x_SEMICOLON
  ;

//Used for second class functions
def_proc
  :   x_PROC type x_ID x_LPAR proc_types x_RPAR x_SEMICOLON 
  ;

proc_types
  : type { }
  | proc_types x_COMMA type { }   
  ;

def_function  
  : x_FUNCTION function_type x_ID x_LPAR function_parameters x_RPAR x_LBRACE x_RBRACE
  ;

function_type
  : type
  | x_VOID
  ;
  
function_parameters 
  : type x_ID {}
  | type x_ID x_COMMA x_EXTEND 
  | type x_ID x_COMMA function_parameters 
  ;

type 
  :  x_INT
  | x_CHAR
  | x_FLOAT
//  | x_ID
  | type x_LBRACKET INTEGER x_RBRACKET
  ;     


block 
  : x_LBRACE declaration_list statement_list x_RBRACE
  | x_LBRACE statement_list x_RBRACE
  ;

declaration_list
  : type x_ID x_SEMICOLON
  | declaration_list type x_ID x_SEMICOLON
  ;
  
statement_list
  : 
  | statement x_SEMICOLON
  | statement_list statement x_SEMICOLON ;

//statements
statement
  : statement_assign
  | statement_for
  | statement_while
  | statement_if
  | statement_read
  | statement_write
  | statement_sleep
  ;

statement_for
  : x_FOR x_LPAR for_def x_RPAR block
  ;

for_def
  : for_init x_SEMICOLON for_condition x_SEMICOLON for_increment
  ;

for_init
  : statement_assign
  ;

for_condition
  : expression
  ;

for_increment
  : statement_assign
  ;

statement_while
  : x_WHILE x_LPAR while_condition x_RPAR block
  ;

while_condition
  : expression
  ;

statement_if
  : x_IF x_LPAR if_condition x_RPAR block
  | x_IF x_LPAR if_condition x_RPAR block statement_else
  ;
  
if_condition
  : expression
  ;
  
statement_else
  : x_ELSE block
  ;

statement_assign
  : variable x_ASSIGN expression
  ;
  
statement_read
  : x_READ x_LPAR variable x_RPAR
  ;
  
statement_write
  : x_WRITE x_LPAR write_list x_RPAR
  ;

write_list
  : expression
  // String missing  
  | write_list x_COMMA expression
  ;
 
statement_sleep
  : x_SLEEP x_LPAR INTEGER x_RPAR
  ;    


//expressions


expression
  : expression_unary  
  | expression x_PLUS expression
  | expression x_MINUS expression
  | expression x_MULT expression
  | expression x_DIV expression
  | expression x_POWER expression

  | expression x_AND expression
  | expression x_OR expression
   
  | expression x_LESS expression
  | expression x_LESSEQ expression
  | expression x_GREATER expression
  | expression x_GREATEREQ expression
  
  | expression x_EQ expression
  | expression x_NEQ expression
  ;

expression_unary
  : constant
  | variable
  | function
  | x_MINUS expression %prec x_UMINUS
  | x_LPAR expression x_RPAR 
  ;
 
constant
  : INTEGER
  | FLOAT
  | x_TRUE
  | x_FALSE
  ;
  
variable
  : variable_id
  | variable x_LBRACKET INTEGER x_RBRACKET
  ;

variable_id
  : x_ID 
  | variable_id x_DOT x_ID

function
  : x_ID x_LPAR function_arguments x_RPAR
  ;

function_arguments
  : expression
  | function_arguments x_COMMA expression
  
  
%%

// We have to implement the error function
void Xplode::BisonParser::error(const Xplode::BisonParser::location_type &loc, const std::string &msg) {
	std::cerr << "Error: " << msg << std::endl;
}

// Now that we have the Parser declared, we can declare the Scanner and implement
// the yylex function
#include "XplodeScanner.h"
static int yylex(Xplode::BisonParser::semantic_type * yylval, Xplode::FlexScanner &scanner) {
	return scanner.yylex(yylval);
}
