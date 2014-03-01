%require "2.4.1"
%skeleton "lalr1.cc"
%defines
%define namespace "Xplode"
%define parser_class_name "BisonParser"
%parse-param { int *program } //int momentaneo, clase por crear 
%parse-param { Xplode::FlexScanner &scanner }
%lex-param   { Xplode::FlexScanner &scanner }


%code requires {
	// Forward-declare the Scanner class; the Parser needs to be assigned a 
	// Scanner, but the Scanner can't be declared without the Parser
	namespace Xplode {
		class FlexScanner;
	}
	#include <stdio.h>
}

%code {
	// Prototype for the yylex function
	static int yylex(Xplode::BisonParser::semantic_type * yylval, Xplode::FlexScanner &scanner);
}

%token INTEGER
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
%token x_POWER

%token x_ASSIGN
%token x_EQ
%token x_NEQ
%token x_AND
%token x_OR
%token x_NOT

%token x_NL

%%

testGrammar 
  : x_PROGRAM testRule { *program= 12345; } //int momentaneo}
  | testRule 

testRule
  : 
	| INTEGER testRule { $$ = $1; }
	| FLOAT testRule { $$ = $1; }
	| x_BEGIN testRule { $$ = $1; }
	| x_END testRule { $$ = $1; }
	| x_POWER testRule { printf("found power.\n"); $$ = $1; }
	| x_MULT testRule { printf("found mult.\n"); $$ = $1; }
	| x_FOR testRule { printf("found for.\n"); $$ = $1; }
	| x_NL testRule { printf("found ENTER.\n"); $$ = $1; }
	| /* empty rule */
	;	

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
