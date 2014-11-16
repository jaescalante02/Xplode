#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

#ifndef X_MIPSVAR
#define X_MIPSVAR




class MIPS_Variable: public MIPS_Argument {
  public:
  
  std::string name;
    
  MIPS_Variable(std::string n){
  
    name=n;
  
  }
 
  std::string toString(){ 
  
    return name;
  
  }
  
     
};

#endif
