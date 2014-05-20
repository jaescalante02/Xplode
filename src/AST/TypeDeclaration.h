#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"

#ifndef X_TYPEDECLARATION
#define X_TYPEDECLARATION


#define TYPE_ERROR 0
#define TYPE_VOID  1
#define TYPE_INT   2
#define TYPE_BOOL  3
#define TYPE_CHAR  4
#define TYPE_FLOAT 5
#define TYPE_ARRAY 6
#define TYPE_TUPLE 7
#define TYPE_FUNCTION 8


class TypeDeclaration: public Node {

  public:

  TypeDeclaration *ntype;
  int numtype;

    TypeDeclaration(){}
    TypeDeclaration(int num, TypeDeclaration *n=NULL) {

      numtype = num;
      ntype = n;

    }


    void print(){}


};

#endif
