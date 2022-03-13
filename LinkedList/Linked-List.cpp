#include "Linked-List.hpp"

/* LinkedList Contructor. */
LinkedList::LinkedList(){
	size = 0;
	
	current = nullptr;
	first = nullptr;
	last = nullptr;
}


/* Insert a item in front of the current Node. */
void LinkedList::insert(int value){
	// -- Create the new Node
	Node* newNodePtr = new Node(value);
	
	// -- non-empty list 
	if(size > 0){
		newNodePtr->setNext(current->getNext()); // -- Null or Node
		newNodePtr->setPrev(current);
		current->setNext(newNodePtr);
		// -- accessing last element
		if (current == last){last = newNodePtr;}
		// -- accessing middle element
		else{newNodePtr->getNext()->setPrev(newNodePtr);}
	}
	else {
		first = newNodePtr;
		last = newNodePtr;
	}
	
	current = newNodePtr;
	size++;
}


/* Prepend to the current list. */
void LinkedList::prepend(int value){
	// -- Create the new Node
	Node* newNodePtr = new Node(value);
	
	// -- set pointers
	newNodePtr->setPrev(nullptr);
	newNodePtr->setNext(first);
	first->setPrev(newNodePtr);
	first = newNodePtr;

	size++;
}


/* Remove the current Node. */
void LinkedList::remove(){
	if (size <= 0){throw "LinkedList.remove() on empty list.";}
	else{
		Node* nextPtr = current->getNext();
		Node* prevPtr = current->getPrev();

		// -- setting Node pointers
		if(nextPtr == nullptr && prevPtr == nullptr){
			current = nullptr;
		}
		else if(nextPtr == nullptr){
			prevPtr->setNext(nullptr);
			last = prevPtr;
			current = prevPtr;
		}
		else if(prevPtr == nullptr){
			nextPtr->setPrev(nullptr);
			first = nextPtr;
			current = nextPtr;
		}
		else{
			prevPtr->setNext(nextPtr);
			nextPtr->setPrev(prevPtr);
			current = nextPtr;
		}
		size--;
	}

}


/* Return the size of the LinkedList. */
int LinkedList::length(){ return size;}


/* Set current to the next item. */
void LinkedList::next(){
	if(current != nullptr){
		if(current->getNext() != nullptr){
			current = current->getNext();
		}
		else{throw "LinkedList.next() on end of list.";}
	}
	else{throw "LinkedList.next() on empty list.";}
}


/* Set current to the previous item. */
void LinkedList::prev(){
	if(current != nullptr){
		if(current->getPrev() != nullptr){
			current = current->getPrev();
		}
		else{throw "LinkedList.prev() on front of list.";}
	}
	else{throw "LinkedList.prev() on empty list.";}
}


/* Set current to the front/last Node. */
void LinkedList::front(){current = first;}
void LinkedList::end(){current = last;}


/* Print the lists state.*/
void LinkedList::info(){
	// -- set the state for printing
	Node* savedCurrent = current;
	front();
	
	// -- print the list on one line.
	cout << "List structure:\n\t[ ";
	if(current == nullptr){cout << " ]\n";}
	else{
		cout << current->fetchItem();
		while(current->getNext()!= nullptr){
			next();
			cout << " <-> " << current->fetchItem();
		}	
		cout << " ]\n";

		// -- Printing list info
		cout << "First Node item: " << first->fetchItem() << "\n";
		cout << "Current Node item: " << savedCurrent->fetchItem() << "\n";
		cout << "Last Node item: " << last->fetchItem() << "\n";
	}
	cout << "Size: " << size << "\n\n";
	
	// -- revert to saved state
	current = savedCurrent;
}



