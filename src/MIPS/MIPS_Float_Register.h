#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include "MIPS_Register.h"

#ifndef X_MIPSFREG
#define X_MIPSFREG




class MIPS_Float_Register: public MIPS_Register{
  public:
  
    
  MIPS_Float_Register(int n){
  
    number=n;
  }
  
   
  std::string toString(){ 
  
    std::stringstream aux;
  
    aux << "$f"<<number;
  
    return aux.str();
  
  }
     
};

#endif

