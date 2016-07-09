CSTD   := c11
CPPSTD := c++11

ifeq "$(CXX)" "g++"
	GCCVERSIONLT48 := $(shell expr `gcc -dumpversion` \< 4.8)
	ifeq "$(GCCVERSIONLT48)" "1"
		CSTD := c99
		CPPSTD := c++0x
	endif
endif

VALGRIND := valgrind

CFLAGS   := -pedantic -std=$(CSTD) -Wall -Werror -O3
CPPFLAGS := -pedantic -std=$(CPPSTD) -Wall -Werror -O3
LIBFLAGS  := -pthread -fopenmp

all : main

main : main.o
	$(CXX) $(CPPFLAGS) -o main main.o $(LIBFLAGS)

%.o : %.cc
	$(CXX) $(CPPFLAGS) -MD -c $*.cc $(LIBFLAGS)

test : all
	tail -n +2 < main.in | ./clean.py
	timeout -k 5 2 ./main < main.in | ./clean.py
	tail -n +2 < large.in | ./clean.py
	timeout -k 5 2 ./main < large.in | ./clean.py

clean :
	rm -f *.d
	rm -f *.o
	rm -f main

-include *.d
