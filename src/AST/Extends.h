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
#include "../Symbol.h"


#ifndef X_EXTENDS
#define X_ENTENDS


class Extends : public Node {
  public:
  std::string type;
  
  Extends(Node *t) {     
    //TypeDeclaration *tp = (TypeDeclaration *) t; 
    //type = tp->name; 
  }

  void print(int tab){
   std::cout << std::string(tab, ' ') << "EXTENDS\n";
   std::cout << std::string(tab, ' ') << "type: " << type << "\n";
  }

  Symbol *toSymbol(){ return NULL;}


  void firstcheck(){ }

};

#endif
