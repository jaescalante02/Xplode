

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
   std::cout << std::string(tab, ' ') << "EXPRESSION" << opname << "\n";
   std::cout << std::string(tab, ' ') << "left expression:\n";
   lexp->print(tab+2);
   std::cout << std::string(tab, ' ') << "right expression: \n";
   rexp ->print(tab+2);
  }

  void firstcheck(SymTable *symtb){

    lexp->firstcheck(symtb);
    rexp-> firstcheck(symtb);
  
  }

};


#endif
