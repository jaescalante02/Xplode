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

#include "AST/TypeDeclaration.h"

/*
nombre 
tipo (apuntador)
linea
columna

*/




class Symbol {

    public:

        std::string name;
        TypeDeclaration *ntype;
        int line;
        int column;

        
        /* define defined
        0 variable
        1 primitives
        2 type
        3 union 
        4 function
        5 proc       
        */

        Symbol(std::string n, TypeDeclaration *t, int l, int c){

            name=n;
            ntype = t;
            line = l;
            column = c; 
            //defined = e;
            //dimensions = d;
            //pt = p;

        }

        std::string getname() {return name;}

};

#endif
