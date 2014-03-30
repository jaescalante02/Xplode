#include "SymTable.h"
#include "AST/Variable.h"

#define toLower(phrase) std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower)

        SymTable::SymTable(){

           table = new std::map<std::string, Symbol *>;
           father = NULL;

        }

        SymTable::SymTable(NodeList *l) {

           table = new std::map<std::string, Symbol *>;
           father = NULL;
           this->add(l);
        }

        void SymTable::add(NodeList *l){

           std::list<Node *>::iterator iter;
           for(iter = (*l).nodeList.begin(); iter != (*l).nodeList.end(); ++iter){
                this->insert((*iter)->toSymbol()); 
           } 

        }

        void SymTable::insert(Symbol *s){

            if (s==NULL) return;
            std::string lowsymbol(s->getname()); 
            toLower(lowsymbol);
            if (!isMember(lowsymbol)) {
            
              (*table)[lowsymbol] = s;
              return;
            }  
            
            Symbol *sym = (*table)[lowsymbol];
            
            if((s->line<sym->line) ||
              ((s->line==sym->line)&&(s->column<sym->column)))
              errorlog->addError(5,sym->line,sym->column,&sym->name);
            else
              errorlog->addError(5,s->line,s->column, &s->name);              
            

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
            std::cout << " -------------------------------------------------\n";
            for (pos = (*table).begin(); pos != (*table).end(); ++pos) {
                printf(" | %15s | %10s | %2d |%3d | %3d | %2d |\n",(*pos).first.c_str(), 
                pos->second->ntype.c_str(),pos->second->dimensions, pos->second->line, 
                pos->second->column,pos->second->defined);

            }
            std::cout << " -------------------------------------------------\n";


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




