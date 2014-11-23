
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
   std::cout << std::string(tab, ' ') << "type: " <<(long int ) ntype << std::endl;
  }

  void firstcheck(SymTable *symtb){}
  
  virtual Quad_Expression* toTAC(TAC_Program *tac, SymTable* symtab){
     
    return new Quad_Constant(atoi(value.c_str()), value);
  }
  
  virtual void condition_toTAC(TAC_Program *tac, SymTable* symtab, 
                      std::string truelabel, std::string falselabel)
  {

    if(value=="TRUE"){
    
      tac->push_quad(new Instruction(JUMP_LABEL, new Quad_Variable(truelabel)));
      tac->new_block();

    
    }else if(value=="FALSE"){
    
      tac->push_quad(new Instruction(JUMP_LABEL, new Quad_Variable(falselabel)));
      tac->new_block();
    
    } else {}  


  }
  
  
};

#endif
