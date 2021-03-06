#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <set> 
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "../SymTable.h"
#include "../AST/Variable.h"

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
    std::vector<Instruction *>::iterator iter2;
    std::vector<Instruction *> ins;
    int cont=0, tam_dealloc = 0;
    Instruction *inst;
    int acum = 0;

    int cont2 = argList->size();

    for(iter = argList->rbegin();iter != argList->rend() ;++iter, --cont2){
  
      ++cont;

      if((reference)&&(reference->count(cont2)>0)){

        Variable *v = (Variable *) *iter;
        inst = v->lval_toTAC(tac, symtab);

        inst->op = PARAM_REF_LABEL;
        //inst->result = inst->leftop;
        //inst->leftop = inst->rightop;

      
      }else{

        inst = new Instruction(PARAM_LABEL);
        inst->result = (*iter)->toTAC(tac, symtab);
        inst->leftop = new Quad_Constant((*iter)->ntype->numtype);
        inst->rightop = new Quad_Constant(tam_dealloc);
      
      
      }
            
      ins.push_back(inst);
      
      if((reference)&&(reference->count(cont2)>0)) tam_dealloc += 4;
      else tam_dealloc += (*iter)->ntype->size; 


    }

    inst = new Instruction(BEGIN_FUNCTION_LABEL);
    tac->push_quad(inst);
    
    for(iter2=ins.begin(); iter2 != ins.end() ;++iter2){
    
      tac->push_quad(*iter2);    
       
    }



    inst = new Instruction(CALL_LABEL);
    Quad_Variable *q = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));  
    inst->result = q;
    Symbol *sym = symtab->find(fname);
    inst->leftop = new Quad_Variable(fname, sym->offset, sym->porref, sym->isarg, sym->ntype->size, sym->ntype->numtype);
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
