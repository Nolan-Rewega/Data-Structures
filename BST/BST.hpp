#ifndef BST_H
#define BST_H

#include<iostream>
#include "Node.hpp"
using namespace std;

class BST{
private:
	int size;
	Node* root;


public:
	BST();	

	void insert(int value);
	void remove(int value);
	Node* search(int value);
	Node* getRoot();
	void setRoot(Node* given);
	
	void info();
};


#endif
