#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad.h"

#ifndef X_COMMENT
#define X_COMMENT


class Comment: public Quad {
  public:
      
  Comment(std::string o){
  
    op = o;  
  }


  std::string toString(){
  
    return "\n#"+op+"\n\n";
  }
    
};

#endif



