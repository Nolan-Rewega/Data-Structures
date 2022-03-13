
# Flags
CPPFLAGS = -g -Wall -Wextra
LDFLAGS  = -g
.PHONY: all clean


# Targets

LinkedList: Linked-List.o Node.o main.o
	g++ $(LDFLAGS) -o LinkedList.out Linked-List.o Node.o main.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

Linked-List.o: Linked-List.cpp Linked-List.hpp Node.hpp
	g++ $(CFLAGS) -c Linked-List.cpp

Node.o: Node.cpp Node.hpp
	g++ $(CFLAGS) -c Node.cpp


all: LinkedList

# Clean
clean:
	rm -f *.o
	rm -f *.out
