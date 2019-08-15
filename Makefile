CC=g++
CPPFLAGS=-g


all: cpptrees

cpptrees: cpptrees.so

cpptrees.so:
	$(CC) $(CPPFLAGS) -fPIC -shared -o $@ tree.h -lc

tests:
	$(CC) $(CPPFLAGS) tests.cpp -o $@.o -lc

clean:
	rm *.so *.o
