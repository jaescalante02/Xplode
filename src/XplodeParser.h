#pragma once

namespace Xplode {
	class Parser {
		public:
			Parser(std::istream* fp) : scanner(fp),parser(scanner) {}
		
			int parse() {
				return parser.parse();
			}
		
		private:
			Xplode::FlexScanner scanner;
			Xplode::BisonParser parser;
	};
}
