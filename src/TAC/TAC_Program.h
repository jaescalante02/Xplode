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
#include "Comment.h"
#include "Instruction.h"
#include "Label.h"
#include "LabelMaker.h"
#include "TAC_Block.h"

#ifndef X_TACPROGRAM
#define X_TACPROGRAM

#define TAC_EXTENSION ".tac"


class TAC_Program {
  public:
  
  std::vector<TAC_Block* > *blocks;
  LabelMaker *labelmaker;
  std::map<std::string, std::string> strings;
  
  TAC_Program(std::string name){
  
    blocks = new std::vector<TAC_Block* >;
    labelmaker = new LabelMaker();
    TAC_Block *b = new TAC_Block();
    b->addquad(new Comment(name));
    b->addquad(new Label(labelmaker->getlabel(LABEL_LABEL)));    
    b->addquad(new Label(INIT_LABEL));
    blocks->push_back(b);    
  
  }

  void new_block(){
  
    blocks->push_back(new TAC_Block());
  
  
  }

  void push_quad(Quad *ptr){
    ((*blocks)[(*blocks).size()-1])->push_quad(ptr); //necesario codigo para separar los bloque
  }

  void tofile(std::string name){
  
    std::string fname(name+TAC_EXTENSION);
    std::ofstream out(fname.c_str());
    
    for(std::map<std::string, std::string>::iterator it = strings.begin(); 
        it != strings.end(); ++it){
     
        
       out<< "\t" << it->first << " --> " << it->second << std::endl;
          
        
    }

    out << "\n\n\n# ------------------------------------------------------\n"; 

    for(int i =0;i<(*blocks).size();i++){
         out << ((*blocks)[i])->toString()<<std::endl;
         out << "# ------------------------------------------------------\n"; 

    }
    out.close();
  
  
  
  
  }

  void push_string(std::string var, std::string str){
  
    strings[var]=str;
    
  }

  void putcomment(std::string tpblock, int line, int column, std::string end_block){
  
    std::stringstream msj;
    
    msj << tpblock<<" situado en "<<line<<":"<<column;
    if(end_block!=EMPTY_LABEL)
      msj<< ", termina en la etiqueta " << end_block;
 
    this->push_quad(new Comment(msj.str()));  
  
  
  
  }

    
};

#endif



