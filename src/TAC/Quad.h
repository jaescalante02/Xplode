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
  std::string result;
  std::string leftop;
  std::string rightop;

  Quad(){}  
  
  Quad(std::string o, std::string rs, std::string l, 
       std::string r){
  
    op = o;
    result = rs;
    leftop = l;
    rightop = r;
  
  }
  
  
  virtual std::string toString(){}

    
};

#endif



