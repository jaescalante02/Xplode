
#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "NodeList.h"
#include "TypeDeclaration.h"
#include "../Symbol.h"
#include "Statement.h"
#include "../Token.h"

#ifndef X_PROCEDUREDEF
#define X_PROCEDUREDEF


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

  Symbol *toSymbol() {return new Symbol(name,"_proc", line, column, true, 0); }

  void firstcheck(){ }

};

#endif
