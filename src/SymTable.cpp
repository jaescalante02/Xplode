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

            //falta caso error, ya existe
            std::string lowsymbol(s->getname()); 
            toLower(lowsymbol);
            if (!isMember(lowsymbol)) (*table)[lowsymbol] = s;

        }

        Symbol *SymTable::findall(std::string variable) {

            if(isMember(variable)) return (*table)[variable];
            if(father==NULL) return NULL;            
            return (*father).findall(variable);

        }

        Symbol *SymTable::find(Variable *variable){ 

            std::string var(*variable->varList->begin());
            toLower(var);
            return this->findall(var);
        }

        void SymTable::print(){

            if (table->empty()) return;

            std::map<std::string, Symbol *>::iterator pos;
            std::cout << " -------------------------------------------------\n";
            for (pos = (*table).begin(); pos != (*table).end(); ++pos) {
                printf(" | %15s | %10s | %2d |%3d | %3d | %2d |%ld\n",(*pos).first.c_str(), 
                pos->second->ntype.c_str(),pos->second->dimensions, pos->second->line, 
                pos->second->column,pos->second->editable, (long int) pos->second->pt);

            }
            std::cout << " -------------------------------------------------\n";


        }

        void SymTable::setFather(SymTable *s){ father=s; }
       

        bool SymTable::isMember(std::string variable){return ((*table).count(variable)>0);} 




