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
#include "../TAC/TAC_Program.h"
#include "../TAC/Instruction.h"

#ifndef X_BINARYEXP
#define X_BINARYEXP


class BinaryExpression : public Expression {
  public:
  std::string opname;
  Expression *lexp, *rexp; 
  BinaryExpression(std::string op,Expression *l, Expression *r){
    opname = op;
    lexp = l;
    rexp = r;
  }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "EXPRESSION " << opname << "\n";
   std::cout << std::string(tab, ' ') << "left expression:\n";
   lexp->print(tab+2);
   std::cout << std::string(tab, ' ') << "right expression: \n";
   rexp ->print(tab+2);
  }

  void firstcheck(SymTable *symtb){

    lexp->firstcheck(symtb);
    rexp-> firstcheck(symtb);
  
  }

  virtual std::string toTAC(TAC_Program *tac, SymTable* symtab){
      
      
      //aqui se debe hacer un if-else-if con los posibles operadores + * -
      Instruction *inst = new Instruction();
      inst->leftop = lexp->toTAC(tac, symtab);
      inst->rightop = rexp->toTAC(tac, symtab);
      inst->result = tac->labelmaker->getlabel(TEMPORAL);      
      if(opname=="+"){
        inst->op = ADD_LABEL;
      }
      else if(opname=="-"){
        inst->op = SUB_LABEL;
      }
      else if(opname=="/"){
        inst->op = DIV_LABEL;
      }
      else if(opname=="*"){
        inst->op = MUL_LABEL;
      } else if(opname=="=="){
        inst->op = EQUAL_LABEL;
      }
      else if(opname=="!="){
        inst->op = NEQUAL_LABEL;
      }
      else if(opname=="<="){
        inst->op = LEQ_LABEL;
      }
      else if(opname==">="){
        inst->op = GEQ_LABEL;
      }
      else if(opname==">"){
        inst->op = GREATER_LABEL;
      }
      else if(opname=="<"){
        inst->op = LESS_LABEL;
      }
      else {}
      
      tac->push_quad(inst);
      
      return inst->result;
  
  }

};


#endif
