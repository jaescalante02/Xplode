#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <fstream>



#ifndef X_MIPSREGALLOCATOR
#define X_MIPSREGALLOCATOR

//Registros del 5 al 25 (21)


#define MIN_REGISTER 5
#define MAX_REGISTER 25

class MIPS_Program;

class MIPS_Reg_Allocator {
  public:
  
  std::queue<MIPS_Register *> free;
  std::map<std::string, MIPS_Register * > used_registers;
  std::map<std::string, Quad_Variable * > variables_alloc;

    
  MIPS_Reg_Allocator();
  
  void getreg(MIPS_Program *assembler, Quad_Expression *expd, MIPS_Register **Rd, 
                                       Quad_Expression *expl ,MIPS_Register **Rl, 
                                       Quad_Expression *expr=NULL, MIPS_Register **Rr=NULL);
  
  MIPS_Register *register_alloc(MIPS_Program *assembler, Quad_Expression *exp);
  
  MIPS_Register *lvalue_register_alloc(MIPS_Program *assembler, Quad_Expression *exp);  

  MIPS_Register *takeregister();

  void flush(MIPS_Program *assembler);

  void clear();
 
};



#endif
