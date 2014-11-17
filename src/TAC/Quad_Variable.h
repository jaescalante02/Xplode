#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad_Expression.h"

#ifndef X_QUADVAR
#define X_QUADVAR

#define NO_OFFSET_NUM -1000000


class Quad_Variable : public Quad_Expression {
  public:
  
  std::string var;
  int offset;

  Quad_Variable(){}  
  
  Quad_Variable(std::string v, int off= NO_OFFSET_NUM){  
    
    if(off==NO_OFFSET_NUM){
    
      var=v;
    
    }else{
    
      std::stringstream aux;
      aux << off;    
     var = v+"_"+aux.str();  
    } 
    offset = off;
  
  }
  
  
  std::string toString(){ 
  
    if (offset==NO_OFFSET_NUM) return var;
  
    std::stringstream aux;
    aux << offset;
    return var + "(" + aux.str() + ")";
  }

    
};

#endif



