CXX = g++
CXXFLAGS = -Wall -Werror -std=c++14
TEST_MATRIX_OBJS = matrix.o test-matrix.o testbase.o

all : test-matrix

test-matrix : $(TEST_MATRIX_OBJS)
				$(CXX) $(CXXFLAGS) $^ -o $@

test : test-matrix
				./test-matrix

clean :
				rm -f test-matrix *.o *~

.PHONY : all clean test
