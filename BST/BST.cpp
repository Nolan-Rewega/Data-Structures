#include "BST.hpp"

BST::BST(){
	root = nullptr;
	size = 0;
}


void BST::insert(int value){
	Node* node = new Node(value);
	if(size == 0){root = node; size++; return;}
	
	// -- on success
	if(root->insert(node)){size++;}	
}

void BST::remove(int value){
	if(size != 0 ){root->remove(value);}
}

Node* BST::search(int value){
	if(size == 0){return nullptr;}
	return root->search(value);
}

void BST::info(){
	// -- BFS traversal
	if(root != nullptr){root->BFSprint();}
	cout << "\n";
}
