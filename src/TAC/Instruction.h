#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad.h"
#include "Quad_Variable.h"
#include "Quad_Constant.h"
#include "Label.h"

#ifndef X_INSTRUCTION
#define X_INSTRUCTION


class Instruction: public Quad {
  public:
  
  Quad_Expression* result;
  Quad_Expression* leftop;
  Quad_Expression* rightop;
  
  Instruction(){
    
        result = NULL;
        leftop = NULL;
        rightop = NULL; 
  
  
  }
  Instruction(std::string o, Quad_Expression* rs=NULL, Quad_Expression* l=NULL, 
       Quad_Expression* r=NULL){
  
    op = o;
    result = rs;
    leftop = l;
    rightop = r;
  
  }

  std::string toString(){
    if((result==NULL) && (rightop==NULL) && (leftop==NULL)){
    
      return "\t\t"+op+"\n";
    } else if ((rightop==NULL) && (leftop==NULL)) {
    
    
      return "\t\t"+op+" "+result->toString()+"\n";
    } else if (rightop==NULL) {
    
    
      return "\t\t"+op+" "+result->toString()+" "+leftop->toString()+"\n";
    } else
    
      return "\t\t"+op+" "+result->toString()+" "+leftop->toString()+" "+rightop->toString() +"\n";
      
  }

    
};

#endif



