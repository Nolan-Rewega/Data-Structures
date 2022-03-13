#ifndef LL_H
#define LL_H

#include<iostream>
#include "Node.hpp"
using namespace std;

class LinkedList{
private:
	int size;
	Node *current;
	Node *first;
	Node *last;

public:
	// -- Constructor
	LinkedList();

	// -- insert a node at the current node.
	void insert(int value);

	// -- prepend to the list, without change current.
	void prepend(int value);

	// -- remove the current pointer value
	void remove();

	// -- return the size of the linked list
	int length();

	// -- move to the next item
	void next();

	// -- move to the prev item
	void prev();

	// -- move cursor to the front
	void front();

	// -- move cursor to the end
	void end();

	// -- print the lists current state
	void info();
};
#endif
