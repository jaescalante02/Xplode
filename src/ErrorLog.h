#ifndef X_ERROR_LOG
#define X_ERROR_LOG

#include <map>
#include <string>
#include <iostream>
#include <sstream>

class ErrorLog{
  public:
  
    ErrorLog();
    void addError(int numerror, int line, int column, std::string lex = "");

    bool existError();
    
    void print();

  private:
  
    std::multimap<int, std::string> *errorList;

};


#endif
