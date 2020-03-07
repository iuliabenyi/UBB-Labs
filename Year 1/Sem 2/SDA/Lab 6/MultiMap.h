#pragma once
#include<vector>
#include<utility>

using namespace std;

typedef int TKey;
typedef int TValue;

typedef std::pair<TKey, TValue> TElem;

class MultiMapIterator;

/*
struct Node
{
	TElem elem;
	Node* next;
};
*/
/*
struct HashTable
{
	Node* T[100];
	int m;
	int h(TKey k)
	{
		return k % m;
	}
};*/

class MultiMap
{
private:
	/* representation of the MultiMap */
	int m;
	TElem *T;
	int *next;
	int firstEmpty;
	int nrEl;

	friend class MultiMapIterator;

public:
	//constructor
	MultiMap();

	int h(TKey k) const;

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	bool actuallyRemove(TKey c, TValue v, int pozitie);

	//returns the vector of values associated to a key. If the key is not in the MultiMap the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	void computeNextEmpty();

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//descturctor
	~MultiMap();

};


