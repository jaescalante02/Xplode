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
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "SLEEP STATEMENT\n";
   std::cout << std::string(tab, ' ') << "argument:\n";
   var->print(tab+2);
  }

  void firstcheck(SymTable *symtb){
  
    var->firstcheck(symtb);
  
  }

  void toTAC(TAC_Program *tac, SymTable* symtab, std::string cont_label, 
             std::string break_label)
  {

  std::string arg = var->toTAC(tac, symtab);
  tac->push_quad(new Instruction(SLEEP_LABEL, arg));
  //comentario para acompanar


  }


};

#endif
