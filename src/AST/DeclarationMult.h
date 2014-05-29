#ifndef X_DECLARATIONMULT
#define X_DECLARATIONMULT

#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "TypeDeclaration.h"
#include "../Symbol.h"
#include "Node.h"
#include "Statement.h"
#include "../Token.h"
#include "../ErrorLog.h"

extern ErrorLog *errorlog;

struct decl{
  std::string var;
  int line;
  int column;
};



class DeclarationMult : public Statement {
  public:
  TypeDeclaration *ntype;
  std::list<decl> lvar;
  
  
  DeclarationMult(Node *n) {
      ntype = (TypeDeclaration *) n; 
  }
  
  void add(Xplode::Token *v){
    decl d;
    d.var = v->value;
    d.line = v->line;
    d.column = v-> column;
    lvar.push_back(d);
  }

  void print(int tab){
   
   std::cout << std::string(tab, ' ') << "DECLARATION\n";
   std::cout << std::string(tab, ' ') << "type: " << (long int) ntype<< "\n";
   for(std::list<decl>::iterator iter = lvar.begin(); iter != lvar.end(); ++iter){
       std::cout << std::string(tab, ' ') << "var: " << (*iter).var << "\n"; 
    }   
  }

  Symbol *toSymbol(){ 
  /*  return NULL;
    decl d;
    d = lvar.front();
    return new Symbol(d.var,ntype->name, d.line, d.column, false,
            ntype->max_index->size()); 
  */
  }

  Symbol *toSymbol2(){ 
   /* decl d;
    d = lvar.front();
    return new Symbol(d.var,ntype->name, d.line, d.column, false,
            ntype->max_index->size()); 
  
  */
  }

  std::list<Symbol *> toSymbols(){
   /* std::list <Symbol *> symbolList;
    decl d;
    for(std::list<decl>::iterator iter = lvar.begin(); iter != lvar.end(); ++iter){
       d = *iter; 
       symbolList.push_front(new Symbol(d.var,ntype->name,d.line,d.column,false,
            ntype->max_index->size())); 
    }

    return symbolList;
  
  */
  }


  void firstcheck(SymTable *symtb){
   /* 
    Symbol *nvar, *ntp;
    decl d;
    d = lvar.front();
    
    nvar = symtb->find(d.var);
    ntp = symtb->find(ntype->name);
    //falta
    if((nvar)&&(nvar->defined)) errorlog->addError(6,d.line, d.column,&d.var);    
    if(!ntp) errorlog->addError(7,d.line,d.column,&ntype->name); 
    if((ntp)&&(!ntp->defined)) errorlog->addError(7,d.line,d.column,&ntype->name); 
  */
  }  

};


#endif
