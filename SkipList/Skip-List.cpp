#include "Skip-List.hpp"

SkipList::SkipList(double probability){
	p_value = probability;
		
	// -- creating intial value
	Node* negInf = new Node(INT_MIN);
	negInf->setNext(nullptr);
	negInf->setParallel(nullptr);
	
	// -- Initalizing vector containing only [ (negInf -> nullptr), \0 ].
	core = {negInf};
}


void SkipList::insert(int value){
	Node* nodePtr = new Node(value);
	
	// -- start at the highest row's negInf node.
	Node* current = core[core.size() - 1];
	
	// -- store the farthestSeen Node from top to bottom.
	vector<Node*> farthestSeen = {current};
	
	// -- stop once we insert our Node. 
	while(true){
		// -- traverse this lane until we are not greater than the next Node.
		while(current->getNext() != nullptr){
			if(value >= current->getNext()->fetchItem()){
				current = current->getNext();
				farthestSeen[0] = current;
			}else{break;}
		}

		// -- check to see if we are not on the bottom lane.
		if(current->getParallel() != nullptr){
			// -- set to current node to its parallel node and repeat.
			current = current->getParallel();
			farthestSeen.insert(farthestSeen.begin(), current);
		}
		// -- else, we have found out spot so begin insertion.
		else{
			// -- set to current node to its parallel node and repeat.
			nodePtr->setNext(current->getNext());
			nodePtr->setParallel(nullptr);
			current->setNext(nodePtr);

			// -- propagate upwards.
			int level = 1;
			Node* prevCopyNode = nodePtr;
			while(coinFlip()){
				Node* copyNodePtr = new Node(value);
				
				// -- if level larger than top level, add a new lane
				if(level > core.size() - 1){
					Node* newNegInf = new Node(INT_MIN);
					copyNodePtr->setNext(nullptr);
					newNegInf->setNext(copyNodePtr);
					newNegInf->setParallel(core[level - 1]);

					// -- add new lane to core.
					core.push_back(newNegInf);
				}
				else{
					copyNodePtr->setNext(farthestSeen[level]->getNext());
					farthestSeen[level]->setNext(copyNodePtr);
				}
				// -- set copyNodes parallel
				copyNodePtr->setParallel(prevCopyNode);
				prevCopyNode = copyNodePtr;
				level++;
			}
			break;
		}
	}
}


// -- remove the first value from the list.
void SkipList::remove(int value){
	// -- start at the highest row's negInf node.
	Node * cur = core[core.size() - 1];
	// -- store the farthestSeen Node from top to bottom.
	vector<Node*> farthestSeen = {cur};
	
	// -- search for top most.
	while(cur != nullptr){
		Node* nextNode = cur->getNext();
		if(nextNode == nullptr){
			cur = cur->getParallel();
			farthestSeen.insert(farthestSeen.begin(), cur);
		}
		else if(value > nextNode->fetchItem()){
			cur = nextNode;
			farthestSeen[0] = cur;
		}
		else if(value == nextNode->fetchItem()){
            cur->setNext(nextNode->getNext());
			// ** Do some garbage collection?
			nextNode->setNext(nullptr);
			nextNode->setParallel(nullptr);
			cur = cur->getParallel();
        }
		else {cur = cur->getParallel();}
	}
}


// -- search the list for the first-highest Node.
Node* SkipList::search(int value){
	Node * cur = core[core.size() - 1];
	
	while(cur != nullptr){
		if(cur->getNext() == nullptr){cur = cur->getParallel();}
		else if(value > cur->getNext()->fetchItem()){cur = cur->getNext();}
		else if(value == cur->getNext()->fetchItem()){return cur->getNext();}
		else {cur = cur->getParallel();}
	}
	return nullptr;
}


// -- print the list.
void SkipList::info(){
	cout << "\nLanes: " << core.size() << "\n";
	cout << "SkipList:\n";
	for(int i = (core.size() - 1); i >= 0; i--){
		Node* current = core[i];
		cout << "[ " << current->fetchItem() << " -> ";
		while(current->getNext() != nullptr){
			current = current->getNext();
			cout << current->fetchItem() << " -> ";
		}
		cout << "null ]\n";	
	}
}



// -- flip a coin.
bool SkipList::coinFlip(){
	// -- need a better way.
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);	
	srand((time_t)ts.tv_nsec);
	return ((double) rand() / RAND_MAX) > p_value ? true : false; 
}

