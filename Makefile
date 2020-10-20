CXX=g++
CXXFLAGS=-Wall -g
SRCS =  nqueens.cpp
OBJ = $(SRCS:.cpp=.o)

all: nqueens

debug: DEFINES = -DDEBUG
debug: clean 
debug: nqueens

nqueens: $(SRCS)
	$(CXX) $(CXXFLAGS) $(DEFINES) $(SRCS) -o nqueens

clean:
	rm -f *.o nqueens *~

tarit:
	tar cvf nqueens.tar Makefile nqueens.cpp
	scp nqueens.tar redekopp@ee.usc.edu:Sites/cs104/
