#include "XplodeScanner.h"
#include "XplodeParser.h"
#include <iostream>     // std::ios, std::istream, std::cout
#include <fstream> 

// Entry Point
int main(int argc, char * argv[]) {

        std::filebuf fb;
        fb.open (argv[1],std::ios::in);
        std::istream is(&fb);
        Xplode::Parser parser(&is);
	return parser.parse();

}

