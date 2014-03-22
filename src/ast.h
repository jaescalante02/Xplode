//Classes for abstract syntax tree
#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <cstdlib>

class Node {
public:
  virtual ~Node () {}
  
  //virtual Node *clone() = 0;

  virtual void print() = 0;
};

//List of nodes
class NodeList  {
  public:
  std::list<Node *> nodeList;
  
  NodeList() { }
  void add(Node* n){
      nodeList.push_back(n);
  }
  
  void push(Node* n){
      nodeList.push_front(n);
  }
  
  int size(){
    return nodeList.size();
  }
  
  void print(){   
    for(std::list<Node *>::iterator iter = nodeList.begin(); iter != nodeList.end(); ++iter){
         (*iter)->print(); 
    }
  }

};


//Definition part
class Declaration : public Node {
  public:
  std::string name;
  std::string var;
  
Declaration(std::string n, std::string v) { name = n; var = v; }
  void print(){
   std::string tab = std::string(4, ' ');
   
   std::cout << "DECLARATION\n";
   std::cout << "type: " << name << "\n";
   std::cout << "var: " << var << "\n";
  }

};

class Union : public Node {
  public:
  std::string name;
  NodeList *attributes;
  
Union(std::string n, NodeList* a) { name = n; attributes = a;}
  void print(){
   std::cout << "UNION\n";
   std::cout << "name: " << name << "\n";
   std::cout << "ATTRIBUTES\n";
   attributes->print();
  }

};

class Type : public Node {
  public:
  std::string name;
  NodeList *attributes;
  
Type(std::string n, NodeList* a) { name = n; attributes = a;}
  void print(){
   std::cout << "TYPE\n";
   std::cout << "name: " << name << "\n";
   std::cout << "ATTRIBUTES\n";
   attributes->print();
  }

};

class Procedure : public Node {
  public:
  std::string name;
  std::string returnType;
  NodeList* types;
  
Procedure(std::string n, std::string r, NodeList* t) { name = n; returnType = r; types = t; }
  void print(){
   std::cout << "PROCEDURE\n";
   std::cout << "name: " << name << "\n";
   std::cout << "return: "<< returnType << "\n";
   std::cout << "TYPE PARAMETERS\n";
   types->print();

  }

};

class ProcedureType : public Node {
  public:
  std::string name;
  
ProcedureType(std::string n) { name = n;}
  void print(){
   std::cout << "PROCEDURE TYPE\n";
   std::cout << "type: " << name << "\n";
  }

};


class Function : public Node {
  public:
  std::string name;
  std::string returnType;
  NodeList *parameters;
  Node* block;
  
  Function(std::string n, std::string r, NodeList *p, Node *b = 0) { 
    name = n; 
    returnType = r; 
    parameters = p; 
    block  = b;
  }
  void print(){
   std::cout << "FUNCTION\n";
   std::cout << "name: " << name << "\n";
   std::cout << "return: "<< returnType << "\n";
   parameters->print();
   if (block != 0 ){
    block->print();
   }

  }

};

class FunctionParameter : public Node {
  public:
  std::string type;
  std::string var;
  
FunctionParameter(std::string t, std::string v) { type = t; var = v; }
  void print(){
   std::cout << "PARAMETER\n";
   std::cout << "type: " << type << "\n";
   std::cout << "var: " << var << "\n";
  }

};

class Extends : public Node {
  public:
  std::string type;
  
Extends(std::string t) { type = t; }
  void print(){
   std::cout << "EXTENDS\n";
   std::cout << "type: " << type << "\n";
  }

};


//expressions
class Expression : public Node {
  public:
  std::string type; //Used for type checks

};

class Constant : public Expression {
  public:
  std::string value;
  Constant(std::string v){value = v; }
  void print(){
   std::cout << "CONSTANT\n";
   std::cout << "value: " << value << "\n";
  }

};

class Variable : public Expression {
  public:
  std::string var;
  std::list<int> indexList;
  std::list<std::string> fieldList;
  
  Variable(std::string v){var = v; }
  void print(){
   std::cout << "VARIABLE\n";
   std::cout << "var: " << var << "\n";
   for(std::list<std::string >::iterator iter = fieldList.begin(); iter != fieldList.end(); ++iter){
     std::cout << "field: " << *iter << "\n"; 
   }
   for(std::list<int>::iterator iter = indexList.begin(); iter != indexList.end(); ++iter){
     std::cout << "index: " << *iter << "\n"; 
   }
   
  }
  
  void addIndex(std::string i){
    int index = atoi(i.c_str());
    indexList.push_back(index);
  }

  void addField(std::string f){
    fieldList.push_back(f);
  }
};

class FunctionExpression : public Expression {
  public:
  std::string fname;
  std::list<Expression *> *argList; 
  FunctionExpression(std::string n, std::list<Expression *> *a){fname = n; argList = a; }
  void print(){
   std::cout << "FUNCTION EXPRESSION\n";
   for(std::list<Expression *>::iterator iter = argList->begin(); iter != argList->end(); ++iter){
      std::cout << "argument: \n";
      (*iter)->print(); 
    }
  }

};


class Uminus : public Expression {
  public:
  Expression *exp; 
  Uminus(Expression *e){exp = e; }
  void print(){
   std::cout << "UMINUS\n";
   std::cout << "expression:\n";
   exp->print();
  }

};

class UnaryExpression : public Expression {
  public:
  Expression *exp; 
  UnaryExpression(Expression *e){exp = e; }
  void print(){
   std::cout << "UNARY EXPRESSION\n";
   exp->print();
  }

};

class BinaryExpression : public Expression {
  public:
  std::string opname;
  Expression *lexp, *rexp; 
  BinaryExpression(std::string op,Expression *l, Expression *r){
    opname = op;
    lexp = l;
    rexp = r;
  }
  void print(){
   std::cout << "EXPRESSION" << opname << "\n";
   std::cout << "left expression:\n";
   lexp->print();
   std::cout << "right expression: \n";
   rexp ->print();
  }

};

//statements
class Block : public Node {
  public:
  NodeList *declarationList; 
  NodeList *statementList; 
  Block(NodeList *s){ declarationList = 0; statementList = s; }
  Block(NodeList *d, NodeList *s){ declarationList = d; statementList = s; }
  void print(){
   std::cout << "BLOCK \n";
   if (declarationList != 0 ){
    std::cout << "DECLARATIONS \n";
    declarationList->print();
   }
   std::cout << "STATEMENTS\n";
   statementList->print();
  }

};

class Main : public Node {
public:
  NodeList *definitionList; 
  Node *block;
  Main(Node *b){ definitionList = 0; block = b; }
  Main(NodeList *d, Node *b){ definitionList = d; block = b; }
  void print(){
   std::cout << "PROGRAM \n";
   if (definitionList != 0 ){
    std::cout << "DEFINITIONS \n";
    definitionList->print();
   }
   block->print();
  }


};

class AssignStatement : public Node {
  public:
  Expression *lvalue, *rvalue;
  AssignStatement(Expression *l, Expression *r){
    lvalue = l;
    rvalue = r;
  }
  void print(){
   std::cout << "ASSIGN STATEMENT\n";
   std::cout << "left value:\n";
   lvalue->print();
   std::cout << "right value: \n";
   rvalue ->print();
  }

};

class ReadStatement : public Node {
  public:
  Expression *var;
  ReadStatement(Expression *v){ var = v; }
  void print(){
   std::cout << "READ STATEMENT\n";
   std::cout << "variable:\n";
   var->print();
  }

};

class WriteStatement : public Node {
  public:
  std::list<Expression *> *writeList; 
  WriteStatement(std::list<Expression *> *a){writeList = a; }
  void print(){
   std::cout << "WRITE STATEMENT\n";
   for(std::list<Expression *>::iterator iter = writeList->begin(); iter != writeList->end(); ++iter){
      std::cout << "write: \n";
      (*iter)->print(); 
    }
  }

};

class SleepStatement : public Node {
  public:
  Expression *var;
  SleepStatement(Expression *v){ var = v; }
  void print(){
   std::cout << "SLEEP STATEMENT\n";
   std::cout << "argument:\n";
   var->print();
  }

};


class WhileStatement : public Node {
  public:
  Expression *condition; 
  Node *block; 
  WhileStatement(Expression *c, Node *b){ condition = c; block = b; }
  void print(){
   std::cout << "WHILE STATEMENT \n";
   std::cout << "condition: \n";
   condition->print();
   block->print();
  }

};

class ForStatement : public Node {
  public:
  Node *init;
  Expression *condition;
  Node *increment;
  Node *block; 
  ForStatement(Node *i, Expression *c, Node *inc, Node *b){
    init = i;
    increment = inc;
    condition = c;
    block = b;
  }
  void print(){
   std::cout << "FOR STATEMENT \n";
   std::cout << "intialization: \n";
   init->print();
   std::cout << "increment: \n";
   increment->print();
   std::cout << "condition: \n";
   condition->print();
   block->print();
  }

};

class IfStatement : public Node {
  public:
  Expression *condition;
  Node *thenBlock;
  Node *elseBlock; 
  IfStatement(Expression *c, Node *t, Node *e = 0){
    condition = c;
    thenBlock = t;
    elseBlock = e;
  }
  void print(){
   std::cout << "IF STATEMENT \n";
   std::cout << "condition: \n";
   condition->print();
   std::cout << "then: \n";
   thenBlock->print();
   if (elseBlock != 0){
    std::cout << "else: \n";
    elseBlock->print();
   }
  }

};
