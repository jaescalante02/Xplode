#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "Statement.h"
#include "../SymTable.h"

#ifndef X_READST
#define X_READST


class ReadStatement : public Statement {
  public:
  Expression *var;
  
  ReadStatement(Expression *v){ var = v; }
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "READ STATEMENT\n";
   std::cout << std::string(tab, ' ') << "variable:\n";
   var->print(tab+2);
  }
  
  void firstcheck(SymTable *symtb){
  
    var->firstcheck(symtb);
  
  }

};

#endif
