#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "CompoundStatement.h"
#include "Block.h"
#include "../SymTable.h"
#include "Expression.h"


#ifndef X_IFSTATEMENT
#define X_IFSTATEMENT

class IfStatement : public CompoundStatement {
  public:
  Expression *condition;
  Block *elseBlock; 
  IfStatement(Expression *c, Node *t, Node *e = 0){
    condition = c;
    block = (Block *) t;
    elseBlock = (Block *) e;
  }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "IF STATEMENT \n";
   std::cout << std::string(tab, ' ') << "condition: \n";
   condition->print(tab+2);
   std::cout << std::string(tab, ' ') << "then: \n";
   block->print(tab+2);
   if (elseBlock != 0){
    std::cout << std::string(tab, ' ') << "else: \n";
    elseBlock->print(tab+2);
   }
  }

  void setFather(SymTable *s){

    block->setFather(s);
    if (elseBlock!=NULL) elseBlock->setFather(s); 

  }

  virtual void printTable() {

     if (block!=NULL) block->printTable();
     if (elseBlock!=NULL) elseBlock->printTable();

  }

  void firstcheck(SymTable *symtb){
  
    condition->firstcheck(symtb);    
    if(block != NULL) block->firstcheck();
    if (elseBlock != NULL) elseBlock->firstcheck();
    
  }

};

#endif

