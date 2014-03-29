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

#ifndef X_CONTINUEST
#define X_CONTINUEST

class ContinueStatement : public Statement {
  public:
  ContinueStatement(){ }
  
  void print(){
   std::cout << "CONTINUE STATEMENT\n";
  }

  void firstcheck(SymTable *symtb){  
  }

};

#endif
