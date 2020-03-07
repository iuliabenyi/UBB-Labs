#include "MultiMap.h"
#include <iostream>

using namespace std;

MultiMap::MultiMap()
{
	nrEl = 0;
	firstEmpty = 0;
	m = 10;
	T = new TElem[m + 1];
	next = new int[m + 1];
	for (int i = 0; i < m; i++)
	{
		next[i] = -1;
	}
}

int MultiMap::h(TKey k) const
{
	return k % m;
}

void MultiMap::add(TKey c, TValue v)
{
	int pos = h(c);
	if (T[pos].first == 0 && T[pos].second == 0)
		T[pos] = TElem(c, v);
	else 
	{
		while (next[pos] != -1)
			pos = next[pos];

		T[firstEmpty] = TElem(c, v);
		next[pos] = firstEmpty;
	}

	++nrEl;
	computeNextEmpty();
}

bool MultiMap::remove(TKey c, TValue v)
{
	if (actuallyRemove(c, v, -1) == true)
	{
		--nrEl;
		return true;
	}

	return false;
}

bool MultiMap::actuallyRemove(TKey c, TValue v, int pos)
{
	int findElem, prefindElem = -1, findProblemElem;

	findElem = h(c);

	while (pos == -1 && findElem != -1 && T[findElem].first != c && T[findElem].second != v) //the first element is removed
		findElem = next[findElem];	//find its position

	if (pos != -1)	//elementu ne incurca
		findElem = pos;	//find its position

	if (pos == -1 && findElem == -1)	//the element doesn't exist
		return false;

	for (int i = 0; i < m; i++) {	//find its predecesssor
		if (next[i] == findElem)
			prefindElem = i;
	}

	findProblemElem = next[findElem];	//the first problem element 

	if (findProblemElem == -1) {	//remove the element if there is no problem element
									//if it is the last one or the only one
		T[findElem].first = 0;
		T[findElem].second = 0;
		next[findElem] = -1;

		if (prefindElem != -1)		// the last one but not the only one
			next[prefindElem] = -1;

		computeNextEmpty();
	}
	else
	{
		while (findProblemElem != -1 && h(T[findProblemElem].first) != findElem)
			findProblemElem = next[findProblemElem];



		if (findProblemElem == -1) {
			if (prefindElem != -1)
				next[prefindElem] = next[findElem];

			T[findElem].first = 0;
			T[findElem].second = 0;
			next[findElem] = -1;

			computeNextEmpty();
			return true;
		}
		else {
			TElem save = T[findProblemElem];
			actuallyRemove(T[findProblemElem].first, T[findProblemElem].second, findProblemElem);
			T[findElem] = save;
			return true;
		}
	}

	return true;
}

vector<TValue> MultiMap::search(TKey c) const
{
	vector<TValue> foundValues;
	int pos = h(c);
	while (pos != -1)
	{
		if (T[pos].first == c)
			foundValues.push_back(T[pos].second);
		pos = next[pos];
	}
	/*
	cout << endl << "---------------------" << endl;
	for (auto e : foundValues)
		cout << foundValues[e] << " ";
	cout << endl << "---------------------" << endl;*/
	//if (foundValues.size() != 0)
		return foundValues;
}

int MultiMap::size() const
{
	return nrEl;
}

bool MultiMap::isEmpty() const
{
	return nrEl == 0;
}

void MultiMap::computeNextEmpty()
{
	if (size() == 0)
	{
		// resize la cacaturi
		TElem *v = T;
		int n = m;

		m = m * 2;
		T = new TElem[m];
		delete[] next;
		next = new int[m];

		for (int i = 0; i < m; ++i)
			next[i] = -1;

		nrEl = 0;
		firstEmpty = 0;
		for (int i = 0; i < n; ++i)
			add(v[i].first, v[i].second);

		delete[] v;
		//firstEmpty = -1;
	}

	firstEmpty = 0;
	while (T[firstEmpty].first != 0 && T[firstEmpty].second != 0)
		++firstEmpty;
}

#include "MultiMapIterator.h"

MultiMapIterator MultiMap::iterator() const
{
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap()
{
	delete[] T;
	delete[] next;
}
