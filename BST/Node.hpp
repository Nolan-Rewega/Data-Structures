#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
using namespace std;

class Node{
private:
	int item;
	Node* left;
	Node* right;

public:
	Node(int value);
	int getItem();
	Node* getLeft();
	Node* getRight();
	void setLeft(Node* node);
	void setRight(Node* node);
	
	bool compareGeq(int value);
    

};

#endif
