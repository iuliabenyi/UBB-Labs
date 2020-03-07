#pragma once

#include "GlobalDefines.h"
#include "DynamicArray.h"
#include <cassert>

class Set {

private:
	Node* nodes;
	int cap;
	int firstEmpty;
	int head;
	int tail;
	int n;

public:
	//implicit constructor
	Set(int capacity = 10);

	TElem allocate();

	void free(int pos);

	//adds an element to the  set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TElem e);

	//removes an element from the set
	//if the element was removed, it returns true, otherwise false
	bool remove(TElem e);

	//checks if an element is in the  set
	bool search(TElem elem) const;

	void runTests();

	//returns the number of elements;
	int size() const;

	//checks if the set is empty
	bool isEmpty() const;

	//returns an iterator for the set
	//SetIterator iterator() const;

	//destructor
	~Set();
};