#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "CompoundStatement.h"
#include "NodeList.h"
#include "../SymTable.h"
#include "Block.h"


#ifndef X_MAINPROGRAM
#define X_MAINPROGRAM

#define INT_SYMBOL new Symbol("int","_type",0,0,true,0)
#define FLOAT_SYMBOL new Symbol("float","_type",0,0,true,0)
#define CHAR_SYMBOL new Symbol("char","_type",0,0,true,0)
#define BOOL_SYMBOL new Symbol("bool","_type",0,0,true,0)

class Program : public CompoundStatement {

public:
  NodeList *definitionList; 
  SymTable *table;

  Program(Node *b){ 

    table= new SymTable();
    this->insertPrimitives(); 
    definitionList = 0; 
    block = (Block *) b;
    block->setFather(table); 

  }

  Program(NodeList *d, Node *b){ 

    table = new SymTable(d); 
    this->insertPrimitives(); 
    definitionList = d; 
    this->setFathers();
    block = (Block *) b; 
    block->setFather(table);

  }

  void insertPrimitives(){

    table->insert(INT_SYMBOL);
    table->insert(FLOAT_SYMBOL); 
    table->insert(CHAR_SYMBOL);   
    table->insert(BOOL_SYMBOL);   

  }

  void print(){
    std::cout << "PROGRAM \n";
    if (definitionList != 0 ){
     std::cout << "DEFINITIONS \n";
     definitionList->print();
    }
    block->print();
  }

  void printTable(){

    if(table!=NULL) table->print();
    std::list<Node *>::iterator iter;
    Statement *st;
    if (definitionList!=NULL) 
      for(iter = (*definitionList).nodeList.begin(); iter != (*definitionList).nodeList.end(); ++iter){
            st = (Statement *) *iter;
            st->printTable(); 
      }
  
    if(block!=NULL) block->printTable();

  }

  void setFathers() {

    Statement *st;
    std::list<Node *>::iterator iter;
    for(iter = (*definitionList).nodeList.begin(); 
        iter != (*definitionList).nodeList.end(); ++iter){
        
        st = (Statement *) *iter;          
        st->setFather(table); 
    }


  }

  void check(){
  
    this->firstcheck();
  
  }

  void firstcheck(){

    std::list<Node *>::iterator iter;
    Statement *st;
    if (definitionList!=NULL) 
      for(iter = (*definitionList).nodeList.begin(); iter != (*definitionList).nodeList.end(); ++iter){
            st = (Statement *) *iter;
            st->firstcheck(table); 
      }
  
    if(block!=NULL) block->firstcheck();  
    
  
  }

};

#endif
