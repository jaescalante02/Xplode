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
	Xplode::FlexScanner *scanner;
        int a=0;
        if(argc<=2) a=1;
        else a=atoi(argv[2]);
        if (a==1) scanner = new Xplode::ClassicScanner(&is);
        else scanner = new Xplode::XplodeScanner(&is);

        Xplode::Parser parser(&program,scanner);
        parser.parse();
        std::cout << program << std::endl; 
	return 0;

}

