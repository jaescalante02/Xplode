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
	#include <string>
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
  //#include "AST/FunctionParameter.h"
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
  #include "AST/StringType.h"  
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
	int inBlock = 0;
	bool inFunction = false;
	bool argument_table = false;
	FunctionType *actualfun;
	std::string name;
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
%right x_POWER
%left	x_UMINUS


//Types for non-terminals

%type <node> definition
%type <node> def_union
%type <node> def_type
%type <node> def_proc
%type <node> def_function
%type <node> declared_function
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
%type <exp> printable
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
    FunctionType *f = new FunctionType((TypeDeclaration *) $2, t, NULL);
    Symbol *s = f->toSymbol($3);
    s->istype = true;
    s->hidden = true;
    if(t->havefunction()) errorlog->addError(19,s->line,s->column,NULL); 
    root->insert(s, NO_SAVE_SIZE);
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
  : init_block x_FUNCTION declared_function block {

    $$ = new Function(actual, name, $3, $4); 
    $$->line= $2->line;
    $$->column= $2->column;  
    pila.pop();
    actual = pila.top();
    inFunction = false;
    
  }
  ;
  
declared_function
    : function_type x_ID x_LPAR function_parameters x_RPAR {
    
        name = $2->value;
        TupleType *t = (TupleType *) $4;
        FunctionType *f = new FunctionType($1,$4,t->extend);
        actualfun = f;
        $$ = f;
        root->insert(f->toSymbol($2), NO_SAVE_SIZE);
        inFunction = true;
        argument_table = true;
    
    
    
    }
    | function_type x_ID x_LPAR x_RPAR {
   
          FunctionType *f = new FunctionType($1,new TupleType(),NULL);
          actualfun = f;
          $$ = f;
          root->insert(f->toSymbol($2), NO_SAVE_SIZE); 
    
    }
    ;
  
function_type
  : primitive_type {$$ = $1; }
  | x_VOID {$$ = root->findType("_void")->ntype; }
  ;
  
function_parameters 
  : function_pars param_type x_ID x_COMMA x_EXTEND { 
  
    TupleType *t = (TupleType *) $1;
    TypeDeclaration *t2 = (TypeDeclaration *) $2;
    if(!t2->isprimitive()) errorlog->addError(20,$3->line,$3->column,NULL); 
    t->add($2,$3->value);
    actual->insert(new Symbol(false,$3->value,(TypeDeclaration *) $2,$3->line,$3->column,false));
    actual->insert(new Symbol(false,"_extend",root->findType("_int")->ntype,$5->line,$5->column,false));    
    t->extend = (TypeDeclaration *) $2;
    $$ = t;
  }
    
  | function_pars x_VAR param_type x_ID x_COMMA x_EXTEND { 
  
    TupleType *t = (TupleType *) $1;
    t->add($3,$4->value);
    actual->insert(new Symbol(false,$4->value,(TypeDeclaration *) $3,$4->line,$4->column,false)); 
    actual->insert(new Symbol(false,"_extend",root->findType("_int")->ntype,$5->line,$5->column,false));           
    t->extend = (TypeDeclaration *) $3;
    $$ = t;
  
  }

  | function_pars param_type x_ID { 
  
    TupleType *t = (TupleType *) $1;
    TypeDeclaration *t2 = (TypeDeclaration *)$2;
    if(!t2->isprimitive()) errorlog->addError(20,$3->line,$3->column,NULL); 
    t->add($2,$3->value);
    actual->insert(new Symbol(false,$3->value,(TypeDeclaration *) $2,$3->line,$3->column,false));
    $$ = t;
  
  }

  | function_pars x_VAR param_type x_ID { 
  
    TupleType *t = (TupleType *) $1;
    t->add($3,$4->value);
    actual->insert(new Symbol(false,$4->value,(TypeDeclaration *) $3,$4->line,$4->column,false, true));
    $$ = t;
  
  }

  | param_type x_ID { 
  
    TypeDeclaration *t2 = (TypeDeclaration *)$1;
    if(!t2->isprimitive()) errorlog->addError(20,$2->line,$2->column,NULL); 
    TupleType *t = new TupleType();
    t->add($1,$2->value);
    actual->insert(new Symbol(false,$2->value,(TypeDeclaration *) $1,$2->line,$2->column,false));
    $$ = t;
  
  }
  
  | x_VAR param_type x_ID { 
  
    TupleType *t = new TupleType();
    t->add($2,$3->value);
    actual->insert(new Symbol(false,$3->value,(TypeDeclaration *) $2,$3->line,$3->column,false, true));
    $$ = t;
  
  }  
  ;
  
function_pars
  : param_type x_ID x_COMMA { 
    TupleType *t = new TupleType();
    TypeDeclaration *t2 = (TypeDeclaration *)$1;
    if(!t2->isprimitive()) errorlog->addError(20,$2->line,$2->column,NULL);  
    t->add($1,$2->value);
    actual->insert(new Symbol(false,$2->value,(TypeDeclaration *) $1,$2->line,$2->column,false));
    $$ = t;
    }
  | x_VAR param_type x_ID x_COMMA { 
  
    TupleType *t = new TupleType(); 
    t->add($2,$3->value);
    actual->insert(new Symbol(false,$3->value,(TypeDeclaration *) $2,$3->line,$3->column, false, true));    
    $$ = t;
    } //falta var
    
  | function_pars param_type x_ID x_COMMA { 
  
    TupleType *t = (TupleType *) $1;
    TypeDeclaration *t2 = (TypeDeclaration *)$2;
    if(!t2->isprimitive()) errorlog->addError(20,$3->line,$3->column,NULL); 
    actual->insert(new Symbol(false,$3->value,(TypeDeclaration *) $2,$3->line,$3->column,false));    
    t->add($2,$3->value);
    $$ = t;
  
  }
  | function_pars x_VAR param_type x_ID x_COMMA { 
  
    TupleType *t = (TupleType *) $1;
    t->add($3,$4->value);
    actual->insert(new Symbol(false,$4->value,(TypeDeclaration *) $3,$4->line,$4->column,false, true));    
    $$ = t;
  
  } //falta var
  | error  { $$ = new TupleType(); }
  ;
  

param_type 
  : primitive_type {$$ = $1; }
  | x_ID {
  
      Symbol *s = root->findType($1->value);
      if(s)
        $$ = s->ntype;
  
  }
  | param_type x_LBRACKET x_RBRACKET {      
     $$ = new ArrayType($1,-1);
   } 
  ;
  
primitive_type
  :  x_INT {$$ = root->findType("_int")->ntype; }
  | x_CHAR {$$ = root->findType("_char")->ntype; } 
  | x_BOOL {$$ = root->findType("_bool")->ntype; } 
  | x_FLOAT {$$ = root->findType("_float")->ntype; }
  ;

type 
  : primitive_type {$$ = $1; }
  | x_ID {
      Symbol *s = root->findType($1->value);
      if(!s) {
        $$ = root->findType("_error")->ntype;
        errorlog->addError(7,$1->line,$1->column,&$1->value);
      }else{
        
        $$ = s->ntype;
      }
        
    }
  | type x_LBRACKET INTEGER x_RBRACKET { 
     $$ = new ArrayType($1,atoi($3->value.c_str()));
    }
  ;     


block  
  : init_block x_LBRACE declaration_list statement_list x_RBRACE {
    $$ = new Block(actual,$3,$4);
    $$->line=$2->line; 
    $$->column=$2->column; 
    int aux = actual->totaloffset;
    pila.pop();
    actual = pila.top();
    if (actual!=root) actual->totaloffset = aux;
  }
  | init_block x_LBRACE statement_list x_RBRACE {
  
    $$ = new Block(actual, $3); 
    $$->line=$2->line; 
    $$->column=$2->column; 
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
    aux->totaloffset = ((actual==root)|| (argument_table))?0:actual->totaloffset;
    argument_table = false;    
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
    actual->insert(new Symbol(false,$1->value,(TypeDeclaration *) decTypeNode,$1->line,$1->column,false));
    //actual->print();
  } 
  | declaration_id_list x_COMMA x_ID {
    $$ = $1; 
    $$->add($3);
    actual->insert(new Symbol(false,$3->value,(TypeDeclaration *) decTypeNode,$3->line,$3->column,false));
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
  //| statement_simple  {errorlog->addError(14,line,column,NULL); $$ = new NodeList(); $$->add($1); }
  | statement_compound {$$ = new NodeList(); $$->add($1); }
  | error x_SEMICOLON { yyclearin; $$ = new NodeList(); }
  | error { yyclearin; $$ = new NodeList(); }
  | statement_list statement x_SEMICOLON {$1->add($2); $$ = $1; }
  //| statement_list statement_simple {errorlog->addError(14,line,column,NULL); $1->add($2); $$ = $1; }
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
  : init_breakable x_FOR x_LPAR for_init x_SEMICOLON for_condition x_SEMICOLON for_increment x_RPAR block {
    
    $$ = new ForStatement($4,$6,$8,$10);
    $$->line= $2->line;
    $$->column= $2->column; 
    inBlock--;
  }
  | init_breakable x_FOR error block { yyclearin; $$ = new Statement(); inBlock--; }
  ;

for_init
  : statement_assign {$$ = $1; }
  ;

for_condition
  : expression {
  
      if($1->ntype->numtype!=TYPE_BOOL){
      
      //error tipos invalidos
        errorlog->addError(21,line,column,NULL);
      
      }
      $$ = $1;
  }
  ;

for_increment
  : statement_assign {$$ = $1; }
  ;

statement_while
  : init_breakable x_WHILE x_LPAR while_condition x_RPAR block 
    {
      $$ = new  WhileStatement($4,$6); 
      $$->line= $2->line;
      $$->column= $2->column;  
      inBlock--;
    }
  | init_breakable x_WHILE error block {  yyclearin; $$ = new Statement(); inBlock--; }
  ;

init_breakable
  : {inBlock++;}
  ;


while_condition
  : expression {
  
      if($1->ntype->numtype!=TYPE_BOOL){
      
      //error tipos invalidos
        errorlog->addError(21,line,column,NULL);
      
      }
  
      $$ = $1; 
  
  }
  ;

statement_if
  : x_IF x_LPAR if_condition x_RPAR block {
      $$ = new IfStatement($3,$5);
      $$->line = $1->line;
      $$->column = $1->column; 
  }
  | x_IF x_LPAR if_condition x_RPAR block statement_else {
      $$ = new IfStatement($3,$5,$6); 
      $$->line = $1->line;
      $$->column = $1->column;    
  }
  | x_IF error block { yyclearin; $$ = new Statement(); }
  ;
  
if_condition
  : expression {
  
      if($1->ntype->numtype!=TYPE_BOOL){
      
      //error tipos invalidos
        errorlog->addError(21,line,column,NULL);
      
      }
  
      $$ = $1; 
  }
  ;
  
statement_else
  : x_ELSE block {$$ = $2; }
  ;

statement_assign
  : variable x_ASSIGN expression {
      //std::cout<<(long)$1->ntype<<' '<<(long)$3->ntype;
      if($1->ntype!=$3->ntype) errorlog->addError(37,$2->line,$2->column,NULL);
      if(!$1->ntype->isprimitive()) errorlog->addError(40,$2->line,$2->column,NULL);
      $$ = new AssignStatement($1,$3); 
      $$->line = $2->line;
      $$->column = $2->column;
      
  }
  | variable error { yyclearin; errorlog->addError(18,line,column,NULL); $$ = new Statement(); }
  ;
  
statement_read
  : x_READ x_LPAR variable x_RPAR {

      if(!($3->ntype->isprimitive())&&!(($3->ntype->isarray())&&($3->ntype->ntype->numtype==TYPE_CHAR))){
      
      //error tipos invalidos
        errorlog->addError(22,$1->line,$1->column,NULL);
      
      } 

    $$ = new ReadStatement($3); 
  }
  ;
  
statement_write
  : x_WRITE x_LPAR write_list x_RPAR {$$ = new WriteStatement($3); }
  ;

write_list
  : printable {

    $$ = new std::list<Expression *>();
    if(!($1->ntype->isprimitive())&&!(($1->ntype->isarray())&&($1->ntype->ntype->numtype==TYPE_CHAR))&&!($1->ntype->numtype==TYPE_STRING)){
      
      //error tipos invalidos
        errorlog->addError(22,line,column,NULL);
      
      } 
    $$->push_back($1);
  } 
  | write_list x_COMMA printable {
  
    $$ = $1; 
    if(!($3->ntype->isprimitive())&&!(($3->ntype->isarray())&&($3->ntype->ntype->numtype==TYPE_CHAR))&&!($3->ntype->numtype==TYPE_STRING)){
      
      //error tipos invalidos
        errorlog->addError(22,line,column,NULL);
      
    }
    
    $$->push_back($3);
  }
  ;

printable
  : expression {$$=$1;}
  | STRING { 
  
      char id[20];
      sprintf(id, "%d_%d", $1->line, $1->column);
      std::string aux("_str"+std::string(id));
      $$ = new StringType(aux, $1->value,root->findType("_string")->ntype);
      root->insertString(new Symbol(true, std::string("_str"+std::string(id)),root->findType("_string")->ntype, $1->line, $1->column, false),
      $1->value.size()-1); //tam(incluye 2 comillas dobles) - 2 + 1 (espacio para el \0)
  } 
  ;
 
statement_sleep
  : x_SLEEP x_LPAR expression x_RPAR {
  
      if($3->ntype->numtype!=TYPE_INT){
      
      //error tipos invalidos
        errorlog->addError(23,$1->line,$1->column,NULL);
      
      }
  
      $$ = new SleepStatement($3);
  }
  ;    

statement_function
  : function {$$ = new FunctionStatement($1); }
  ;
  
statement_break
  : x_BREAK {
    
    if(!inBlock) errorlog->addError(24,$1->line,$1->column,&$1->value);
    $$ = new BreakStatement();
  }
  ;
   
statement_continue
  : x_CONTINUE {
    if(!inBlock) errorlog->addError(24,$1->line,$1->column,&$1->value);
    $$ = new ContinueStatement();
  }
  ;

statement_return
  : 
    x_RETURN {
    
    if(inFunction){
      if(actualfun->returnType->numtype!=TYPE_VOID) 
        errorlog->addError(25,$1->line,$1->column,NULL);
    } else  
        errorlog->addError(26,$1->line,$1->column,NULL);
             
    $$ = new ReturnStatement(NULL);
  }
  | x_RETURN expression {
    
    if(inFunction){
      if(actualfun->returnType!=$2->ntype) 
        errorlog->addError(25,$1->line,$1->column,NULL);
    }else  
        errorlog->addError(26,$1->line,$1->column,NULL);
         
    $$ = new ReturnStatement($2); 
  }
  ;

statement_exit
  : x_EXIT x_LPAR x_RPAR {$$ =  new ExitStatement(); }
  ;

//expressions


expression
  : expression_unary  {$$ = $1;}
  | expression x_PLUS expression {
      
      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isnumeric() || !$3->ntype->isnumeric()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = $1->ntype;
        
        }
        
      }
      
      
      
      
      $$ = new BinaryExpression($2->value,$1,$3); 
      $$->ntype = tp;
      
  }
  | expression x_MINUS expression {
  
      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isnumeric() || !$3->ntype->isnumeric()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = $1->ntype;
        
        }
        
      }
    $$ = new BinaryExpression($2->value,$1,$3); 
    $$->ntype = tp;
  }
  | expression x_MULT expression {
  
      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isnumeric() || !$3->ntype->isnumeric()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = $1->ntype;
        
        }
        
      }  
  
      $$ = new BinaryExpression($2->value,$1,$3); 
      $$->ntype = tp;
  }
  | expression x_DIV expression {

      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isnumeric() || !$3->ntype->isnumeric()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = $1->ntype;
        
        }
        
      }  
      
      $$ = new BinaryExpression($2->value,$1,$3);
      $$->ntype = tp; 
  }
  | expression x_POWER expression {

      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(($1->ntype->numtype!=TYPE_INT)||($3->ntype->numtype!=TYPE_INT)){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = $1->ntype;
        
        }
        
      }
  
      $$ = new BinaryExpression($2->value,$1,$3); 
      $$->ntype = tp; 
  }

  | expression x_AND expression {
  
      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(($1->ntype->numtype!=TYPE_BOOL)||($3->ntype->numtype!=TYPE_BOOL)){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = $1->ntype;
        
        }
        
      }
  
    $$ = new BinaryExpression("AND",$1,$3); 
    $$->ntype = tp; 
  }
  | expression x_OR expression {

      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(($1->ntype->numtype!=TYPE_BOOL)||($3->ntype->numtype!=TYPE_BOOL)){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = $1->ntype;
        
        }
        
      }  
  
    $$ = new BinaryExpression("OR",$1,$3); 
    $$->ntype = tp; 
  }  
  | expression x_LESS expression {
  
      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isnumeric() || !$3->ntype->isnumeric()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = root->findType("_bool")->ntype;
        
        }
        
      }

    $$ = new BinaryExpression($2->value,$1,$3); 
    $$->ntype = tp; 
  }
  | expression x_LESSEQ expression {
  
      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isnumeric() || !$3->ntype->isnumeric()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = root->findType("_bool")->ntype;
        
        }
        
      }  
  
    $$ = new BinaryExpression($2->value,$1,$3); 
    $$->ntype = tp; 
  }
  | expression x_GREATER expression {
  
      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isnumeric() || !$3->ntype->isnumeric()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = root->findType("_bool")->ntype;
        
        }
        
      }  
  
    $$ = new BinaryExpression($2->value,$1,$3); 
    $$->ntype = tp; 
  }
  | expression x_GREATEREQ expression {
  
      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isnumeric() || !$3->ntype->isnumeric()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = root->findType("_bool")->ntype;
        
        }
        
      }  
  
      $$ = new BinaryExpression($2->value,$1,$3);
      $$->ntype = tp; 
  }
  
  | expression x_EQ expression {
 
      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isprimitive() || !$3->ntype->isprimitive()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = root->findType("_bool")->ntype;
        
        }
        
      }  
  
    $$ = new BinaryExpression($2->value,$1,$3); 
    $$->ntype = tp; 
  }
  | expression x_NEQ expression {

      TypeDeclaration *tp = root->findType("_error")->ntype;
      
      if(!$1->ntype->isprimitive() || !$3->ntype->isprimitive()){
      
      //error tipos invalidos
        errorlog->addError(27,$1->line,$1->column,&$2->value);
      
      } else {
      
        if($1->ntype!=$3->ntype){
        
        errorlog->addError(27,$1->line,$1->column,&$2->value);
        
        
        } else {
        
          tp = root->findType("_bool")->ntype;
        
        }
        
      }
  
    $$ = new BinaryExpression($2->value,$1,$3);
    $$->ntype = tp;  
  }
  ;

expression_unary
  : constant { $$ = $1; }
  | variable { $$ = $1; }
  | function { $$ = $1; }
  | expression_cast {$$ = $1; }
  | x_MINUS expression %prec x_UMINUS { 
  
      UnaryOp *u = new UnaryOp($1->value,$2);
      u->ntype= $2->ntype; 
      if(!$2->ntype->isnumeric()){
      
        errorlog->addError(28,$1->line,$1->column,&$1->value);
        u->ntype= root->findType("_error")->ntype; 
      
      }
      
      $$ = u; 
  }
  | x_NOT expression {
   
      UnaryOp *u = new UnaryOp($1->value,$2);
      u->ntype= root->findType("_bool")->ntype; 
      if($2->ntype->numtype!=TYPE_BOOL){
      
        errorlog->addError(28,$1->line,$1->column,&$1->value);
        u->ntype= root->findType("_error")->ntype; 
      
      }
      
      $$ = u;
  }
  | x_LPAR expression x_RPAR { $$ = $2;}
  ;
 
expression_cast
  : x_CTOI x_LPAR expression x_RPAR {
  
  
      if($3->ntype->numtype!=TYPE_CHAR){
      
      //error tipos invalidos
        errorlog->addError(29,$1->line,$1->column,&$1->value);
      
      }
      
      $$ = new CastedExpression("CTOI", $3); 
      $$->ntype = root->findType("_int")->ntype; 
  }
  | x_ITOC x_LPAR expression x_RPAR {
  
  
      if($3->ntype->numtype!=TYPE_INT){
      
      //error tipos invalidos
        errorlog->addError(29,$1->line,$1->column,&$1->value);
      
      }
      
      $$ = new CastedExpression("ITOC", $3); 
      $$->ntype = root->findType("_char")->ntype; 
  }
  | x_ITOF x_LPAR expression x_RPAR {
  
  
      if($3->ntype->numtype!=TYPE_INT){
      
      //error tipos invalidos
        errorlog->addError(29,$1->line,$1->column,&$1->value);
      
      }
      
      $$ = new CastedExpression("ITOF",$3); 
      $$->ntype = root->findType("_float")->ntype; 
  }
  | x_FTOI x_LPAR expression x_RPAR {
  
  
      if($3->ntype->numtype!=TYPE_FLOAT){
      
      //error tipos invalidos
        errorlog->addError(29,$1->line,$1->column,&$1->value);
      
      }
      
      $$ = new CastedExpression("FTOI",$3); 
      $$->ntype = root->findType("_int")->ntype; 
  }
  ;
 
constant
  : INTEGER { $$ = new Constant($1->value,root->findType("_int")->ntype);}
  | FLOAT { $$ = new Constant($1->value, root->findType("_float")->ntype);}
  | CHAR { $$ = new Constant($1->value,root->findType("_char")->ntype);}  
  | x_TRUE { $$ = new Constant("TRUE",root->findType("_bool")->ntype);}
  | x_FALSE { $$ = new Constant("FALSE", root->findType("_bool")->ntype);}
  ;
  
variable
  : variable_id {
      Variable *v = (Variable *) $1;
      Symbol *s = actual->find((*v->varList->begin())->value);
      TypeDeclaration *tp = root->findType("_error")->ntype;;
      if(!s){
      
        errorlog->addError(30,line,column,NULL); //no es variable o no existe
      } else {
      
          std::list<std::pair<int, Expression *> >::iterator it;
          //verificar indices enteros, # parametros
          tp = s->ntype;
          for(it=v->indexList->begin(); it!=v->indexList->end();++it){
          
            if((*it).second->ntype->numtype!=TYPE_INT) errorlog->addError(31,line,column,NULL); //no es entero
          
            if(tp->isarray()){
            
            ArrayType *arrt = (ArrayType *) tp;
            tp = arrt->ntype;
            
            }else{
            
            errorlog->addError(32,line,column,NULL); // no es un arreglo
            
            
            }
          
          }
          
      
      
      }
      
      v->ntype = tp;
      $$ = $1; 
      
   }
  | variable x_DOT variable_id { 
      //buscar el tipo de variable, verificar tipo del union o type
      Variable *v  = (Variable *) $1;
      TypeDeclaration *t = v->ntype, *tp = root->findType("_error")->ntype;

      if(!t->haveattributes()){
      
        errorlog->addError(33,line,column,NULL);//no tiene operador .
      
      
      } else {
        Variable *v2  = (Variable *) $3;
        std::string id = (*v2->varList->begin())->value;        
        TupleType *tup = (TupleType *) t;
        std::list< std::pair<TypeDeclaration*, int>* >::iterator it2 = tup->types->begin();
        std::list<std::string>::iterator it;
        //verificar
        for(it=tup->names->begin();it!=tup->names->end();++it){
        
          if(!(*it).compare(id)){
        
        
            tp = (*it2)->first;
            break;
          } //break y tienes el siguiente tipo
        
          ++it2;
        }
        
        if(it==tup->names->end()) errorlog->addError(34,line,column,&id); //no exist ele atrr
      
        if(tp->isarray()){
      
          ArrayType *arrt = (ArrayType *) tp; 
          std::list<std::pair<int, Expression *> >::iterator it;
          
          for(it=v2->indexList->begin(); it!=v2->indexList->end();++it){
          
            if((*it).second->ntype->numtype!=TYPE_INT) errorlog->addError(31,line,column,NULL); //no es entero
          
            if(tp->isarray()){
            
            ArrayType *arrt = (ArrayType *) tp;
            tp = arrt->ntype;
            
            }else{
            
            errorlog->addError(32,line,column,NULL); // no es un arreglo
            
            
            }
          
          }
      
        }
        
      } 
      
      v->ntype = tp;
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
      TypeDeclaration *tp = root->findType("_error")->ntype;
      FunctionType *f;
      if(!s){
      
        errorlog->addError(35,line,column,&$1->value);
      
      }else {
      
        if(!s->ntype->isfunction()){

          errorlog->addError(36,line,column,&$1->value);
          
        } else {
        
          f = (FunctionType *) s->ntype;
          TupleType *t = (TupleType *) f->arguments;
          std::list<Expression *>::iterator it = $3->begin();
          std::list< std::pair<TypeDeclaration*, int>* >::iterator it2;

          for(it2=t->types->begin();it2!=t->types->end();++it2){
        
            if(it==$3->end()) break;
          
            if((*it)->ntype->isarray()){
            
              TypeDeclaration *t=(*it)->ntype,*t2 =(*it2)->first;
              
              while((t->isarray())||(t2->isarray())){              
                t= t->ntype;
                t2= t2->ntype;
                if((!t->isarray())||(!t2->isarray())) break;
              }
              if((t->ntype!=t2->ntype)||(t->numtype!=t2->numtype)) errorlog->addError(37,line,column,&$1->value);
 
             } else if ((*it)->ntype->isfunction()){
             
             
             }else{
            
              if((*it)->ntype != (*it2)->first)
                 errorlog->addError(37,line,column,&$1->value);
            }
            ++it;
          }
        
          if(it2!=t->types->end()) errorlog->addError(38,line,column,&$1->value); //faltan argumentos
        
          if(it!=$3->end()){
         
            if(!f->extend){
            
              errorlog->addError(39,line,column,&$1->value);
            
            } else {//caso sobran extend
          
              for(;it!=$3->end();++it){
            

                if(f->extend!=(*it)->ntype) errorlog->addError(37,line,column,&$1->value);
            
            
              }
          
                tp = f->returnType;
          
            }
                
          } else {
           
            tp = f->returnType;
          }
        
        
        
        
        }
      
      }
      
      FunctionExpression *fun = new FunctionExpression($1->value,$3);
      fun->reference = f->reference;
            
      $$ =  fun;      

      $$->ntype = tp;
      $$->line = $1->line;
      $$->column = $1->column; 
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
