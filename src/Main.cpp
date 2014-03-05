#include <iostream>     // std::ios, std::istream, std::cout
#include <fstream> 

#include "XplodeScanner.h"
#include "ClassicScanner.h"
#include "XplodeParser.h"
#include "FlexScanner.h"

// Entry Point
int main(int argc, char * argv[]) {

        std::filebuf fb;
        int program =0 ; //int momentaneo
        fb.open (argv[1],std::ios::in);
        std::istream is(&fb);
        Xplode::Parser parser(&program, &is);
        parser.parse();
        std::cout << program << std::endl; 
	return 0;

}

