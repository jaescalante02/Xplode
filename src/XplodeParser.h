#pragma once

#include "FlexScanner.h"

namespace Xplode {
	class Parser {
		public:
			Parser(int *program, std::istream* fp) {  


                                  scanner = new Xplode::XplodeScanner(fp); // aqui se cambia el lexer XplodeScanner o ClassicScanner
                                  parser = new Xplode::BisonParser(program, *scanner);



                                                                 }
		
			int parse() {
				return (*parser).parse();
			}
		
		private:
			Xplode::FlexScanner *scanner;
			Xplode::BisonParser *parser;
	};
}
