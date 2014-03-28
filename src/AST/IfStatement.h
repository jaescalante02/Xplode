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
  void print(){
   std::cout << "IF STATEMENT \n";
   std::cout << "condition: \n";
   condition->print();
   std::cout << "then: \n";
   block->print();
   if (elseBlock != 0){
    std::cout << "else: \n";
    elseBlock->print();
   }
  }

  void firstcheck(SymTable *symtb){
  
    condition->firstcheck(symtb);    
    if(block != NULL) block->firstcheck();
    if (elseBlock != NULL) elseBlock->firstcheck();
    
  }

};

#endif

