#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"
#include "../SymTable.h"

#ifndef X_STATEMENTDEF
#define X_STATEMENTDEF

class Statement: public Node {

  public:
  
    virtual void print() {};

    virtual void printTable() {}

    virtual void setFather(SymTable *s){}

    virtual void firstcheck(SymTable *symtb){}


};

#endif
