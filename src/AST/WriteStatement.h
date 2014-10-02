#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Statement.h"
#include "Expression.h"
#include "../SymTable.h"


#ifndef X_WRITESTATEMENT
#define X_WRITESTATEMENT

class WriteStatement : public Statement {
  public:
  std::list<Expression *> *writeList; 

  WriteStatement(std::list<Expression *> *a){writeList = a; }

  void print(int tab){
   std::cout << std::string(tab, ' ') << "WRITE STATEMENT\n";
   for(std::list<Expression *>::iterator iter = writeList->begin(); iter != writeList->end(); ++iter){
      std::cout << std::string(tab, ' ') << "write: \n";
      (*iter)->print(tab+2); 
    }
  }

  void firstcheck(SymTable *symtb){
  
    for(std::list<Expression *>::iterator iter = writeList->begin(); iter != writeList->end(); ++iter)
      (*iter)->firstcheck(symtb); 
    
  
  }

virtual void toTAC(TAC_Program *tac, SymTable* symtab, std::string cont_label, std::string break_label ){

    for(std::list<Expression *>::iterator iter = writeList->begin(); iter != writeList->end(); ++iter){
      std::string tmp = (*iter)->toTAC(tac,symtab);
      std::stringstream aux;
      aux<<(*iter)->ntype->numtype;
      tac->push_quad(new Instruction(WRITE_LABEL,tmp,aux.str()));
    }
  }


};

#endif
