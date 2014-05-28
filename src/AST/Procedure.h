
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
#include "TupleType.h"
#include "../Symbol.h"
#include "Statement.h"
#include "../Token.h"

#ifndef X_PROCEDUREDEF
#define X_PROCEDUREDEF


class Procedure : public Statement {
  public:
  std::string name;
  std::string returnType;
  TupleType* types;
  
  Procedure(Xplode::Token *n, Node* r, Node* t) { 
      name = n->value; 
    //  TypeDeclaration *tp = (TypeDeclaration *) r; 
    //  returnType = tp->name; 
      types = (TupleType *) t; 
      line = n->line;
      column = n->column;
  }

  void print(int tab){
   std::cout << std::string(tab, ' ') << "PROCEDURE\n";
   std::cout << std::string(tab, ' ') << "name: " << name << "\n";
   std::cout << std::string(tab, ' ') << "return: "<< returnType << "\n";
   std::cout << std::string(tab, ' ') << "TYPE PARAMETERS\n";
   types->print(tab + 2);

  }

  Symbol *toSymbol() {return new Symbol(false,name,NULL, line, column,false); }

  void firstcheck(){ }

};

#endif
