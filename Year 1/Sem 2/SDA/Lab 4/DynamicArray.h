#pragma once

#include <exception>
#include <iostream>
#include "GlobalDefines.h"

//typedef int TElem;

using namespace std;

class DAIterator;

class DynamicArray {
private:

	/*representation of Dynamic Array*/
	Node *v;
	int n; // current size
	int capacity;

public:
	friend class Set;

	// constructor
	// throws exception if capacity is 0 or negative
	DynamicArray(int capacity = 10);

	//returns the size (number of elements) from the DynamicArray
	int size() const;

	//returns the element from a given position (indexing starts from 0)
	//throws exception if pos is not a valid position
	Node getElement(int pos) const;

	//changes the element from a pozition to a different value
	//returns the old element from pozition poz
	//throws exception if pos is not a valid position
	Node setElement(int pos, Node newElem);

	//adds a new element to the end of the DynamicArray
	void addToEnd(Node newElem);

	//adds a new element to a given position in a DynamicArray
	//throws exception if pos is not a valid position
	void addToPosition(int pos, Node newElem);

	//removes an element from a given position
	//returns the removed element
	//throws exception if pos is not a valid position
	Node remove(int pos);

	//returns an iterator for the DynamicArray
	//inline DAIterator iterator() const;

	//destructor
	~DynamicArray();
	/*
	void runTests();
	void runExtendedTests();*/

	int findElem(Node e);
	void resize();
};
