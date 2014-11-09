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
#include <cstring>
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

  virtual void toTAC(TAC_Program *tac, SymTable* symtab, std::string cont_label, std::string break_label ){

    Quad_Expression *auxstr = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));
    tac->push_quad(new Instruction(READ_LABEL, auxstr, new Quad_Constant(var->ntype->numtype)));
    Instruction *inst = var->lval_toTAC(tac,symtab);
    if(inst->leftop==NULL){

      inst->leftop = auxstr;
    }else{  

      inst->rightop = auxstr;
    }
    tac->push_quad(inst);
    
  }

};

#endif
