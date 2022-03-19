#ifndef BST_H
#define BST_H

#include<iostream>
#include "Node.hpp"
using namespace std;

class BST{
private:
	int size;
	Node* root;

	void setRoot(Node* given);

public:
	BST();	

	void insert(int value);
	void remove(int value);
	Node* search(int value);
	Node* getRoot();
	
	void info();
};


#endif
