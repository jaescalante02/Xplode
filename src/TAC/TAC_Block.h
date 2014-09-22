#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad.h"



#ifndef X_TACBLOCK
#define X_TACBLOCK

class TAC_Block {
  public:
  
  std::list<Quad* > *instructions;
  
  TAC_Block(){
  
    instructions = new std::list<Quad* >;
  
  }

  void addquad(Quad *q){
  
    instructions->push_back(q);
  
  }
    
  std::string toString(){

    std::stringstream buffer;
  
    for(std::list<Quad *>::iterator iter = instructions->begin(); iter != instructions->end(); ++iter){
         buffer << (*iter)->toString();
    }
    return buffer.str();
  
  }  
    
};

#endif



