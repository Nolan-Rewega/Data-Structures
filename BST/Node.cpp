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

void Node::remove(int value){}

Node* Node::search(int value){
	if(item == value){return this;}

	Node* leftResult = nullptr;
	Node* rightResult = nullptr;

	if(left != nullptr){leftResult = left->search(value);}
	if(right != nullptr){rightResult = right->search(value);}
	
	if(leftResult != nullptr){return leftResult;}
	if(rightResult != nullptr){return rightResult;}
	return nullptr;
}



void Node::BFSprint(){
	cout << item << "\t";
	
	if(left != nullptr){left->BFSprint();}
	if(right != nullptr){right->BFSprint();}

}



/* Node methods*/
int Node::getItem(){ return item;}
Node* Node::getRight(){ return right;}
Node* Node::getLeft(){ return left;}
void Node::setRight(Node* given){ right = given ;}
void Node::setLeft(Node* given){ left = given;}

