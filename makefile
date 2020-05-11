CC= g++
CFLAGS= -Wall
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system

all:	PhotoMagic

PhotoMagic:	PhotoMagic.o LFSR.o
	$(CC) PhotoMagic.o LFSR.o -o PhotoMagic $(SFMLFLAGS)

PhotoMagic.o:	PhotoMagic.cpp LFSR.hpp
	$(CC) -c PhotoMagic.cpp LFSR.hpp $(CFLAGS)

LFSR.o:		LFSR.cpp LFSR.hpp
	$(CC) -c LFSR.cpp $(CFLAGS)

clean:
	rm *.o
	rm PhotoMagic
