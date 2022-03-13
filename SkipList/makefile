
# Flags
CPPFLAGS = -g -Wall -Wextra
LDFLAGS  = -g
.PHONY: all clean


# Targets
SkipList: Skip-List.o Node.o main.o
	g++ $(LDFLAGS) -o SkipList.out Skip-List.o Node.o main.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

Node.o: Node.cpp Node.hpp
	g++ $(CFLAGS) -c Node.cpp

Skip-List.o: Skip-List.cpp Skip-List.hpp Node.hpp
	g++ $(CFLAGS) -c Skip-List.cpp

all: SkipList

# Clean
clean:
	rm -f *.o
	rm -f *.out
