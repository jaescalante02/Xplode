#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <string>

#ifndef X_MIPSINST
#define X_MIPSINST

#define LA_MIPS                           "la"
#define LI_MIPS                           "li"
#define LI_FLOAT_MIPS                     "li.s"
#define STOREW_MIPS                       "sw"
#define STOREW_FLOAT_MIPS                 "swc1"
#define LOADW_MIPS                        "lw"
#define LOADW_FLOAT_MIPS                  "lwc1"
//#define LO_REGISTER_MIPS                  "Lo"
#define SYSCALL_MIPS                      "syscall"
#define UMINUSINT_MIPS                    "neg"
#define ADD_REGISTER_MIPS                 "add"
#define ADD_FLOAT_MIPS                    "add.s"
#define ADD_CONSTANT_MIPS                 "addi"
#define SUB_REGISTER_MIPS                 "sub"
#define SUB_FLOAT_MIPS                    "sub.s"  
#define MUL_REGISTER_MIPS                 "mul"
#define MUL_FLOAT_MIPS                    "mul.s"  
#define DIV_REGISTER_MIPS                 "div"
#define DIV_FLOAT_MIPS                    "div.s"  
#define MOVE_MIPS                         "move"
#define MOVE_FLOAT_MIPS                   "mov.s"
#define MOVE_FROM_LO_MIPS                 "mflo"
#define JUMP_MIPS                         "b"
#define JUMP_EQUAL_MIPS                   "beq"
#define JUMP_NEQUAL_MIPS                  "bne"
#define JUMP_LESS_MIPS                    "blt"
#define JUMP_GREATER_MIPS                 "bgt"
#define JUMP_LESS_EQ_MIPS                 "ble"
#define JUMP_GREATER_EQ_MIPS              "bge"
#define JUMP_FUNCTION_MIPS                "jal"
#define JUMP_RETURN_MIPS                  "jr"
#define SYSCALL_NUMBER_REGISTER           2
#define SYSCALL_EXIT_NUMBER               "10"
#define SYSCALL_WRITE_STRING_NUMBER       4
#define SYSCALL_WRITE_INT_NUMBER          1
#define SYSCALL_WRITE_FLOAT_NUMBER        2
#define SYSCALL_WRITE_CHAR_NUMBER         11
#define SYSCALL_READ_INT_NUMBER           5
#define SYSCALL_READ_FLOAT_NUMBER         6
#define SYSCALL_READ_CHAR_NUMBER          12
#define ARGUMENT_REGISTER                 4
#define ARGUMENT_FREGISTER                12
#define RESULT_REGISTER                   2
#define RESULT_FREGISTER                  0
#define SP_REGISTER                       new MIPS_Register(29)
#define RA_REGISTER                       new MIPS_Register(31)
#define FP_REGISTER                       new MIPS_Register(30)
#define ZERO_REGISTER                     new MIPS_Register(0)

class MIPS_Instruction {
  public:
  
  std::string op;
  MIPS_Argument* result;
  MIPS_Argument* leftop;
  MIPS_Argument* rightop;


  MIPS_Instruction(){}
  MIPS_Instruction(std::string o, MIPS_Argument *r=NULL, MIPS_Argument* i=NULL, MIPS_Argument* d=NULL){
  
    op=o;
    result=r;
    leftop=i;
    rightop=d;
  
  
  }
  
  
  virtual std::string toString(){
  
    if((result==NULL) && (rightop==NULL) && (leftop==NULL)){
    
      return "\t\t"+op;
    } else if ((rightop==NULL) && (leftop==NULL)) {
    
    
      return "\t\t"+op+" "+result->toString();
    } else if (rightop==NULL) {
    
    
      return "\t\t"+op+" "+result->toString()+" "+leftop->toString();
    } else
    
      return "\t\t"+op+" "+result->toString()+" "+leftop->toString()+" "+rightop->toString();
  
  }


    
};

#endif

