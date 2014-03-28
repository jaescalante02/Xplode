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


#ifndef X_UNARYEXP
#define X_UNARYEXP

class UnaryExpression : public Expression {
  public:
  Expression *exp; 
  UnaryExpression(Expression *e){exp = e; }
  void print(){
   std::cout << "UNARY EXPRESSION\n";
   exp->print();
  }

  void firstcheck(SymTable *symtb){
  
    exp->firstcheck(symtb);
  
  }

};

#endif
