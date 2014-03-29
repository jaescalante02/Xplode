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

extern ErrorLog *errorlog;

class Variable : public Expression {
  public:

  std::list<std::string> *varList;
  std::list<std::pair<int, Expression *> > *indexList;
  
  Variable(std::string v){
    varList = new std::list<std::string>; 
    indexList = new std::list<std::pair<int, Expression *> >;
    varList->push_back(v);
  }
  
  void print(){ 
   std::cout << "VARIABLE\n";
   for(std::list<std::string >::iterator iter = varList->begin(); 
      iter != varList->end(); ++iter){
      
     std::cout << "field: " << *iter << "\n"; 
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
  
     Symbol *tempsym;
     SymTable *temptb = symtb;
     std::list<std::string>::iterator itvar;
     std::list<std::pair<int, Expression *> >::iterator itindex;
     int index=0, dim,i,tam;
     
     tam = varList->size()-1;
     itvar = varList->begin();
     itindex = indexList->begin();
     
     while(true){
     
      tempsym = temptb->find(*itvar);
     
      if(tempsym==NULL) {//sin declarar en ningun ambito, campo incorrecto
     
        errorlog->addError(0,0,0,*itvar);
        return;
      }
     
      dim = tempsym->dimensions;
      i=0;
      while ((itindex!=indexList->end())&&(itindex->first==index)){
   
        ++itindex;
        ++i;
      }
     
      if((index!=tam)&&(i!=dim)) { //index malo
     
          errorlog->addError(0,0,0,"[]");
          return;
      }
     
      if(i>dim) { //ultimo posee mas [] de lo maximo
     
          errorlog->addError(0,0,0,"[]2");
          return;
      }
     
      tempsym = temptb->find(tempsym->ntype);
      
      if(tempsym==NULL){ //no consiguio el tipo
      
        errorlog->addError(0,0,0,"tipo");
        return;      
      }
      
      ++index;
      ++itvar;
      temptb = (SymTable *) tempsym->pt;
      
      if(!temptb){  // primitivo
            
          if((itvar==varList->end())&&(itindex==indexList->end())){
          
            return; //correcto
          } else { //mal tipo para . y un caso [] con [] en exceso
        
            errorlog->addError(0,0,0,".");
            return;          
          }
      } else {
      
        if (itvar==varList->end()){ //faltan campos
        
          errorlog->addError(0,0,0,"..");
          return;          
        }
      
      
      }
      
      
     }
    
     // (){std::cout << "Declarada "<<*varList->begin()<<"\n";}
     // else {std::cout << "No declarada "<<*varList->begin()<<"\n";}
  
  }

};


#endif
