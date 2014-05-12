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

#ifndef X_CASTEDEXP
#define X_CASTEDEXP

class CastedExpression : public Expression {
  public:
  std::string cname;
  Expression *exp; 
  CastedExpression(std::string c, Expression *e){cname = c; exp = e; }
  void print(){
   std::cout << "CAST \n";
   std::cout << "name: " << cname << "\n";
   std::cout << "expression: \n";
   exp->print();
  }

  void firstcheck(SymTable *symtb){
  
  
     //Symbol *sym = symtb->getRoot()->find(fname); //verificar si el nombre pertenece a una funcion
     //if((!sym)||((sym)&&((sym->defined!=4)&&(sym->defined!=5)))) errorlog->addError(15,0,0,&fname);

     exp->firstcheck(symtb); 
  
  
  }

};


#endif
