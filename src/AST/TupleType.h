#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"
#include "TypeDeclaration.h"

#ifndef X_TUPLETYPE
#define X_TUPLETYPE

class TupleType : public TypeDeclaration {

  public:

    std::list<TypeDeclaration *> *types;
    std::list<std::string> *names;


    TupleType(){
    
    types = new std::list<TypeDeclaration *>;
    names = new std::list<std::string>;
    numtype = TYPE_TUPLE;
    
    }
    
    void add(Node *t, std::string name){
    
    types->push_back((TypeDeclaration *) t);
    names->push_back(name);
    
    
    }
 
    void addType(Node *t){
    
      types->push_back((TypeDeclaration *) t);
    
    }


    Symbol *toSymbol(Xplode::Token *s){
    
    return new Symbol(s->value,this,s->line,s->column);
    
    
    }

    void print(){}


};

#endif
