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
  
     if(symtb->find(this)){std::cout << "Declarada "<<*varList->begin()<<"\n";}
     else {std::cout << "No declarada "<<*varList->begin()<<"\n";}
  
  }

};


#endif
