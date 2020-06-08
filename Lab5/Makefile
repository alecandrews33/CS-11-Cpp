CXX = g++
CXXFLAGS = -Wall -Werror -std=c++14
HW5TEST_OBJS = rational.o testbase.o test-rational.o

all : test-rational

test-rational : $(HW5TEST_OBJS)
				$(CXX) $(CXXFLAGS) $^ -o $@

test : test-rational
				./test-rational

clean :
				rm -f all test-rational *.o *~

.PHONY : all clean test
