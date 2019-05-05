# Makefile for Linux Compilation
# Made by Josh Winton for Assignment 4 in CSCI 335

# FLAGS
C++FLAG = -g -std=c++11 -Wall

.cc.o:
	g++ $(C++FLAG)


PROGRAM_0=
creategraphandtest:
	g++ CreateGraphAndTest.cc -o CreateGraphAndTest -g

findpaths:
	g++ FindPaths.cc -o FindPaths -g

clean:
	rm -rf *.o; rm -rf CreateGraphAndTest; rm -rf FindPaths;
