#pragma once
#include "DynamicArray.h"
#include "Repository.h"


DynamicArray* offers;

void runCtrl();


void testValues();

int addOffer(char* type, char* address, int surface, int price);

int removeOffer(char* address);

int updateType(int indx, char* new);

void updateAddress(int index, char* newAddress, int record);

int ctrlFind(char* address);

int updateSurface(int indx, int new);

int updatePrice(int indx, int new);

int containString(int indx, char* string);

int offersBySurface(int surface, int arr[]);

int offersByType(char* type, int arr[], int surface);