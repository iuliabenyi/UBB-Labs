#include "Tests.h"
#include "Repository.h"
#include <stddef.h>
#include "Validator.h"
#include <assert.h>


void testDA()
{
	/*
		Test the dynamic array
	*/
	DynamicArray* offers = createDynamicArray(2);
	if (offers == NULL)
		assert(0);

	assert(offers->capacity == 2);
	assert(offers->length == 0);

	char house[] = "house";
	char apartment[] = "apartment";
	char addr1[] = "addr1";
	char addr2[] = "addr2";
	char addr3[] = "addr3";

	struct Offer o1 = createOffer(house, addr1, 5, 5);
	add(offers, o1);
	assert(offers->length == 1);

	struct Offer o2 = createOffer(house, addr2, 3, 18);
	add(offers, o2);
	assert(offers->length == 2);

	// capacity must double
	struct Offer o3 = createOffer(apartment, addr3, 10, 3);
	add(offers, o3);
	assert(offers->length == 3);
	assert(offers->capacity == 4);

	removee(offers, 1);
	assert(offers->length == 2);

	destroy(offers);
}

void testValidators()
{
	/*
		Tests the validator 
	*/
	assert(validateAddress("stuff") == 1);
	assert(validateAddress("") == -1);

	assert(validateType("") == -1);
	assert(validateType("type") == -1);
	assert(validateType("house") == 1);
	assert(validateType("apartment") == 1);
	assert(validateType("penthouse") == 1);

	assert(validatePrice(-5) == -1);
	assert(validatePrice(0) == -1);
	assert(validatePrice(7129) == 1);

	assert(validateSurface(-813) == -1);
	assert(validateSurface(0) == -1);
	assert(validateSurface(812) == 1);
}

void runTests()
{
	/*
		Runs all the tests 
	*/
	testDA();
	testValidators();
}