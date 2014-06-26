
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
      
        buffer <<"ERROR " << line << ":" << column << "\n";
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
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' es una definicion y no puede ser solapada.\n";
        break;  
      
      case 7:
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' no es un tipo.\n";
        break;
            
      case 8:
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<< "' no ha sido declarada.\n";
        break;

      case 9: //falta
      
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[1]<< "' no posee atributo '"<<arrstr[0]<<"' declarado.\n";
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
     
      case 19:
    
        buffer <<"ERROR "<< line <<":"<<column << " los procs no aceptan funciones como parametros.\n";
        break;  
          
      case 20:
    
        buffer <<"ERROR "<< line <<":"<<column << " solo los valores primitivos pueden ser pasados por valor.\n";
        break; 
      case 21:
    
        buffer <<"ERROR "<< line <<":"<<column << " la condicion debe ser un booleano.\n";
        break; 
      case 22:
    
        buffer <<"ERROR "<< line <<":"<<column << " las operaciones IO solo aceptan tipos primitivos.\n";
        break;
      case 23:
    
        buffer <<"ERROR "<< line <<":"<<column << " la funcion sleep recibe un entero.\n";
        break;           
      case 24:
    
        buffer <<"ERROR "<< line <<":"<<column << "'"<<arrstr[0]<<"' no se encuentra dentro de un bloque\n";  
        break;
      case 25:
    
        buffer <<"ERROR "<< line <<":"<<column << " el valor retornado no es el esperado\n";  
        break;              
      case 26:
    
        buffer <<"ERROR "<< line <<":"<<column << " no se puede retornar en el main.\n";  
        break; 
      case 27:
    
        buffer <<"ERROR "<< line <<":"<<column << " el operador '"<<arrstr[0]<<"' no puede operar con estos tipos\n";  
        break; 
      case 28:
    
        buffer <<"ERROR "<< line <<":"<<column << " el operador '"<<arrstr[0]<<"' no puede operar este tipo\n";  
        break; 
      case 29:
    
        buffer <<"ERROR "<< line <<":"<<column << " la funcion '"<<arrstr[0]<<"' no recibe el tipo correcto.\n";  
        break; 
      case 30:
    
        buffer <<"ERROR "<< line <<":"<<column << " no es una variable valida.\n";  
        break; 
      case 31:
    
        buffer <<"ERROR "<< line <<":"<<column << " el indice del arreglo no es entero.\n";  
        break; 
      case 32:
    
        buffer <<"ERROR "<< line <<":"<<column << " la variable no posee el operador '[]'.\n";  
        break;  
      case 33:
    
        buffer <<"ERROR "<< line <<":"<<column << " la variable no posee el operador '.'.\n";  
        break; 
      case 34:
    
        buffer <<"ERROR "<< line <<":"<<column << " el atributo '"<<arrstr[0]<<"' no pertenece a este record.\n";  
        break;  
      case 35:
    
        buffer <<"ERROR "<< line <<":"<<column << " la funcion '"<<arrstr[0]<<"' no ha sido declarada.\n";  
        break; 
      case 36:
    
        buffer <<"ERROR "<< line <<":"<<column << " '"<<arrstr[0]<<"' no es una funcion.\n";  
        break; 
      case 37:
    
        buffer <<"ERROR "<< line <<":"<<column << " el tipo no coincide.\n";  
        break;  
      case 38:
    
        buffer <<"ERROR "<< line <<":"<<column << " el numero de argumentos es menor de los requeridos.\n";  
        break;  
      case 39:
    
        buffer <<"ERROR "<< line <<":"<<column << " el numero de argumentos es mayor de los requeridos.\n";  
        break; 
      case 40:
    
        buffer <<"ERROR "<< line <<":"<<column << " la asignacion solo realiza copias en tipos primitivos.\n";  
        break;                                                                           
      case 18:
    
        buffer <<"NOTA "<< line <<":"<<column << " probablemente quisiste usar \':=\'.\n";
        break;  
 
        
      }
      
      
      errorList->insert(std::make_pair(line,buffer.str())); 
    
    }
