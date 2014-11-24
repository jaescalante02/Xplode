#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad_Expression.h"

#ifndef X_QUADCONST
#define X_QUADCONST


class Quad_Constant : public Quad_Expression {
  public:
  
  int num;
  std::string val;

  Quad_Constant(){}  
  
  Quad_Constant(int n, std::string v=""){
  
    if(v==""){
    
      std::stringstream aux;
      aux << n;
      val = aux.str();
    
    } else {
  
      val = v;
    
    }
    num = n;
  
  }
  
  
  std::string toString(){ 
    

    return val;
  }

  virtual bool isconstant(){ return true;}
    
};

#endif



