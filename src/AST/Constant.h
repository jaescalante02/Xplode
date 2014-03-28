
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

#ifndef X_CONSTANTEXP
#define X_CONSTANTEXP


class Constant : public Expression {
  public:
  std::string value;
  Constant(std::string v){value = v; }
  void print(){
   std::cout << "CONSTANT\n";
   std::cout << "value: " << value << "\n";
  }

  void firstcheck(SymTable *symtb){}

};

#endif
