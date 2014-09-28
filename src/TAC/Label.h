#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad.h"

#ifndef X_LABEL
#define X_LABEL

#define EMPTY_LABEL            ""
#define NUMBERED_LABEL         ""
#define COMMENT_LABEL          "#"
#define INIT_LABEL             "INIT"
#define ADD_LABEL              "ADD "
#define SUB_LABEL              "SUB "
#define MUL_LABEL              "MUL "
#define DIV_LABEL              "DIV "
#define EQUAL_LABEL            "EQ  "
#define NEQUAL_LABEL           "NEQ "
#define LESS_LABEL             "LESS"
#define GREATER_LABEL          "GRET"
#define GEQ_LABEL              "GEQ "
#define LEQ_LABEL              "LEQ "
#define ASSIGN_LABEL           "ASN "
#define CALL_LABEL             "CALL"
#define PARAM_LABEL            "PARM"
#define TEMPORAL               "t"


class Label: public Quad {
  public:
  
  std::string op;

    
  Label(std::string o){
  
    op = o;
  
  }

  std::string toString(){
  
    return op+":\n";
  }
    
};

#endif



