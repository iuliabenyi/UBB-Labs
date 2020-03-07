#include "DynamicArray.h"

DynamicArray::DynamicArray(int capacity) : capacity{ capacity }, n{ 0 }
{
	if (capacity <= 0) {
		throw exception();
	}

	//this->v = (TElem*)malloc(capacity * sizeof(TElem));
	this->v = new TElem[capacity];
}

DynamicArray::~DynamicArray()
{
	//free(this->v);
	//this->v = NULL;
	delete[] this->v;
}

int DynamicArray::size() const
{
	//teta(1)
	return this->n;
}

TElem DynamicArray::getElement(int pos) const
{
	//teta(1)
	if (pos <= n && n > 0)
		return this->v[pos];
	else
		throw exception();
}

TElem DynamicArray::setElement(int pos, TElem newElem)
{
	//teta(1)
	if (pos <= n && n > 0)
	{
		int oldElem = this->v[pos];
		this->v[pos] = newElem;
		/*
		for (int i = 0; i < this->n; ++i) {
			cout << v[i] << ' ';
		}*/

		//cout << "\n---------------\n";

		return oldElem;
	}
	else
		throw exception();
}

void DynamicArray::addToEnd(TElem newElem)
{
	//O(n)
	if (n == capacity)
	{
		this->capacity *= 2;
		//TElem* aux = (TElem*)realloc(this->v, this->capacity * sizeof(TElem));
		//this->v = aux;
		TElem* els = new TElem[this->capacity];
		for (int i = 0; i < this->n; i++)
			els[i] = this->v[i];

		delete[] this->v;
		v = els;
	}

	this->v[n] = newElem;
	n++;
	/*
	for (int i = 0; i < this->n; ++i) {
		cout << v[i] << ' ';
	}

	cout << "\n---------------\n";*/
}

void DynamicArray::addToPosition(int pos, TElem newElem)
{
	//O(n)
	if (pos <= n)
	{
		if (n == capacity)
		{
			this->capacity *= 2;
			//TElem* aux = (TElem*)realloc(this->v, this->capacity * sizeof(TElem));
			//this->v = aux;

			TElem* els = new TElem[this->capacity];
			for (int i = 0; i < this->n; i++)
				els[i] = this->v[i];

			delete[] this->v;
			v = els;
		}

		if (pos == n) {
			v[pos] = newElem;
			++n;
			/*
			for (int i = 0; i < this->n; ++i) {
				cout << v[i] << ' ';
			}

			cout << "\n---------------\n";*/

			return;

		}

		// 0 1 2 3 4 5
		// 5 1

		for (int i = n; i > pos; --i) {
			v[i] = v[i - 1];
		}

		v[pos] = newElem;
		++n;
		/*
		for (int i = 0; i < this->n; ++i) {
			cout << v[i] << ' ';
		}

		cout << "\n---------------\n";*/
	}
	else
		throw exception();
}

TElem DynamicArray::remove(int pos)
{
	if (pos <= n)
	{
		if (pos == n - 1) {
			--n;

			//for (int i = 0; i < this->n; ++i) {
			//	cout << v[i] << ' ';
			//}

			//cout << "\n---------------\n";

			return v[pos];
		}

		int oldElem = v[pos];

		for (int i = pos; i < n - 1; ++i) {
			v[i] = v[i + 1];
		}

		--n;

		//for (int i = 0; i < this->n; ++i) {
			//cout << v[i] << ' ';
		//}

		//cout << "\n---------------\n";

		return oldElem;
	}
	else
		throw exception();
}

#include "DAIterator.h"

inline DAIterator DynamicArray::iterator() const
{
	return DAIterator(*this);
}

#include <assert.h>

void DynamicArray::runTests()
{
	DynamicArray da = DynamicArray();
	assert(da.size() == 0);
	da.addToEnd(5);
	da.addToPosition(1, 1);
	da.addToPosition(0, 10);
	da.addToPosition(1, 7);
	da.addToPosition(1, 1);
	da.addToPosition(1, 11);
	da.addToPosition(1, -3);
	assert(da.size() == 7);
	assert(da.remove(1) == -3);
	assert(da.remove(4) == 5);
	assert(da.size() == 5);
	assert(da.setElement(0, 7) == 10);
	assert(da.size() == 5);
	DAIterator it = da.iterator();
	int vals[] = { 7,11,1,7,1 };
	it.first();
	int k = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		assert(e == vals[k++]);
		it.next();
	}
}

void testCreate() {
	DynamicArray da(10);
	assert(da.size() == 0);
	DAIterator it = da.iterator();
	assert(it.valid() == false);
}

void testAdd() {
	DynamicArray da(5);
	for (int i = 0; i < 5; i++) {
		da.addToEnd(i);
	}
	
	da.addToPosition(da.size(), 5);
	da.addToPosition(da.size(), 6);
	da.addToPosition(da.size(), 7);
	assert(da.size() == 8);
	da.addToPosition(0, 10);
	da.addToPosition(1, 11);
	da.addToPosition(2, 12);
	da.setElement(da.size() - 1, 9);
	assert(da.size() == 11);
	int vals[] = { 10,11,12,0,1,2,3,4,5,6,9 };
	DAIterator it = da.iterator();
	it.first();
	int k = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		assert(e == vals[k]);
		k++;
		it.next();
	}
	//test parcurgere
	for (int i = 0; i < da.size(); i++) {
		TElem e = da.getElement(i);
		assert(e == vals[i]);
	}
}

void testRemove() {
	DynamicArray da(20);
	for (int i = -100; i < 100; i = i + 2) {
		da.addToEnd(i);
	}
	assert(da.size() == 100);
	int val = 98;
	for (int i = 0; i < 100; i++) {
		assert(da.remove(da.size() - 1) == val);
		val -= 2;
	}
	assert(da.size() == 0);
	for (int i = -100; i <= 100; i = i + 2) {
		da.addToEnd(i);
	}
	assert(da.remove(da.size() - 1) == 100);
	assert(da.size() == 100);
	val = -100;
	for (int i = 0; i < 100; i++) {
		assert(da.remove(0) == val);
		val += 2;
	}
	assert(da.size() == 0);
	for (int i = -100; i <= 100; i++) {
		da.addToEnd(i);
	}
	int i = 0;
	while (i < da.size()) {
		TElem e = da.getElement(i);
		if (e % 2 == 0)
			e = da.remove(i);
		else
			i++;
	}
	DAIterator it = da.iterator();
	it.first();
	val = -99;
	while (it.valid()) {
		TElem e = it.getCurrent();
		assert(e == val);
		val += 2;
		it.next();
	}
	val = -99;
	for (int i = 0; i < da.size(); i++) {
		TElem e = da.getElement(i);
		assert(e == val);
		val += 2;
	}
}


void testIterator() {
	DynamicArray da(10);
	for (int i = 0; i < 9; i = i + 2) {
		da.addToEnd(i);
	}
	DAIterator it = da.iterator();
	assert(it.valid() == true);
	it.first();
	int k = 0;
	while (it.valid()) {
		TElem e1 = it.getCurrent();
		TElem e2 = da.getElement(k);
		assert(e1 == e2);
		it.next();
		k++;
	}
}

void testQuantity() {
	DynamicArray da(100);
	for (int i = 0; i < 200000; i++)
		da.addToEnd(i);
	assert(da.size() == 200000);
	DAIterator it = da.iterator();
	assert(it.valid() == true);
	for (int i = 0; i < da.size(); i++) {
		it.next();
	}
	it.first();
	int i = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		assert(e == i);
		i++;
		it.next();
	}
	assert(it.valid() == false);
	for (int i = da.size() - 1; i >= 0; i--) {
		assert(da.remove(da.size() - 1) == i);
	}
	assert(da.size() == 0);
}

void testExceptions() {
	DynamicArray da(10);
	try {
		da.getElement(0);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		TElem e = da.remove(1);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		da.setElement(0, 1);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		assert(da.size() == 0);
	}
	catch (exception&) {
		assert(false);
	}
	try {
		DynamicArray da2(-2);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
}

void testAllExtended() {
	testCreate();
	testAdd();
	testRemove();
	testIterator();
	testQuantity();
	testExceptions();
}

void DynamicArray::runExtendedTests()
{
	testAllExtended();
}

int DynamicArray::findElem(TElem e)
{
	for (int i = 0; i < this->n; ++i)
	{
		if (v[i] == e)
			return i;
	}

	return -1;
}
