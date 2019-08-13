CC=g++
CPPFLAGS=-g


all: cpptrees tests

cpptrees: cpptrees.so

cpptrees.so:
	$(CC) $(CPPFLAGS) -fPIC -shared -o $@ tree.h -lc

tests:
	$(CC) $(CPPFLAGS) tests.cpp -o $@ -lc

clean:
	rm *.so tests
