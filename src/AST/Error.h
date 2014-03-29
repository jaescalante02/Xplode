#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "../SymTable.h"

#ifndef ERRORDEF
#define ERRORDEF


class Error : public Node {
  public:
  Error(){ }
  void print(){
  }

  void firstcheck(SymTable *symtb){
  }

};

#endif
