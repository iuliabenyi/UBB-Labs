#include "Validator.h"
#include <string.h>


int validateOffer(const char* type, const char* address, int surface, int price)
{
	/*
		Validates an offer 
		Input:
			- type: the offer's type 
			- address: the offer's address
			- surface: the offer's surface 
			- price: the offer's price 
		Output:
			- 1 if the offer is valid 
			- -1 otherwise 
	*/
	if (surface <= 0)
		return -1;

	if (price <= 0)
		return -1;

	if (strlen(type) == 0 || strlen(address) == 0)
		return -1;

	if (!(strcmp(type, "house") == 0) && !(strcmp(type, "apartment") == 0) && !(strcmp(type, "penthouse") == 0))
		return -1;
	return 1;
}

int validateType(char* type)
{
	/*
		Validates a type 
		Input: 
			- type: the offer's type 
		Output:
			- 1 if the type is valid 
			- -1 otherwise 
	*/
	if (!(strcmp(type, "house") == 0) && !(strcmp(type, "apartment") == 0) && !(strcmp(type, "penthouse") == 0))
		return -1;
	return 1;
}

int validateAddress(char* type)
{
	/*
		Validates an address 
		Input:
			- address: the offer's address
		Output:
			- 1 if the address is valid 
			- -1 otherwise 
	*/
	if (strlen(type) == 0)
		return -1;

	return 1;
}

int validateSurface(int surface)
{
	/*
		Validates a surface 
		Input:
			- surface: the offer's surface 
		Output:
			- 1 if the surface is valid 
			- -1 otherwise 
	*/
	if (surface <= 0)
		return -1;

	return 1;
}

int validatePrice(int price)
{
	/*
		Validates a price
		Input:
			- price: the offer's price 
		Output:
			- 1 if the price is valid 
			- -1 otherwise 
	*/
	if (price <= 0)
		return -1;

	return 1;
}