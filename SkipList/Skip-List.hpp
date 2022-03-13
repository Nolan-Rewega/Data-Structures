#ifndef SKIP_H
#define SKIP_H

#include "Node.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <climits>
#include <vector>
using namespace std;

class SkipList{
private:
	double p_value;
	vector<Node*> core;
	
	bool coinFlip();	

public:
	SkipList(double probability);	

	// -- insert a value into the list, then probablisically propigate.
	void insert(int value);
	
	// -- remove from the first node of 'value' from all lists.
	void remove(int value);
	
	// -- seach and return the first 'value' in the list.
	Node* search(int value);

	// -- print the list
	void info();
};


#endif
