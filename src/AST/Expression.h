#ifndef X_EXPRESSION
#define X_EXPRESSION

#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"


class SymTable;


class Expression : public Node {
  public:
  std::string type; //Used for type checks

  virtual void print() {}

  virtual void firstcheck(SymTable *symtb){ }

};

#endif
