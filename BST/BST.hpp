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
	void insert();
	void remove();
	Node* search();
	Node* getRoot();
	void setRoot(Node* given);

};


#endif
