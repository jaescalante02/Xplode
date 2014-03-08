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

%token<tok><tok> INTEGER
%token<tok> FLOAT

//Reserved words
%token<tok><tok> x_PROGRAM
%token<tok> x_BEGIN
%token<tok> x_END
%token<tok> x_FUNCTION
%token<tok> x_RETURN
%token<tok> x_BREAK
%token<tok> x_CONTINUE
%token<tok> x_EXIT

%token<tok> x_ID
%token<tok> x_INT
%token<tok> x_CHAR
%token<tok> x_BOOL
%token<tok> x_FLOAT
%token<tok> x_VOID

%token<tok> x_TRUE
%token<tok> x_FALSE

%token<tok> x_WRITE
%token<tok> x_READ

%token<tok> x_FOR
%token<tok> x_WHILE
%token<tok> x_IF
%token<tok> x_ELSE
%token<tok> x_CASE
%token<tok> x_TYPE
%token<tok> x_UNION

//Single characters
%token<tok> x_LPAR
%token<tok> x_RPAR
%token<tok> x_LBRACKET
%token<tok> x_RBRACKET
%token<tok> x_LBRACE
%token<tok> x_RBRACE
%token<tok> x_SEMICOLON
%token<tok> x_COMMA
%token<tok> x_DOT

//Operators
%token<tok> x_PLUS
%token<tok> x_MINUS
%token<tok> x_MULT
%token<tok> x_DIV
%token<tok><tok> x_POWER

%token<tok> x_ASSIGN
%token<tok> x_EQ
%token<tok> x_NEQ
%token<tok> x_AND
%token<tok> x_OR
%token<tok> x_NOT

%token<tok> x_LESS
%token<tok> x_LESSEQ
%token<tok> x_GREATER
%token<tok> x_GREATEREQ

%token<tok> x_EXTEND
%token<tok> x_PROC
%token<tok> x_SLEEP


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
  : x_PROGRAM main { std::cout  << "I'm a very basic program\n";  }
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
  :   x_UNION x_ID x_LBRACE attributes x_RBRACE
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

extern int line,column;  
extern std::string tok;
 
void Xplode::BisonParser::error(const Xplode::BisonParser::location_type &loc, const std::string &msg) {
	std::cerr << "Error de sintaxis en linea " << line << ", columna " << column << ": token "
	<< "\'" << tok << "\' inesperado.\n"; 
}

// Now that we have the Parser declared, we can declare the Scanner and implement
// the yylex function
#include "XplodeScanner.h"
static int yylex(Xplode::BisonParser::semantic_type * yylval, Xplode::FlexScanner &scanner) {
	return scanner.yylex(yylval);
}
