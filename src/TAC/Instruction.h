#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad.h"
#include "Label.h"

#ifndef X_INSTRUCTION
#define X_INSTRUCTION


class Instruction: public Quad {
  public:
  
  std::string result;
  std::string leftop;
  std::string rightop;
  
  Instruction(){}
  Instruction(std::string o, std::string rs=EMPTY_LABEL, std::string l=EMPTY_LABEL, 
       std::string r=EMPTY_LABEL){
  
    op = o;
    result = rs;
    leftop = l;
    rightop = r;
  
  }

  std::string toString(){
  
    return "\t\t"+op+" "+result+" "+leftop+" "+rightop +"\n";
  }

    
};

#endif



