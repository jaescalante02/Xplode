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

#define LA_MIPS "la"
#define LI_MIPS "li"
#define SYSCALL_MIPS "syscall"
#define SYSCALL_NUMBER_REGISTER 2
#define SYSCALL_EXIT_NUMBER "10"
#define SYSCALL_WRITE_STRING_NUMBER "4"
#define ARGUMENT_REGISTER 4

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

