#include "BST.hpp"

BST::BST(){
	root = nullptr;
	size = 0;
}


BST::insert(int value){
	Node* node = new Node(value);
	if(size == 0){root = node; size++; return;}
	
	// -- on success
	if(root->insert(node)){size++;}	
}


BST::info(){
	// -- BFS traversal

}
