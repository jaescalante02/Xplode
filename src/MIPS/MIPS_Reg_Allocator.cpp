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
    
    for(int i=MIN_FREGISTER;i<=MAX_FREGISTER; ++i){
    
      if(i==12) continue;
    
      freef.push(new MIPS_Float_Register(i));    
    }
  
  }
  
  void MIPS_Reg_Allocator::getreg(MIPS_Program *assembler, Quad_Expression *expd, MIPS_Register **Rd, 
                                       Quad_Expression *expl ,MIPS_Register **Rl, 
                                       Quad_Expression *expr, MIPS_Register **Rr){
  

    if ((expr)&&(Rr))  
        *Rr = register_alloc(assembler, expr);  
    if ((expl)&&(Rl))
        *Rl = register_alloc(assembler, expl);        
    if(Rd) *Rd = lvalue_register_alloc(assembler, expd);

 
 
    //Caso Constant

        
    if((expd) && (expd->isconstant())) free.push(*Rd);
        
    if((expl) && (Rl) &&  (expl->isconstant())) free.push(*Rl);

    if((expr) && (Rr) && (expr->isconstant())) free.push(*Rr);    
    
    //Caso temporal
    
    
    
   
  }

//float  
  void MIPS_Reg_Allocator::getregf(MIPS_Program *assembler, Quad_Expression *expd, MIPS_Float_Register **Rd, 
                                       Quad_Expression *expl ,MIPS_Float_Register **Rl, 
                                       Quad_Expression *expr, MIPS_Float_Register **Rr){
  

    if ((expr)&&(Rr))  
        *Rr = register_allocf(assembler, expr);  
    if ((expl)&&(Rl))
        *Rl = register_allocf(assembler, expl);        
    if(Rd) *Rd = lvalue_register_allocf(assembler, expd);

 
 
    //Caso Constant

        
    if((expd) && (expd->isconstant())) freef.push(*Rd);
        
    if((expl) && (Rl) &&  (expl->isconstant())) freef.push(*Rl);

    if((expr) && (Rr) && (expr->isconstant())) freef.push(*Rr);    
    
    //Caso temporal
    
    
    
   
  }
  
  
  MIPS_Register *MIPS_Reg_Allocator::register_alloc(MIPS_Program *assembler, Quad_Expression *exp){



    if(exp->isconstant()){
    
      MIPS_Register *reg = free.front();
      free.pop();      
      Quad_Constant *cons = (Quad_Constant *) exp;
      assembler->add(new MIPS_Instruction(LI_MIPS, reg, 
                           new MIPS_Variable(cons->val)));
    
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
      variables_alloc[var->var] = var;

      if(var->offset!=NO_OFFSET_NUM){
      

      
        assembler->add(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           reg, ZERO_REGISTER, new MIPS_Variable(var->offset))); 

        assembler->add(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           reg, reg, (var->arg)?FP_REGISTER:SP_REGISTER)); 
  
  
        assembler->add(new MIPS_Instruction(LOADW_MIPS,
                           reg, new MIPS_Offset(reg->number)));
                           
        if(var->ref){
        
          assembler->add(new MIPS_Instruction(LOADW_MIPS,
                           reg, new MIPS_Offset(reg->number, 0)));        
        
        
        }                   
                           
                          
      }
      
      return reg;
          
    }

}          
//float
  MIPS_Float_Register *MIPS_Reg_Allocator::register_allocf(MIPS_Program *assembler, Quad_Expression *exp){

    if(exp->isconstant()){
    
      MIPS_Float_Register *reg = freef.front();
      freef.pop();      
      Quad_Constant *cons = (Quad_Constant *) exp;
      assembler->add(new MIPS_Instruction(LI_FLOAT_MIPS, reg, 
                           new MIPS_Variable(cons->val)));
    
      return reg;
    }
 
    //Estoy asumiendo que tengo registros

    Quad_Variable* var = (Quad_Variable *) exp;
    
    if(used_fregisters.count(var->var)>0){

      return used_fregisters[var->var];

    } else {
    
      MIPS_Float_Register *reg = freef.front();
      freef.pop();
      used_fregisters[var->var] = reg;
      variables_alloc[var->var] = var;

      if(var->offset!=NO_OFFSET_NUM){
        assembler->add(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           reg, ZERO_REGISTER, new MIPS_Variable(var->offset))); 

        assembler->add(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           reg, reg, (var->arg)?FP_REGISTER:SP_REGISTER)); 
  
        assembler->add(new MIPS_Instruction(LOADW_MIPS,
                           reg, new MIPS_Offset(reg->number)));
      }
      
      return reg;
          
    }
    
  
  
  
  }
   

  MIPS_Register *MIPS_Reg_Allocator::lvalue_register_alloc(MIPS_Program *assembler, Quad_Expression *exp){



    if(exp->isconstant()){
    
      MIPS_Register *reg = free.front();
      free.pop();      
      Quad_Constant *cons = (Quad_Constant *) exp;
      assembler->add(new MIPS_Instruction(LI_MIPS, reg, 
                           new MIPS_Variable(cons->val)));
    
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
      variables_alloc[var->var] = var;      
      

      
      return reg;
          
    }
          
    
  
  
  
  }

//float
 MIPS_Float_Register *MIPS_Reg_Allocator::lvalue_register_allocf(MIPS_Program *assembler, Quad_Expression *exp){



    if(exp->isconstant()){
    
      MIPS_Float_Register *reg = freef.front();
      freef.pop();      
      Quad_Constant *cons = (Quad_Constant *) exp;
      assembler->add(new MIPS_Instruction(LI_FLOAT_MIPS, reg, 
                           new MIPS_Variable(cons->val)));
    
      return reg;
    }
 
    //Estoy asumiendo que tengo registros

    Quad_Variable* var = (Quad_Variable *) exp;
    
    if(used_fregisters.count(var->var)>0){

      return used_fregisters[var->var];

    } else {
    
      MIPS_Float_Register *reg = freef.front();
      freef.pop();
      used_fregisters[var->var] = reg;
      variables_alloc[var->var] = var;      
      

      
      return reg;
          
    }
          
    
  
  
  
  }


  MIPS_Register *MIPS_Reg_Allocator::takeregister(){
  
    return free.front();
    
  }

  void MIPS_Reg_Allocator::flush(MIPS_Program *assembler){

    std::map<std::string, MIPS_Register *>::iterator it;
    //asumo que tengo reg
    MIPS_Register *Reg= free.front();

    for(it=used_registers.begin();it!=used_registers.end(); ++it){
      
      if(variables_alloc[it->first]->offset!=NO_OFFSET_NUM){

        Quad_Variable* var = (Quad_Variable *) variables_alloc[it->first];
      
        if(var->ref){
        
          assembler->add(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           Reg, ZERO_REGISTER, new MIPS_Variable(var->offset))); 

          assembler->add(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Reg, Reg, (var->arg)?FP_REGISTER:SP_REGISTER)); 
  
          assembler->add(new MIPS_Instruction(LOADW_MIPS,
                           Reg, new MIPS_Offset(Reg->number)));

        
          assembler->add(new MIPS_Instruction(STOREW_MIPS,
                           it->second, new MIPS_Offset(Reg->number, 0))); 
        
        
        } else {
      
          assembler->add(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           Reg, ZERO_REGISTER, new MIPS_Variable(var->offset))); 

          assembler->add(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Reg, Reg, (var->arg)?FP_REGISTER:SP_REGISTER)); 
  
          assembler->add(new MIPS_Instruction(STOREW_MIPS,
                           it->second, new MIPS_Offset(Reg->number)));  
      
      
        }
      
      
      
      }
      

    
    }
    
  }

  void MIPS_Reg_Allocator::clear(){

    std::map<std::string, MIPS_Register *>::iterator it;
   
    for(it=used_registers.begin();it!=used_registers.end(); ++it){
            
      free.push(it->second);
    
    }
    
    used_registers.clear();
    variables_alloc.clear();


  }

