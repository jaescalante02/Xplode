all:
	bison xplode.y -v
	flex xplode.l
	g++ lex.yy.cc Main.cpp xplode.tab.c -o xplode
	
clean:
	rm -rf xplode.tab.c xplode.tab.h location.hh position.hh stack.hh
	rm -rf lex.yy.cc
	rm -rf xplode
	rm -rf *~
