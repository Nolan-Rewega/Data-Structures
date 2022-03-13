#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

class Node{
private:
	int item;
	Node *next;
	Node *prev;

public:
	Node(int value);
	int  fetchItem();
	Node* getNext();
	Node* getPrev();
	void setNext(Node* given);
	void setPrev(Node* given);
};


#endif
