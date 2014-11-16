#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

#ifndef X_QUAD
#define X_QUAD


class Quad {
  public:
  
  std::string op;


  Quad(){}  
  
  Quad(std::string o){
  
    op = o;

  
  }
  
  
  virtual std::string toString(){}

  virtual bool isinstruction(){ return false; }
  
  virtual bool islabel(){ return false; }    
    
};

#endif



