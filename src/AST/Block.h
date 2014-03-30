#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"
#include "NodeList.h"
#include "Declaration.h"
#include "../SymTable.h"
#include "Statement.h"

#ifndef X_BLOCK
#define X_BLOCK


class Block : public Node {
  public:
  NodeList *declarationList; 
  NodeList *statementList; 
  SymTable *table;

  Block(NodeList *s){ 

    table= new SymTable(); 
    declarationList = 0; 
    statementList = s; 
    this->setFathers();
  }

  Block(NodeList *d, NodeList *s) { 

    table = new SymTable(d); 
    declarationList = d; 
    statementList = s; 
    this->setFathers();
  }

  void print(){
   std::cout << "BLOCK \n";
   if (declarationList != 0 ){
    std::cout << "DECLARATIONS \n";
    declarationList->print();
   }
   std::cout << "STATEMENTS\n";
   statementList->print();
  }

  void printTable(){

    table->print();
    Statement *st;
    std::list<Node *>::iterator iter;
    for(iter = (*statementList).nodeList.begin(); 
      iter != (*statementList).nodeList.end(); ++iter){
      
        st = (Statement *) *iter;          
        st->printTable(); 
    }       
  }

  virtual void setFathers() {

    Statement *st;
    std::list<Node *>::iterator iter;
    for(iter = (*statementList).nodeList.begin(); 
        iter != (*statementList).nodeList.end(); ++iter){
        
        st = (Statement *) *iter;          
        st->setFather(table); 
    }


  }

  virtual void setFather(SymTable *s){

    table->setFather(s);

  }

  void firstcheck(){
  
    Declaration *decl;
    Statement *st;
    std::list<Node *>::iterator iter;
    SymTable *root = table->getRoot();
    
    if(declarationList != NULL)
          for(iter = (*declarationList).nodeList.begin();
              iter != (*declarationList).nodeList.end(); ++iter){
     
                decl = (Declaration *) *iter;          
                decl->firstcheck(root); 
          } 
    
    for(iter = (*statementList).nodeList.begin();
     iter != (*statementList).nodeList.end(); ++iter){
     
        st = (Statement *) *iter;          
        st->firstcheck(table); 
    } 
  
  
  }


};

#endif
