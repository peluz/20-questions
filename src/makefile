IDIR =include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs -std=c++11 -g
ODIR=obj

_DEPS = arvore.h catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = arvore.o testa_arvore.o test_main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

jogo: obj/arvore.o obj/jogo_20_perguntas.o
	$(CC) $^ -o jogo $(CFLAGS)

obj/jogo_20_perguntas.o:
	$(CC) -o obj/jogo_20_perguntas.o -c jogo_20_perguntas.c $(CFLAGS)

obj/testa_arvore.o: 
	$(CC) -o obj/testa_arvore.o -c testa_arvore.c $(CFLAGS)

obj/test_main.o:
	$(CC) -o obj/test_main.o -c test_main.c $(CFLAGS)

obj/arvore.o:
	$(CC) -o obj/arvore.o -c arvore.c $(CFLAGS)

test:  obj/arvore.o obj/test_main.o obj/testa_arvore.o
	$(CC) $^ -o catch.exe $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 