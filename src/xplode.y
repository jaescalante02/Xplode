%require "2.4.1"
%skeleton "lalr1.cc"
%defines
%define namespace "Xplode"
%define parser_class_name "BisonParser"
%parse-param { Main **program } //int momentaneo, clase por crear 
%parse-param { Xplode::FlexScanner &scanner }
%lex-param   { Xplode::FlexScanner &scanner }
%union {
  Token *tok;
  Node *node; //Node from the AST
  NodeList *nodelist;
  Variable *var;
  Expression *exp;
  std::list<Expression *> *explist;
}

%code requires {
	// Forward-declare the Scanner class; the Parser needs to be assigned a 
	// Scanner, but the Scanner can't be declared without the Parser
	namespace Xplode {
		class FlexScanner;
	}
	#include <stdio.h>
	#include "Token.h"
	#include "ast.h"
}

%code {
	// Prototype for the yylex function
	static int yylex(Xplode::BisonParser::semantic_type * yylval, Xplode::FlexScanner &scanner);
}

%token<tok> INTEGER
%token<tok> FLOAT
%token<tok> STRING

//Reserved words
%token<tok> x_PROGRAM
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


//Types for non-terminals

%type <node> definition
%type <node> def_union
%type <node> def_type
%type <node> def_proc
%type <node> def_function
%type <node> statement
%type <node> statement_assign statement_sleep 
%type <node> statement_read statement_write
%type <node> statement_while statement_for
%type <node> statement_if statement_else
%type <node> for_init for_increment

%type <node> block
%type <node> main
%type <node> start


//expressions

%type <var> variable
%type <var> variable_id
%type <exp> constant
%type <exp> expression expression_unary function
%type <explist> function_arguments write_list
%type <exp> while_condition for_condition if_condition


%type <nodelist> definition_list
%type <nodelist> declaration_list
%type <nodelist> attribute_list
%type <nodelist> proc_type_list
%type <nodelist> function_parameters 
%type <nodelist> statement_list 



//
%type <tok> type
%type <tok> function_type 

%%

// Grammar for classic version
start
  : x_PROGRAM main { *program = new Main($2); }
  | x_PROGRAM definition_list main { *program = new Main($2,$3); }
  ;

main
  : x_BEGIN statement_list x_END {$$ = new Block($2); } 
  | x_BEGIN declaration_list statement_list x_END {$$ = new Block($2,$3);}
  ;
  

definition_list
  : definition { 
    $$ = new NodeList();
    $$->add($1);  
  }
  | definition_list definition {
    $1->add($2);
    $$ = $1;
  }
  ;
definition
  : def_union { $$ = $1; }
  | def_proc { $$ = $1; }
  | def_type { $$ = $1; }
  | def_function {$$ = $1; }
  ;

def_union
  : x_UNION x_ID x_LBRACE attribute_list x_RBRACE { 
    $$ = new Union($2->value, $4);
  }
  ;

def_type 
  :  x_TYPE x_ID x_LBRACE attribute_list x_RBRACE { 
    $$ = new Type($2->value, $4);
  }
  ; 

attribute_list
  : type x_ID x_SEMICOLON { 
    $$ = new NodeList();
    $$->push(new Declaration($1->value, $2->value));  
  }
  | attribute_list type x_ID x_SEMICOLON {
    $1->push(new Declaration($2->value, $3->value));
    $$ = $1;
  }
  ;

//Used for second class functions
def_proc
  : x_PROC type x_ID x_LPAR proc_type_list x_RPAR x_SEMICOLON {
    $$ = new Procedure($2->value,$3->value,$5);
  }
  ;

proc_type_list
  : type {
    $$ = new NodeList();
    $$->add(new ProcedureType($1->value));
  }
  | proc_type_list x_COMMA type { 
    $1->add(new ProcedureType($3->value));
    $$ = $1;
  }   
  ;

def_function  
  : x_FUNCTION function_type x_ID x_LPAR function_parameters x_RPAR x_LBRACE x_RBRACE{
    $$ = new Function($3->value, $2->value, $5);
  }
  | x_FUNCTION function_type x_ID x_LPAR function_parameters x_RPAR block {
    $$ = new Function($3->value, $2->value, $5, $7);
  }
  ;

function_type
  : type {$$ = $1; }
  | x_VOID {$$ = $1; }
  ;
  
function_parameters 
  : type x_ID {
    $$ = new NodeList();
    $$->push(new FunctionParameter($1->value,$2->value));
  }
  | type x_ID x_COMMA x_EXTEND {
    $$ = new NodeList();
    $$->push(new Extends($1->value));
    $$->push(new FunctionParameter($1->value,$2->value));
    
  }
  | type x_ID x_COMMA function_parameters {
    $4->push(new FunctionParameter($1->value,$2->value));
    $$ = $4;  
  }
  ;

type 
  :  x_INT {$$ = $1; }
  | x_CHAR {$$ = $1; } 
  | x_FLOAT {$$ = $1; }
//  | x_ID
  | type x_LBRACKET INTEGER x_RBRACKET
  ;     


block 
  : x_LBRACE declaration_list statement_list x_RBRACE {$$ = new Block($2,$3); }
  | x_LBRACE statement_list x_RBRACE {$$ = new Block($2); }
  ;

declaration_list
  : type x_ID x_SEMICOLON { 
    $$ = new NodeList();
    $$->add(new Declaration($1->value, $2->value));  
  }
  
  | declaration_list type x_ID x_SEMICOLON {
    $1->add(new Declaration($2->value, $3->value));
    $$ = $1;
  }
  ;
  
statement_list
  : statement x_SEMICOLON {$$ = new NodeList(); $$->add($1); }
  | statement_list statement x_SEMICOLON {$1->add($2); $$ = $1; }
  ;


//statements
statement
  : statement_assign {$$ = $1; }
  | statement_for {$$ = $1; }
  | statement_while {$$ = $1; }
  | statement_if {$$ = $1; }
  | statement_read {$$ = $1; }
  | statement_write {$$ = $1; }
  | statement_sleep {$$ = $1; }
  ;

statement_for
  : x_FOR x_LPAR for_init x_SEMICOLON for_condition x_SEMICOLON for_increment x_RPAR block{
    $$ = new ForStatement($3,$5,$7,$9); $$->print();
  }
  ;

for_init
  : statement_assign {$$ = $1; }
  ;

for_condition
  : expression {$$ = $1; }
  ;

for_increment
  : statement_assign {$$ = $1; }
  ;

statement_while
  : x_WHILE x_LPAR while_condition x_RPAR block {$$ = new  WhileStatement($3,$5); }
  ;

while_condition
  : expression {$$ = $1; }
  ;

statement_if
  : x_IF x_LPAR if_condition x_RPAR block {$$ = new IfStatement($3,$5); }
  | x_IF x_LPAR if_condition x_RPAR block statement_else {$$ = new IfStatement($3,$5,$6); }
  ;
  
if_condition
  : expression {$$ = $1; }
  ;
  
statement_else
  : x_ELSE block {$$ = $2; }
  ;

statement_assign
  : variable x_ASSIGN expression {$$ = new AssignStatement($1,$3); }
  ;
  
statement_read
  : x_READ x_LPAR variable x_RPAR {$$ = new ReadStatement($3); }
  ;
  
statement_write
  : x_WRITE x_LPAR write_list x_RPAR {$$ = new WriteStatement($3); }
  ;

write_list
  : expression {$$ = new std::list<Expression *>(); $$->push_back($1);}
  // String missing  
  | write_list x_COMMA expression {$$ = $1; $$->push_back($3); }
  ;
 
statement_sleep
  : x_SLEEP x_LPAR variable x_RPAR {$$ = new SleepStatement($3); }
  ;    


//expressions


expression
  : expression_unary  {$$ = $1;}
  | expression x_PLUS expression {$$ = new BinaryExpression($2->value,$1,$3); }
  | expression x_MINUS expression {$$ = new BinaryExpression($2->value,$1,$3); }
  | expression x_MULT expression {$$ = new BinaryExpression($2->value,$1,$3); }
  | expression x_DIV expression {$$ = new BinaryExpression($2->value,$1,$3); }
  | expression x_POWER expression {$$ = new BinaryExpression($2->value,$1,$3); }

  | expression x_AND expression {$$ = new BinaryExpression($2->value,$1,$3); }
  | expression x_OR expression {$$ = new BinaryExpression($2->value,$1,$3); }
  
  | expression x_LESS expression {$$ = new BinaryExpression($2->value,$1,$3); }
  | expression x_LESSEQ expression {$$ = new BinaryExpression($2->value,$1,$3); }
  | expression x_GREATER expression {$$ = new BinaryExpression($2->value,$1,$3); }
  | expression x_GREATEREQ expression {$$ = new BinaryExpression($2->value,$1,$3); }
  
  | expression x_EQ expression {$$ = new BinaryExpression($2->value,$1,$3); }
  | expression x_NEQ expression {$$ = new BinaryExpression($2->value,$1,$3); }
  ;

expression_unary
  : constant { $$ = $1; }
  | variable { $$ = $1; }
  | function { $$ = $1; }
  | x_MINUS expression %prec x_UMINUS { $$ = new Uminus($2); }
  | x_LPAR expression x_RPAR { $$ = new UnaryExpression($2); }
  ;
 
constant
  : INTEGER { $$ = new Constant($1->value);}
  | FLOAT { $$ = new Constant($1->value);}
  | x_TRUE { $$ = new Constant($1->value);}
  | x_FALSE { $$ = new Constant($1->value);}
  ;
  
variable
  : variable_id { $$ = $1;}
  | variable x_LBRACKET INTEGER x_RBRACKET { $1->addIndex($3->value); $$ = $1; }
  ;

variable_id
  : x_ID { $$ = new Variable($1->value);}
  | variable_id x_DOT x_ID { $1->addField($3->value); $$ = $1; }
  ;

function
  : x_ID x_LPAR function_arguments x_RPAR {$$ = new FunctionExpression($1->value,$3); }
  ;

function_arguments
  : expression {$$ = new std::list<Expression *>(); $$->push_back($1); }
  | function_arguments x_COMMA expression {$$ = $1; $$->push_back($3); }
  ;
  
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
