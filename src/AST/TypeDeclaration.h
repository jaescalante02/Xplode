#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"

#ifndef X_TYPEDECLARATION
#define X_TYPEDECLARATION

class TypeDeclaration: public Node {

  public:

    std::string name;
    std::list<std::string> *max_index;

    TypeDeclaration(std::string n) {

      name = n;
      max_index = new std::list<std::string>;

    }

    void addDimension(std::string number){ (*max_index).push_front(number); }

    void print(){}


};

#endif
