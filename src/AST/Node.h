
#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "../Symbol.h"


#ifndef X_NODE
#define X_NODE


class Node {
  public:
    virtual ~Node () {}
  
  //virtual Node *clone() = 0;

    virtual void print() = 0;


    int line;
    int column;

};

#endif
