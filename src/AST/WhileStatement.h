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

};

#endif
