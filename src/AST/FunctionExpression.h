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

#ifndef X_FUNCTIONEXP
#define X_FUNCTIONEXP

class FunctionExpression : public Expression {
  public:
  std::string fname;
  std::list<Expression *> *argList; 
  FunctionExpression(std::string n, std::list<Expression *> *a = 0){fname = n; argList = a; }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "FUNCTION \n";
   std::cout << std::string(tab, ' ') << "name: " << fname << "\n";
   if ( argList != 0 ){
     for(std::list<Expression *>::iterator iter = argList->begin(); iter != argList->end(); ++iter){
        std::cout << std::string(tab, ' ') << "argument: \n";
        (*iter)->print(tab+2); 
     }
   }
  }

  void firstcheck(SymTable *symtb){
  
  
     //Symbol *sym = symtb->getRoot()->find(fname); //verificar si el nombre pertenece a una funcion
     //if((!sym)||((sym)&&((sym->defined!=4)&&(sym->defined!=5)))) errorlog->addError(15,0,0,&fname);
     for(std::list<Expression *>::iterator iter = argList->begin(); iter != argList->end(); ++iter){
        (*iter)->firstcheck(symtb); 
     }
  
  
  }

  virtual std::string toTAC(TAC_Program *tac, SymTable *symtab){
  

    std::list<Expression *>::reverse_iterator iter;
    int cont=0;
    Instruction *inst;

    for(iter = argList->rbegin();iter != argList->rend() ;++iter){
  
      inst = new Instruction(PARAM_LABEL);
      inst->result = (*iter)->toTAC(tac, symtab);
      tac->push_quad(inst);
      cont++;

    }

    inst = new Instruction(CALL_LABEL);
    inst->result = tac->labelmaker->getlabel(TEMPORAL); 
    inst->leftop = fname;
    std::stringstream aux;
    aux << cont;
    inst->rightop = aux.str();
    tac->push_quad(inst);
    return inst->result;
    
  }


  virtual void condition_toTAC(TAC_Program *tac, SymTable* symtab, 
                      std::string truelabel, std::string falselabel)
  {

    std::string cond = this->toTAC(tac,symtab);
    tac->push_quad(new Instruction(NEQUAL_ZERO_LABEL, cond, truelabel));
    tac->new_block();
    tac->push_quad(new Label(tac->labelmaker->getlabel(LABEL_LABEL)));
    tac->push_quad(new Instruction(JUMP_LABEL, falselabel));
    tac->new_block();
      

  }


};


#endif
