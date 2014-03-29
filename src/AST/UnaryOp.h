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
#include "Expression.h"

#ifndef X_UNARYOP
#define X_UNARYOP


class UnaryOp : public Expression {
  public:
  Expression *exp; 
  std::string opname;
  UnaryOp( std::string op, Expression *e){
    exp = e; 
    if (op == "-"){
      opname = "UMINUS";
    } else if (op == "!"){
      opname = "NOT";
    } else {
      opname = "UNKNOWN";
    }
    
  }
  void print(){
   std::cout << opname << "\n";
   std::cout << "expression:\n";
   exp->print();
  }

  void firstcheck(SymTable *symtb){
  }

};

#endif
