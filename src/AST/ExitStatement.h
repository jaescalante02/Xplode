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

#ifndef X_EXITST
#define X_EXITST

class ExitStatement : public Statement {
  public:
  ExitStatement(){ }
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "EXIT STATEMENT\n";
  }

  void firstcheck(SymTable *symtb){  
  }

};

#endif
