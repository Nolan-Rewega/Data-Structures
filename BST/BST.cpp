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
	if(size != 0){
		// -- if removing root, we have to handle it in BST.cpp
		if(root->getItem() == value){
			if(root->getRight() == nullptr && root->getLeft() == nullptr){root = nullptr;}
			else if(root->getRight() != nullptr && root->getLeft() != nullptr){
				root->getRight()->insert(root->getLeft());
				setRoot(root->getRight());
			}
			else if(root->getRight() != nullptr){ setRoot(root->getRight());}
			else{setRoot(root->getLeft());}
		}
		else{root->remove(value);}
	}
}



Node* BST::search(int value){
	if(size == 0){return nullptr;}
	return root->search(value);
}



void BST::setRoot(Node* given){
	root = given;
	root->setParent(nullptr);
}



void BST::info(){
	// -- BFS traversal
	if(root != nullptr){root->BFSprint();}
	cout << "\n";
}
