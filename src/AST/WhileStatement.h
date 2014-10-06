#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "CompoundStatement.h"
#include "Expression.h"
#include "Block.h"

#ifndef X_WHILESTATEMENT
#define X_WHILESTATEMENT

class WhileStatement : public CompoundStatement {
  public:
  
  Expression *condition; 
  WhileStatement(Expression *c, Node *b){ 
    condition = c; 
    block = (Block *) b;
  }
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "WHILE STATEMENT \n";
   std::cout << std::string(tab, ' ') << "condition: \n";
   condition->print(tab+2);
   block->print(tab+2);
  }

  void firstcheck(SymTable *symtb){
  
    condition->firstcheck(symtb);
    if(block!=NULL) block->firstcheck();
  
  }


  virtual void toTAC(TAC_Program *tac, SymTable* symtab, std::string cont_label, std::string break_label ){

    std::string init = tac->labelmaker->getlabel(WHILE_LABEL);
    std::string medio = tac->labelmaker->getlabel(LABEL_LABEL);
    std::string end = tac->labelmaker->getlabel(END_LABEL);
    tac->push_quad(new Label(init));
    std::string cond = condition->toTAC(tac, symtab);
    tac->push_quad(new Instruction(EQUAL_ZERO_LABEL, cond, end));  
    tac->new_block();  
    tac->push_quad(new Label(medio));
    block->toTAC(tac, init, end);
    cond = condition->toTAC(tac, symtab);
    tac->push_quad(new Instruction(NEQUAL_ZERO_LABEL, cond, medio)); 
    tac->new_block();         
    tac->push_quad(new Label(end));

  }


};

#endif
