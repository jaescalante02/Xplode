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
    
  MIPS_Offset(int n){
  
    number=n;
  
  }
  
  std::string toString(){ 
  
  std::stringstream aux;
  
  aux << "4($"<<number<<")";
  
  return aux.str();
  
  }
     
};

#endif
