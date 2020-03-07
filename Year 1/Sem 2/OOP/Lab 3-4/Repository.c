#include "Repository.h"
#include "DynamicArray.h"
#include <stddef.h>




void add(DynamicArray* arr, TElem t)
{
	/*
		Add a TElement to the given dynamic array
	*/
	if (arr == NULL)
		return;

	if (arr->elems == NULL)
		return;

	if (arr->length == arr->capacity)
		resize(arr);

	arr->elems[arr->length] = t;
	++arr->length;
}

void removee(DynamicArray* arr, int indx)
{
	/*
		Removes an offer
		Input:
			- arr: a dynamic array 
			- indx: the indx of the element we need to remove
	*/
	for (int i = indx; i < arr->length - 1; ++i)
		arr->elems[i] = arr->elems[i + 1];

	--arr->length;
}

int find(DynamicArray* arr, char* address)
{
	/*
		Finds a given element 
		Input: 
			- arr: a dynamic array
			- address: the address we need to find 
		Output:
			- i: the indx of the offer
			- -1 if the offer doesn't exist 
	*/
	if (arr == NULL)
		return -1;

	if (arr->elems == NULL)
		return -1;

	int i;
	for (i = 0; i < arr->length; ++i)
	{
		if (hasAddress(arr->elems[i].address, address) == 1)
			return i;
	}

	return -1;
}