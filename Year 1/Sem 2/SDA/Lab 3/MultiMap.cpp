#include "MultiMap.h"
#include <iostream>

using namespace std;

MultiMap::MultiMap()
{
	// init head on first add, not here
}

void MultiMap::add(TKey c, TValue v)
{
	//O(n)
	if (head == NULL)
	{
		head = new Node();
		head->info = TElem(c, v);
		head->next = NULL;
	}
	else
	{
		Node *tmp = head;
		while (tmp->next)
			tmp = tmp->next;

		Node *newNode = new Node();
		newNode->info = TElem(c, v);
		tmp->next = newNode;
	}
}

bool MultiMap::remove(TKey c, TValue v)
{
	//O(n)
	if (!search(c).size())
		return false;

	if (head->info.first == c && head->info.second == v)
	{
		Node *tmp = head;
		head = head->next;
		free(tmp);
		return true;
	}

	Node *prev = head;
	Node *tmp = head->next;

	while (tmp)
	{
		if (tmp->info.first == c && tmp->info.second == v)
		{
			prev->next = tmp->next;
			free(tmp);
			return true;
		}

		prev = tmp;
		tmp = tmp->next;
	}

	return false;
}

vector<TValue> MultiMap::search(TKey c) const
{
	//O(n)
	vector<TValue> v;
	Node *tmp = head;
	while (tmp)
	{
		if (tmp->info.first == c)
		{
			v.push_back(tmp->info.second);
		}

		tmp = tmp->next;
	}

	return v;
}

int MultiMap::size() const
{
	//teta(n)
	int cnt = 0;
	Node *tmp = head;
	while (tmp)
	{
		++cnt;
		tmp = tmp->next;
	}

	return cnt;
}

bool MultiMap::isEmpty() const
{
	//teta(1)
	return head == NULL;
}

#include "MultiMapIterator.h"

MultiMapIterator MultiMap::iterator() const
{
	//teta(1)
	return MultiMapIterator(*this);
}

TKey MultiMap::maxKey() const
{
	//teta(n)
	if (size() == 0)
		return NULL_TKEY;

	MultiMapIterator im = iterator();
	TKey maxKey = im.getCurrent().first; // first key
	im.next();

	while (im.valid()) {
		if (im.getCurrent().first > maxKey)
			maxKey = im.getCurrent().first;

		im.next();
	}

	return maxKey;
}


MultiMap::~MultiMap()
{
	/*
	Node *prev = head;
	Node *next = head->next;
	while (next->next)
	{
		free(prev);
		prev = next;
		next = next->next;
	}

	free(next);
	*/
}

void testCreate() {
	MultiMap m;
	assert(m.isEmpty() == true);
	assert(m.size() == 0);

	MultiMapIterator im = m.iterator();
	assert(im.valid() == false);

	for (int i = -10; i < 30; i++) {
		assert(m.remove(i, i) == false);
	}
	vector<TValue> v;
	for (int i = -10; i < 30; i++) {
		v = m.search(i);
		assert(v.size() == 0);
	}
}

void testAdd() {
	MultiMap m;
	for (int i = 0; i < 10; i++) {
		m.add(i, i);
	}
	assert(m.isEmpty() == false);
	assert(m.size() == 10);
	for (int i = -10; i < 20; i++) {
		m.add(i, 2 * i);
	}
	assert(m.isEmpty() == false);
	assert(m.size() == 40);
	for (int i = -100; i < 100; i++) {
		m.add(i, 3 * i);
	}
	assert(m.isEmpty() == false);
	assert(m.size() == 240);
	for (int i = -200; i < 200; i++) {
		vector<TValue> v;
		if (i < -100) {
			v = m.search(i);
			assert(v.size() == 0);
		}
		else if (i < -10) {
			v = m.search(i);
			assert(v.size() == 1);
		}
		else if (i < 0) {
			v = m.search(i);
			assert(v.size() == 2);
		}
		else if (i < 10) {
			v = m.search(i);
			assert(v.size() == 3);
		}
		else if (i < 20) {
			v = m.search(i);
			assert(v.size() == 2);
		}
		else if (i < 100) {
			v = m.search(i);
			assert(v.size() == 1);
		}
		else {
			v = m.search(i);
			assert(v.size() == 0);
		}
	}
	for (int i = 10000; i > -10000; i--) {
		m.add(i, 4 * i);
	}
	assert(m.size() == 20240);
}

void testRemove() {
	MultiMap m;
	for (int i = -100; i < 100; i++) {
		assert(m.remove(i, i) == false);
	}
	assert(m.size() == 0);
	for (int i = -100; i < 100; i = i + 2) {
		m.add(i, i);
	}
	for (int i = -100; i < 100; i++) {

		if (i % 2 == 0) {
			assert(m.remove(i, i) == true);
			assert(m.remove(i, 2 * i) == false);
		}
		else {
			assert(m.remove(i, i) == false);
			assert(m.remove(i, 2 * i) == false);
		}
	}
	assert(m.size() == 0);

	for (int i = 0; i <= 100; i++)
		m.add(0, i);
	m.add(1, 100);
	for (int i = 0; i <= 100; i++)
		assert(m.remove(0, i) == true);

	vector<TValue> v;
	v = m.search(1);
	assert(v.size() == 1 && v.at(0) == 100);
	v = m.search(0);
	assert(v.size() == 0);
	MultiMapIterator it = m.iterator();
	it.next();
	assert(it.valid() == false);

	assert(m.remove(1, 100) == true);

	assert(m.size() == 0);
	for (int i = -100; i <= 100; i = i + 2) {
		m.add(i, 2 * i);
	}
	for (int i = 100; i > -100; i--) {
		if (i % 2 == 0) {
			assert(m.remove(i, 3 * i + 1) == false);
			assert(m.remove(i, 2 * i) == true);
		}
		else {
			assert(m.remove(i, 3 * i + 1) == false);
		}
	}

	assert(m.size() == 1);
	bool b = m.remove(-100, -200);
	assert(b == true);
	for (int i = -100; i < 100; i++) {
		if (i != 0) {
			m.add(i, i + 1);
			m.add(i, 2 * i + 1);
			m.add(i, 3 * i + 1);
			m.add(i, 4 * i + 1);
			m.add(i, 5 * i + 1);
		}
	}
	assert(m.size() == 995);
	for (int i = -100; i < 100; i++) {
		if (i != 0) {
			v = m.search(i);
			assert(v.size() == 5);
		}
	}
	for (int i = -100; i < 100; i++) {
		if (i != 0)
			assert(m.remove(i, i + 1) == true);
	}
	assert(m.size() == 796);
	for (int i = -100; i < 100; i++) {
		if (i != 0) {
			v = m.search(i);
			assert(v.size() == 4);
		}
	}
	for (int i = -200; i < 200; i++) {
		if (i < -100 || i >= 100) {
			assert(m.remove(i, i) == false);
			assert(m.remove(i, i) == false);
			assert(m.remove(i, i) == false);
			assert(m.remove(i, i) == false);
			assert(m.remove(i, i) == false);
		}
		else
			if (i != 0) {
				assert(m.remove(i, i + 1) == false);
				assert(m.remove(i, 2 * i + 1) == true);
				assert(m.remove(i, 3 * i + 1) == true);
				assert(m.remove(i, 4 * i + 1) == true);
				assert(m.remove(i, 5 * i + 1) == true);
			}
	}
	assert(m.size() == 0);
	for (int i = -1000; i < 1000; i++) {
		v = m.search(i);
		assert(v.size() == 0);
	}
	int min = -200;
	int max = 200;
	while (min < max) {
		m.add(min, min);
		m.add(max, max);
		min++;
		max--;
	}
	m.add(0, 100);
	m.add(0, 200);
	assert(m.size() == 402);
	for (int i = -30; i < 30; i++) {
		v = m.search(i);
		if (i == 0) assert(v.size() == 2);
		else assert(v.size() == 1);
		if (i != 0) assert(m.remove(i, i) == true);
		if (i != 0) {
			v = m.search(i);
			assert(v.size() == 0);
		}
	}
	assert(m.size() == 343);
}


void testIterator() {
	MultiMap m;
	MultiMapIterator im = m.iterator();
	assert(im.valid() == false);

	for (int i = 0; i < 100; i++) {
		m.add(33, 33);
	}
	MultiMapIterator im2 = m.iterator();
	assert(im2.valid() == true);
	for (int i = 0; i < 100; i++) {
		TElem elem = im2.getCurrent();
		assert(elem.first == 33 && elem.second == 33);
		im2.next();
	}
	assert(im2.valid() == false);
	im2.first();
	assert(im2.valid() == true);
	for (int i = 0; i < 100; i++) {
		TElem elem = im2.getCurrent();
		TElem elem2 = im2.getCurrent();
		assert(elem.first == 33 && elem.second == 33);
		assert(elem2.first == 33 && elem2.second == 33);
		im2.next();
	}
	assert(im2.valid() == false);

	MultiMap m2;
	for (int i = -100; i < 100; i++) {
		m2.add(i, 2 * i);
		m2.add(i, 3 * i);
		m2.add(i, 4 * i);
	}
	MultiMapIterator im3 = m2.iterator();
	assert(im3.valid() == true);
	for (int i = 0; i < 600; i++) {
		TElem e1 = im3.getCurrent();
		im3.next();
	}
	assert(im3.valid() == false);
	im3.first();
	assert(im3.valid() == true);
	MultiMap m3;
	for (int i = 0; i < 200; i = i + 4) {
		m3.add(i, 5 * i);
	}
	MultiMapIterator im4 = m3.iterator();
	assert(im4.valid() == true);
	int count = 0;
	while (im4.valid()) {
		TElem e = im4.getCurrent();
		assert(e.first % 4 == 0);
		im4.next();
		count++;
	}
	assert(count == 50);
	MultiMap m4;
	for (int i = 0; i < 100; i++) {
		m4.add(i, i);
		m4.add(i, i * (-2));
		m4.add(i, i * 2);
		m4.add(i, i / 2);
		m4.add(i, i / (-2));
	}

	vector<TElem> elements;
	MultiMapIterator im5 = m4.iterator();
	while (im5.valid()) {
		TElem e = im5.getCurrent();
		elements.push_back(e);
		im5.next();
	}

	assert(elements.size() == m4.size());
	for (unsigned int i = 0; i < elements.size(); i++) {
		TElem lastElem = elements.at(elements.size() - i - 1);
		vector<TValue> v1;
		v1 = m4.search(lastElem.first);
		assert(v1.size() != 0);
		bool b = m4.remove(lastElem.first, lastElem.second);
		assert(b == true);
	}
}

void testQuantity() {
	MultiMap m;
	for (int i = 10; i >= 1; i--) {
		for (int j = -30000; j < 30000; j = j + i) {
			m.add(j, j);
		}
	}
	assert(m.size() == 175739);
	vector<TValue> v;
	v = m.search(-30000);
	assert(v.size() == 10);

	MultiMapIterator im = m.iterator();
	assert(im.valid() == true);
	for (int i = 0; i < m.size(); i++) {
		im.next();
	}
	im.first();
	while (im.valid()) {
		TElem e = im.getCurrent();
		v = m.search(e.first);
		assert(v.size() != 0);
		im.next();
	}
	assert(im.valid() == false);
}


void testAllExtended() {
	testCreate();
	cout << "Passed create!"<<endl;
	testAdd();
	cout << "Passed add!"<<endl;
	testRemove();
	cout << "Passed remove!"<<endl;
	testIterator();
	cout << "Passed iterator!"<<endl;
	testQuantity();
	cout << "Passed uqantity!"<<endl;
}


void MultiMap::testAll() {
	testAllExtended();
	return;

	MultiMap m;
	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(1, 500);
	m.add(2, 600);
	m.add(4, 800);


	assert(m.size() == 6);

	assert(m.remove(5, 600) == false);
	assert(m.remove(1, 500) == true);

	assert(m.size() == 5);

	vector<TValue> v;
	v = m.search(6);
	assert(v.size() == 0);

	v = m.search(1);
	assert(v.size() == 1);

	assert(m.isEmpty() == false);

	MultiMapIterator im = m.iterator();
	assert(im.valid() == true);
	while (im.valid()) {
		im.getCurrent();
		im.next();
	}
	assert(im.valid() == false);
	im.first();
	assert(im.valid() == true);
}
