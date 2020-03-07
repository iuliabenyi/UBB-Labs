#pragma once

struct Offer
{
	char type[20];
	char address[100];
	int surface;
	int price;
};

struct Offer createOffer(char* type, char* address, int surface, int price);

int hasAddress(char* offerAddress, char* address);
