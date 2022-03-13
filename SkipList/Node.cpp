#include "Node.hpp"

Node::Node(int value){
	item = value;
	next = nullptr;
	parallel = nullptr;
}

int Node::fetchItem(){return item;}
Node* Node::getNext(){return next;}
Node* Node::getParallel(){return parallel;}
void Node::setNext(Node* given){next = given;}
void Node::setParallel(Node* given){parallel = given;}

