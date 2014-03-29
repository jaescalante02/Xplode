#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "TypeDeclaration.h"
#include "../Symbol.h"
#include "Node.h"
#include "Statement.h"
#include "../Token.h"

#ifndef X_DECLARATION
#define X_DECLARATION


class Declaration : public Statement {
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
   std::cout << "type: " << ntype->name << "\n";
   std::cout << "var: " << var << "\n";
  }

  Symbol *toSymbol(){ 
  
    return new Symbol(var,ntype->name, line, column, false,
            ntype->max_index->size()); 
  }

  void firstcheck(SymTable *symtb){
  
  
  }  

};


#endif
