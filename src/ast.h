//Classes for abstract syntax tree
#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 

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
  NodeList* parameters;
  
Function(std::string n, std::string r, NodeList* p) { name = n; returnType = r; parameters = p; }
  void print(){
   std::cout << "FUNCTION\n";
   std::cout << "name: " << name << "\n";
   std::cout << "return: "<< returnType << "\n";
   parameters->print();

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




