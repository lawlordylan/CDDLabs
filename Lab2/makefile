CC=g++
CFLAGS= -std=c++11 -pthread
FILES= rendezous.cpp Semaphore.cpp
OUT_EXE=rendezous

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS)

clean:
	rm *.o
