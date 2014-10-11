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
        if(lexp->ntype->numtype==TYPE_INT)
          inst->op = ADD_INT_LABEL;
        else
          inst->op = ADD_FLOAT_LABEL;  
          
      }
      else if(opname=="-"){
        if(lexp->ntype->numtype==TYPE_INT)
          inst->op = SUB_INT_LABEL;
        else
          inst->op = SUB_FLOAT_LABEL; 
      }
      else if(opname=="/"){
        if(lexp->ntype->numtype==TYPE_INT)
          inst->op = DIV_INT_LABEL;
        else
          inst->op = DIV_FLOAT_LABEL;
      }
      else if(opname=="*"){
        if(lexp->ntype->numtype==TYPE_INT)
          inst->op = MUL_INT_LABEL;
        else
          inst->op = MUL_FLOAT_LABEL;
      }else if(opname=="**"){
        inst->op = POWER_LABEL;
      } else if(opname=="=="){
        inst->op = OP_EQUAL_LABEL;
      }
      else if(opname=="!="){
        inst->op = OP_NEQUAL_LABEL;
      }
      else if(opname=="<="){
        inst->op = OP_LEQ_LABEL;
      }
      else if(opname==">="){
        inst->op = OP_GEQ_LABEL;
      }
      else if(opname==">"){
        inst->op = OP_GREATER_LABEL;
      }
      else if(opname=="<"){
        inst->op = OP_LESS_LABEL;
      }
      else if(opname=="AND"){
        inst->op = AND_LABEL;
      }
      else if(opname=="OR"){
        inst->op = OR_LABEL;
      }
      else {}
      
      tac->push_quad(inst);
      
      return inst->result;
  
  }

  virtual void condition_toTAC(TAC_Program *tac, SymTable* symtab, 
                      std::string truelabel, std::string falselabel)
  {
        
      if(opname=="AND"){

        std::string newl =  tac->labelmaker->getlabel(LABEL_LABEL);      
        lexp->condition_toTAC(tac, symtab, newl, falselabel);
        tac->push_quad(new Label(newl));
        rexp->condition_toTAC(tac, symtab, truelabel, falselabel);

      }
      else if(opname=="OR"){
      
        std::string newl =  tac->labelmaker->getlabel(LABEL_LABEL);
        lexp->condition_toTAC(tac, symtab, truelabel, newl);
        tac->push_quad(new Label(newl));
        rexp->condition_toTAC(tac, symtab, truelabel, falselabel);
      }
      else if(opname=="<"){
      
        Instruction *inst = new Instruction(LESS_LABEL);
        inst->result = lexp->toTAC(tac, symtab);
        inst->leftop = rexp->toTAC(tac, symtab);
        inst->rightop = truelabel;
        tac->push_quad(inst);
        tac->new_block();
        tac->push_quad(new Label(tac->labelmaker->getlabel(LABEL_LABEL)));
        tac->push_quad(new Instruction(JUMP_LABEL, falselabel));
        tac->new_block();
      }
      else if(opname=="<="){

        Instruction *inst = new Instruction(LEQ_LABEL);
        inst->result = lexp->toTAC(tac, symtab);
        inst->leftop = rexp->toTAC(tac, symtab);
        inst->rightop = truelabel;
        tac->push_quad(inst);
        tac->new_block();
        tac->push_quad(new Label(tac->labelmaker->getlabel(LABEL_LABEL)));
        tac->push_quad(new Instruction(JUMP_LABEL, falselabel));
        tac->new_block();

        
      } else if(opname=="=="){

        Instruction *inst = new Instruction(EQUAL_LABEL);
        inst->result = lexp->toTAC(tac, symtab);
        inst->leftop = rexp->toTAC(tac, symtab);
        inst->rightop = truelabel;
        tac->push_quad(inst);
        tac->new_block();
        tac->push_quad(new Label(tac->labelmaker->getlabel(LABEL_LABEL)));
        tac->push_quad(new Instruction(JUMP_LABEL, falselabel));
        tac->new_block();

      }
      else if(opname=="!="){

        Instruction *inst = new Instruction(NEQUAL_LABEL);
        inst->result = lexp->toTAC(tac, symtab);
        inst->leftop = rexp->toTAC(tac, symtab);
        inst->rightop = truelabel;
        tac->push_quad(inst);
        tac->new_block();
        tac->push_quad(new Label(tac->labelmaker->getlabel(LABEL_LABEL)));
        tac->push_quad(new Instruction(JUMP_LABEL, falselabel));
        tac->new_block();

      }
      else if(opname==">="){

        Instruction *inst = new Instruction(GEQ_LABEL);
        inst->result = lexp->toTAC(tac, symtab);
        inst->leftop = rexp->toTAC(tac, symtab);
        inst->rightop = truelabel;
        tac->push_quad(inst);
        tac->new_block();
        tac->push_quad(new Label(tac->labelmaker->getlabel(LABEL_LABEL)));
        tac->push_quad(new Instruction(JUMP_LABEL, falselabel));
        tac->new_block();

      }
      else if(opname==">"){

        Instruction *inst = new Instruction(GREATER_LABEL);
        inst->result = lexp->toTAC(tac, symtab);
        inst->leftop = rexp->toTAC(tac, symtab);
        inst->rightop = truelabel;
        tac->push_quad(inst);
        tac->new_block();
        tac->push_quad(new Label(tac->labelmaker->getlabel(LABEL_LABEL)));
        tac->push_quad(new Instruction(JUMP_LABEL, falselabel));
        tac->new_block();

      }
      else {}
  
  
  }  


};


#endif
