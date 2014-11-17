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

  Quad_Constant(){}  
  
  Quad_Constant(int n){
  
    num = n;
  
  }
  
  
  std::string toString(){ 
    
    std::stringstream aux;
    aux << num;
    return aux.str();
  }

  virtual bool isconstant(){ return true;}
    
};

#endif



