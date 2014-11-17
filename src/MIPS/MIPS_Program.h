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
#include "MIPS_Argument.h"
#include "MIPS_Variable.h"
#include "MIPS_Register.h"
#include "MIPS_Offset.h"
#include "MIPS_Instruction.h"
#include "MIPS_Label.h"

#include "../TAC/TAC_Program.h"

#ifndef X_MIPSPROGRAM
#define X_MIPSPROGRAM

#include "MIPS_Reg_Allocator.h"

#define MIPS_EXTENSION ".s"


class MIPS_Program {
  public:
  
  std::vector<MIPS_Instruction* > instructions;
  std::map<std::string, std::string> strings;
  MIPS_Reg_Allocator *allocator;
  

  MIPS_Program(){
  
    allocator = new MIPS_Reg_Allocator();
  
  }

  void create(TAC_Program *tac){
  
      strings = tac->strings;
  
      for(int i =0;i<tac->blocks->size();i++){
  
       this->blocktoMIPS(tac->blocks->at(i));
    
      }
  
  }
  
  void add(MIPS_Instruction *inst){
  
    instructions.push_back(inst);
  
  
  }
  
  
  void tofile(std::string name){
  
    std::string fname(name+MIPS_EXTENSION);
    std::ofstream out(fname.c_str());
    
    out << ".data\n";
    
    for(std::map<std::string, std::string>::iterator it = strings.begin(); 
        it != strings.end(); ++it){
     
        
       out << it->first << ":  .asciiz " << it->second << std::endl;
          
        
    }


    out << "\n.text\n\nmain:\n";

    for(int i =0;i<instructions.size();i++){
    
      out << instructions[i]->toString() << std::endl;
    
    }
    out.close();  
  
  
  }

  void blocktoMIPS(TAC_Block* block){
  
    
    for(int i =0;i<block->instructions->size();i++){  
  

      if(block->instructions->at(i)->islabel()){
      

        instructions.push_back(new MIPS_Label(block->instructions->at(i)->op));
      
      
      } if(block->instructions->at(i)->isinstruction()){
      

        this->insttoMIPS(block->instructions->at(i));
      
      } 
    
    }
  
  }

  void insttoMIPS(Quad *q){
  
    Instruction *inst = (Instruction *) q;
  
    if(inst->op==EXIT_LABEL){
    
      exit_toMIPS(inst);
    
    
    } else if(inst->op==WRITE_LABEL){
    
    
      write_toMIPS(inst);    
    
    } else if(inst->op==ALLOC_LABEL){
    
    
      alloc_toMIPS(inst);    
    
    } else if(inst->op==ADD_INT_LABEL){
    
    
      addint_toMIPS(inst);    
    
    } else if(inst->op==ASSIGN_LABEL){
    
    
      assign_toMIPS(inst);    
    
    }else if(inst->op==SUB_INT_LABEL){
    
    
      subint_toMIPS(inst);    
    
    }
  
  
  
  }
  
  void exttoMIPS(Instruction *inst){
  
  
  
  }

  void assign_toMIPS(Instruction *inst){
  
  MIPS_Register *Rr, *Rl, *Rd;
  
    this->allocator->getreg(this, inst, &Rd, &Rl);
  
    instructions.push_back(new MIPS_Instruction(MOVE_MIPS,
                           Rd, Rl));
  
  
  }

  void subint_toMIPS(Instruction *inst){
  
  MIPS_Register *Rr, *Rl, *Rd;
  
    this->allocator->getreg(this, inst, &Rd, &Rl, &Rr);
  
    instructions.push_back(new MIPS_Instruction(SUB_REGISTER_MIPS,
                           Rd, Rl, Rr));
  
  
  }
  
  void addint_toMIPS(Instruction *inst){
  
  MIPS_Register *Rr, *Rl, *Rd;
  
    this->allocator->getreg(this, inst, &Rd, &Rl, &Rr);
  
    instructions.push_back(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Rd, Rl, Rr));
  
  
  }  
  
  void alloc_toMIPS(Instruction *inst){
  
    Quad_Constant *cons = (Quad_Constant *) inst->result;
    
    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-cons->num)));
  
  
  
  }
  
  void exit_toMIPS(Instruction *inst){
  
  
    instructions.push_back(new MIPS_Instruction(LI_MIPS,
                           new MIPS_Register(SYSCALL_NUMBER_REGISTER), 
                           new MIPS_Variable(SYSCALL_EXIT_NUMBER)));
                           
    instructions.push_back(new MIPS_Instruction(SYSCALL_MIPS));    
  
  
  }

  void write_toMIPS(Instruction *inst){
  
  
    Quad_Constant *aux= (Quad_Constant *) inst->leftop;
    if(aux->num==TYPE_STRING){ //String
  
      Quad_Variable *instvar= (Quad_Variable *) inst->result;
      instructions.push_back(new MIPS_Instruction(LA_MIPS,
                             new MIPS_Register(ARGUMENT_REGISTER),           
                             new MIPS_Variable(instvar->var)));
                             
      instructions.push_back(new MIPS_Instruction(LI_MIPS, 
                             new MIPS_Register(SYSCALL_NUMBER_REGISTER),     
                             new MIPS_Variable(SYSCALL_WRITE_STRING_NUMBER)));
                                       
      instructions.push_back(new MIPS_Instruction(SYSCALL_MIPS));    
    } else if(aux->num==TYPE_INT){
    
      MIPS_Register *Rd;  
      this->allocator->getreg(this, inst, &Rd);
      
      Quad_Variable *instvar= (Quad_Variable *) inst->result;
      instructions.push_back(new MIPS_Instruction(MOVE_MIPS,
                             new MIPS_Register(ARGUMENT_REGISTER),           
                             Rd));
                             
      instructions.push_back(new MIPS_Instruction(LI_MIPS, 
                             new MIPS_Register(SYSCALL_NUMBER_REGISTER),     
                             new MIPS_Variable(SYSCALL_WRITE_INT_NUMBER)));
                                       
      instructions.push_back(new MIPS_Instruction(SYSCALL_MIPS));    
    
    
    }
  
  }
    
};


#include "MIPS_Reg_Allocator.cpp"

#endif

