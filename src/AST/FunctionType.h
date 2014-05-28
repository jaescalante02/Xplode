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

#ifndef X_FUNCTYPE
#define X_FUNCTYPE

class FunctionType : public TypeDeclaration {

  

  public:

    TypeDeclaration *returnType, *arguments, *extend;
    
    FunctionType(Node *ret, Node *args,Node *e) {

      numtype = TYPE_FUNCTION;
      returnType = (TypeDeclaration *) ret;
      arguments = (TypeDeclaration *) args;
      extend = (TypeDeclaration *) e;

    }

    Symbol *toSymbol(Xplode::Token *s){
    
    return new Symbol(s->value,this,s->line,s->column);
    
    
    }


    void print(){}


};

#endif
