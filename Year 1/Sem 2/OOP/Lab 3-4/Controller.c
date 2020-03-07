#include "Controller.h"
#include "Domain.h"
#include "UndoRedo.h"
#include "Validator.h"
#include <stdio.h>
#include <string.h>


void runCtrl()
{
	undoLength = 0;
	redoLength = 0;
	/*
	Initialize a dynamic array with a capacity of 10 elements
	*/
	
	offers = createDynamicArray(10);
}


void testValues()
{
	/*
		Testing values
	*/
	addOffer("house", "address1", 100, 300, -1);
	addOffer("apartment", "address2", 500, 700, -1);
	addOffer("penthouse", "address3", 800, 1000, -1);
	addOffer("house", "address4", 400, 600, -1);
	addOffer("penthouse", "address5", 600, 800, -1);
	addOffer("apartment", "address6", 200, 400, -1);
	addOffer("house", "address7", 900, 1100, -1);
	addOffer("house", "address8", 1000, 1200, -1);
	addOffer("penthouse", "address9", 700, 900, -1);
	addOffer("apartment", "address10", 300, 500, -1);

	addOffer("penthouse", "address11", 700, 900, -1);
	addOffer("house", "address12", 700, 800, -1);
	addOffer("apartment", "address13", 700, 500, -1);
	addOffer("penthouse", "address14", 700, 1100, -1);
	addOffer("house", "address15", 700, 1500, -1);
}



int ctrlFind(char* address)
{
	/*
		Finds a given address
		Input:
			- address: the address we need to find 
		Output:
			- returns the indx of the address
			- -1 if the address doesn't exist 
	*/
	return find(offers, address);
}


int addOffer(char* type, char* address, int surface, int price, int record)
{
	/*
		Create and add offer (after validating it) to the "offers" dynamic array
		Input: 
			- type: the offer's type
			- address: the offer's address
			- surface: the offer's surface
			- price: the offer's price 
		Output:
			- 1 if the offer was added 
			- -1 otherwise 
	*/
	
	if (validateOffer(type, address, surface, price) == 1)
	{
		struct Offer offer = createOffer(type, address, surface, price);
		add(offers, offer);

		if (record == 1)
		{
			//undoOp[undoLength].indx = 0;
			undoOp[undoLength].oldOffer = offer;
			undoOp[undoLength].operationType = opAdd;
			++undoLength;
		}

		return 1;
	}

	return -1;
}
void insertAtPos(DynamicArray* array, int indx, struct Offer oldElem)
{
	for (int i = array->length; i > indx; --i)
		array->elems[i] = array->elems[i - 1];

	array->elems[indx] = oldElem;
	++array->length;
}

int removeOffer(char* address, int record)
{
	/*
		Removes an offer
		Input: 
			- address: the offer's address
		Output:
			- 1 in the offer was removed
			- -1 otherwise 
	*/
	int pos = find(offers, address);
	if (pos == -1)
		return -1;

	if (record == 1)
	{
		undoOp[undoLength].indx = pos;
		undoOp[undoLength].oldOffer = offers->elems[pos];
		undoOp[undoLength].operationType = opRemove;
		++undoLength;
	}

	removee(offers, pos);

	return 1;
}

int updateType(int indx, char* new, int record)
{
	/*
		Updates the offer's type 
		Input:
			- indx: the indx of the offer to be updated
			- new: the new type
		Output:
			- 1 if the type was updated
			- -1 otherwise 
	*/
	if (validateType(new) == 1)
	{
		if (record == 1)
		{
			undoOp[undoLength].indx = indx;
			undoOp[undoLength].oldOffer = offers->elems[indx];
			undoOp[undoLength].operationType = opUpdateType;
			++undoLength;
		}

		strcpy_s(offers->elems[indx].type, 20, new);
		if (record == 1)
			undoOp[undoLength - 1].currOffer = offers->elems[indx];
		return 1;
	}
	return -1;
}

int updateSurface(int indx, int new, int record)
{
	/*
		Updates the offer's surface
		Input:
			- indx: the indx of the offer to be updated
			- new: the new type
		Output:
			- 1 if the type was updated
			- -1 otherwise
	*/
	if (validateSurface(new) == 1)
	{
		if (record == 1)
		{
			undoOp[undoLength].indx = indx;
			undoOp[undoLength].oldOffer = offers->elems[indx];
			undoOp[undoLength].operationType = opUpdateSurface;
			++undoLength;
		}
		offers->elems[indx].surface = new;
		if (record == 1)
			undoOp[undoLength - 1].currOffer = offers->elems[indx];
		return 1;
	}
	return -1;
}

int updatePrice(int indx, int new, int record)
{
	/*
		Updates the offer's price
		Input:
			- indx: the indx of the offer to be updated
			- new: the new type
		Output:
			- 1 if the type was updated
			- -1 otherwise
	*/
	if (validatePrice(new) == 1)
	{
		if (record == 1)
		{
			undoOp[undoLength].indx = indx;
			undoOp[undoLength].oldOffer = offers->elems[indx];
			undoOp[undoLength].operationType = opUpdatePrice;
			++undoLength;
		}


		offers->elems[indx].price = new;
		if (record == 1)
			undoOp[undoLength - 1].currOffer = offers->elems[indx];
		return 1;
	}
	return -1;
}

void updateAddress(int index, char* newAddress, int record)
{
	if (record == 1)
	{
		undoOp[undoLength].indx = index;
		undoOp[undoLength].oldOffer = offers->elems[index];
		undoOp[undoLength].operationType = opUpdateAddress;
		++undoLength;
	}

	strcpy_s(offers->elems[index].address, 100, newAddress);
	if (record == 1)
		undoOp[undoLength - 1].currOffer = offers->elems[index];
}

int containString(int indx, char* string)
{
	/*
		Checks if the address has a given string 
		Input:
			- indx: the indx of the address to be verified
			- string: the string we need to find in the addresses
		Output:
			- 1 if the addresses are found
			- -1 otherwise
	*/
	char* verif;
	verif = strstr(offers->elems[indx].address, string);
	if (verif == NULL)
		return -1;
	return 1;
}

int offersBySurface(int surface, int arr[])
{
	int i, j, ctr = 0;
	if (validateSurface(surface) == -1)
		return -1;
	for (i = 0; i < offers->length; i++)
		if (offers->elems[i].surface == surface)
			arr[ctr++] = i;
	for(i = 0; i < ctr - 1; i++)
		for (j = i + 1; j < ctr; j++)
			if (offers->elems[arr[i]].price > offers->elems[arr[j]].price)
			{
				int aux;
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		
	return ctr;

}

int offersByType(char* type, int arr[], int surface)
{
	int i, ctr = 0;
	if (validateType(type) == 1 && validateSurface(surface) == 1)
	{
		for (i = 0; i < offers->length; i++)
			if (strcmp(offers->elems[i].type, type) == 0)
				if (offers->elems[i].surface >= surface)
					arr[ctr++] = i;

		return ctr;
	}
	return -1;

}




