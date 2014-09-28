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

//TYPE
#define TYPE_ERROR 0
#define TYPE_VOID  1
#define TYPE_INT   2
#define TYPE_BOOL  3
#define TYPE_CHAR  4
#define TYPE_FLOAT 5
#define TYPE_ARRAY 6
#define TYPE_TUPLE 7
#define TYPE_FUNCTION 8
#define TYPE_STRING 9
#define TYPE_UNION 10
#define TYPE_TYPE 11
//SIZE

#define SIZE_INT   4
#define SIZE_BOOL  1
#define SIZE_CHAR  1
#define SIZE_FLOAT 4
#define SIZE_POINTER 4

#define ALIGNMENT 1

class TypeDeclaration: public Node {

  public:

  TypeDeclaration *ntype;
  int numtype;
  int size;
  std::string name;

    TypeDeclaration(){}
    TypeDeclaration(int num,int s=0, TypeDeclaration *n=NULL) {

      numtype = num;
      ntype = n;
      size = s;
    }

   

    void print(int tab){
        std::cout <<(long int) numtype << std:: endl;

    }

    bool isarray(){ return (this->numtype==TYPE_ARRAY); }

    bool isfunction(){ return (this->numtype==TYPE_FUNCTION); }
    
    bool isnumeric(){ return ((this->numtype==TYPE_INT) || ((this->numtype==TYPE_FLOAT))); }
    
    bool isprimitive(){ return ((this->numtype==TYPE_INT) || (this->numtype==TYPE_FLOAT) 
                             || (this->numtype==TYPE_CHAR) || (this->numtype==TYPE_BOOL)); }

    bool haveattributes() {return ((this->numtype==TYPE_UNION) || ((this->numtype==TYPE_TYPE)));}

};

#endif
