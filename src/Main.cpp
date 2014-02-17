#include "XplodeScanner.h"
#include "XplodeParser.h"

// Entry Point
int main(int argc, char * argv[]) {
	Xplode::Parser parser;
	return parser.parse();
}

