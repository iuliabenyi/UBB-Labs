#include "Set.h"
#include <cstddef> 
#include <cassert>



Set::Set(int capacity) : cap{ capacity }, firstEmpty{ 0 }, head{ -1 }, tail{ -1 }, nodes{ new Node[capacity] }, n{ 0 }
{
	for (int i = 0; i < capacity; ++i)
	{
		nodes[i].prev = -1;
		nodes[i].next = -1;
	}
}

TElem Set::allocate()
{
	TElem newElem = firstEmpty; // new elem's index
	if (newElem != -1)
	{
		firstEmpty = nodes[newElem].next;

		if (firstEmpty != -1)
			nodes[firstEmpty].prev = -1;

		nodes[newElem].next = -1;
		nodes[newElem].prev = -1;
	}

	return newElem;
}

void Set::free(int pos)
{
	nodes[pos].next = firstEmpty;
	nodes[pos].prev = -1;
	if (firstEmpty != -1)
		nodes[firstEmpty].prev = pos;
	firstEmpty = pos;
}

bool Set::add(TElem e)
{
	if (search(e))
		return false;
	
	/*
	int newElem = allocate();
	if (newElem == -1)
	{
		nodes.resize();
		newElem = allocate();
	}
	*/
	
	/*nodes[newElem].info = e;

	if (head == -1)
	{
		head = newElem;
		tail = newElem;

		return true;
	}
	else
	{
		int nodC = head;
		if (nodC != -1)
		{
			int nodNext = nodes[nodC].next;
			nodes[newElem].next = nodNext;
			nodes[newElem].prev = nodC;
			nodes[nodC].next = newElem;

			if (nodNext == -1)
			{
				tail = newElem;
				return true;
			}
			else
				nodes[nodNext].prev = newElem;
		}

	}*/

	if (head == -1)
	{
		int nextFreePosition = nodes[firstEmpty].next;
		head = firstEmpty;
		tail = firstEmpty;
		nodes[head].info = e;
		nodes[head].next = -1;
		nodes[head].prev = -1;
		firstEmpty = nextFreePosition;
	}
	else
	{
		int nextFreePosition = nodes[firstEmpty].next;
		nodes[head].info = e;
		nodes[head].next = -1;
		nodes[head].prev = tail;
		nodes[tail].next = firstEmpty;
		tail = firstEmpty;
		firstEmpty = nextFreePosition;
	}

	++n;

	return true;
}

bool Set::remove(TElem e)
{
	if (!search(e))
		return false;

	int currNode = head;
	while (currNode != -1)
	{
		if (nodes[currNode].info == e)
			break;

		currNode = nodes[currNode].next;
	}

	int prevNode = nodes[currNode].prev;
	int nextNode = nodes[currNode].next;

	if (currNode == tail)
	{
		tail = prevNode;
		if (tail == -1)
			head = -1;
	}
	else if (currNode == head)
	{
		head = nextNode;
		if (head == -1)
		{
			tail = -1;
		}
	}

	nodes[currNode].next = firstEmpty;
	firstEmpty = currNode;
	if (prevNode != -1) {
		nodes[prevNode].next = nextNode;
	}
	if (nextNode != -1) {
		nodes[nextNode].prev = prevNode;
	}

	--n;

	return true;
}

bool Set::search(TElem elem) const
{
	int currNode = head;
	while (currNode != -1)
	{
		if (nodes[currNode].info == elem)
			return true;

		currNode = nodes[currNode].next;
	}

	return false;
}

void Set::runTests()
{
	Set s = Set();
	assert(s.isEmpty() == true);
	assert(s.size() == 0);
	
	assert(s.add(5) == true);
	assert(s.add(1) == true);
	
	//assert(s.add(10) == true);
	//assert(s.add(7) == true);
	//assert(s.add(1) == false);
	//assert(s.add(10) == false);
	//assert(s.add(-3) == true);
	/*
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);
	*/
	

	/*
	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);
	*/
}

int Set::size() const
{
	return n;
}

bool Set::isEmpty() const
{
	return size() == 0;
}

Set::~Set()
{
	delete[] nodes;
}
