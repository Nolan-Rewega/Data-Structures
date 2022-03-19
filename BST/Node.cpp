#include "Node.hpp"

Node::Node(int value){
	item = value;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}


/*BST methods*/
bool Node::insert(Node* given){
	// -- insert/search right
	if(given->getItem() >= item){
		if(right != nullptr){return right->insert(given);}
		else{
			right = given;
			given->setParent(this);
			return true;
		}
	}
	// -- insert/search left
	else{
		if(left != nullptr){return left->insert(given);}
    	else{
			left = given;
			given->setParent(this);
			return true;
		}
	}
}


void Node::remove(int value){
	if(value == item){
		/* ugly duplicate code.*/
		if(item >= parent->getItem()){
			if(right == nullptr && left == nullptr){parent->setRight(nullptr);}
			else if(right != nullptr && left != nullptr){
				parent->setRight(right);
				right->insert(left);
			}
			else if(right != nullptr){parent->setRight(right);}
			else{parent->setRight(left);}
		}
		else{
			if(right == nullptr && left == nullptr){parent->setLeft(nullptr);}
			else if(right != nullptr && left != nullptr){
				parent->setLeft(left);
				left->insert(right);
			}
			else if(right != nullptr){parent->setLeft(right);}
			else{parent->setLeft(left);}
		}
	}
	else if( value > item && right != nullptr){right->remove(value);}
	else if( value < item && left != nullptr){left->remove(value);}

}



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
Node* Node::getParent(){return parent;}
void Node::setRight(Node* given){ right = given ;}
void Node::setLeft(Node* given){ left = given;}
void Node::setParent(Node* given){ parent = given;}

