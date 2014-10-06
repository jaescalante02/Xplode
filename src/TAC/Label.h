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
#define LABEL_LABEL            "l"
#define COMMENT_LABEL          "#"
#define INIT_LABEL             "INIT"
#define ADD_LABEL              "ADD "
#define SUB_LABEL              "SUB "
#define UMINUS_LABEL           "NEG "
#define NOT_LABEL              "NOT "
#define ITOC_LABEL             "ITOC"
#define CTOI_LABEL             "CTOI"
#define ITOF_LABEL             "ITOF"
#define FTOI_LABEL             "FTOI"
#define MUL_LABEL              "MUL "
#define DIV_LABEL              "DIV "
#define EQUAL_ZERO_LABEL       "EQZ " //if salto
#define EQUAL_LABEL            "EQ  "
#define NEQUAL_ZERO_LABEL      "NEQZ" //if salto
#define NEQUAL_LABEL           "NEQ "
#define LESS_LABEL             "LESS"
#define GREATER_LABEL          "GRET"
#define GEQ_LABEL              "GEQ "
#define LEQ_LABEL              "LEQ "
#define ASSIGN_LABEL           ":=  "
#define ASSIGN_ARRAY_LABEL     ":=[]"
#define ASSIGN_TO_ARRAY_LABEL  "[]:="
#define CALL_LABEL             "CALL"
#define PARAM_LABEL            "PARM"
#define JUMP_LABEL             "JUMP"
#define RETURN_LABEL           "RET "
#define WRITE_LABEL            "WR  "
#define READ_LABEL             "READ"
#define EXIT_LABEL             "EXIT"
#define SLEEP_LABEL            "ZZZZ"
#define TEMPORAL               "t"
#define FOR_LABEL              "for"
#define WHILE_LABEL            "whl"
#define IF_LABEL               "if"
#define ELSE_LABEL             "els"
#define END_LABEL              "end"


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



