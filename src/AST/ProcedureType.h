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

#ifndef X_PROCEDURETYPE
#define X_PROCEDURETYPE

class ProcedureType : public Node {
  public:
  std::string name;
  
  ProcedureType(Node *n) { 
    TypeDeclaration *tp = (TypeDeclaration *) n; 
    name = tp->name;
  }
  void print(){
   std::cout << "PROCEDURE TYPE\n";
   std::cout << "type: " << name << "\n";
  }

};


#endif
