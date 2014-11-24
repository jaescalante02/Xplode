#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <set> 
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
  std::set<int> *reference; 
  
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

  virtual Quad_Expression* toTAC(TAC_Program *tac, SymTable *symtab){
  

    std::list<Expression *>::reverse_iterator iter;
    int cont=0, tam_dealloc = 0;
    Instruction *inst;
    int acum = 0;

    int cont2 = argList->size();

    inst = new Instruction(BEGIN_FUNCTION_LABEL);
    tac->push_quad(inst);
    for(iter = argList->rbegin();iter != argList->rend() ;++iter, --cont2){
  
      ++cont;

      inst = new Instruction((reference->count(cont2)>0)?PARAM_REF_LABEL:PARAM_LABEL);
      inst->result = (*iter)->toTAC(tac, symtab);
      inst->leftop = new Quad_Constant((*iter)->ntype->numtype);
      inst->rightop = new Quad_Constant(tam_dealloc);      
      tac->push_quad(inst);
      
      if(reference->count(cont2)>0) tam_dealloc += 4;
      else tam_dealloc += (*iter)->ntype->size; 

    }

    inst = new Instruction(CALL_LABEL);
    Quad_Variable *q = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));  
    inst->result = q;
    inst->leftop = new Quad_Variable(fname);
    inst->rightop = new Quad_Constant(cont);
    tac->push_quad(inst);

    inst = new Instruction(END_FUNCTION_LABEL);
    inst->result = q;
    inst->leftop = new Quad_Constant(tam_dealloc);
    tac->push_quad(inst);    
    
    return inst->result;
    
  }

  


  virtual void condition_toTAC(TAC_Program *tac, SymTable* symtab, 
                      std::string truelabel, std::string falselabel)
  {

    Quad_Expression* cond = this->toTAC(tac,symtab);
    tac->push_quad(new Instruction(NEQUAL_ZERO_LABEL, cond, new Quad_Variable(truelabel)));
    tac->new_block();
    tac->push_quad(new Label(tac->labelmaker->getlabel(LABEL_LABEL)));
    tac->push_quad(new Instruction(JUMP_LABEL, new Quad_Variable(falselabel)));
    tac->new_block();
      

  }


};


#endif
