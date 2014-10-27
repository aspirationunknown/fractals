# Makefile for Fractal program.

# Author: John M. Weiss, Ph.D., Derek Stotz, Charles Parsons
# Written Fall 2014 for CSC433/533 Computer Graphics.

# Usage:  make target1 target2 ...

#-----------------------------------------------------------------------

# GNU C/C++ compiler and linker:
CC = gcc
CXX = g++
LINK = g++

# Turn on optimization and warnings (add -g for debugging with gdb):
CXXFLAGS = -O3 -Wall -std=c++11 -g

# OpenGL/Mesa libraries for Linux:
GL_LIBS = -lglut -lGLU -lGL -lm

#-----------------------------------------------------------------------

OBJS = fractal.o fractalGraphics.o structs.o


fractal: fractal.o fractalGraphics.o structs.o 

	${LINK} ${OBJS} ${CXXFLAGS} -o fractal ${GL_LIBS}


fractal.o: fractal.cpp fractal.h structs.o

	${CXX} ${CXXFLAGS} -c fractal.cpp ${GL_LIBS}


fractalGraphics.o: fractalGraphics.cpp fractal.h structs.o

	${CXX} ${CXXFLAGS} -c fractalGraphics.cpp ${GL_LIBS}


structs.o: structs.cpp structs.h

	${CXX} ${CXXFLAGS} -c structs.cpp ${GL_LIBS}

clean:

	rm -rf *o fractal
