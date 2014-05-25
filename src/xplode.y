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
  DeclarationMult *decl; //modificar
}

%code requires {
	// Forward-declare the Scanner class; the Parser needs to be assigned a 
	// Scanner, but the Scanner can't be declared without the Parser
	namespace Xplode {
		class FlexScanner;
	}
	#include <stdio.h>
	#include <stack>
	#include "Token.h"
	#include "AST/AssignStatement.h"
  #include "AST/BinaryExpression.h"
  #include "AST/Block.h"
  #include "AST/BreakStatement.h"
  #include "AST/CastedExpression.h"
  #include "AST/CompoundStatement.h"
  #include "AST/Constant.h"
  #include "AST/ContinueStatement.h"
  #include "AST/Declaration.h"
  #include "AST/DeclarationMult.h"
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
  #include "AST/ArrayType.h"  
  #include "AST/TupleType.h"  
  #include "AST/FunctionType.h"      
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
  
  extern int line,column;  
  extern std::string tok;
  extern ErrorLog *errorlog;

  
  
}

%code {
	// Prototype for the yylex function
	static int yylex(Xplode::BisonParser::semantic_type * yylval, Xplode::FlexScanner &scanner);
	Node *decTypeNode;
	SymTable *actual, *root;
	std::stack<SymTable *> pila;
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

%token<tok> x_TYPE
%token<tok> x_UNION

//Type casting
%token<tok> x_CTOI
%token<tok> x_ITOC
%token<tok> x_ITOF
%token<tok> x_FTOI

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
%token<tok> x_POWER

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
%type <decl> declaration
%type <node> declaration_type
%type <decl> declaration_id_list
//%type <node> declaration_mult
%type <node> statement
%type <node> statement_simple
%type <node> statement_compound
%type <node> statement_assign statement_sleep 
%type <node> statement_read statement_write
%type <node> statement_while statement_for
%type <node> statement_if statement_else
%type <node> statement_return statement_exit
%type <node> statement_break statement_continue
%type <node> statement_function
%type <node> for_init for_increment

%type <node> block
%type <node> init_block
%type <node> main
%type <node> start
%type <node> init

//expressions

%type <var> variable
%type <var> variable_id
%type <exp> constant
%type <exp> expression expression_unary function
%type <exp> expression_cast
%type <explist> function_arguments write_list
%type <exp> while_condition for_condition if_condition


%type <nodelist> definition_list
%type <nodelist> declaration_list
%type <node> attribute_list
%type <node> proc_type_list
%type <node> function_parameters
%type <node> function_pars
%type <nodelist> statement_list 





//
%type <node> primitive_type param_type type
%type <node> function_type 

%%

// Grammar for classic version
start
  : init x_PROGRAM main { 
   
    *program = new Program(actual, $3);  
  }
  | init x_PROGRAM definition_list main { 
  
    *program = new Program(actual, $3, $4); 
  }
  | init main { 
  
    errorlog->addError(17,1,1,NULL); 
    *program = new Program(actual, $2);  
  }
  | init definition_list main { 
  
    errorlog->addError(17,1,1,NULL); 
    *program = new Program(actual, $2, $3); 
  }
  ;
  
init: {    

    //std::cout <<"INITTTTT\n";
    root = new SymTable();
    actual = root; 
    pila.push(actual);
    root->insert(INT_SYMBOL, NO_SAVE_SIZE);    
    root->insert(FLOAT_SYMBOL, NO_SAVE_SIZE);    
    root->insert(CHAR_SYMBOL, NO_SAVE_SIZE);        
    root->insert(BOOL_SYMBOL, NO_SAVE_SIZE); 
    root->insert(STRING_SYMBOL, NO_SAVE_SIZE);    
    root->insert(VOID_SYMBOL, NO_SAVE_SIZE);    
    root->insert(ERROR_SYMBOL, NO_SAVE_SIZE);    
            
   }
   ;  

main
  : init_block x_BEGIN statement_list x_END { 
    $$ = new Block(actual, $3);
    pila.pop();
    actual = pila.top();
     
  } 
  | init_block x_BEGIN declaration_list statement_list x_END {
    $$ = new Block(actual, $3, $4);
    pila.pop();
    actual = pila.top();
  }
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
    errorlog->addError(14,line,column,NULL);
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
    TupleType *t = (TupleType *) $4;
    t->make_union();
    root->insert(t->toSymbol($2), NO_SAVE_SIZE);    
    //root->print();    
    $$ = new Union($2, $4);
  }
  ;

def_type 
  :  x_TYPE x_ID x_LBRACE attribute_list x_RBRACE {
    TupleType *t = (TupleType *) $4;
    t->make_type();    
    root->insert(t->toSymbol($2), NO_SAVE_SIZE);
    //root->print();
    $$ = new TypeStructure($2, $4);
  }
  ; 

attribute_list
  : type x_ID x_SEMICOLON {  //puede mejorarse
    TupleType *t = new TupleType();
    t->add($1, $2->value);
    $$ = t;  
  }
  | error x_SEMICOLON { $$ = new TupleType(); }
  | error x_RBRACE { $$ = new TupleType(); }
  | attribute_list type x_ID x_SEMICOLON {
    TupleType *t = (TupleType *) $1;
    t->add($2, $3->value);
    $$ = t;
  }
  ;

//Used for second class functions
def_proc
  : x_PROC function_type x_ID x_LPAR proc_type_list x_RPAR {
    TupleType *t = (TupleType *) $5;
    root->insert(t->toSymbol($3), NO_SAVE_SIZE);
    //root->print();    
    $$ = new Procedure($3, $2, $5);
  }
  ;

proc_type_list
  : type {
    TupleType *t;
    t = new TupleType();
    t->addType($1);
    $$ = t;
  }
  | error type { $$ = new TupleType(); }
  | proc_type_list x_COMMA type { 
    TupleType *t = (TupleType *) $1;  
    t->addType($3);
    $$ = t;
  }   
  ;

def_function  
  : x_FUNCTION function_type x_ID x_LPAR x_RPAR  block {
    FunctionType *f = new FunctionType($2,new TupleType());
    root->insert(f->toSymbol($3), NO_SAVE_SIZE);   
    $$ = new Function($3, $2, $6);
  }
  | x_FUNCTION function_type x_ID x_LPAR function_parameters x_RPAR block {
    FunctionType *f = new FunctionType($2,$5);
    root->insert(f->toSymbol($3), NO_SAVE_SIZE);    
    $$ = new Function($3, $2, $7, $5);
  }
  ;
  

function_type
  : primitive_type {$$ = $1; }
  | x_VOID {$$ = root->find("_void")->ntype; }
  ;
  
function_parameters 
  : function_pars param_type x_ID x_COMMA x_EXTEND { 
  
    TupleType *t = (TupleType *) $1;
    t->add($2,$3->value);
    $$ = t;
  }
    
  | function_pars x_VAR param_type x_ID x_COMMA x_EXTEND { 
  
    TupleType *t = (TupleType *) $1;
    t->add($3,$4->value);
    $$ = t;
  
  }

  | function_pars param_type x_ID { 
  
    TupleType *t = (TupleType *) $1;
    t->add($2,$3->value);
    $$ = t;
  
  }

  | function_pars x_VAR param_type x_ID { 
  
    TupleType *t = (TupleType *) $1;
    t->add($3,$4->value);
    $$ = t;
  
  }

  | param_type x_ID { 
  
    TupleType *t = new TupleType();
    t->add($1,$2->value);
    $$ = t;
  
  }
  
  | x_VAR param_type x_ID { 
  
    TupleType *t = new TupleType();
    t->add($2,$3->value);
    $$ = t;
  
  }
  
  
  ;
  
function_pars
  : param_type x_ID x_COMMA { 
    TupleType *t = new TupleType(); 
    t->add($1,$2->value);
    $$ = t;
    }
  | x_VAR param_type x_ID x_COMMA { 
  
    TupleType *t = new TupleType(); 
    t->add($2,$3->value);
    $$ = t;
    } //falta var
    
  | function_pars param_type x_ID x_COMMA { 
  
    TupleType *t = (TupleType *) $1;
    t->add($2,$3->value);
    $$ = t;
  
  }
  | function_pars x_VAR param_type x_ID x_COMMA { 
  
    TupleType *t = (TupleType *) $1;
    t->add($3,$4->value);
    $$ = t;
  
  } //falta var
  | error  { $$ = new TupleType(); }
  ;
  

param_type 
  : primitive_type {$$ = $1; }
  | x_ID {
  
      Symbol *s = root->find($1->value);
      if(s)
        $$ = s->ntype;
  
  }
  | param_type x_LBRACKET x_RBRACKET {      
     $$ = new ArrayType($1,-1);
   } 
  ;
  
primitive_type
  :  x_INT {$$ = root->find("_int")->ntype; }
  | x_CHAR {$$ = root->find("_char")->ntype; } 
  | x_BOOL {$$ = root->find("_bool")->ntype; } 
  | x_FLOAT {$$ = root->find("_float")->ntype; }
  ;

type 
  : primitive_type {$$ = $1; }
  | x_ID {
      Symbol *s = root->find($1->value);
      if(s)
        $$ = s->ntype;
    }
  | type x_LBRACKET INTEGER x_RBRACKET { 
     $$ = new ArrayType($1,atoi($3->value.c_str()));
    }
  ;     


block  
  : init_block x_LBRACE declaration_list statement_list x_RBRACE {
    $$ = new Block(actual,$3,$4); 
    int aux = actual->totaloffset;
    pila.pop();
    actual = pila.top();
    if (actual!=root) actual->totaloffset = aux;
  }
  | init_block x_LBRACE statement_list x_RBRACE {
  
    $$ = new Block(actual, $3); 
    int aux = actual->totaloffset;
    pila.pop();
    actual = pila.top();
    if (actual!=root) actual->totaloffset = aux;
  }
  | init_block declaration_list statement_list x_RBRACE { 
    errorlog->addError(16,line,column,NULL); 
    $$ = new Block(actual,$2,$3); 
    int aux = actual->totaloffset;
    pila.pop();
    actual = pila.top();
    if (actual!=root) actual->totaloffset = aux;  
  }
  | init_block statement_list x_RBRACE { 
    $$ = new Block(actual,$2);
    int aux = actual->totaloffset;
    pila.pop();
    actual = pila.top();
    if (actual!=root) actual->totaloffset = aux; 
    errorlog->addError(16,line,column,NULL); 

  }
  ;

init_block 
  : {  
  
    SymTable *aux = new SymTable();
    aux->setFather(actual);
    aux->totaloffset = (actual==root)?0:actual->totaloffset;
    actual = aux;
    pila.push(actual);
  }
  ;


//declaration
//  : x_LET declaration_type x_ID { $$ = new Declaration(decTypeNode, $3);  } 
//  ;


declaration_type
  : type { decTypeNode = $1; $$ =  $1; }  
  ;

declaration
  : x_LET declaration_type declaration_id_list { $$ = $3;  } 
  ;
  

declaration_id_list
  : x_ID {
    
    $$ = new DeclarationMult(decTypeNode); 
    $$->add($1); 
    actual->insert(new Symbol($1->value,(TypeDeclaration *) decTypeNode,$1->line,$1->column));
    //actual->print();
  } 
  | declaration_id_list x_COMMA x_ID {
    $$ = $1; 
    $$->add($3);
    actual->insert(new Symbol($3->value,(TypeDeclaration *) decTypeNode,$3->line,$3->column));
    //actual->print();
  }
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
    errorlog->addError(14,line,column,NULL);
    $1->add($2);
    $$ = $1;
  }
  ;
  
statement_list
  : statement x_SEMICOLON {$$ = new NodeList(); $$->add($1); }
  | statement_simple  {errorlog->addError(14,line,column,NULL); $$ = new NodeList(); $$->add($1); }
  | statement_compound {$$ = new NodeList(); $$->add($1); }
  | error x_SEMICOLON { yyclearin; $$ = new NodeList(); }
  | error { yyclearin; $$ = new NodeList(); }
  | statement_list statement x_SEMICOLON {$1->add($2); $$ = $1; }
  | statement_list statement_simple {errorlog->addError(14,line,column,NULL); $1->add($2); $$ = $1; }
  | statement_list statement_compound {$1->add($2); $$ = $1; }
  ;


statement
  : statement_simple {$$ = $1; }
  | statement_compound {$$ = $1; }
  ;

//statements
statement_simple
  : statement_assign {$$ = $1; }
  | statement_read {$$ = $1; }
  | statement_write {$$ = $1; }
  | statement_sleep {$$ = $1; }
  | statement_function {$$ = $1; }
  | statement_break {$$ = $1; }
  | statement_continue {$$ = $1; }
  | statement_return {$$ = $1; }
  | statement_exit{$$ = $1; }
  ;

statement_compound
  : statement_for {$$ = $1; }
  | statement_while {$$ = $1; }
  | statement_if {$$ = $1; }
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
  : variable x_ASSIGN expression {
  
      $$ = new AssignStatement($1,$3); 
  }
  | variable error { yyclearin; errorlog->addError(18,line,column,NULL); $$ = new Statement(); }
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
  : x_SLEEP x_LPAR expression x_RPAR {$$ = new SleepStatement($3); }
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
  | expression x_PLUS expression {
      
    /*  if(!$1->ntype->isnumeric() || !$3->ntype->isnumeric()){
      
      //error tipos invalidos
      
      } else {
      
        if($1->ntype==$3->ntype){
        
        
        
        } else {
        
        
        }
        
      }
      
      
      */
      
      $$ = new BinaryExpression($2->value,$1,$3); 
      
  }
  | expression x_MINUS expression {
    $$ = new BinaryExpression($2->value,$1,$3); 
  }
  | expression x_MULT expression {
      $$ = new BinaryExpression($2->value,$1,$3); 
  }
  | expression x_DIV expression {
      $$ = new BinaryExpression($2->value,$1,$3); 
  }
  | expression x_POWER expression {
      $$ = new BinaryExpression($2->value,$1,$3); 
  }

  | expression x_AND expression {
    $$ = new BinaryExpression($2->value,$1,$3); 
  }
  | expression x_OR expression {
    $$ = new BinaryExpression($2->value,$1,$3); 
  }  
  | expression x_LESS expression {
    $$ = new BinaryExpression($2->value,$1,$3); 
  }
  | expression x_LESSEQ expression {
    $$ = new BinaryExpression($2->value,$1,$3); 
  }
  | expression x_GREATER expression {
    $$ = new BinaryExpression($2->value,$1,$3); 
  }
  | expression x_GREATEREQ expression {
      $$ = new BinaryExpression($2->value,$1,$3);
  }
  
  | expression x_EQ expression {
    $$ = new BinaryExpression($2->value,$1,$3); 
  }
  | expression x_NEQ expression {
    $$ = new BinaryExpression($2->value,$1,$3); 
  }
  ;

expression_unary
  : constant { $$ = $1; }
  | variable { $$ = $1; }
  | function { $$ = $1; }
  | expression_cast {$$ = $1; }
  | x_MINUS expression %prec x_UMINUS { 
      $$ = new UnaryOp($1->value,$2); 
  }
  | x_NOT expression { 
      $$ = new UnaryOp($1->value,$2); 
  }
  | x_LPAR expression x_RPAR { $$ = $2;}
  ;
 
expression_cast
  : x_CTOI x_LPAR expression x_RPAR {$$ = new CastedExpression($1->value,$3); }
  | x_ITOC x_LPAR expression x_RPAR {$$ = new CastedExpression($1->value,$3); }
  | x_ITOF x_LPAR expression x_RPAR {$$ = new CastedExpression($1->value,$3); }
  | x_FTOI x_LPAR expression x_RPAR {$$ = new CastedExpression($1->value,$3); }
  ;
 
constant
  : INTEGER { $$ = new Constant($1->value,root->find("_int")->ntype);}
  | FLOAT { $$ = new Constant($1->value, root->find("_float")->ntype);}
  | STRING { 
  
      char id[20];
      sprintf(id, "%d_%d", $1->line, $1->column);
      $$ = new Constant($1->value,root->find("_string")->ntype);
      root->insertString(new Symbol(std::string("_str"+std::string(id)),root->find("_string")->ntype, line, column),
      $1->value.size());
  } 
  | CHAR { $$ = new Constant($1->value,root->find("_char")->ntype);}  
  | x_TRUE { $$ = new Constant($1->value,root->find("_bool")->ntype);}
  | x_FALSE { $$ = new Constant($1->value, root->find("_bool")->ntype);}
  ;
  
variable
  : variable_id {
      Variable *v = (Variable *) $1;
      Symbol *s = actual->find((*v->varList->begin())->value);
      if(!s){
      //error
      } else {
      
          std::list<std::pair<int, Expression *> >::iterator it;
          //verificar indices enteros, # parametros
          for(it=v->indexList->begin(); it!=v->indexList->end();++it){
          
          //indices
          
          
          }
      
      
      }
      $$ = $1; 
   }
  | variable x_DOT variable_id { 
      //buscar el tipo de variable, verificar tipo del union o type
      Variable *v  = (Variable *) $1;
      TypeDeclaration *t = v->ntype;
      $1->concat($3); 
      $$=$1;  
  }
  ;

variable_id
  : x_ID {
      $$ = new Variable($1); 
  }
  | variable_id x_LBRACKET expression x_RBRACKET { 
      $1->addIndex($3); 
      $$=$1; 
  }
  ;

function
  : x_ID x_LPAR function_arguments x_RPAR {
  
      Symbol *s = actual->find($1->value);
      if(!s){
      //ERROR no existe el simbolo
      }
      else {
      
        if(!s->ntype->isfunction()){
        
        //error
        } else {
        
        std::list<Expression *>::iterator it;
        std::list< std::pair<TypeDeclaration*, int>* >::iterator it2;
        
        
        }
      
      }
      $$ = new FunctionExpression($1->value,$3); 
  }
  | x_ID x_LPAR x_RPAR {$$ = new FunctionExpression($1->value); }
  ;

function_arguments
  : expression {$$ = new std::list<Expression *>(); $$->push_back($1); }
  | function_arguments x_COMMA expression {$$ = $1; $$->push_back($3); }
  ;
  
%%

// We have to implement the error function
 
void Xplode::BisonParser::error(const Xplode::BisonParser::location_type &loc, const std::string &msg) {

  errorlog->addError(2,line,column-tok.length(),&tok);


}

// Now that we have the Parser declared, we can declare the Scanner and implement
// the yylex function
#include "XplodeScanner.h"
static int yylex(Xplode::BisonParser::semantic_type * yylval, Xplode::FlexScanner &scanner) {
	return scanner.yylex(yylval);
}
