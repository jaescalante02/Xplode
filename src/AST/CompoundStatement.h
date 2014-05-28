
#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Statement.h"
#include "Block.h"
#include "../SymTable.h"

#ifndef X_COMPSTATEMENT
#define X_COMPSTATEMENT


class CompoundStatement: public Statement {

public:

  Block *block;

  CompoundStatement(){}

  void print(int tab){}

  virtual void printTable() {

     if (block!=NULL) block->printTable();

  }

  virtual void setFather(SymTable *s){

    block->setFather(s);

  }

  virtual void firstcheck(SymTable *symtb){}

};

#endif
