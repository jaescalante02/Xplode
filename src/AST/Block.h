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
#include "../TAC/TAC_Program.h"

#ifndef X_BLOCK
#define X_BLOCK


class Block : public Node {
  public:
  NodeList *declarationList; 
  NodeList *statementList; 
  SymTable *table;

  Block(SymTable *stb, NodeList *s){ 

    table= stb; //new SymTable(); 
    declarationList = 0; 
    statementList = s; 
    this->setFathers();
  }

  Block(SymTable *stb, NodeList *d, NodeList *s) { 

    table = stb; //new SymTable(); 
    declarationList = d; 
    statementList = s; 
    this->setFathers();
  }

  void print(int tab){
   std::cout << std::string(tab, ' ') << "BLOCK \n";
   if (declarationList != 0 ){
    std::cout << std::string(tab, ' ') << "DECLARATIONS \n";
    declarationList->print(tab+2);
   }
   std::cout << std::string(tab, ' ') << "STATEMENTS\n";
   statementList->print(tab+2);
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
  
  void toTAC(TAC_Program *tac){
  
      std::list<Node *>::iterator iter;
  
      for(iter = (*statementList).nodeList.begin(); 
      iter != (*statementList).nodeList.end(); ++iter){
      
        Statement *st = (Statement *) *iter;          
        st->toTAC(tac, table); 
      }
  
  }


};

#endif
