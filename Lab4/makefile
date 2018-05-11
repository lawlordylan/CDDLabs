#Dylan Lawlor 11/05/2018
#License Employed: GNU General Public License v3.0
#Makefile
#Used to contain commands to compile project


EXE = Barrier
CC = g++
CFLAGS = -std=c++11 -pthread -I.
CFILES = main.o Barrier.o Semaphore.o

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(CFILES)
	$(CC) $(CFILES) $(CFLAGS) -o $(EXE) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
