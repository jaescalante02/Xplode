#ifndef X_VARIABLEEXP
#define X_VARIABLEEXP

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
#include "../ErrorLog.h"
#include "../Token.h"

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
  
  void print(){ 
   std::cout << "VARIABLE\n";
   for(std::list<Xplode::Token *>::iterator iter = varList->begin(); 
      iter != varList->end(); ++iter){
      
     std::cout << "field: " << (*iter)->value << "\n"; 
   }
   for(std::list<std::pair<int, Expression *> >::iterator iter = indexList->begin();
       iter != indexList->end(); ++iter){
       
     std::cout << "index: " << (*iter).first <<"|"<<"\n";
     iter->second->print(); 
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

  void firstcheck(SymTable *symtb){
  
     Symbol *tempsymv, *tempsymt=NULL;
     SymTable *temptb = symtb;
     std::string arrstr[3];
     std::list<Xplode::Token *>::iterator itvar;
     std::list<std::pair<int, Expression *> >::iterator itindex;
     int index=0, dim,i,tam;
     
     tam = varList->size()-1;
     itvar = varList->begin();
     itindex = indexList->begin();
     
     while(true){
     
      tempsymv = temptb->find((*itvar)->value);
     
      if(tempsymv==NULL) {//sin declarar en ningun ambito, campo incorrecto
     
        if(!tempsymt){ 
          errorlog->addError(8,0,0,&(*itvar)->value);
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
      
        errorlog->addError(7, 0, 0, &tempsymv->ntype);
        return;      
      }
      
      ++index;
      ++itvar;
      temptb = (SymTable *) tempsymt->pt;
      
      if(!temptb){  // primitivo o arreglo
            
          if((itvar==varList->end())&&(itindex==indexList->end())){
          
            return; //correcto
          } else { //mal tipo para . 
            
            errorlog->addError(11,0,0, &tempsymt->name);
            return;          
          }
      } else {
      
        if (itvar==varList->end()){ //faltan campos
        
          
          errorlog->addError(12, 0, 0, &tempsymt->name);
          return;          
        }
      
      
      }
      
      
     }
    
     // (){std::cout << "Declarada "<<*varList->begin()<<"\n";}
     // else {std::cout << "No declarada "<<*varList->begin()<<"\n";}
  
  }

};


#endif
