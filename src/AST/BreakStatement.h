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
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "BREAK STATEMENT\n";
  }

  void firstcheck(SymTable *symtb){  
  }

  virtual void toTAC(TAC_Program *tac, SymTable* symtab, std::string cont_label,
                      std::string break_label){

    tac->push_quad(new Instruction(JUMP_LABEL, break_label)); 
    tac->new_block(); 
    tac->push_quad(new Label(tac->labelmaker->getlabel(LABEL_LABEL)));        

  }

};

#endif
