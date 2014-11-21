#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include "MIPS_Reg_Allocator.h"
#include "MIPS_Program.h"




    
  MIPS_Reg_Allocator::MIPS_Reg_Allocator(){
  
    for(int i=MIN_REGISTER;i<=MAX_REGISTER; ++i){
    
      free.push(new MIPS_Register(i));    
    }
  
  }
  
  void MIPS_Reg_Allocator::getreg(MIPS_Program *assembler, Instruction *inst, MIPS_Register **Rd, 
                                  MIPS_Register **Rl, MIPS_Register **Rr){
  

    if ((inst->rightop)&&(Rr))  
        *Rr = register_alloc(assembler, inst->rightop);  
    if ((inst->leftop)&&(Rl))
        *Rl = register_alloc(assembler, inst->leftop);        
    if(Rd) *Rd = register_alloc(assembler, inst->result);

 
 
    //Caso Constant

        
    if(inst->result->isconstant()) free.push(*Rd);
        
    if((inst->leftop) &&(Rl) && (inst->leftop->isconstant())) free.push(*Rl);

    if((inst->rightop) && (Rr) && (inst->rightop->isconstant())) free.push(*Rr);    
    
    //Caso temporal
    
    
    
   
  }
  
  
  MIPS_Register *MIPS_Reg_Allocator::register_alloc(MIPS_Program *assembler, Quad_Expression *exp){



    if(exp->isconstant()){
    
      MIPS_Register *reg = free.front();
      free.pop();      
      Quad_Constant *cons = (Quad_Constant *) exp;
      assembler->add(new MIPS_Instruction(LI_MIPS, reg, 
                           new MIPS_Variable(cons->num)));
    
      return reg;
    }
 
    //Estoy asumiendo que tengo registros

    Quad_Variable* var = (Quad_Variable *) exp;
    
    if(used_registers.count(var->var)>0){

      return used_registers[var->var];

    } else {
    
      MIPS_Register *reg = free.front();
      free.pop();
      used_registers[var->var] = reg;
      return reg;
          
    }
          
    
  
  
  
  }
   

