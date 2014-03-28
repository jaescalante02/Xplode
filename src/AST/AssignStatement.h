
#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Statement.h"
#include "Expression.h"


#ifndef X_ASSIGN
#define X_ASSIGN

class AssignStatement : public Statement {
  public:
  Expression *lvalue, *rvalue;
  AssignStatement(Expression *l, Expression *r){
    lvalue = l;
    rvalue = r;
  }
  void print(){
   std::cout << "ASSIGN STATEMENT\n";
   std::cout << "left value:\n";
   lvalue->print();
   std::cout << "right value: \n";
   rvalue ->print();
  }
  
  void firstcheck(SymTable *symtb){
  
    lvalue->firstcheck(symtb);
    rvalue->firstcheck(symtb);
  
  }

};

#endif

