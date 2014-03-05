#pragma once

#ifndef CL_FLEX_LEXER
#define yyFlexLexer clFlexLexer
#include <FlexLexer.h>
#define CL_FLEX_LEXER
#endif

// Override the interface for yylex since we namespaced it


// Include Bison for types / tokens
#include "xplode.tab.h"
#include "FlexScanner.h"

namespace Xplode {
	class ClassicScanner : public clFlexLexer, public FlexScanner {
		public:

                        ClassicScanner();
                        ClassicScanner(std::istream* fp){ switch_streams(fp, 0); }
			// save the pointer to yylval so we can change it, and invoke scanner
			int yylex(Xplode::BisonParser::semantic_type * lval) { yylval = lval; return yylex(); }
		
		private:
			// Scanning function created by Flex; make this private to force usage
			// of the overloaded method so we can get a pointer to Bison's yylval
			int yylex();
			void LexerError( const char* msg ){

                          std::cout << "Simbolo extrano encontrado '"<< msg<<"'\n";

                        }
			// point to yylval (provided by Bison in overloaded yylex)
			Xplode::BisonParser::semantic_type * yylval;
	};
}

