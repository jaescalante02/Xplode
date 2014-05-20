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

#ifndef X_ARRAYTYPE
#define X_ARRAYTYPE

class ArrayType : public TypeDeclaration {

  public:

  int limit;

    ArrayType(Node *n, int lim){

      ntype = (TypeDeclaration *) n;
      numtype = TYPE_ARRAY;
      limit = lim;

    }


    void print(){}


};

#endif
