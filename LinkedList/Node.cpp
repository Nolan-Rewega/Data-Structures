#include "Node.hpp"

Node::Node(int value){
	item = value;
	next = nullptr;
	prev = nullptr;
	//cout << "next is: " << next << "\n";
	//cout << "prev is: " << prev << "\n";
}

int Node::fetchItem(){return item;}
Node* Node::getNext(){
	return next;
}
Node* Node::getPrev(){
	return prev;
}
void Node::setNext(Node* given){next = given;}
void Node::setPrev(Node* given){prev = given;}
