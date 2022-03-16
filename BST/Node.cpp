#include "Node.hpp"

Node::Node(int value){
	item = value;
	left = nullptr;
	right = nullptr;
}


/*BST methods*/
bool Node::insert(Node* given){
	// -- insert/search right
	if(given->getItem() >= item){
		if(right != nullptr){return right->insert(given);}
		else{ right = given; return true;}
	}
	// -- insert/search left
	else{
		if(left != nullptr){return left->insert(given);}
    	else{ left = given; return true;}
	}
}


void Node::BFSprint(int height){
	for(int i = 0; i < height; i++){
		if(i < height * 2 || i > height * 2){cout << "\t";}
		else{cout << item;}
	}
	cout << "\n";
	
	if(left != nullptr){left->BFSprint(height - 1);}
	if(left != nullptr){left->BFSprint(height - 1);}

}



/* Node methods*/
int Node::getItem(){ return item;}
Node* Node::getRight(){ return right;}
Node* Node::getLeft(){ return left;}
void Node::setRight(Node* given){ right = given ;}
void Node::setLeft(Node* given){ left = given;}

