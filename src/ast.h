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

class Declaration : public Node {
  public:
  std::string name;
  std::string var;
  
Declaration(std::string n, std::string v) { name = n; var = v; }
  void print(){
   std::cout << "DECLARATION\n";
   std::cout << "Type: " << name << "\n";
   std::cout << "Var: " << var << "\n";
  }

};

class NodeList  {
  public:
  std::list<Node *> nodeList;
  
  NodeList() { }
  void add(Node* n){
      nodeList.push_back(n);
  }
  
  void print(){   
    for(std::list<Node *>::iterator iter = nodeList.begin(); iter != nodeList.end(); ++iter){
         (*iter)->print(); 
    }
  }

};


class Union : public Node {
  public:
  std::string name;
  
Union(std::string n) { name = n; }
  void print(){
   std::cout << "UNION\n";
   std::cout << "Name: " << name << "\n";
  }

};


