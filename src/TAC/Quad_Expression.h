#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

#ifndef X_QUADEXP
#define X_QUADEXP


class Quad_Expression{
  public:
  


  Quad_Expression(){}  
  
  virtual std::string toString(){ return "";}
  
  virtual bool isconstant(){ return false;}

    
};

#endif



