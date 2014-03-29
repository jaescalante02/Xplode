#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "../SymTable.h"
#include "Statement.h"

#ifndef X_BREAKST
#define X_BREAKST

class BreakStatement : public Statement {
  public:
  BreakStatement(){ }
  
  void print(){
   std::cout << "BREAK STATEMENT\n";
  }

  void firstcheck(SymTable *symtb){  
  }

};

#endif
