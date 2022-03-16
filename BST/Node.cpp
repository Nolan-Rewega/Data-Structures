#include "Node.hpp"

Node::Node(int value){
	item = value;
	left = nullptr;
	right = nullptr;
}


int Node::getItem(){ return item;}

Node* Node::getRight(){ return right;}

Node* Node::getLeft(){ return left;}

void Node::setRight(Node* given){ right = given ;}

void Node::setLeft(Node* given){ left = given;}

bool Node::compareGeq(int value){ return item >= value;}
