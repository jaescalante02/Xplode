#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

#ifndef X_MIPSOFFSET
#define X_MIPSOFFSET




class MIPS_Offset: public MIPS_Argument {
  public:
  
  int number; 
  int reg;
    
  MIPS_Offset(int r, int n=4){
  
    reg = r;
    number=n;
  
  }
  
  std::string toString(){ 
  
  std::stringstream aux;
  
  aux << number<<"($"<<reg<<")";
  
  return aux.str();
  
  }
     
};

#endif
