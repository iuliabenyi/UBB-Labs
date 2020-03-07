	#pragma once
#include <string>
#include "Dog.h"

using namespace std;

template <class T>
class DynamicArray {
public:
	// default constructor for a DynamicArray
	DynamicArray(int capacity = 10);

	// copy constructor for a DynamicArray
	DynamicArray(const DynamicArray& v);
	~DynamicArray();

	// assignment operator for a DynamicArray
	DynamicArray& operator=(const DynamicArray& v);

	DynamicArray& operator+(T& element);

	DynamicArray& operator+(DynamicArray& da);


	// Adds an element to the current DynamicArray.
	void add(T e);

	/*
	Overloading the subscript operator
	Input: pos - a valid position within the dator.
	Output: a reference to the element o position pos.
	*/
	T& operator[](int pos);

	int getSize() const;
	int getCapacity() const;

	int searchElement(string name);
	void deleteElement(int index);
	void updateElement(int index, string breed, string name, int age, string photograph);
	T* getArray();


private:
	// Resizes the current DynamicArray, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);

	T* elems;
	int size;
	int capacity;
};

template <class T>
DynamicArray<T>& operator+(T& e, DynamicArray<T>& da);





template <class T>
int DynamicArray<T>::getCapacity() const
{
	return this->capacity;
}

template <class T>
DynamicArray<T>::DynamicArray(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->elems;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator+(T& element)
{
	this->add(element);

	return *this;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator+(DynamicArray& dv)
{
	int i = 0;
	int n = dv.getSize();
	for (; i <= n; i++)
	{
		this->add(dv.getArray()[i++]);
	}
	return *this;
}

template <class T>
void DynamicArray<T>::add(T e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <class T>
void DynamicArray<T>::resize(double factor)
{
	this->capacity *= int(factor);

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	elems = els;
}

template <class T>
T& DynamicArray<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <class T>
int DynamicArray<T>::getSize() const
{
	return this->size;
}

template <class T>
int DynamicArray<T>::searchElement(string name)
{
	for (int i = 0; i < this->size; ++i)
	{
		if (this->elems[i].getName() == name)
		{
			return i;
		}
	}

	return -1;
}

template <class T>
void DynamicArray<T>::deleteElement(int index)
{
	for (; index < this->size - 1; ++index)
	{
		this->elems[index] = this->elems[index + 1];
	}

	--this->size;
}

template <class T>
void DynamicArray<T>::updateElement(int index, string breed, string name, int age, string pic)
{
	this->elems[index].setBreed(breed);
	this->elems[index].setName(name);
	this->elems[index].setAge(age);
	this->elems[index].setPic(pic);
}

template <class T>
T * DynamicArray<T>::getArray()
{
	return elems;
}

template <class T>
DynamicArray<T>& operator+(T& e, DynamicArray<T>& da)
{
	da.add(e);

	return da;
}
