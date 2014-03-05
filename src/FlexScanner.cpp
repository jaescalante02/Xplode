
// Override the interface for yylex since we namespaced it

// Include Bison for types / tokens
#include "xplode.tab.h"
#include "FlexScanner.h"



Xplode::FlexScanner::FlexScanner() {}
Xplode::FlexScanner::FlexScanner(std::istream* fp) {}
			// save the pointer to yylval so we can change it, and invoke scanner


int Xplode::FlexScanner::yylex(Xplode::BisonParser::semantic_type * lval) {}
			// Scanning function created by Flex; make this private to force usage
			// of the overloaded method so we can get a pointer to Bison's yylval
int yylex();
void LexerError( const char* msg ){

  std::cout << "Simbolo extrano encontrado '"<< msg<<"'\n";

}
			// point to yylval (provided by Bison in overloaded yylex)
Xplode::BisonParser::semantic_type * yylval;


