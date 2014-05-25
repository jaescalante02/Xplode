#include "SymTable.h"
#include "AST/Variable.h"
#include "AST/DeclarationMult.h"
#include <list>
#include <stdio.h>

#define toLower(phrase) std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower)

        SymTable::SymTable(){

           table = new std::map<std::string, Symbol *>;
           father = NULL;
           totaloffset= 0;

        }

        SymTable::SymTable(NodeList *l) {

           table = new std::map<std::string, Symbol *>;
           father = NULL;
           this->add(l);
        }

        void SymTable::add(NodeList *l){
          /* Symbol *s;
           DeclarationMult *d;
           std::list<Node *>::iterator iter;
           for(iter = (*l).nodeList.begin(); iter != (*l).nodeList.end(); ++iter){
              s = (*iter)->toSymbol();
              if (s == NULL){
                d = (DeclarationMult *) (*iter);
                std::list<Symbol *> symbolList;
                std::list<Symbol *>::iterator iter2;
                symbolList = d->toSymbols(); 
                
                for(iter2 = symbolList.begin(); iter2 != symbolList.end(); ++iter2){
                  this->insert(*iter2); 
                } 
              } else {
              this->insert(s); 
              }
           } 
*/
        }

        void SymTable::insert(Symbol *s, bool save){

            if (s==NULL) return;
            std::string lowsymbol(s->getname()); 
            toLower(lowsymbol);
            if (!isMember(lowsymbol)) {
            
              (*table)[lowsymbol] = s;
              if(save){
                s->offset = totaloffset;
                totaloffset += s->ntype->size;
              }
              return;
            }  
            
            Symbol *sym = (*table)[lowsymbol];
            
            if((s->line<sym->line) ||
              ((s->line==sym->line)&&(s->column<sym->column)))
              errorlog->addError(5,sym->line,sym->column,&sym->name);
            else
              errorlog->addError(5,s->line,s->column, &s->name);              
            

        }

        void SymTable::insertString(Symbol *s, int tam){
        
            if (s==NULL) return;
            std::string lowsymbol(s->getname()); 
            toLower(lowsymbol);
            (*table)[lowsymbol] = s;
            s->offset = totaloffset;
            totaloffset += tam;
        
        
        }


        Symbol *SymTable::findall(std::string variable) {

            if((*table).count(variable)>0) return (*table)[variable];
            if(father==NULL) return NULL;            
            return (*father).findall(variable);

        }

        Symbol *SymTable::find(std::string variable){ 

            std::string var(variable);
            toLower(var);
            return this->findall(var);
        }

        void SymTable::print(){

            if (table->empty()) return;

            std::map<std::string, Symbol *>::iterator pos;
            std::cout << " ---------------------------------------------------------------------\n";
            std::cout << " |        id       |    tipo    |     offset    | linea  |  columna  |\n";
            std::cout << " ---------------------------------------------------------------------\n";
            for (pos = (*table).begin(); pos != (*table).end(); ++pos) {
                printf(" | %15s | %10ld |      %4d     |  %3d   |    %3d    |\n",
                (*pos).first.c_str(), (long int) pos->second->ntype,
                pos->second->offset, pos->second->line, 
                pos->second->column);

            }
            //if(this->father) this->father->print();
            std::cout << " ---------------------------------------------------------------------\n\n";


        }

        void SymTable::setFather(SymTable *s){ father=s; }
       
        SymTable *SymTable::getRoot(){
        
          SymTable *temp = this;
        
          while(temp->father!=NULL) temp = temp->father;
        
          return temp;
        }

        bool SymTable::isMember(std::string variable){
        
          std::string var(variable);
          toLower(var);
          return ((*table).count(var)>0);
        } 




