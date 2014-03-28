#ifndef X_SYMTABLE_
#define X_SYMTABLE_


#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Symbol.h"
#include "AST/NodeList.h"


class Variable;

class SymTable {

    public:

        SymTable *father;
        std::map<std::string, Symbol *> *table;

        SymTable();

        SymTable(NodeList *l);

        void add(NodeList *l);

        void insert(Symbol *s);

        Symbol *find(Variable *variable);

        void print();

        void setFather(SymTable *s);
       
        bool isMember(std::string variable);

        Symbol *findall(std::string variable);
             
};

#endif
