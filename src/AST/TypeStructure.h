#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Statement.h"
#include "NodeList.h"
#include "../SymTable.h"
#include "../Symbol.h"
#include "../Token.h"

#ifndef X_TYPESTRUCT
#define X_TYPESTRUCT

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

  Symbol *toSymbol() { return new Symbol(name,"_type", line, column, true,0, table); }

  void firstcheck(){
  
  
  }

};

#endif

