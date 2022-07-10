#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>
#include <iostream>

class Heap {
public:
	enum HEAPTYPE {MAX, MIN};

	/* Constructor */
	Heap(HEAPTYPE _type);


	/**
      * Insert an element via swapping
	  * 
	  * @time O(log(n))
      */
	void insert(int _value);

	/**
	  * Delete the root element
	  * 
	  * @time O(log(n))
	  */
	void pop();


	/**
	 * Search for an element in
	 * 
	 * @time O(n)
	 */
	bool search(int _value);

	/**
	 * Peak at the root element
	 *
	 * @time O(1)
	 */
	int peak();


	void printHeap();

private:
	std::vector<int> heap;
	int size;
	HEAPTYPE type;

};



#endif // !HEAP_H


