#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

class Node{
private:
	int item;
	Node* next;
	Node* parallel;	

public:
	Node(int value);
	int fetchItem();
	Node* getNext();
	Node* getParallel();
	void setParallel(Node* given);
	void setNext(Node* given);
};

#endif
