#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
using namespace std;

class Node{
private:
	int item;
	Node* parent;
	Node* left;
	Node* right;

public:
	Node(int value);
	
	/* BST methods */
	bool insert(Node* given);
	void remove(int given);
	Node* search(int value);
	void BFSprint();

	/* Node methods */
	int getItem();
	Node* getLeft();
	Node* getRight();
	void setLeft(Node* given);
	void setRight(Node* given);
	Node* getParent();
	void setParent(Node* given);
};

#endif
