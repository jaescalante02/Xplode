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
        void *pt;
        int defined; //use bool
        
        /* define defined
        0 variable
        1 primitives
        2 type
        3 union 
        4 function
        5 proc       
        */

        Symbol(std::string n, std::string t, int l, int c, int e, int d, void *p=NULL){

            name=n;
            ntype = t;
            line = l;
            column = c; 
            defined = e;
            dimensions = d;
            pt = p;

        }

        std::string getname() {return name;}

};

#endif
