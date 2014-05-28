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
#include "../SymTable.h"
#include "TypeDeclaration.h"

class Expression : public Node {
  public:
  TypeDeclaration *ntype; //Used for type checks

  virtual void print(int tab) {}

  virtual void firstcheck(SymTable *symtb){ }

};

#endif
