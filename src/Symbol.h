#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>


#ifndef X_SYMBOL_
#define X_SYMBOL_

class Symbol {

    public:

        std::string name;
//valor
        std::string ntype;
//tamano
 
        int dimensions;       
        int line;
        int column;
        bool editable;
        void *pt;
        

        Symbol(std::string n, std::string t, int l, int c, bool e, int d, void *p=NULL){

            name=n;
            ntype = t;
            line = l;
            column = c; 
            editable = e;
            dimensions = d;
            pt = p;

        }

        std::string getname() {return name;}

};

#endif
