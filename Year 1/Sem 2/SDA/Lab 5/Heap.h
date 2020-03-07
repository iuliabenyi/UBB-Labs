#pragma once
#include <list>
#include <iostream>
#include "DynamicArray.h"

using namespace std;

typedef int TElem;

class Heap
{
public:
	Heap();
	~Heap();
	TElem remove();
	void bubbleDown(int p);
	list<TElem> returnInList(list<TElem> l);
	void printEl();
	void heapify(int i);
	// to get index of left child of node at index i 
	int left(int i) { return (2 * i + 1); }

	// to get index of right child of node at index i 
	int right(int i) { return (2 * i + 2); }

	void addElem(TElem elem);
private:
	int cap;
	int len;
	DynamicArray elems;
	
};

