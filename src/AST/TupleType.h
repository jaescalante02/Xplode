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

    std::list< std::pair<TypeDeclaration*, int>* > *types;
    std::list<std::string> *names;
    TypeDeclaration *extend;


    TupleType(){
    
    types = new std::list< std::pair<TypeDeclaration*, int>* >;
    names = new std::list<std::string>;
    numtype = TYPE_TUPLE;
    extend = NULL;
    size=0;
    
    }
    
    void add(Node *t, std::string name){
    
    types->push_back(new std::pair<TypeDeclaration*, int>((TypeDeclaration *) t, 0));
    names->push_back(name);
    
    
    }
 
    void addType(Node *t){
    
      types->push_back(new std::pair<TypeDeclaration*, int>((TypeDeclaration *) t, 0));
    
    }


    Symbol *toSymbol(Xplode::Token *s){
    
    return new Symbol(s->value,this,s->line,s->column);
    
    
    }
    
    void make_union(){
    
      numtype = TYPE_UNION;
      size = 0;
      for(std::list< std::pair<TypeDeclaration*, int>* >::iterator iter = types->begin(); 
      iter != types->end(); ++iter){
      
        if(size<(*iter)->first->size) size = (*iter)->first->size;
      
      }  
    
    }

    void make_type(){
    
      numtype = TYPE_TYPE;
      size = 0;
      for(std::list< std::pair<TypeDeclaration*, int>* >::iterator iter = types->begin(); 
      iter != types->end(); ++iter){
        (*iter)->second = size;
         size += (*iter)->first->size;
      
      }  
    
    }

    void print(){}


};

#endif
