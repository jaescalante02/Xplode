
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
    
    
    void ErrorLog::addError(int numerror, int line, int column, std::string *arrstr){
    
      std::stringstream buffer;
      
      switch(numerror){

      case 0:
      
        buffer << "'"<<arrstr[0] << "' con error.\n";
        break;
        
      case 1:
      
        buffer << "ERROR " << line << ":" << column << " caracter inesperado"
	      << "\'" << arrstr[0] << "\'.\n"; 
        break;
        
      case 2:
      
        buffer << "ERROR " << line << ":" << column << " sintaxis inadecuada, token "
	      << "\'" << arrstr[0] << "\' inesperado.\n"; 
        break;
      case 5:
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' ya ha sido declarada.\n";
        break;
        
      case 6:
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' es un tipo.\n";
        break;  
      
      case 7:
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' no es un tipo.\n";
        break;
            
      case 8:
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' no ha sido declarada.\n";
        break;

      case 9: //falta
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<<arrstr[1]<<arrstr[2]<< "' no ha sido declarada.\n";
        break;

      case 10:
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' posee una cantidad incorrecta de dimensiones.\n";
        break;
        
      case 11:
    
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' es un tipo primitivo y no posee el operador de acceso.\n";
        break;   

      case 12:
    
        buffer <<"ERROR "<< line <<":"<<column << " El tipo '"<<arrstr[0]<< "' no se puede operar.\n";
        break;
        
      case 14:
    
        buffer <<"ERROR "<< line <<":"<<column << " ';' faltante.\n";
        break;        

      case 15:
    
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' no es una funcion.\n";
        break;
        
      case 16:
    
        buffer <<"ERROR "<< line <<":"<<column << " '{' faltante.\n";
        break;   
      
      case 17:
    
        buffer <<"ERROR "<< line <<":"<<column << " palabra de inicio faltante.\n";
        break;   
        
      }
      
      
      errorList->insert(std::make_pair(line,buffer.str())); 
    
    }
