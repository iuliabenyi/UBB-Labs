#include "Heap.h"
#include <list>
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;


Heap::Heap()
{
	/*l.sort();
	int i = 0;
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		//cout << *it<<" ";
		this->elems.addToEnd(*it);
		i++;
	}
	//cout << endl;
	//cout << i << endl;
	//cout << this->elems[0];
	/*
 	for (int k = 0; k < i; k++)
		cout << this->elems[k] << " ";*/
	/*
	this->len = this->elems.size();
	this->cap = this->len + 1;
	*/
}
void swap(int *x, int *y)
{
	int *aux;
	aux = x;
	x = y;
	y = aux;

}

Heap::~Heap()
{
}

TElem Heap::remove()
{
	if (this->len == 0)
		throw("Empty heap!");
	TElem deletedElem = elems[0];
	this->elems[0] = this->elems[this->len-1];
	this->len--;
	/*
	cout <<endl << "AICI"<<endl;
	printEl();
	cout << endl;*/
	bubbleDown(0);
	return deletedElem;

}

void Heap::bubbleDown(int p)
{
	int poz = p;
	TElem elem = this->elems[p];
	while (poz < this->len)
	{
		int maxChild = -1;
		if (poz * 2 <= this->len)
			maxChild = poz * 2;
		if (poz * 2 + 1 <= len && this->elems[2 * poz + 1] < this->elems[2 * poz])
			maxChild = poz * 2 + 1;
		if (maxChild != -1 && this->elems[maxChild] < elem)
		{
			TElem tmp = this->elems[poz];
			
			this->elems[poz] = this->elems[maxChild];
			this->elems[maxChild] = tmp;
			poz = maxChild;
		}
		else
			poz = this->len + 1;
		//cout << "Child: " << maxChild;
	}
	//cout <<"AAAAAAAAAAAAAAAAA " << this->len << endl;
}

void Heap::printEl()
{
	cout << "sugi pula";
	cout << "len: " << len;
	for (int k = 0; k < this->len; k++)
		cout << this->elems[k] << " ";
}

void Heap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < len && elems[l] < elems[i])
		smallest = l;
	if (r < len && elems[r] < elems[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&elems[i], &elems[smallest]);
		heapify(smallest);
	}
	
}

void Heap::addElem(TElem elem)
{
	this->elems.addToEnd(elem);
	this->len = this->elems.size();
	bubbleDown(0);
}

list<TElem> Heap::returnInList(list<TElem> l)
{
	cout << "[0]:" << this->elems[0] << endl << endl << endl;
	list <TElem> newList;
	for (int i = 0; i < this->len; i++)
		newList.emplace_back(this->elems[i]);
	return newList;
}
