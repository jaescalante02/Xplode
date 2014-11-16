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

#define MIPS_EXTENSION ".s"


class MIPS_Program {
  public:
  
  std::vector<MIPS_Instruction* > instructions;
  std::map<std::string, std::string> strings;
  

  MIPS_Program(){}

  void create(TAC_Program *tac){
  
      strings = tac->strings;
  
      for(int i =0;i<tac->blocks->size();i++){
  
       this->blocktoMIPS(tac->blocks->at(i));
    
      }
  
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
    
      exittoMIPS(inst);
    
    
    } if(inst->op==WRITE_LABEL){
    
    
      writetoMIPS(inst);    
    
    }
  
  
  
  }
  
  void exttoMIPS(Instruction *inst){
  
  
  
  }
  
  void exittoMIPS(Instruction *inst){
  
  
    instructions.push_back(new MIPS_Instruction(LI_MIPS,
                           new MIPS_Register(SYSCALL_NUMBER_REGISTER), 
                           new MIPS_Variable(SYSCALL_EXIT_NUMBER)));
                           
    instructions.push_back(new MIPS_Instruction(SYSCALL_MIPS));    
  
  
  }

  void writetoMIPS(Instruction *inst){
  
  
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
    }
  
  }
    
};

#endif

