#include "Linked-List.hpp"
#include<cassert>
using namespace std;


/* Test suite for Linked-List.cpp */
int main (){
	LinkedList LList = LinkedList();
	// -- Empty List testing.
	assert(LList.length() == 0 /*"Empty List has non-zero size.\n"*/);
	try{ LList.next();}
	catch(const char* msg){cerr << msg << "\n";}
	try{ LList.prev();}
	catch(const char* msg){cerr << msg << "\n";}
	try{ LList.remove();}
	catch(const char* msg){cerr << msg << "\n";}

	// -- Integration testing.
	LList.insert(10);
	//assert(LList.length() == 1 /*"List of size 1 has non-one size.\n"*/);
    try{LList.next();}
	catch(const char* msg){cerr << msg << "\n";}
	try{LList.prev();}
	catch(const char* msg){cerr << msg << "\n";}

	LList.insert(11);
	LList.insert(12);
	LList.prev();
	LList.prev();
	LList.remove();
	assert(LList.length() == 2 /*"List of size 2 had non-two size."*/);
	LList.insert(13);
	LList.next();
	LList.insert(14);
	LList.info();
	LList.prepend(99);
	assert(LList.length() == 5 /*"List of size 5 had non-five size."*/);
	LList.info();
}
