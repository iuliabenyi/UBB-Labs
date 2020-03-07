#include "DynamicArray.h"
#include <stddef.h>


DynamicArray* createDynamicArray(int capacity)
{
	/*
		Create a dynamic array of a given capacity and return it
	*/
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (da == NULL)
		return NULL;

	da->capacity = capacity;
	da->length = 0;

	da->elems = (TElem*)malloc(capacity * sizeof(TElem));
	if (da->elems == NULL)
		return NULL;

	return da;
}


void destroy(DynamicArray* arr)
{
	/*
		Destroy the given dynamic array
	*/
	if (arr == NULL)
		return;

	free(arr->elems);
	arr->elems = NULL;

	free(arr);
	arr = NULL;
}


void resize(DynamicArray* arr)
{
	/*
		Double the capacity of the given dynamic array
	*/
	if (arr == NULL)
		return;

	arr->capacity *= 2;
	TElem* aux = (TElem*)realloc(arr->elems, arr->capacity * sizeof(TElem));
	if (aux == NULL)
		return;

	arr->elems = aux;
}

