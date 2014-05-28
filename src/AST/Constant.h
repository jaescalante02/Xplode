
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
#include "TypeDeclaration.h"

#ifndef X_CONSTANTEXP
#define X_CONSTANTEXP


class Constant : public Expression {
  public:
  std::string value;
  Constant(std::string v, TypeDeclaration *n){value = v; ntype = n; }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "CONSTANT\n";
   std::cout << std::string(tab, ' ') << "value: " << value << "\n";
  }

  void firstcheck(SymTable *symtb){}

};

#endif
