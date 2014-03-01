#pragma once

namespace Xplode {
	class Parser {
		public:
			Parser(int *program, std::istream* fp) : scanner(fp),parser(program,scanner) {}
		
			int parse() {
				return parser.parse();
			}
		
		private:
			Xplode::FlexScanner scanner;
			Xplode::BisonParser parser;
	};
}
