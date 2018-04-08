IDIR =include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs -std=c++11
ODIR=obj

_DEPS = arvore.h catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = arvore.o testa_arvore.o test_main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

obj/testa_arvore.o: 
	g++ -o obj/testa_arvore.o -c testa_arvore.c $(CFLAGS)

obj/test_main.o:
	g++ -o obj/test_main.o -c test_main.c $(CFLAGS)

obj/arvore.o:
	g++ -o obj/arvore.o -c arvore.c $(CFLAGS)

test:  obj/arvore.o obj/test_main.o obj/testa_arvore.o
	g++ $^ -o catch.exe $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 