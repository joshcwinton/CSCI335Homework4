# Makefile for Linux Compilation
# Made by Josh Winton for Assignment 4 in CSCI 335

# FLAGS
C++FLAG = -g -std=c++11 -Wall

.cc.o:
	g++ $(C++FLAG)


PROGRAM_0=
all:
	g++ CreateGraphAndTest.cc -o creategraphandtest

clean:
	rm -rf *.o; rm -rf creategraphandtest
