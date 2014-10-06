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


//No se usa 4/10/2014

#ifndef X_UNARYEXP
#define X_UNARYEXP

class UnaryExpression : public Expression {
  public:
  Expression *exp; 
  UnaryExpression(Expression *e){exp = e; }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "UNARY EXPRESSION\n";
   exp->print(tab+2);
  }

  void firstcheck(SymTable *symtb){
  
    exp->firstcheck(symtb);
  
  }


};

#endif
