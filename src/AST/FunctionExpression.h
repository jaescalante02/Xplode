#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "../SymTable.h"

#ifndef X_FUNCTIONEXP
#define X_FUNCTIONEXP

class FunctionExpression : public Expression {
  public:
  std::string fname;
  std::list<Expression *> *argList; 
  FunctionExpression(std::string n, std::list<Expression *> *a = 0){fname = n; argList = a; }
  void print(){
   std::cout << "FUNCTION \n";
   std::cout << "name: " << fname << "\n";
   if ( argList != 0 ){
     for(std::list<Expression *>::iterator iter = argList->begin(); iter != argList->end(); ++iter){
        std::cout << "argument: \n";
        (*iter)->print(); 
     }
   }
  }

  void firstcheck(SymTable *symtb){
  
  }

};


#endif
