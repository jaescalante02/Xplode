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
#include "../TAC/LabelMaker.h"
#include "../TAC/TAC_Block.h"
#include "../TAC/TAC_Program.h"

#ifndef X_MAINPROGRAM
#define X_MAINPROGRAM

#define INT_SYMBOL new Symbol(true,"_int",new TypeDeclaration(TYPE_INT,SIZE_INT),0,0,true)
#define FLOAT_SYMBOL new Symbol(true, "_float",new TypeDeclaration(TYPE_FLOAT,SIZE_FLOAT),0,0,true)
#define CHAR_SYMBOL new Symbol(true,"_char",new TypeDeclaration(TYPE_CHAR,SIZE_CHAR),0,0,true)
#define BOOL_SYMBOL new Symbol(true,"_bool",new TypeDeclaration(TYPE_BOOL,SIZE_BOOL),0,0,true)
#define VOID_SYMBOL new Symbol(true,"_void",new TypeDeclaration(TYPE_VOID),0,0,true)
#define STRING_SYMBOL new Symbol(true,"_string",new TypeDeclaration(TYPE_STRING),0,0,true)
#define ERROR_SYMBOL new Symbol(true,"_error",new TypeDeclaration(TYPE_ERROR),0,0,true)

class Program : public CompoundStatement {

public:
  NodeList *definitionList; 
  SymTable *table;

  Program(SymTable *stb, Node *b){ 

    table= stb;
    //this->insertPrimitives(); 
    definitionList = 0; 
    block = (Block *) b;
    block->setFather(table); 

  }

  Program(SymTable *stb, NodeList *d, Node *b){ 

    table = stb; 
    //this->insertPrimitives(); 
    definitionList = d; 
    //this->setFathers();
    block = (Block *) b; 
    block->setFather(table);

  }

  void insertPrimitives(){

    table->insert(INT_SYMBOL);
    table->insert(FLOAT_SYMBOL); 
    table->insert(CHAR_SYMBOL);   
    table->insert(BOOL_SYMBOL);   
    table->insert(VOID_SYMBOL);

  }

  void print(int tab = 0){
    std::cout << std::string(tab, ' ') << "PROGRAM \n";
    if (definitionList != 0 ){
     std::cout << std::string(tab, ' ') << "DEFINITIONS \n";
     definitionList->print(tab+2);
    }
    block->print(tab+2);
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

    //this->checktypes(table, table, NULL);
    std::list<Node *>::iterator iter;
    Statement *st;
    if (definitionList!=NULL) 
      for(iter = (*definitionList).nodeList.begin(); iter != (*definitionList).nodeList.end(); ++iter){
            st = (Statement *) *iter;
            st->firstcheck(table); 
      }
  
    if(block!=NULL) block->firstcheck();  
    
  
  }

  void checktypes(SymTable *tb, SymTable* root, Symbol *s){
  
  /*  std::map<std::string, Symbol *>::iterator it;
  
    for(it=tb->table->begin();it!=tb->table->end();++it){
    
      if(s==it->second) error;
      if(it->second->defined>1) 
        checktypes((SymTable *) it->second->pt, root,it->second);
    
    
    }
  */
  }


  TAC_Program *toTAC(std::string name){
  
    TAC_Program *tac = new TAC_Program(name);
    int c = ((block->table->totaloffset)%ALIGNMENT)?(ALIGNMENT-((block->table->totaloffset)%ALIGNMENT)):0;
    tac->push_quad(new Instruction(ALLOC_LABEL, new Quad_Constant(block->table->totaloffset+c))); 
    block->toTAC(tac, EMPTY_LABEL, EMPTY_LABEL);
    tac->push_quad(new Instruction(EXIT_LABEL));
    tac->new_block();
    
    std::list<Node *>::iterator iter;
    Statement *st;
    if (definitionList!=NULL) 
      for(iter = (*definitionList).nodeList.begin(); iter != (*definitionList).nodeList.end(); ++iter){
            st = (Statement *) *iter;
            st->toTAC(tac, table, EMPTY_LABEL, EMPTY_LABEL); 
      }
  
    return tac;
  }


};

#endif
