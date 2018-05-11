#Dylan Lawlor 11/05/2018
#Makefile
#Used to contain commands to compile project

EXE = rendevous
CC = g++
CFLAGS = -std=c++11 -pthread -I.
CFILES = rendevous.o Semaphore.o

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: $(CFILES)
	$(CC) $(CFILES) $(CFLAGS) -o $(EXE)


#this is customary and just deletes all .o files
CLEAN:
	rm *.o
