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
    //TypeDeclaration *tp = (TypeDeclaration *) n; 
    //name = tp->name;
  }
  void print(int tab){
   std::cout << std::string(tab, ' ') << "PROCEDURE TYPE\n";
   std::cout << std::string(tab, ' ') << "type: " << name << "\n";
  }

};


#endif
