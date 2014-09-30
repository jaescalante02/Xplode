
#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Statement.h"
#include "Expression.h"
#include "../TAC/TAC_Program.h"

#ifndef X_ASSIGN
#define X_ASSIGN

class AssignStatement : public Statement {
  public:
  Expression *lvalue, *rvalue;
  AssignStatement(Expression *l, Expression *r){
    lvalue = l;
    rvalue = r;
  }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "ASSIGN STATEMENT\n";
   std::cout << std::string(tab, ' ') << "left value:\n";
   lvalue->print(tab+2);
   std::cout << std::string(tab, ' ') << "right value: \n";
   rvalue ->print(tab+2);
  }
  
  void firstcheck(SymTable *symtb){
  
    lvalue->firstcheck(symtb);
    rvalue->firstcheck(symtb);
  
  }
  
  virtual void toTAC(TAC_Program *tac, SymTable* symtab, std::string cont_label, std::string break_label){
    Instruction *inst= new Instruction(ASSIGN_LABEL);    
    inst->leftop = rvalue->toTAC(tac, symtab);
    inst->result = lvalue->toTAC(tac, symtab);
    tac->push_quad(inst);
    
  } 
};

#endif

