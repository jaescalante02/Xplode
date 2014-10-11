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

#ifndef X_STRINGXP
#define X_STRINGXP


class StringType : public Expression {
  public:
  std::string value, str;
  StringType(std::string var,std::string sstr, TypeDeclaration *n){
    value = var; 
    str = sstr;
    ntype = n; 
  }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "STRING\n";
   std::cout << std::string(tab, ' ') << "var: " << value << "\n";
   std::cout << std::string(tab, ' ') << "string: " << str << std::endl;
  }

  void firstcheck(SymTable *symtb){}
  
  virtual std::string toTAC(TAC_Program *tac, SymTable* symtab){
    
    tac->push_string(value, str);
    
    return value;
  }
    
};

#endif
