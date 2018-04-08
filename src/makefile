IDIR =include
CC=gcc
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs
ODIR=obj

obj/testa_arvore.o: 
	g++ -o obj/testa_arvore.o -c testa_arvore.c -std=c++11

obj/test_main.o:
	g++ -o obj/test_main.o -c test_main.c -std=c++11

obj/arvore.o:
	g++ -o obj/arvore.o -c arvore.c

test:  obj/arvore.o obj/test_main.o obj/testa_arvore.o
	g++ $^ -o catch.exe

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 