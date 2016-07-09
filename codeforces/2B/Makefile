CSTD   := c99
CPPSTD := c++11

ifeq "$(CXX)" "g++"
	GCCVERSIONLT48 := $(shell expr `gcc -dumpversion` \< 4.8)
	ifeq "$(GCCVERSIONLT48)" "1"
		CPPSTD := c++0x
	endif
endif

CFLAGS   := -pedantic -std=$(CSTD) -Wall -Werror -O3
CPPFLAGS := -pedantic -std=$(CPPSTD) -Wall -Werror -O3
LIBFLAGS := 

all : main

main : main.cc
	$(CXX) $(CPPFLAGS) -o main main.cc $(LIBFLAGS)

test : all
	./main < main.in

clean :
	rm -f *.d
	rm -f *.o
	rm -f main

-include *.d
