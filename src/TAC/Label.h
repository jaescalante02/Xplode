#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad.h"

#ifndef X_LABEL
#define X_LABEL

#define EMPTY_LABEL            ""
#define NUMBERED_LABEL         ""
#define COMMENT_LABEL          "#"
#define INIT_LABEL             "INIT"
#define ADD_LABEL              "ADD"
#define ASSIGN_LABEL           "ASSIGN"

class Label: public Quad {
  public:
  
  std::string op;

    
  Label(std::string o){
  
    op = o;
  
  }

  std::string toString(){
  
    return op+":\n";
  }
    
};

#endif



