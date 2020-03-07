#include "Domain.h"
#include <string.h>


struct Offer createOffer(char* type, char* address, int surface, int price)
{
	/*
		Creates an offer 
		Input:
			- type: the type of the real-estate
			- address: the address of the real-estate
			- surface: the surface of the real-estate 
			- the price of the real-estate 
		Output:
			- the offer
	*/
	struct Offer offer;
	strcpy_s(offer.type, 20, type);
	strcpy_s(offer.address, 100, address);
	offer.surface = surface;
	offer.price = price;

	return offer;
}

int hasAddress(char* offerAddress, char* address)
{
	/*
		Checks if offerAddress is the same as address
		Input:
			- offerAddress, address: 2 addresses
		Output:
			- 1 if the addresses are the same 
			- -1 otherwise 
	*/
	char* found = strstr(offerAddress, address);

	if (found != NULL && strlen(offerAddress) == strlen(address))
		return 1;

	return -1;
}
