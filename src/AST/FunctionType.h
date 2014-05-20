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

  TypeDeclaration *returnType, *arguments;

  public:

    FunctionType(Node *ret, Node *args){

      numtype = TYPE_FUNCTION;
      returnType = (TypeDeclaration *) ret;
      arguments = (TypeDeclaration *) args;
      

    }


    void print(){}


};

#endif
