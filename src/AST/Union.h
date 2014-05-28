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

  void print(int tab){
   std::cout << std::string(tab, ' ') << "UNION\n";
   std::cout << std::string(tab, ' ') << "name: " << name << "\n";
   std::cout << std::string(tab, ' ') << "ATTRIBUTES\n";
   attributes->print(tab+2);
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
