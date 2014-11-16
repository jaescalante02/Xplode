#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

#ifndef X_MIPSLABEL
#define X_MIPSLABEL




class MIPS_Label: public MIPS_Instruction {
  public:
    
  MIPS_Label(std::string n){
  
    op=n;
  
  }
  
  
  virtual std::string toString(){
  
    return op+":\n";
  
  }  
    
};

#endif

