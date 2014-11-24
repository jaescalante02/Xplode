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
    
    } else if(inst->op==END_FUNCTION_LABEL){
    
    
      endfun_toMIPS(inst);    
    
    } else if(inst->op==ALLOC_FUNC_LABEL){
    
    
      allocfun_toMIPS(inst);    
    
    }else if(inst->op==ADD_INT_LABEL){
    
    
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
    
    } else if(inst->op==BEGIN_FUNCTION_LABEL){
    
    
      beginfun_toMIPS(inst); 
    
    } else if(inst->op==PARAM_LABEL){
    
    
      param_toMIPS(inst);   
    
    } else if(inst->op==PARAM_REF_LABEL){
    
    
      paramref_toMIPS(inst);    
    
    } else if(inst->op==CALL_LABEL){
    
    
      call_toMIPS(inst);    
    
    } else if(inst->op==RETURN_LABEL){
    
    
      return_toMIPS(inst);    
    
    } else if(inst->op==ADD_FLOAT_LABEL){
    
    
      addfloat_toMIPS(inst);    
    
    } else if(inst->op==SUB_FLOAT_LABEL){
    
    
      subfloat_toMIPS(inst);    
    
    } else if(inst->op==MUL_FLOAT_LABEL){
    
    
      mulfloat_toMIPS(inst);    
    
    } else if(inst->op==DIV_FLOAT_LABEL){
    
    
      divfloat_toMIPS(inst);    
    
    }
    
  
  
  
  }
  
  void exttoMIPS(Instruction *inst){
  

  }
  
  void addfloat_toMIPS(Instruction *inst){

    MIPS_Float_Register *Rr, *Rl, *Rd;
  

    this->allocator->getregf(this, inst->result, &Rd, inst->leftop, &Rl, inst->rightop, &Rr);  
  
    instructions.push_back(new MIPS_Instruction(ADD_FLOAT_MIPS,
                           Rd, Rl, Rr));
  

  }

  void subfloat_toMIPS(Instruction *inst){

    MIPS_Float_Register *Rr, *Rl, *Rd;
  
    this->allocator->getregf(this, inst->result, &Rd, inst->leftop, &Rl, inst->rightop, &Rr);  
  
    instructions.push_back(new MIPS_Instruction(SUB_FLOAT_MIPS,
                           Rd, Rl, Rr));
  

  }

  void mulfloat_toMIPS(Instruction *inst){

    MIPS_Float_Register *Rr, *Rl, *Rd;
  

    this->allocator->getregf(this, inst->result, &Rd, inst->leftop, &Rl, inst->rightop, &Rr);  
  
    instructions.push_back(new MIPS_Instruction(MUL_FLOAT_MIPS,
                           Rd, Rl, Rr));
  

  }

  void divfloat_toMIPS(Instruction *inst){

    MIPS_Float_Register *Rr, *Rl, *Rd;
  

    this->allocator->getregf(this, inst->result, &Rd, inst->leftop, &Rl, inst->rightop, &Rr);  
  
    instructions.push_back(new MIPS_Instruction(DIV_FLOAT_MIPS,
                           Rd, Rl, Rr));
  

  }

  void return_toMIPS(Instruction *inst){

    MIPS_Register *Rd=NULL;

    this->allocator->getreg(this, NULL, NULL, inst->result, &Rd);  
  
    if(inst->result){
    
      instructions.push_back(new MIPS_Instruction(STOREW_MIPS,
                           Rd, new MIPS_Offset(30, 0)));      
        
    }
  
    instructions.push_back(new MIPS_Instruction(LOADW_MIPS,
                           RA_REGISTER, new MIPS_Offset(30, -4)));  
  
    instructions.push_back(new MIPS_Instruction(MOVE_MIPS,
                           SP_REGISTER, FP_REGISTER));


    instructions.push_back(new MIPS_Instruction(LOADW_MIPS,
                           FP_REGISTER, new MIPS_Offset(30, -8)));


    instructions.push_back(new MIPS_Instruction(JUMP_RETURN_MIPS, RA_REGISTER));
    
    this->allocator->clear();


  }

  void allocfun_toMIPS(Instruction *inst){
  
    Quad_Constant *cons = (Quad_Constant *) inst->result;
    
    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-4)));
 
    instructions.push_back(new MIPS_Instruction(STOREW_MIPS,
                           RA_REGISTER, new MIPS_Offset(29)));    

    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-4)));

    instructions.push_back(new MIPS_Instruction(STOREW_MIPS,
                           FP_REGISTER, new MIPS_Offset(29))); 

    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           FP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(12)));
    
    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-cons->num)));
  
  
  
  }

  void beginfun_toMIPS(Instruction *inst){

    this->allocator->flush(this);
  
  }

  void param_toMIPS(Instruction *inst){
  
    MIPS_Register *Rd;
        
    this->allocator->getreg(this, NULL, NULL, inst->result, &Rd);  
    
    Quad_Constant *cons = (Quad_Constant *) inst->leftop;

    
    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-4)));
                                 
    instructions.push_back(new MIPS_Instruction(STOREW_MIPS,
                           Rd, new MIPS_Offset(29)));
  
  }

  void paramref_toMIPS(Instruction *inst){
  
    MIPS_Register *Rb, *Rd = this->allocator->takeregister();

    Quad_Variable *var = (Quad_Variable *) inst->result;            
    Quad_Constant *cons = (Quad_Constant *) inst->leftop;
    Quad_Constant *cons2 = (Quad_Constant *) inst->rightop;    
    
    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-4)));
                                 
    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           Rd, ZERO_REGISTER, new MIPS_Variable(var->offset+cons2->num))); 

    Rb = (var->arg)?FP_REGISTER:SP_REGISTER;

    instructions.push_back(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Rd, Rd, Rb)); 
  
    instructions.push_back(new MIPS_Instruction(STOREW_MIPS,
                           Rd, new MIPS_Offset(Rb->number)));
  
  }

  void call_toMIPS(Instruction *inst){
  
    MIPS_Register  *Rl;
        //Rr lo quite numero de parametros
    this->allocator->getreg(this, NULL, NULL, inst->leftop, &Rl);  

    Quad_Variable *instvar= (Quad_Variable *) inst->leftop;

    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-4)));

    instructions.push_back(new MIPS_Instruction(LA_MIPS, Rl, 
                                              new MIPS_Variable(instvar->var)));  



    instructions.push_back(new MIPS_Instruction(JUMP_FUNCTION_MIPS, Rl)); 
        
    this->allocator->clear();


  }  
  

  void jump_toMIPS(Instruction *inst){
  
  Quad_Variable *instvar= (Quad_Variable *) inst->result;
    
  instructions.push_back(new MIPS_Instruction(JUMP_MIPS,
                           new MIPS_Variable(instvar->var)));    
  
  
  
  }

  void equal_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, NULL, NULL, inst->result, &Rd, inst->leftop, &Rl);  
  
    instructions.push_back(new MIPS_Instruction(JUMP_EQUAL_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));    
  
  
  
  }

  void nequal_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, NULL, NULL, inst->result, &Rd, inst->leftop, &Rl);  
  
    instructions.push_back(new MIPS_Instruction(JUMP_NEQUAL_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));    
  
  
  
  }
  
  void less_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, NULL, NULL, inst->result, &Rd, inst->leftop, &Rl);  
  
    instructions.push_back(new MIPS_Instruction(JUMP_LESS_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));    
  
  
  
  }
  
  void greater_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
    this->allocator->getreg(this, NULL, NULL, inst->result, &Rd, inst->leftop, &Rl);  
  
    instructions.push_back(new MIPS_Instruction(JUMP_GREATER_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));    
  
  
  
  }  

  void lesseq_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
      this->allocator->getreg(this, NULL, NULL, inst->result, &Rd, inst->leftop, &Rl);  
  
    instructions.push_back(new MIPS_Instruction(JUMP_LESS_EQ_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));  
  
  
  }

  void greatereq_toMIPS(Instruction *inst){
  
  MIPS_Register *Rl, *Rd;
  Quad_Variable *instvar= (Quad_Variable *) inst->rightop;
  
      this->allocator->getreg(this, NULL, NULL, inst->result, &Rd, inst->leftop, &Rl);  
  
    instructions.push_back(new MIPS_Instruction(JUMP_GREATER_EQ_MIPS,
                           Rd, Rl, new MIPS_Variable(instvar->var)));  
  
  
  }

  void assign_toMIPS(Instruction *inst){
    
    Quad_Variable *var = (Quad_Variable *) inst->result;
  
    if(var->numtype==TYPE_FLOAT){

      MIPS_Float_Register *Rl, *Rd;

      this->allocator->getregf(this, inst->result, &Rd, inst->leftop, &Rl);  
  
      instructions.push_back(new MIPS_Instruction(MOVE_FLOAT_MIPS,
                           Rd, Rl));
    
    } else {
  
      MIPS_Register *Rl, *Rd;
  
      this->allocator->getreg(this, inst->result, &Rd, inst->leftop, &Rl);  
  
      instructions.push_back(new MIPS_Instruction(MOVE_MIPS,
                           Rd, Rl));
    }
  
  }

  void assigntoarray_toMIPS(Instruction *inst){
    //caso global falta
    
    Quad_Variable *var = (Quad_Variable *) inst->result;    
    
    if(var->numtype!=TYPE_FLOAT){
    
      MIPS_Register *Rr, *Rl;
             
      this->allocator->getreg(this, NULL, NULL, inst->leftop, &Rl, inst->rightop, &Rr);  

      instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           Rl, Rl, new MIPS_Variable(var->offset))); 

      instructions.push_back(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Rl, Rl, SP_REGISTER)); 

      instructions.push_back(new MIPS_Instruction(STOREW_MIPS,
                           Rr, new MIPS_Offset(Rl->number)));
                           
    } else {
    
      MIPS_Float_Register *Rr;
      MIPS_Register *Rl;
    
      this->allocator->getregf(this, NULL, NULL, inst->rightop, &Rr);  
      this->allocator->getreg(this, NULL, NULL, inst->leftop, &Rl);  

      instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           Rl, Rl, new MIPS_Variable(var->offset))); 

      instructions.push_back(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Rl, Rl, SP_REGISTER)); 

      instructions.push_back(new MIPS_Instruction(STOREW_FLOAT_MIPS,
                           Rr, new MIPS_Offset(Rl->number)));
    
    
    
    }                          
  

  }
  
  void assignfromarray_toMIPS(Instruction *inst){

    Quad_Variable *var = (Quad_Variable *) inst->leftop;

    if(var->numtype!=TYPE_FLOAT){
  
      MIPS_Register *Rr, *Rd;
  
      this->allocator->getreg(this, inst->result, &Rd, inst->rightop, &Rr);  

      instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           Rr, Rr, new MIPS_Variable(var->offset))); 

      instructions.push_back(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Rr, Rr, SP_REGISTER)); 

      instructions.push_back(new MIPS_Instruction(LOADW_MIPS,
                           Rd, new MIPS_Offset(Rr->number)));
                           
    } else {
    
      MIPS_Register *Rr;
      MIPS_Float_Register *Rd;
  
      this->allocator->getregf(this, inst->result, &Rd, NULL, NULL);  
      this->allocator->getreg(this, NULL, NULL, inst->rightop, &Rr);  

      instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           Rr, Rr, new MIPS_Variable(var->offset))); 

      instructions.push_back(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Rr, Rr, SP_REGISTER)); 

      instructions.push_back(new MIPS_Instruction(LOADW_FLOAT_MIPS,
                           Rd, new MIPS_Offset(Rr->number)));    
    
    
    }
    

  }


  void uminusint_toMIPS(Instruction *inst){
  
    MIPS_Register *Rd, *Rl;
  
    this->allocator->getreg(this, inst->result, &Rd, inst->leftop, &Rl);  
  
    instructions.push_back(new MIPS_Instruction(UMINUSINT_MIPS,
                           Rd, Rl));
  
  
  }

  void divint_toMIPS(Instruction *inst){
  
  MIPS_Register *Rr, *Rl, *Rd;
  
    this->allocator->getreg(this, inst->result, &Rd, inst->leftop, &Rl, inst->rightop, &Rr);  
  
    instructions.push_back(new MIPS_Instruction(DIV_REGISTER_MIPS,
                           Rl, Rr));
  
    instructions.push_back(new MIPS_Instruction(MOVE_FROM_LO_MIPS, Rd));
  
  
  }


  void multint_toMIPS(Instruction *inst){
  
  MIPS_Register *Rr, *Rl, *Rd;

    this->allocator->getreg(this, inst->result, &Rd, inst->leftop, &Rl, inst->rightop, &Rr);  
  
    instructions.push_back(new MIPS_Instruction(MUL_REGISTER_MIPS,
                           Rd, Rl, Rr));
  
  
  }

  void subint_toMIPS(Instruction *inst){
  
  MIPS_Register *Rr, *Rl, *Rd;
  
    this->allocator->getreg(this, inst->result, &Rd, inst->leftop, &Rl, inst->rightop, &Rr);  
  
    instructions.push_back(new MIPS_Instruction(SUB_REGISTER_MIPS,
                           Rd, Rl, Rr));
  
  
  }
  
  void addint_toMIPS(Instruction *inst){
  
  MIPS_Register *Rr, *Rl, *Rd;
  

    this->allocator->getreg(this, inst->result, &Rd, inst->leftop, &Rl, inst->rightop, &Rr);  
  
    instructions.push_back(new MIPS_Instruction(ADD_REGISTER_MIPS,
                           Rd, Rl, Rr));
  
  
  }  
  
  void alloc_toMIPS(Instruction *inst){
  
    Quad_Constant *cons = (Quad_Constant *) inst->result;
    
    instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(-cons->num)));
  
  
  
  }
  
  void endfun_toMIPS(Instruction *inst){
  
      Quad_Constant *cons = (Quad_Constant *) inst->leftop;

      MIPS_Register *Rd;  
      this->allocator->getreg(this, inst->result, &Rd, NULL, NULL);
      
      instructions.push_back(new MIPS_Instruction(LOADW_MIPS,
                           Rd, new MIPS_Offset(29, 0)));
    
      instructions.push_back(new MIPS_Instruction(ADD_CONSTANT_MIPS,
                           SP_REGISTER, SP_REGISTER, 
                           new MIPS_Variable(cons->num)));
  

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
      this->allocator->getreg(this, NULL, NULL, inst->result, &Rd);
      
      Quad_Variable *instvar= (Quad_Variable *) inst->result;
      instructions.push_back(new MIPS_Instruction(MOVE_MIPS,
                             new MIPS_Register(ARGUMENT_REGISTER),           
                             Rd));
                             
      instructions.push_back(new MIPS_Instruction(LI_MIPS, 
                             new MIPS_Register(SYSCALL_NUMBER_REGISTER),     
                             new MIPS_Variable(SYSCALL_WRITE_INT_NUMBER)));
                                       
      instructions.push_back(new MIPS_Instruction(SYSCALL_MIPS));    
    
    
    } else if(aux->num==TYPE_FLOAT){
    
      MIPS_Float_Register *Rd;  
      this->allocator->getregf(this, NULL, NULL, inst->result, &Rd);
      
      Quad_Variable *instvar= (Quad_Variable *) inst->result;

      instructions.push_back(new MIPS_Instruction(MOVE_FLOAT_MIPS,
                             new MIPS_Float_Register(ARGUMENT_FREGISTER),           
                             Rd));
                             
      instructions.push_back(new MIPS_Instruction(LI_MIPS, 
                             new MIPS_Register(SYSCALL_NUMBER_REGISTER),     
                             new MIPS_Variable(SYSCALL_WRITE_FLOAT_NUMBER)));
                                       
      instructions.push_back(new MIPS_Instruction(SYSCALL_MIPS));    
    
    
    }
  
  }
  
  void read_toMIPS(Instruction *inst){
  
  
    Quad_Constant *aux= (Quad_Constant *) inst->leftop;
    if(aux->num==TYPE_INT){
    
      MIPS_Register *Rd;  
      this->allocator->getreg(this, inst->result, &Rd, NULL, NULL);
                                   
      instructions.push_back(new MIPS_Instruction(LI_MIPS, 
                             new MIPS_Register(SYSCALL_NUMBER_REGISTER),     
                             new MIPS_Variable(SYSCALL_READ_INT_NUMBER)));
                                       
      instructions.push_back(new MIPS_Instruction(SYSCALL_MIPS));  
      
      Quad_Variable *instvar= (Quad_Variable *) inst->result;
      instructions.push_back(new MIPS_Instruction(MOVE_MIPS,           
                             Rd, new MIPS_Register(RESULT_REGISTER)));  
    
    
    } else if (aux->num==TYPE_FLOAT){
    
      MIPS_Float_Register *Rd;  
      this->allocator->getregf(this, inst->result, &Rd, NULL, NULL);
                                   
      instructions.push_back(new MIPS_Instruction(LI_MIPS, 
                             new MIPS_Register(SYSCALL_NUMBER_REGISTER),     
                             new MIPS_Variable(SYSCALL_READ_FLOAT_NUMBER)));
                                       
      instructions.push_back(new MIPS_Instruction(SYSCALL_MIPS));  
      
      Quad_Variable *instvar= (Quad_Variable *) inst->result;

      instructions.push_back(new MIPS_Instruction(MOVE_FLOAT_MIPS,           
                             Rd, new MIPS_Float_Register(RESULT_FREGISTER)));  
    
    
    }


  
  }

  
    
};


#include "MIPS_Reg_Allocator.cpp"

#endif

