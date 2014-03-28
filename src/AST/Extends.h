#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"
#include "TypeDeclaration.h"

#ifndef X_EXTENDS
#define X_ENTENDS


class Extends : public Node {
  public:
  std::string type;
  
  Extends(Node *t) {     
    TypeDeclaration *tp = (TypeDeclaration *) t; 
    type = tp->name; 
  }

  void print(){
   std::cout << "EXTENDS\n";
   std::cout << "type: " << type << "\n";
  }

};

#endif
