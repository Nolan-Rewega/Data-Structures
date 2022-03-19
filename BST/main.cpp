#include "BST.hpp"
#include<cassert>


int main(){
	BST* bst = new BST();

	bst->insert(10);
	bst->insert(8);
	bst->insert(12);
	bst->insert(100);
	bst->insert(11);
	bst->insert(90);
	bst->insert(150);
	bst->insert(2);
	bst->info();
	
	assert(bst->search(10) != nullptr /* didn't find anything */);
	assert(bst->search(9000) == nullptr /* found something that does not exist*/);
	assert(bst->search(2) != nullptr /* didn't find anything */);




}
