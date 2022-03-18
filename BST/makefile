
# Flags
CPPFLAGS = -g -Wall -Wextra
LDFLAGS  = -g
.PHONY: all clean



# Targets

BST: BST.o Node.o main.o
	g++ $(LDFLAGS) -o BST.out BST.o Node.o main.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

BST.o: BST.cpp BST.hpp Node.hpp
	g++ $(CFLAGS) -c BST.cpp

Node.o: Node.cpp Node.hpp
	g++ $(CFLAGS) -c Node.cpp


all: BST

clean:
	rm -f *.o
	rm -f *.out



