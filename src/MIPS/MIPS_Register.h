#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

#ifndef X_MIPSREG
#define X_MIPSREG




class MIPS_Register: public MIPS_Argument {
  public:
  
  int number;
    
  MIPS_Register(int n){
  
    number=n;
  }
  
   
  std::string toString(){ 
  
    std::stringstream aux;
  
    aux << "$"<<number;
  
    return aux.str();
  
  }
     
};

#endif

