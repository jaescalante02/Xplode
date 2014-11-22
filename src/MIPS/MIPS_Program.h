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
    
    } else if(inst->op==SUB_INT_LABEL){
    
    
      subint_toMIPS(inst);    
    
    } else if(inst->op==MUL_INT_LABEL){
    
    
      multint_toMIPS(inst);    
    
    } else if(inst->op==DIV_INT_LABEL){
    
    
      divint_toMIPS(inst);    
    
    } else if(inst->op==READ_LABEL){
    
    
      read_toMIPS(inst);    
    
    } else if(inst->op==LESS_LABEL){
    
    
      less_toMIPS(inst);    
    
    } else if(inst->op==JUMP_LABEL){
    
    
      jump_toMIPS(inst);    
    
    } else if(inst->op==LEQ_LABEL){
    
    
      lesseq_toMIPS(inst);    
    
    } else if(inst->op==EQUAL_LABEL){
    
    
      equal_toMIPS(inst);    
    
    } else if(inst->op==NEQUAL_LABEL){
    
    
      nequal_toMIPS(inst);    
    
    } else if(inst->op==GREATER_LABEL){
    
    
      greater_toMIPS(inst);    
    
    } else if(inst->op==GEQ_LABEL){
    
    
      greatereq_toMIPS(inst);    
    
    } else if(inst->op==UMINUS_INT_LABEL){
    
    
      uminusint_toMIPS(inst);    
    
    } else if(inst->op==ASSIGN_TO_ARRAY_LABEL){
    
    
      assigntoarray_toMIPS(inst);    
    
    }  else if(inst->op==ASSIGN_ARRAY_LABEL){
    
    
      assignfromarray_toMIPS(inst);    
    
    } else if(inst->op==PARAM_LABEL){
    
    
      param_toMIPS(inst);    
    
    } else if(inst->op==CALL_LABEL){
    
    
      call_toMIPS(inst);    
    
    }
  
  
  
  }
  
  void exttoMIPS(Instruction *inst){
  

  }

  void param_toMIPS(Instruction *inst){
  
    MIPS_Register *Rr, *Rl, *Rd;
        
    this->allocator->getreg(this, inst, &Rd);
    
    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-4)));
                                 
    instructions.push_back(new MIPS_Instruction(STOREW_MIPS,
                           Rd, new MIPS_Offset(29)));
  
  }

  void call_toMIPS(Instruction *inst){
  
    MIPS_Register *Rr, *Rl, *Rd;
        //Rr lo quite numero de parametros
    this->allocator->getreg(this, inst, &Rd, &Rl);

    Quad_Variable *instvar= (Quad_Variable *) inst->leftop;

    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-4)));

    instructions.push_back(new MIPS_Instruction(LA_MIPS, Rl, 
                                              new MIPS_Variable(instvar->var)));  

    instructions.push_back(new MIPS_Instruction(JUMP_FUNCTION_MIPS, Rl));  


    this->allocator->flush();
  }  
  

  void jump_toMIPS(Instruction *inst){
  
  MIPS_Register *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->result;
  
    this->allocator->getreg(this, inst, &Rd);
  
    instructions.push_back(new MIPS_Instruction(JUMP_MIPS,
                           new MIPS_Variable(instvar->var)));    
  
  
  
  }

  void equal_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, inst, &Rd, &Rl);
  
    instructions.push_back(new MIPS_Instruction(JUMP_EQUAL_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));    
  
  
  
  }

  void nequal_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, inst, &Rd, &Rl);
  
    instructions.push_back(new MIPS_Instruction(JUMP_NEQUAL_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));    
  
  
  
  }
  
  void less_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, inst, &Rd, &Rl);
  
    instructions.push_back(new MIPS_Instruction(JUMP_LESS_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));    
  
  
  
  }
  
  void greater_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, inst, &Rd, &Rl);
  
    instructions.push_back(new MIPS_Instruction(JUMP_GREATER_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));    
  
  
  
  }  

  void lesseq_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, inst, &Rd, &Rl);
  
    instructions.push_back(new MIPS_Instruction(JUMP_LESS_EQ_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));  
  
  
  }

  void greatereq_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, inst, &Rd, &Rl);
  
    instructions.push_back(new MIPS_Instruction(JUMP_GREATER_EQ_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));  
  
  
  }

  void assign_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  
    this->allocator->getreg(this, inst, &Rd, &Rl);
  
    instructions.push_back(new MIPS_Instruction(MOVE_MIPS,
                           Rd, Rl));
  
  
  }

  void assigntoarray_toMIPS(Instruction *inst){
    //caso global falta
    MIPS_Register *Rr, *Rl, *Rd;
        
    this->allocator->getreg(this, inst, NULL, &Rl, &Rr);
 
    Quad_Variable *var = (Quad_Variable *) inst->result;

    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           Rl, Rl, new MIPS_Variable(var->offset))); 

    instructions.push_back(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Rl, Rl, SP_REGISTER)); 


  
    instructions.push_back(new MIPS_Instruction(STOREW_MIPS,
                           Rr, new MIPS_Offset(Rl->number)));    
  
  
  }
  
  void assignfromarray_toMIPS(Instruction *inst){
  
    MIPS_Register *Rr, *Rl, *Rd;
  
    this->allocator->getreg(this, inst, &Rd, NULL, &Rr);
 
    Quad_Variable *var = (Quad_Variable *) inst->leftop;

    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           Rr, Rr, new MIPS_Variable(var->offset))); 

    instructions.push_back(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Rr, Rr, SP_REGISTER)); 


  
    instructions.push_back(new MIPS_Instruction(LOADW_MIPS,
                           Rd, new MIPS_Offset(Rr->number)));
    

  }


  void uminusint_toMIPS(Instruction *inst){
  
    MIPS_Register *Rd, *Rl;
  
    this->allocator->getreg(this, inst, &Rd, &Rl);
  
    instructions.push_back(new MIPS_Instruction(UMINUSINT_MIPS,
                           Rd, Rl));
  
  
  }

  void divint_toMIPS(Instruction *inst){
  
  MIPS_Register *Rr, *Rl, *Rd;
  
    this->allocator->getreg(this, inst, &Rd, &Rl, &Rr);
  
    instructions.push_back(new MIPS_Instruction(DIV_REGISTER_MIPS,
                           Rl, Rr));
  
    instructions.push_back(new MIPS_Instruction(MOVE_FROM_LO_MIPS, Rd));
  
  
  }


  void multint_toMIPS(Instruction *inst){
  
  MIPS_Register *Rr, *Rl, *Rd;
  
    this->allocator->getreg(this, inst, &Rd, &Rl, &Rr);
  
    instructions.push_back(new MIPS_Instruction(MUL_REGISTER_MIPS,
                           Rd, Rl, Rr));
  
  
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
  
  void read_toMIPS(Instruction *inst){
  
  
    Quad_Constant *aux= (Quad_Constant *) inst->leftop;
    if(aux->num==TYPE_INT){
    
      MIPS_Register *Rd;  
      this->allocator->getreg(this, inst, &Rd);
                                   
      instructions.push_back(new MIPS_Instruction(LI_MIPS, 
                             new MIPS_Register(SYSCALL_NUMBER_REGISTER),     
                             new MIPS_Variable(SYSCALL_READ_INT_NUMBER)));
                                       
      instructions.push_back(new MIPS_Instruction(SYSCALL_MIPS));  
      
      Quad_Variable *instvar= (Quad_Variable *) inst->result;
      instructions.push_back(new MIPS_Instruction(MOVE_MIPS,           
                             Rd, new MIPS_Register(RESULT_REGISTER)));  
    
    
    }

  
  
  }

  
    
};


#include "MIPS_Reg_Allocator.cpp"

#endif

