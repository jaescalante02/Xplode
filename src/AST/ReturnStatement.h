#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "../SymTable.h"
#include "Expression.h"
#include "Statement.h"

#ifndef X_RETURNST
#define X_RETURNST

class ReturnStatement : public Statement {
  public:
  Expression *exp;
  ReturnStatement(Expression *e){ exp = e; }
  
  void print(){
   std::cout << "RETURN STATEMENT\n";
   std::cout << "argument:\n";
   exp->print();
  }

  void firstcheck(SymTable *symtb){
    exp->firstcheck(symtb);
  }

};

#endif
