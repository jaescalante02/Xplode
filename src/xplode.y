%require "2.4.1"
%skeleton "lalr1.cc"
%defines
%define namespace "Xplode"
%define parser_class_name "BisonParser"
%parse-param { Program **program } //int momentaneo, clase por crear 
%parse-param { Xplode::FlexScanner &scanner }
%lex-param   { Xplode::FlexScanner &scanner }
%union {
  Token *tok;
  Node *node; //Node from the AST
  NodeList *nodelist;
  Variable *var;
  Parameter *par;
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
	#include "AST/AssignStatement.h"
  #include "AST/BinaryExpression.h"
  #include "AST/Block.h"
  #include "AST/BreakStatement.h"
  #include "AST/CompoundStatement.h"
  #include "AST/Constant.h"
  #include "AST/ContinueStatement.h"
  #include "AST/Declaration.h"
  #include "AST/Expression.h"
  #include "AST/Error.h"
  #include "AST/ExitStatement.h"
  #include "AST/Extends.h"
  #include "AST/ForStatement.h"
  #include "AST/Function.h"
  #include "AST/FunctionExpression.h"
  #include "AST/FunctionParameter.h"
  #include "AST/FunctionStatement.h"
  #include "AST/IfStatement.h"
  #include "AST/Program.h"
  #include "AST/Node.h"
  #include "AST/NodeList.h"
  #include "AST/Parameter.h"
  #include "AST/Procedure.h"
  #include "AST/ProcedureType.h"
  #include "AST/ReadStatement.h"
  #include "AST/ReturnStatement.h"
  #include "AST/SleepStatement.h"
  #include "AST/Statement.h"
  #include "AST/TypeDeclaration.h"
  #include "AST/TypeStructure.h"
  #include "AST/UnaryExpression.h"
  #include "AST/UnaryOp.h"
  #include "AST/Union.h"
  #include "AST/Variable.h"
  #include "AST/WhileStatement.h"
  #include "AST/WriteStatement.h"
  #include "Symbol.h"
  #include "SymTable.h"
  #include "ErrorLog.h"	
  
}

%code {
	// Prototype for the yylex function
	static int yylex(Xplode::BisonParser::semantic_type * yylval, Xplode::FlexScanner &scanner);
}

%token<tok> INTEGER
%token<tok> FLOAT
%token<tok> STRING
%token<tok> CHAR

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
%token<tok> x_VAR

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

%token<tok> x_LET


//Precedence and associativity
%nonassoc x_EQ x_NEQ
%nonassoc x_LESS x_LESSEQ x_GREATER x_GREATEREQ
%left x_AND x_OR
%left x_NOT
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
%type <node> declaration
%type <node> statement 
%type <node> statement_assign statement_sleep 
%type <node> statement_read statement_write
%type <node> statement_while statement_for
%type <node> statement_if statement_else
%type <node> statement_return statement_exit
%type <node> statement_break statement_continue
%type <node> statement_function
%type <node> for_init for_increment

%type <node> block
%type <node> main
%type <node> start

%type <par> parameter

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
%type <node> primitive_type param_type type
%type <node> function_type 

%%

// Grammar for classic version
start
  : x_PROGRAM main { *program = new Program($2);  }
  | x_PROGRAM definition_list main { *program = new Program($2,$3); }
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
  | definition_list error {
    errorlog->addError(14,0,0,NULL);
    $1->add(new Statement());
    $$ = $1;
  }
  ;
  
definition
  : def_union { $$ = $1; }
  | def_proc x_SEMICOLON { $$ = $1; }
  | def_type { $$ = $1; }
  | def_function {$$ = $1; }
  | declaration x_SEMICOLON {$$ = $1; }
  | error x_SEMICOLON { yyerrok; yyclearin; $$ = new Statement(); }
  | error x_LBRACE attribute_list x_RBRACE  {  yyerrok; yyclearin; $$ = new Statement(); }
  ;

def_union
  : x_UNION x_ID x_LBRACE attribute_list x_RBRACE { 
    $$ = new Union($2, $4);
  }
  ;

def_type 
  :  x_TYPE x_ID x_LBRACE attribute_list x_RBRACE { 
    $$ = new TypeStructure($2, $4);
  }
  ; 

attribute_list
  : type x_ID x_SEMICOLON {  //puede mejorarse
    $$ = new NodeList();
    $$->push(new Declaration($1, $2));  
  }
  | error x_SEMICOLON { $$ = new NodeList(); }
  | error x_RBRACE { $$ = new NodeList(); }
  | attribute_list type x_ID x_SEMICOLON {
    $1->push(new Declaration($2, $3));
    $$ = $1;
  }
  ;

//Used for second class functions
def_proc
  : x_PROC function_type x_ID x_LPAR proc_type_list x_RPAR {
    $$ = new Procedure($3, $2, $5);
  }
  ;

proc_type_list
  : type {
    $$ = new NodeList();
    $$->add(new ProcedureType($1));
  }
  | error type { $$ = new NodeList(); }
  | proc_type_list x_COMMA type { 
    $1->add(new ProcedureType($3));
    $$ = $1;
  }   
  ;

def_function  
  : x_FUNCTION function_type x_ID x_LPAR x_RPAR block {
    $$ = new Function($3, $2, $6);
  }
  | x_FUNCTION function_type x_ID x_LPAR function_parameters x_RPAR block {
    $$ = new Function($3, $2, $7, $5);
  }
  ;

function_type
  : primitive_type {$$ = $1; }
  | x_VOID {$$ = new TypeDeclaration($1->value); }
  ;
  
function_parameters 
  : parameter {
    $$ = new NodeList();
    $$->push($1); 
  }
  | error  { $$ = new NodeList(); }
  | parameter x_COMMA x_EXTEND {
    $$ = new NodeList();
    $$->push(new Extends($1->ntype));
    $$->push($1);
    
  }
  | parameter x_COMMA function_parameters {
    $3->push($1);
    $$ = $3;  
  }
  ;

parameter
  : param_type x_ID {$$ = new Parameter($1,$2);} 
  | x_VAR param_type x_ID {$$ = new Parameter($2,$3,"ref");} 
  ;

param_type 
  : primitive_type {$$ = $1; }
  | x_ID {$$ = new TypeDeclaration($1->value); }
  | param_type x_LBRACKET x_RBRACKET {      
     TypeDeclaration *tp = (TypeDeclaration *) $1; 
     tp->addDimension("-1"); //NO TIENE VALOR POR AHORA
     $$ = tp;
   } 
  ;
  
primitive_type
  :  x_INT {$$ = new TypeDeclaration($1->value); }
  | x_CHAR {$$ = new TypeDeclaration($1->value); } 
  | x_BOOL {$$ = new TypeDeclaration($1->value); } 
  | x_FLOAT {$$ = new TypeDeclaration($1->value); }
  ;

type 
  : primitive_type {$$ = $1; }
  | x_ID {$$ = new TypeDeclaration($1->value); }
  | type x_LBRACKET INTEGER x_RBRACKET { 
    TypeDeclaration *tp = (TypeDeclaration *) $1; 
     tp->addDimension($3->value);
     $$ = tp;
    }
  ;     


block  
  : x_LBRACE declaration_list statement_list x_RBRACE {$$ = new Block($2,$3); }
  | x_LBRACE statement_list x_RBRACE {$$ = new Block($2); }
  ;

declaration
  : x_LET type x_ID { $$ = new Declaration($2, $3);  } 
  ;

declaration_list
  : declaration x_SEMICOLON { 
    $$ = new NodeList();
    $$->add($1);  
  }
  | declaration  { 
    errorlog->addError(14,$1->line,$1->column,NULL);
    $$ = new NodeList();
    $$->add($1);  
  }
  | declaration_list declaration x_SEMICOLON {
    $1->add($2);
    $$ = $1;
  }
  | declaration_list declaration  {
    errorlog->addError(14,0,0,NULL);
    $1->add($2);
    $$ = $1;
  }
  ;
  
statement_list
  : statement x_SEMICOLON {$$ = new NodeList(); $$->add($1); }
  | error x_SEMICOLON { yyclearin; $$ = new NodeList(); }
  | statement_list statement x_SEMICOLON {$1->add($2); $$ = $1; }
  | statement_list statement {errorlog->addError(14,0,0,NULL); $1->add($2); $$ = $1; }
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
  | statement_function {$$ = $1; }
  | statement_break {$$ = $1; }
  | statement_continue {$$ = $1; }
  | statement_return {$$ = $1; }
  | statement_exit{$$ = $1; }
  ;

statement_for
  : x_FOR x_LPAR for_init x_SEMICOLON for_condition x_SEMICOLON for_increment x_RPAR block{
    $$ = new ForStatement($3,$5,$7,$9);
  }
  | x_FOR error block { yyclearin; $$ = new Statement(); }
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
  | x_WHILE error block {  yyclearin; $$ = new Statement(); }
  ;

while_condition
  : expression {$$ = $1; }
  ;

statement_if
  : x_IF x_LPAR if_condition x_RPAR block {$$ = new IfStatement($3,$5); }
  | x_IF x_LPAR if_condition x_RPAR block statement_else {$$ = new IfStatement($3,$5,$6); }
  | x_IF error block { yyclearin; $$ = new Statement(); }
  ;
  
if_condition
  : expression {$$ = $1; }
  ;
  
statement_else
  : x_ELSE block {$$ = $2; }
  ;

statement_assign
  : variable x_ASSIGN expression {$$ = new AssignStatement($1,$3); }
  | variable error { yyclearin; std::cout << "Maybe you meant to use \':=\'.\n"; $$ = new Statement(); }
  ;
  
statement_read
  : x_READ x_LPAR variable x_RPAR {$$ = new ReadStatement($3); }
  ;
  
statement_write
  : x_WRITE x_LPAR write_list x_RPAR {$$ = new WriteStatement($3); }
  ;

write_list
  : expression {$$ = new std::list<Expression *>(); $$->push_back($1);} 
  | write_list x_COMMA expression {$$ = $1; $$->push_back($3); }
  ;
 
statement_sleep
  : x_SLEEP x_LPAR variable x_RPAR {$$ = new SleepStatement($3); }
  ;    

statement_function
  : function {$$ = new FunctionStatement($1); }
  ;
  
statement_break
  : x_BREAK {$$ = new BreakStatement(); }
  ;
   
statement_continue
  : x_CONTINUE {$$ = new ContinueStatement();}
  ;

statement_return
  : x_RETURN expression {$$ = new ReturnStatement($2); }
  ;

statement_exit
  : x_EXIT x_LPAR x_RPAR {$$ =  new ExitStatement(); }
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
  | x_MINUS expression %prec x_UMINUS { $$ = new UnaryOp($1->value,$2); }
  | x_NOT expression { $$ = new UnaryOp($1->value,$2); }
  | x_LPAR expression x_RPAR { $$ = new UnaryExpression($2); }
  ;
 
constant
  : INTEGER { $$ = new Constant($1->value);}
  | FLOAT { $$ = new Constant($1->value);}
  | STRING { $$ = new Constant($1->value);}
  | CHAR { $$ = new Constant($1->value);}  
  | x_TRUE { $$ = new Constant($1->value);}
  | x_FALSE { $$ = new Constant($1->value);}
  ;
  
variable
  : variable_id {$$ = $1; }
  | variable x_DOT variable_id { $1->concat($3); $$=$1;  }
  ;

variable_id
  : x_ID {$$ = new Variable($1); }
  | variable_id x_LBRACKET expression x_RBRACKET { $1->addIndex($3); $$=$1; }
  ;

function
  : x_ID x_LPAR function_arguments x_RPAR {$$ = new FunctionExpression($1->value,$3); }
  | x_ID x_LPAR x_RPAR {$$ = new FunctionExpression($1->value); }
  ;

function_arguments
  : expression {$$ = new std::list<Expression *>(); $$->push_back($1); }
  | function_arguments x_COMMA expression {$$ = $1; $$->push_back($3); }
  ;
  
%%

// We have to implement the error function

extern int line,column;  
extern std::string tok;
extern ErrorLog *errorlog;
 
void Xplode::BisonParser::error(const Xplode::BisonParser::location_type &loc, const std::string &msg) {

  errorlog->addError(2,line,column,&tok);


}

// Now that we have the Parser declared, we can declare the Scanner and implement
// the yylex function
#include "XplodeScanner.h"
static int yylex(Xplode::BisonParser::semantic_type * yylval, Xplode::FlexScanner &scanner) {
	return scanner.yylex(yylval);
}
