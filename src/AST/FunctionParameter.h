#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"

#ifndef X_FUNCPARAMETER
#define X_FUNCPARAMETER

class FunctionParameter : public Node {
  public:
  std::string type;
  std::string var;
  
FunctionParameter(std::string t, std::string v) { type = t; var = v; }
  void print(){
   std::cout << "PARAMETER\n";
   std::cout << "type: " << type << "\n";
   std::cout << "var: " << var << "\n";
  }

};

#endif
