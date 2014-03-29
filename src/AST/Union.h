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

  void setFather(SymTable *s){
  
    table->setFather(s);
  
  }

  void printTable() {

     if (table!=NULL) table->print();

  }

  Symbol *toSymbol() { return new Symbol(name,"_union",line,column,true,0); }

  void firstcheck(){
  
  
  }

};

#endif
