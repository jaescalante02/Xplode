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
#include "FunctionType.h"
#include "TupleType.h"
#include "../Token.h"


#ifndef X_FUNCTIONDEF
#define X_FUNCTIONDEF

class Function : public CompoundStatement {
  public:

  TypeDeclaration *ntype;
  SymTable* symtb;
  std::string returnType;
  std::string fname;

  Function(SymTable *s,std::string name,Node *t,Node *b) { 

    symtb = s;
    ntype = (TypeDeclaration *) t; 
    //TypeDeclaration *tp = (TypeDeclaration *) r; 
    fname =name; 
    //parameters = (TupleType *) p; 
    block  = (Block *) b;
    //if (parameters != 0){
    //  block->table->add(parameters);
    //}
  }

  void print(int tab){
   
   std::cout << std::string(tab, ' ') << "FUNCTION\n";
   std::cout << std::string(tab, ' ') << "name: " << fname << "\n";
   ntype->print(tab);
    block->print(tab+2);
  }

  void setFather(SymTable *s){
  
    if(block!=NULL) block->setFather(s);
  
  }

  Symbol *toSymbol() {}//return new Symbol(name,NULL, line, column); }

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

  void printTable() {

     symtb->print();
     if (block!=NULL) block->printTable();

  }


  void toTAC(TAC_Program *tac, SymTable *symtab, std::string cont_label, 
             std::string break_label)
  {
  
    tac->putcomment("FUNCTION", line, column, EMPTY_LABEL);
    tac->push_quad(new Label(fname));
    block->toTAC(tac, cont_label, break_label);
    FunctionType *fun = ( FunctionType *) ntype;
    if(fun->returnType->numtype!=TYPE_VOID)
      tac->push_quad(new Instruction(RETURN_LABEL, new Quad_Variable("0")));
    else
      tac->push_quad(new Instruction(RETURN_LABEL));
    tac->new_block();
  
  
  
  }


};

#endif

