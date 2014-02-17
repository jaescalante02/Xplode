#pragma once

namespace Xplode {
	class Parser {
		public:
			Parser() : parser(scanner) {}
		
			int parse() {
				return parser.parse();
			}
		
		private:
			Xplode::FlexScanner scanner;
			Xplode::BisonParser parser;
	};
}
