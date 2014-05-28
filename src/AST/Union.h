#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Statement.h"
#include "../SymTable.h"
#include "NodeList.h"
#include "../Symbol.h"
#include "../Token.h"

#ifndef X_UNIONDEF
#define X_UNIONDEF

class Union : public Statement {
  public:
  std::string name;
  TypeDeclaration *attributes;
  SymTable *table;
  
  Union(Xplode::Token *n, Node* a) { 

   // table = new SymTable(a);
    table = new SymTable();
    name = n->value; 
    attributes = (TypeDeclaration *) a;
    line = n->line; 
    column = n->column; 
  }

  void print(){
   std::cout << "UNION\n";
   std::cout << "name: " << name << "\n";
   std::cout << "ATTRIBUTES\n";
   attributes->print();
  }

  void setFather(SymTable *s){
  
    table->setFather(s);
  
  }

  void printTable() {

     if (table!=NULL) table->print();

  }

  Symbol *toSymbol() { return new Symbol(true,name,NULL,line,column,true); }

  void firstcheck(){
  
  
  }

};

#endif
