#ifndef X_VARIABLEEXP
#define X_VARIABLEEXP

#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <vector> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Expression.h"
#include "../SymTable.h"
#include "../ErrorLog.h"
#include "../Token.h"
#include "TupleType.h"
#include "ArrayType.h"

extern ErrorLog *errorlog;

class Variable : public Expression {
  public:

  std::list<Xplode::Token *> *varList;
  std::list<std::pair<int, Expression *> > *indexList;
  
  Variable(Xplode::Token *v){
    varList = new std::list<Xplode::Token *>; 
    indexList = new std::list<std::pair<int, Expression *> >;
    varList->push_back(v);
  }
  
  void print(int tab){ 
   std::cout << std::string(tab, ' ') << "VARIABLE\n";
   for(std::list<Xplode::Token *>::iterator iter = varList->begin(); 
      iter != varList->end(); ++iter){
      
     std::cout << std::string(tab, ' ') << "field: " << (*iter)->value << "\n"; 
   }
   for(std::list<std::pair<int, Expression *> >::iterator iter = indexList->begin();
       iter != indexList->end(); ++iter){
       
     std::cout << std::string(tab, ' ') << "index: " << (*iter).first <<"|"<<"\n";
     iter->second->print(tab+2); 
   }
  }
    
  void addIndex(Expression *exp){
    indexList->push_back(std::make_pair(0, exp));
  }

  void concat(Variable *v){
  
    varList->push_back(*v->varList->begin());
    
    std::list<std::pair<int, Expression *> >::iterator it;
    
    for(it=v->indexList->begin(); it != v->indexList->end();++it){
    
      indexList->push_back(std::make_pair(varList->size()-1, (*it).second));
    
    }
  
  
  }

  virtual Quad_Expression* toTAC(TAC_Program *tac, SymTable *symtab){

     std::list<Xplode::Token *>::iterator itvar;
     std::list<Xplode::Token *>::iterator itvaraux;
     std::list<std::pair<int, Expression *> >::iterator itindex;
     itvar = varList->begin();
     itvaraux = varList->begin();
     ++itvaraux;
     int tamitvar=varList->size(), contitvar=1;
     itindex = indexList->begin();
     int tamitindex=indexList->size(), contitindex=1;
     Quad_Expression* res = NULL;
     Symbol *base_sym, *sym = symtab->find((*itvar)->value);

     if((varList->size()==1) && (indexList->size()==0)){
     
        std::string low((*itvar)->value);
        std::transform(low.begin(), low.end(), low.begin(), ::tolower);
        return new Quad_Variable(low, sym->offset, sym->porref, sym->isarg, sym->ntype->size);     
     }

     
     
     base_sym= sym;
     Instruction *inst;
     //Instruction *inst = new Instruction(ASSIGN_LABEL);
     //inst->result = tac->labelmaker->getlabel(TEMPORAL);      
     //inst->leftop = sym->name;
     //res= EMPTY_LABEL;
     //tac->push_quad(inst);
     TypeDeclaration *tipo = sym->ntype; 
        
     while(itvar != varList->end()){
     

      
      if(tipo->isarray()){

        //++itvar;
        //++contitvar;
        if((itvaraux == varList->end())&&(itindex==indexList->end())) break;
        
        ArrayType *arrtp = (ArrayType *) tipo;
        std::vector<int> *index= arrtp->takeindex();
        Quad_Expression* res_fin=res;
        
        res = itindex->second->toTAC(tac, symtab);
        ++itindex;
        tipo = tipo->ntype;
        int i=1;


        
        while(i<index->size()){
        
          if((itvaraux == varList->end())&&(itindex==indexList->end())) break;
          inst=new Instruction(MUL_INT_LABEL);
          inst->leftop = res;
          inst->rightop = new Quad_Constant((*index)[i]);
          inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));      
          tac->push_quad(inst);
          res = inst->result;
          
          inst=new Instruction(ADD_INT_LABEL);
          inst->leftop = res;
          inst->rightop = itindex->second->toTAC(tac, symtab);
          inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL)); 
          res = inst->result;     
          tac->push_quad(inst);
          tipo = tipo->ntype;
                   
          itindex++;                          
          i++;

        }

          inst=new Instruction(MUL_INT_LABEL);
          inst->leftop = res;
          inst->rightop = new Quad_Constant(tipo->size);
          inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));      
          tac->push_quad(inst);
          res = inst->result;

          if(res_fin!=NULL){
          
            inst=new Instruction(ADD_INT_LABEL);
            inst->leftop = res;
            inst->rightop = res_fin;
            inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL)); 
            res = inst->result;     
            tac->push_quad(inst);
                      
          
          }
        


              
      } else if (tipo->haveattributes()) {
      

      
        ++itvar;
        ++contitvar;
        ++itvaraux;
        if((itvar == varList->end())&&(itindex==indexList->end())) break;  

        TupleType *tup= (TupleType *) tipo;
        std::pair<TypeDeclaration*, int> *info = tup->takeattribute((*itvar)->value);

        if(res==NULL){
        
          res = new Quad_Constant(info->second);
                  
        }else { 
        
          inst=new Instruction(ADD_INT_LABEL);
          inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));      
          inst->leftop = res;
          inst->rightop = new Quad_Constant(info->second);
          tac->push_quad(inst); 
          res= inst->result;

        } 
        
        tipo = info->first;
       // std::cout << (long) tipo<< std::endl;
      
      } else {
      
        ++itvar;
        ++itvaraux;
        ++contitvar;
      
                    
      }
     
      
      
     }


     inst = new Instruction(ASSIGN_ARRAY_LABEL);
     inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));      
     inst->leftop = new Quad_Variable(base_sym->name, base_sym->offset, base_sym->porref, base_sym->isarg, tipo->size);
     inst->rightop = res;
     res = inst->result;  
     tac->push_quad(inst);

     return res;
        

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


  Instruction *lval_toTAC(TAC_Program *tac, SymTable *symtab){

     std::list<Xplode::Token *>::iterator itvar;
     std::list<Xplode::Token *>::iterator itvaraux;
     std::list<std::pair<int, Expression *> >::iterator itindex;
     itvar = varList->begin();
     itvaraux = varList->begin();
     ++itvaraux;
     int tamitvar=varList->size(), contitvar=1;
     itindex = indexList->begin();
     int tamitindex=indexList->size(), contitindex=1;
     Quad_Expression* res=NULL;
     Instruction *inst;
     Symbol *base_sym, *sym = symtab->find((*itvar)->value);

     if((varList->size()==1) && (indexList->size()==0)){
 
        inst = new Instruction(ASSIGN_LABEL);
        std::string low((*itvar)->value);
        std::transform(low.begin(), low.end(), low.begin(), ::tolower);     
        inst->result = new Quad_Variable(low, sym->offset, sym->porref, sym->isarg, sym->ntype->size);      
        inst->leftop =  NULL;
        inst->rightop = NULL; 
        return inst;     
     }

     

     base_sym= sym;
     
     //Instruction *inst = new Instruction(ASSIGN_LABEL);
     //inst->result = tac->labelmaker->getlabel(TEMPORAL);      
     //inst->leftop = sym->name;
     //res= EMPTY_LABEL;
     //tac->push_quad(inst);
     TypeDeclaration *tipo = sym->ntype; 
        
     while(itvar != varList->end()){
     

      
      if(tipo->isarray()){


        if((itvaraux == varList->end())&&(itindex==indexList->end())) break;
        
        ArrayType *arrtp = (ArrayType *) tipo;
        std::vector<int> *index= arrtp->takeindex();
        Quad_Expression* res_fin=res;
        
        res = itindex->second->toTAC(tac, symtab);
        ++itindex;
        tipo = tipo->ntype;
        int i=1;


        
        while(i<index->size()){

          if((itvaraux == varList->end())&&(itindex==indexList->end())) break; 
          inst=new Instruction(MUL_INT_LABEL);
          inst->leftop = res;
          inst->rightop = new Quad_Constant( (*index)[i]);
          inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));      
          tac->push_quad(inst);
          res = inst->result;
          
          inst=new Instruction(ADD_INT_LABEL);
          inst->leftop = res;
          inst->rightop = itindex->second->toTAC(tac, symtab);
          inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL)); 
          res = inst->result;     
          tac->push_quad(inst);
          tipo = tipo->ntype;
          
          itindex++;                          
          i++;

        }

          inst=new Instruction(MUL_INT_LABEL);
          inst->leftop = res;
          inst->rightop = new Quad_Constant(tipo->size);
          inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));      
          tac->push_quad(inst);
          res = inst->result;

          if(res_fin!=NULL){
          
            inst=new Instruction(ADD_INT_LABEL);
            inst->leftop = res;
            inst->rightop = res_fin;
            inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL)); 
            res = inst->result;     
            tac->push_quad(inst);
                      
          
          }
        
       
      } else if (tipo->haveattributes()) {
      
        ++itvar;
        ++itvaraux;        
        ++contitvar;
        if((itvar == varList->end())&&(itindex==indexList->end())) break;   
        TupleType *tup= (TupleType *) tipo;
        std::pair<TypeDeclaration*, int> *info = tup->takeattribute((*itvar)->value);
        if(res==NULL){
        
          res = new Quad_Constant(info->second);          
        
        }else { 
        
          inst=new Instruction(ADD_INT_LABEL);
          inst->result = new Quad_Variable(tac->labelmaker->getlabel(TEMPORAL));      
          inst->leftop = res;
          inst->rightop = new Quad_Constant(info->second);          
          tac->push_quad(inst); 
          res= inst->result;
        } 
        
        tipo = info->first;
        //std::cout << (long) tipo<< std::endl;
      
      } else {
      
        ++itvar;
        ++itvaraux;        
        ++contitvar;
      
                    
      }
     
      
      
     }


     inst = new Instruction(ASSIGN_TO_ARRAY_LABEL);

     std::string low(base_sym->name);
     std::transform(low.begin(), low.end(), low.begin(), ::tolower);     
     inst->result = new Quad_Variable(low, base_sym->offset );      
     inst->leftop = res;
     inst->rightop = NULL;     

     return inst;
        

  } 


  void firstcheck(SymTable *symtb){
  
  /*   Symbol *tempsymv, *tempsymt=NULL;
     SymTable *temptb = symtb;
     std::string arrstr[3];
     std::list<Xplode::Token *>::iterator itvar;
     std::list<std::pair<int, Expression *> >::iterator itindex;
     int index=0, dim,i,tam;
     Xplode::Token *auxtk;
     tam = varList->size()-1;
     itvar = varList->begin();
     itindex = indexList->begin();
     
     while(true){
     
      tempsymv = temptb->find((*itvar)->value);
     
      if(tempsymv==NULL) {//sin declarar en ningun ambito, campo incorrecto
     
        if(!tempsymt){ 
          errorlog->addError(8,(*itvar)->line,(*itvar)->column,&(*itvar)->value);
        }else{
          arrstr[0] = (*itvar)->value;
          arrstr[1] = tempsymt->name;
          arrstr[2] = tempsymt->ntype;
          errorlog->addError(9,(*itvar)->line,(*itvar)->column,arrstr);
        }   
        return;
      }
     
      dim = tempsymv->dimensions;
      i=0;
      while ((itindex!=indexList->end())&&(itindex->first==index)){
   
        ++itindex;
        ++i;
      }
     
      if((index!=tam)&&(i!=dim)) { //index malo
     
          errorlog->addError(10, (*itvar)->line, (*itvar)->column, &(*itvar)->value);
          return;
      }
     
      if(i>dim) { //ultimo posee mas [] de lo maximo
     
          errorlog->addError(10, (*itvar)->line, (*itvar)->column, &(*itvar)->value);
          return;
      }
     
      tempsymt = temptb->find(tempsymv->ntype);
      
      if(tempsymt==NULL){ //no consiguio el tipo
      
        arrstr[0] = (*itvar)->value;
        arrstr[1] = tempsymt->name;
        errorlog->addError(7, tempsymv->line, tempsymv->line, arrstr);
        return;      
      }
      
      ++index;
      auxtk = *itvar;
      ++itvar;
      temptb = (SymTable *) tempsymt->pt;
      
      if(!temptb){  // primitivo o arreglo
            
          if((itvar==varList->end())&&(itindex==indexList->end())){
          
            return; //correcto
          } else { //mal tipo para . 
            
            errorlog->addError(11,auxtk->line,auxtk->column, &tempsymt->name);
            return;          
          }
      } else {
      
        if (itvar==varList->end()){ //faltan campos
        
          
          //errorlog->addError(12, 0, 0, &tempsymt->name);
          return;          
        }
      
      
      }
      
      
     }
    
     // (){std::cout << std::string(tab, ' ') << "Declarada "<<*varList->begin()<<"\n";}
     // else {std::cout << std::string(tab, ' ') << "No declarada "<<*varList->begin()<<"\n";}
  */
  }

};


#endif
