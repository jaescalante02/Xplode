#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <vector> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad.h"



#ifndef X_TACBLOCK
#define X_TACBLOCK

class TAC_Block {
  public:
  
  std::vector<Quad* > *instructions;
  
  TAC_Block(){
  
    instructions = new std::vector<Quad* >;
  
  }

  void addquad(Quad *q){
  
    instructions->push_back(q);
  
  }
  
  void push_quad(Quad *ptr){
    (*instructions).push_back(ptr);
  }
    
  std::string toString(){

    std::stringstream buffer;
  
    for(int i=0;i<(*instructions).size();i++){
         buffer << ((*instructions)[i])->toString();
    }
    return buffer.str();
  
  }  
    
};

#endif



