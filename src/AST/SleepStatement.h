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

#ifndef X_SLEEPST
#define X_SLEEPST

class SleepStatement : public Statement {
  public:
  Expression *var;
  SleepStatement(Expression *v){ var = v; }
  
  void print(){
   std::cout << "SLEEP STATEMENT\n";
   std::cout << "argument:\n";
   var->print();
  }

  void firstcheck(SymTable *symtb){
  
    var->firstcheck(symtb);
  
  }

};

#endif
