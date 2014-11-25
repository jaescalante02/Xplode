#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Quad_Expression.h"
#include "Label.h"

#ifndef X_QUADVAR
#define X_QUADVAR

#define NO_OFFSET_NUM -1000000


class Quad_Variable : public Quad_Expression {
  public:
  
  std::string var;
  int offset;
  bool ref;
  bool arg;
  int tam;
  int numtype;

  Quad_Variable(){}  
  
  Quad_Variable(std::string v, int off= NO_OFFSET_NUM, bool r=false, bool a=false, int t=-1, int nt=-1){  
    
    if((off==NO_OFFSET_NUM) || (t<1)){
    
      var=v;
    
    }else {
    
      std::stringstream aux;
      aux << off;    
     var = v+"_"+aux.str();  
    } 
    
    offset = off;
    ref=r;
    arg=a;
    tam=t;
    numtype = nt;
  
  }
  
  
  std::string toString(){ 
  
    if (offset==NO_OFFSET_NUM) return var;
  
    std::stringstream aux;
    aux << var << "(" << offset << ")(r->" << ref << ")(arg->" << arg <<")(tam=" <<tam <<")(numtp="<<numtype<<")";
    return aux.str();
  }

  bool istemporal(){
  
  if((var.find(TEMPORAL)==0)&&(offset==NO_OFFSET_NUM)) return true;
  
  return false;
  
  }

    
};

#endif



