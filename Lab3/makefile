CC=g++
CFLAGS= -std=c++11 -pthread
FILES= mutex.o Semaphore.o
OUT_EXE=mutex

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS) $(DEBUGFLAGS)

debug: DEBUGFLAGS = -ddebug
debug: build

clean:
	rm *.o
