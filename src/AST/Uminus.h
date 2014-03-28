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

#ifndef X_UMINUS
#define X_UMINUS


class Uminus : public Expression {
  public:
  Expression *exp; 
  Uminus(Expression *e){exp = e; }
  void print(){
   std::cout << "UMINUS\n";
   std::cout << "expression:\n";
   exp->print();
  }

  void firstcheck(SymTable *symtb){
  
  
  }

};

#endif
