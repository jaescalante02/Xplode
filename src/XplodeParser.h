#pragma once

#include "FlexScanner.h"

namespace Xplode {
	class Parser {
		public:
			Parser(Program **program, Xplode::FlexScanner *scanner) {  

                                  parser = new Xplode::BisonParser(program, *scanner);



                                                                }
		
			int parse() {
				return (*parser).parse();
			}
		
		private:
			Xplode::BisonParser *parser;
	};
}
