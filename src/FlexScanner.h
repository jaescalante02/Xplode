#pragma once

// Override the interface for yylex since we namespaced it
// Include Bison for types / tokens
#include "xplode.tab.h"

#ifndef FL_FLEX_LEXER
#define FL_FLEX_LEXER



namespace Xplode {
	class FlexScanner {
		public:

                        FlexScanner();
                        FlexScanner(std::istream* fp);
			// save the pointer to yylval so we can change it, and invoke scanner
			virtual int yylex(Xplode::BisonParser::semantic_type * lval);
		
		private:
			// Scanning function created by Flex; make this private to force usage
			// of the overloaded method so we can get a pointer to Bison's yylval
			int yylex();
			void LexerError( const char* msg );

			// point to yylval (provided by Bison in overloaded yylex)
			Xplode::BisonParser::semantic_type * yylval;
	};
}


#endif
