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
#include "../Token.h"

#ifndef X_PARAMETER
#define X_PARAMETER


class Parameter : public Node {
  public:
  TypeDeclaration *ntype;
  std::string var;
  std::string passtype; //Either value or reference
  
  Parameter(Node *n, Xplode::Token *v, std::string ptype = "value") { 
      //ntype = (TypeDeclaration *) n; 
      var = v->value; 
      line = v->line; 
      column = v->column; 
      passtype = ptype;
  }

  void print(int tab){
   
   
   std::cout << std::string(tab, ' ') << "PARAMETER\n";
   std::cout << std::string(tab, ' ') << "passing by: " << passtype << "\n";
   //std::cout << std::string(tab, ' ') << "type: " << ntype->name << "\n";
   std::cout << std::string(tab, ' ') << "var: " << var << "\n";
  }

  Node* type(){
    return ntype;
  }

  Symbol *toSymbol(){ 
  /*
    return new Symbol(var,ntype->name, line, column, false,
            ntype->max_index->size()); 
  
  */
  }


};


#endif
