.PHONY: all build test clean

all: build

build: tests/run_all_tests

tests/run_all_tests: tests/run_all.o
	g++ -o tests/run_all_tests tests/run_all.o

tests/run_all.o: heapless_cpp.hpp tests/run_all.cpp
	g++ -c tests/run_all.cpp -o tests/run_all.o

test: build
	./tests/run_all_tests

clean:
	rm tests/run_all_tests tests/run_all.o