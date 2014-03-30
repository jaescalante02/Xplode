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
#include "../Symbol.h"
#include "Block.h"
#include "TypeDeclaration.h"
#include "../Token.h"


#ifndef X_FUNCTIONDEF
#define X_FUNCTIONDEF

class Function : public CompoundStatement {
  public:
  std::string name;
  std::string returnType;
  NodeList *parameters;

  Function(Xplode::Token *n, Node *r,Node *b, NodeList *p = 0 ) { 

    name = n->value; 
    TypeDeclaration *tp = (TypeDeclaration *) r; 
    returnType = tp->name; 
    parameters = p; 
    block  = (Block *) b;
    if (parameters != 0){
      block->table->add(parameters);
    }
    line = n->line;
    column = n->column;
  }

  void print(){
   std::cout << "FUNCTION\n";
   std::cout << "name: " << name << "\n";
   std::cout << "return: "<< returnType << "\n";
   
   if (parameters != 0){
    parameters->print();
   }
    block->print();
  }

  void setFather(SymTable *s){
  
    if(block!=NULL) block->setFather(s);
  
  }

  Symbol *toSymbol() {return new Symbol(name,returnType, line, column, 4, 0); }

  void firstcheck(SymTable *symtb){

    /*SymTable *root = symtb->getRoot();
    Declaration *decl;
    std::list<Node *>::iterator iter;
    
    if(parameters != NULL)
          for(iter = (*parameters).nodeList.begin();
              iter != (*parameters).nodeList.end(); ++iter){
     
                decl = (Declaration *) *iter;          
                decl->firstcheck(root); 
          }
    
    */ //falta verificar los parametros de las funciones 
    
    if(block!=NULL) block->firstcheck();
  
  }



};

#endif

