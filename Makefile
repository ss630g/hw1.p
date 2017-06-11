# cs335 hw1
# to compile your project, type make and press enter

all: hw1

hw1: hw1.cpp hw1function.cpp
	g++ hw1.cpp hw1function.cpp libggfonts.a -Wall -ohw1 -lX11 -lGL -lGLU -lm

clean:
	rm -f hw1
	rm -f *.o

