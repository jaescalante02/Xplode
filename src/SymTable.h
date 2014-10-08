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
#include "ErrorLog.h"

extern ErrorLog *errorlog;

#define NO_SAVE_SIZE false

#define toLower(phrase) std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower)

class SymTable {

    public:

        SymTable *father;
        std::map<std::string, Symbol *> *table;
        int totaloffset;

        SymTable();

        SymTable(NodeList *l);

        void add(NodeList *l);

        void insert(Symbol *s,  bool save = true);
        
        void insertString(Symbol *s, int tam);

        Symbol *find(std::string variable);
        
        Symbol *findType(std::string type);

        void print();

        void setFather(SymTable *s);
       
        bool isMember(std::string variable);

        Symbol *findall(std::string variable);
        
        SymTable *getRoot();
             
};

#endif
