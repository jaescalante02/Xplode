#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"
#include "TypeDeclaration.h"

#ifndef X_TUPLETYPE
#define X_TUPLETYPE

class TupleType : public TypeDeclaration {

  public:

    std::list< std::pair<TypeDeclaration*, int>* > *types;
    std::list<std::string> *names;
    TypeDeclaration *extend;


    TupleType(){
    
    types = new std::list< std::pair<TypeDeclaration*, int>* >;
    names = new std::list<std::string>;
    numtype = TYPE_TUPLE;
    extend = NULL;
    size=0;
    
    }
    
    void add(Node *t, std::string name){
    
    types->push_back(new std::pair<TypeDeclaration*, int>((TypeDeclaration *) t, 0));
    names->push_back(name);
    
    
    }
 
    void addType(Node *t){
    
      types->push_back(new std::pair<TypeDeclaration*, int>((TypeDeclaration *) t, 0));
    
    }


    Symbol *toSymbol(Xplode::Token *s){
    
    return new Symbol(true,s->value,this,s->line,s->column,true);
    
    
    }
    
    bool havefunction(){
    
      for(std::list< std::pair<TypeDeclaration*, int>* >::iterator iter = types->begin(); 
      iter != types->end(); ++iter){
      //std::cout<<(long)(*iter)->first<<' '<<(*iter)->first->numtype<<std::endl;
        if((*iter)->first->isfunction()) return true;
      
      }  
    //std::cout<<"buenas\n";
      return false;
    
    }
    
    void make_union(){
    
      numtype = TYPE_UNION;
      size = 0;
      for(std::list< std::pair<TypeDeclaration*, int>* >::iterator iter = types->begin(); 
      iter != types->end(); ++iter){
      
        if(size<(*iter)->first->size) size = (*iter)->first->size;
      
      }  
    
    }

    void make_type(){
    
      numtype = TYPE_TYPE;
      size = 0;
      for(std::list< std::pair<TypeDeclaration*, int>* >::iterator iter = types->begin(); 
      iter != types->end(); ++iter){
        (*iter)->second = size;
         size += (*iter)->first->size;
      
      }  
    
    }

    std::pair<TypeDeclaration*, int> *takeattribute(std::string at){
    
      std::list< std::string>::iterator it1;
      std::list< std::pair<TypeDeclaration*, int>* >::iterator it2;
      int i=0;
      for( it1 = names->begin(); it1 != names->end() ; ++it1){
        
        if((*it1)==at) break;
        //std::cout<< (*it1)<<" "<<at<<std::endl;
        i++;
          
      }
    
      int j=0;
      it2= types->begin();
      
      while(j<i){
        
        it2++;
        j++;  
      }
    
      return (*it2);
    
    }


    void print(int tab){
    
      std::list< std::string>::iterator it1;
      std::list< std::pair<TypeDeclaration*, int>* >::iterator it2;
      for( it1 = names->begin(), it2= types->begin(); 
          it1 != names->end() && it2 != types->end(); ++it1, ++it2){
          std::cout << std::string(tab, ' ') << "name: " << (*it1) << std::endl;
          std::cout << std::string(tab, ' ') << "type: "<< (long int) (*it2)->first << std::endl;
          
      }

    }

    std::set<int> *withreference(SymTable *symtb){
    
      std::set<int> *sett = new std::set<int>();
      std::list< std::string>::iterator it1;
      int i=1;

      for( it1 = names->begin(); it1 != names->end() ; ++it1, ++i){
          Symbol *s = symtb->find(*it1);
          
          if(s->porref){
          
            //std::cout << *it1 << std::endl;
            sett->insert(i); 
          
          }
          
      }

    return sett;
    
    
    }


};

#endif
