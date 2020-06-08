CXX = g++
CXXFLAGS = -Wall -Werror -std=c++14
CONVERT_OBJS = units.o convert.o
HW3TEST_OBJS = units.o hw3testunits.o testbase.o

all : convert hw3testunits

convert : $(CONVERT_OBJS)
				$(CXX) $(CXXFLAGS) $^ -o $@

hw3testunits : $(HW3TEST_OBJS)
				$(CXX) $(CXXFLAGS) $^ -o $@

test : hw3testunits
				./hw3testunits

doc : Doxyfile
				doxygen

clean :
				rm -f convert hw3testunits *.o *~
				rm -rf docs

.PHONY : all clean doc test
