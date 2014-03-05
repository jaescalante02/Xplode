all:  bis fle FlexScanner.o
	g++ lex.xp.cc lex.cl.cc FlexScanner.o Main.cpp xplode.tab.c -o xplode
	
FlexScanner.o:  FlexScanner.h FlexScanner.cpp bis
	g++ -c FlexScanner.cpp	

bis: xplode.y 
	bison -v xplode.y

fle: classic.l xplode.l
	flex -i classic.l
	flex -i xplode.l

clean:
	rm -rf xplode.tab.c xplode.tab.h location.hh position.hh stack.hh
	rm -rf lex.xp.cc lex.cl.cc
	rm -rf xplode FlexScanner.o xplode.output
	rm -rf *~
