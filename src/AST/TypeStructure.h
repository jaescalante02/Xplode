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
  TypeDeclaration *attributes;
  SymTable *table;
  
  TypeStructure(Xplode::Token *n, Node* a) { 

   // table = new SymTable(a);
    table = new SymTable();
    name = n->value; 
    attributes = (TypeDeclaration *) a;
    line = n->line; 
    column = n->column; 
  }
  
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "TYPE\n";
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

  Symbol *toSymbol() { return new Symbol(false,name,NULL, line, column,false); }

  void firstcheck(){
  
  
  }

};

#endif

