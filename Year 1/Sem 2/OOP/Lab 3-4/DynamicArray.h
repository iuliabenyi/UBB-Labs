#pragma once
#include "Domain.h"

typedef struct Offer TElem;

typedef struct
{
	TElem* elems;
	int length;
	int capacity;

}DynamicArray;

DynamicArray* createDynamicArray(int capacity);

void destroy(DynamicArray* arr);

void resize(DynamicArray* arr);