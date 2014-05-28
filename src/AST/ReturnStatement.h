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
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "RETURN STATEMENT\n";
   std::cout << std::string(tab, ' ') << "argument:\n";
   exp->print(tab+2);
  }

  void firstcheck(SymTable *symtb){
    exp->firstcheck(symtb);
  }

};

#endif
