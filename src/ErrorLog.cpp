
#include "ErrorLog.h"


    ErrorLog::ErrorLog() {
    
      errorList = new std::multimap<int, std::string>;
    
    }

    bool ErrorLog::existError() { return ! errorList->empty(); }
    
    void ErrorLog::print(){
        
        std::multimap<int, std::string>::iterator it;
        
        for(it = errorList->begin();it!=errorList->end();++it)
            std::cout << (*it).second;      
        
       
        
        }
    
    
    void ErrorLog::addError(int numerror, int line, int column, std::string lex){
    
      std::stringstream buffer;
      
      switch(numerror){

      case 0:
      
        buffer << "'"<<lex<< "' con error.\n";
        break;
      
      case 5:
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<lex<< "' ya ha sido declarada.\n";
        break;
      
            
      }
      
      errorList->insert(std::make_pair(line,buffer.str())); 
    
    }
