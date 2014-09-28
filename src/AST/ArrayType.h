#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <vector> 
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
      size = lim*ntype->size;
      numtype = TYPE_ARRAY;
      limit = lim;

    }

    std::vector<int> *takeindex(){
    
      std::vector<int> *v;
    
      if(ntype->isarray()){
      
        ArrayType *atp = (ArrayType *) ntype;
        v = atp->takeindex();
        v->push_back(limit);
        return v;        
      
      } else {
      
        v = new std::vector<int>;
        v->push_back(limit);
        return v;
      
      
      }
    
    
    }


    void print(int tab){}


};

#endif
