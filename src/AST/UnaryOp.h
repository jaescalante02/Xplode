#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "../SymTable.h"
#include "Expression.h"

#ifndef X_UNARYOP
#define X_UNARYOP


class UnaryOp : public Expression {
  public:
  Expression *exp; 
  std::string opname;
  UnaryOp( std::string op, Expression *e){
    exp = e; 
    if (op == "-"){
      opname = "UMINUS";
    } else if (op == "!"){
      opname = "NOT";
    } else {
      opname = "UNKNOWN";
    }
    
  }
  void print(int tab){
   std::cout << std::string(tab, ' ') << opname << "\n";
   std::cout << std::string(tab, ' ') << "expression:\n";
   exp->print(tab+2);
  }

  void firstcheck(SymTable *symtb){
  }

  virtual std::string toTAC(TAC_Program *tac, SymTable* symtab){
      
      Instruction *inst = new Instruction();
      inst->leftop = exp->toTAC(tac, symtab);
      inst->result = tac->labelmaker->getlabel(TEMPORAL);
            
      if(opname=="UMINUS"){
        if(exp->ntype->numtype==TYPE_INT)
          inst->op = UMINUS_INT_LABEL;
        else
          inst->op = UMINUS_FLOAT_LABEL;
      }
      else if(opname=="NOT"){
      
        inst->op = NOT_LABEL;
      } else {}
      
      tac->push_quad(inst);
      
      return inst->result;
  
  }

  virtual void condition_toTAC(TAC_Program *tac, SymTable* symtab, 
                      std::string truelabel, std::string falselabel)
  {

    exp->condition_toTAC(tac,symtab, falselabel, truelabel);  


  }

};

#endif
