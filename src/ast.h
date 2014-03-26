//Classes for abstract syntax tree
#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
 
#define toLower(phrase) std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower)

#define INT_SYMBOL new Symbol("int","_type",0,0,true)
#define FLOAT_SYMBOL new Symbol("float","_type",0,0,true)
#define CHAR_SYMBOL new Symbol("char","_type",0,0,true)

class Symbol {

    public:

        Symbol(std::string n, std::string t, int l, int c, bool e){

            name=n;
            ntype = t;
            line = l;
            column = c; 
            editable = e;

        }

        std::string getname() {return name;}

        std::string name;
//valor
        std::string ntype;
//tamano
        
        int line;
        int column;
        bool editable;


};


class Node {
public:
  virtual ~Node () {}
  
  //virtual Node *clone() = 0;

  virtual void print() = 0;

  virtual Symbol *toSymbol(){}

  int line;
  int column;

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

class SymTable {

    public:

        SymTable(){

           table = new std::map<std::string, Symbol *>;
           father = NULL;

        }

        SymTable(NodeList *l) {

           table = new std::map<std::string, Symbol *>;
           father = NULL;
           this->add(l);
        }

        void add(NodeList *l){

           std::list<Node *>::iterator iter;
           for(iter = (*l).nodeList.begin(); iter != (*l).nodeList.end(); ++iter){
                this->insert((*iter)->toSymbol()); 
           } 

        }

        void insert(Symbol *s){

            //falta caso error, ya existe
            std::string lowsymbol(s->getname()); 
            toLower(lowsymbol);
            if (!isMember(lowsymbol)) (*table)[lowsymbol] = s;

        }

        Symbol *find(std::string variable){ 

            std::string var(variable);
            toLower(var);
            return this->findall(var);
        }

        void print(){

            if (table->empty()) return;

            std::map<std::string, Symbol *>::iterator pos;
            std::cout << " -------------------------------------------------\n";
            for (pos = (*table).begin(); pos != (*table).end(); ++pos) {
                printf(" | %15s | %10s | %3d | %3d | %2d |\n",(*pos).first.c_str(), 
                pos->second->ntype.c_str(), pos->second->line, 
                pos->second->column,pos->second->editable);

            }
            std::cout << " -------------------------------------------------\n";


        }

        void setFather(SymTable *s){ father=s; }
       
    private:

        bool isMember(std::string variable){return ((*table).count(variable)>0);} 

        Symbol *findall(std::string variable) {

            if(isMember(variable)) return (*table)[variable];
            if(father==NULL) return NULL;            
            return (*father).findall(variable);

        }

             
        SymTable *father;
        std::map<std::string, Symbol *> *table;



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


class TypeDeclaration: public Node {

  public:

    std::string name;
    std::list<std::string> *max_index;

    TypeDeclaration(std::string n) {

      name = n;
      max_index = new std::list<std::string>;

    }

    void addDimension(std::string number){ (*max_index).push_front(number); }

    void print(){}


};


class Declaration : public Node {
  public:
  TypeDeclaration *ntype;
  std::string var;
  
  Declaration(Node *n, Xplode::Token *v) { 
      ntype = (TypeDeclaration *) n; 
      var = v->value; 
      line = v->line; 
      column = v->column; 
  }

  void print(){
   std::string tab = std::string(4, ' ');
   
   std::cout << "DECLARATION\n";
   std::cout << "type: " << ntype << "\n";
   std::cout << "var: " << var << "\n";
  }

  Symbol *toSymbol(){ return new Symbol(var,ntype->name, line, column, false); }


};

//statements


class Statement: public Node {
public:
  
  virtual void print() {};

  virtual void printTable() {}

  virtual void setFather(SymTable *s){}

};

class Block : public Node {
  public:
  NodeList *declarationList; 
  NodeList *statementList; 
  SymTable *table;

  Block(NodeList *s){ 

    table= new SymTable(); 
    declarationList = 0; 
    statementList = s; 
    this->setFathers();
  }

  Block(NodeList *d, NodeList *s) { 

    table = new SymTable(d); 
    declarationList = d; 
    statementList = s; 
    this->setFathers();
  }

  void print(){
   std::cout << "BLOCK \n";
   if (declarationList != 0 ){
    std::cout << "DECLARATIONS \n";
    declarationList->print();
   }
   std::cout << "STATEMENTS\n";
   statementList->print();
  }

  void printTable(){

    table->print();
    Statement *st;
    std::list<Node *>::iterator iter;
    for(iter = (*statementList).nodeList.begin(); iter != (*statementList).nodeList.end(); ++iter){
        st = (Statement *) *iter;          
        st->printTable(); 
    }       
  }

  virtual void setFathers() {

    Statement *st;
    std::list<Node *>::iterator iter;
    for(iter = (*statementList).nodeList.begin(); iter != (*statementList).nodeList.end(); ++iter){
        st = (Statement *) *iter;          
        st->setFather(table); 
    }


  }

  virtual void setFather(SymTable *s){

    table->setFather(s);

  }

};

class CompoundStatement: public Statement {

public:

  Block *block;

  CompoundStatement(){}

  void print(){}

  virtual void printTable() {

     if (block!=NULL) block->printTable();

  }

  virtual void setFather(SymTable *s){

    block->setFather(s);

  }

};

class Union : public Statement {
  public:
  std::string name;
  NodeList *attributes;
  SymTable *table;
  
  Union(Xplode::Token *n, NodeList* a) { 

    table = new SymTable(a);
    name = n->value; 
    attributes = a;
    line = n->line; 
    column = n->column; 
  }

  void print(){
   std::cout << "UNION\n";
   std::cout << "name: " << name << "\n";
   std::cout << "ATTRIBUTES\n";
   attributes->print();
  }

  void printTable() {

     if (table!=NULL) table->print();

  }

  Symbol *toSymbol() { return new Symbol(name,"_union",line,column,true); }

};

class TypeStructure : public Statement {
  public:
  std::string name;
  NodeList *attributes;
  SymTable *table;
  
  TypeStructure(Xplode::Token *n, NodeList* a) { 

    table = new SymTable(a);
    name = n->value; 
    attributes = a;
    line = n->line; 
    column = n->column; 
  }
  void print(){
   std::cout << "TYPE\n";
   std::cout << "name: " << name << "\n";
   std::cout << "ATTRIBUTES\n";
   attributes->print();
  }

  void printTable() {

     if (table!=NULL) table->print();

  }

  Symbol *toSymbol() { return new Symbol(name,"_type", line, column, true); }

};

class Procedure : public Statement {
  public:
  std::string name;
  std::string returnType;
  NodeList* types;
  
  Procedure(Xplode::Token *n, Node* r, NodeList* t) { 
      name = n->value; 
      TypeDeclaration *tp = (TypeDeclaration *) r; 
      returnType = tp->name; 
      types = t; 
      line = n->line;
      column = n->column;
  }

  void print(){
   std::cout << "PROCEDURE\n";
   std::cout << "name: " << name << "\n";
   std::cout << "return: "<< returnType << "\n";
   std::cout << "TYPE PARAMETERS\n";
   types->print();

  }

Symbol *toSymbol() {return new Symbol(name,"_proc", line, column, true); }

};

class ProcedureType : public Node {
  public:
  std::string name;
  
  ProcedureType(Node *n) { 
    TypeDeclaration *tp = (TypeDeclaration *) n; 
    name = tp->name;
  }
  void print(){
   std::cout << "PROCEDURE TYPE\n";
   std::cout << "type: " << name << "\n";
  }

};


class Function : public CompoundStatement {
  public:
  std::string name;
  std::string returnType;
  NodeList *parameters;

  
  Function(Xplode::Token *n, Node *r, NodeList *p, Node *b = 0) { 

    name = n->value; 
    TypeDeclaration *tp = (TypeDeclaration *) r; 
    returnType = tp->name; 
    parameters = p; 
    block  = (Block *) b;
    if (block!=NULL) block->table->add(parameters);
    line = n->line;
    column = n->column;
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

Symbol *toSymbol() {return new Symbol(name,"_function", line, column, true); }

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
  
  Extends(Node *t) {     
    TypeDeclaration *tp = (TypeDeclaration *) t; 
    type = tp->name; 
  }

  void print(){
   std::cout << "EXTENDS\n";
   std::cout << "type: " << type << "\n";
  }

};


class Main : public CompoundStatement {

public:
  NodeList *definitionList; 
  SymTable *table;

  Main(Node *b){ 

    table= new SymTable();
    this->insertPrimitives(); 
    definitionList = 0; 
    block = (Block *) b; 

  }

  Main(NodeList *d, Node *b){ 

    table = new SymTable(d); 
    this->insertPrimitives(); 
    definitionList = d; 
    block = (Block *) b; 

  }

  void insertPrimitives(){

    table->insert(INT_SYMBOL);
    table->insert(FLOAT_SYMBOL); 
    table->insert(CHAR_SYMBOL);   

  }

  void print(){
    std::cout << "PROGRAM \n";
    if (definitionList != 0 ){
     std::cout << "DEFINITIONS \n";
     definitionList->print();
    }
    block->print();
  }

  void printTable(){

    if(table!=NULL) table->print();
    std::list<Node *>::iterator iter;
    Statement *st;
    if (definitionList!=NULL) 
      for(iter = (*definitionList).nodeList.begin(); iter != (*definitionList).nodeList.end(); ++iter){
            st = (Statement *) *iter;
            st->printTable(); 
      }
  
    if(block!=NULL) block->printTable();

  }

};

class AssignStatement : public Statement {
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

class ReadStatement : public Statement {
  public:
  Expression *var;
  ReadStatement(Expression *v){ var = v; }
  void print(){
   std::cout << "READ STATEMENT\n";
   std::cout << "variable:\n";
   var->print();
  }

};

class WriteStatement : public Statement {
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

class SleepStatement : public Statement {
  public:
  Expression *var;
  SleepStatement(Expression *v){ var = v; }
  void print(){
   std::cout << "SLEEP STATEMENT\n";
   std::cout << "argument:\n";
   var->print();
  }

};


class WhileStatement : public CompoundStatement {
  public:
  Expression *condition; 
  WhileStatement(Expression *c, Node *b){ condition = c; block = (Block *) b; }
  void print(){
   std::cout << "WHILE STATEMENT \n";
   std::cout << "condition: \n";
   condition->print();
   block->print();
  }

};

class ForStatement : public CompoundStatement {
  public:
  Node *init;
  Expression *condition;
  Node *increment; 
  ForStatement(Node *i, Expression *c, Node *inc, Node *b){
    init = i;
    increment = inc;
    condition = c;
    block = (Block *) b;
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

class IfStatement : public CompoundStatement {
  public:
  Expression *condition;
  Block *elseBlock; 
  IfStatement(Expression *c, Node *t, Node *e = 0){
    condition = c;
    block = (Block *) t;
    elseBlock = (Block *) e;
  }
  void print(){
   std::cout << "IF STATEMENT \n";
   std::cout << "condition: \n";
   condition->print();
   std::cout << "then: \n";
   block->print();
   if (elseBlock != 0){
    std::cout << "else: \n";
    elseBlock->print();
   }
  }

};



