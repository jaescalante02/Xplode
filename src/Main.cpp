#include <iostream>     // std::ios, std::istream, std::cout
#include <fstream> 
#include <string>

#include "XplodeScanner.h"
#include "ClassicScanner.h"
#include "XplodeParser.h"
#include "FlexScanner.h"


int line = 1;
int column = 1;
std::string tok;
 

int selectLexer(char* fp){

    std::ifstream input(fp);
    int progcl=0,comment=0, progxp=0;

    for( std::string line; getline(input, line); ){

         comment = line.find("//");  
         progxp  =  line.find("explotion");
         progcl  = line.find("program");

         if ((progcl!=-1)&&((comment==-1)||(progcl<comment))) 
            return 1;

         if ((progxp!=-1)&&((comment==-1)||(progxp<comment))) 
            return 2;

    }

    return 1;

}

// Entry Point
int main(int argc, char * argv[]) {

    std::filebuf fb;
    fb.open (argv[1] ,std::ios::in);
    std::istream is(&fb);

    Xplode::FlexScanner *scanner;
    int a=0;
    Main *program;
    a = selectLexer(argv[1]);
    if (a==1) scanner = new Xplode::ClassicScanner(&is);
    else scanner = new Xplode::XplodeScanner(&is);
    Xplode::Parser parser(&program,scanner);
    parser.parse();
    program->printTable(); 
    return 0;

}

