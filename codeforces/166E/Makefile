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

all : PS6Codeforces166E.class ps6-codeforces-166E

PS6Codeforces166E.class : PS6Codeforces166E.java
	javac PS6Codeforces166E.java

ps6-codeforces-166E : ps6-codeforces-166E.cc
	$(CXX) $(CPPFLAGS) -o ps6-codeforces-166E ps6-codeforces-166E.cc $(LIBFLAGS)

test : all
	timeout -k 5 2 ./ps6-codeforces-166E < ps6-codeforces-166E.in
	timeout -k 5 2 java PS6Codeforces166E < ps6-codeforces-166E.in
	timeout -k 5 2 ./ps6-codeforces-166E.py < ps6-codeforces-166E.in

clean :
	rm -f *.d
	rm -f *.o
	rm -f *.pyc
	rm -f *.class
	rm -f ps6-codeforces-166E

-include *.d
