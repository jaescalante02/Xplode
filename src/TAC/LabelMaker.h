#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

#ifndef X_LABELMAKER
#define X_LABELMAKER

class LabelMaker {
  public:
  
  std::map<std::string, int> *counter;
  
  LabelMaker(){
  
    counter = new std::map<std::string, int>;
  
  }

  std::string getlabel(std::string prefix){
  
      char label[60];              
      (*counter)[prefix]++;
      sprintf(label,"%s%d", prefix.c_str(), (*counter)[prefix]);
      return std::string(label);
    
  }
    
};

#endif
