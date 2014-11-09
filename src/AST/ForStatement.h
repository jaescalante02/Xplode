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
#include "../SymTable.h"

#ifndef X_FORSTATEMENT
#define X_FORSTATEMENT


class ForStatement : public CompoundStatement {
  public:
  Statement *init;
  Expression *condition;
  Statement *increment; 
  ForStatement(Node *i, Expression *c, Node *inc, Node *b){
    init = (Statement *) i;
    increment = (Statement *) inc;
    condition = c;
    block = (Block *) b;
  }
  
  
  virtual void toTAC(TAC_Program *tac, SymTable* symtab, std::string cont_label, std::string break_label ){

    std::string ini = tac->labelmaker->getlabel(LABEL_LABEL);
    std::string end = tac->labelmaker->getlabel(END_LABEL);
    std::string primer_for = tac->labelmaker->getlabel(LABEL_LABEL);

    tac->putcomment("FOR", line, column, end);
    tac->push_quad(new Label(tac->labelmaker->getlabel(FOR_LABEL)));
    init->toTAC(tac,symtab,cont_label,break_label);
    tac->push_quad(new Instruction(JUMP_LABEL, new Quad_Variable(primer_for)));
    tac->new_block();
    tac->push_quad(new Label(ini));
    increment->toTAC(tac,symtab,cont_label,break_label);
    tac->push_quad(new Label(primer_for));    
    std::string medio = tac->labelmaker->getlabel(LABEL_LABEL);
    condition->condition_toTAC(tac, symtab, medio, end);
    tac->push_quad(new Label(medio));
    block->toTAC(tac, ini, end);
    tac->push_quad(new Instruction(JUMP_LABEL, new Quad_Variable(ini)));
    tac->new_block();
    tac->push_quad(new Label(end));

  }

  
  
  void print(int tab){
   std::cout << std::string(tab, ' ') << "FOR STATEMENT \n";
   std::cout << std::string(tab, ' ') << "intialization: \n";
   init->print(tab+2);
   std::cout << std::string(tab, ' ') << "increment: \n";
   increment->print(tab+2);
   std::cout << std::string(tab, ' ') << "condition: \n";
   condition->print(tab+2);
   block->print(tab+2);
  }

  void firstcheck(SymTable *symtb){
  
    init->firstcheck(symtb); 
    condition->firstcheck(symtb); 
    increment->firstcheck(symtb); 
    if (block!=NULL) block->firstcheck();  
  
  }
  
  

};


#endif
