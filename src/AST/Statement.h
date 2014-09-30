#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"
#include "../Symbol.h"
#include "../SymTable.h"
#include "../TAC/TAC_Program.h"

#ifndef X_STATEMENTDEF
#define X_STATEMENTDEF

class Statement: public Node {

  public:
  
    virtual void print(int tab) {}

    virtual void printTable() {}

    virtual void setFather(SymTable *s){}

    virtual void firstcheck(SymTable *symtb){}
    
    virtual Symbol *toSymbol() {return NULL;}

    virtual void toTAC(TAC_Program *ptr, SymTable *symtab, 
                        std::string cont_label, std::string break_label){}

};

#endif
