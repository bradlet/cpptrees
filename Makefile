CC=g++
CPPFLAGS=-g


all: cpptrees

cpptrees: cpptrees.so

cpptrees.so:
	$(CC) $(CPPFLAGS) -fPIC -shared -o $@ tree.h -lc

tests: test intersect

test:
	$(CC) $(CPPFLAGS) tests/tests.cpp -o $@.o -lc

intersect:
	$(CC) $(CPPFLAGS) tests/intersection.cpp -o $@.o -lc

clean:
	rm *.so *.o
