#include <iostream>
#include <cassert>
#include "Skip-List.hpp"
using namespace std;


int main(){
	SkipList* SList = new SkipList(0.75);
	
	// -- testing insert.
	SList->insert(10);
	SList->insert(20);
	SList->insert(100);
	SList->insert(15);
	SList->insert(-1110);
	SList->insert(INT_MIN);
	SList->insert(INT_MAX);
	SList->info();
	
	// -- testing search. Assuming search(INT_MIN) dosn't return a core node.
	assert(SList->search(15)->fetchItem() == 15 /*got wrong node*/);
	assert(SList->search(105) == nullptr /*got non nullptr*/);

	// -- testing remove.
	SList->remove(-1110);
	SList->remove(-111);
	SList->info();
}
