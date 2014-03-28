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
  
  void print(){
   std::cout << "WHILE STATEMENT \n";
   std::cout << "condition: \n";
   condition->print();
   block->print();
  }

  void firstcheck(SymTable *symtb){
  
    condition->firstcheck(symtb);
    if(block!=NULL) block->firstcheck();
  
  }

};

#endif
