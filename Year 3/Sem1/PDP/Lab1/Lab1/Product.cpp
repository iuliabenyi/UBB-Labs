#include "Product.h"
#include<iostream>

int Product::currProdID = 0;

Product::Product(int price, int quantity)
{
	this->ID = this->currProdID++;
	this->price = price;
	this->initQuantity = quantity;
	this->quantity = this->initQuantity;
}

int Product::getID() const
{
	return this->ID;
}

int Product::getPrice() const
{
	return this->price;
}

int Product::getQuantity() const {
	return this->quantity;
}

int Product::buyQuantity(int quantity)
{
	mtx.lock();
	if (quantity <= this->quantity) {
		std::cout << "\tBuying " << quantity << " products\n\n";
		this->quantity -= quantity;
	}
	else {
		mtx.unlock();
		return 0;
	}
	mtx.unlock();
	return this->price * quantity;
}

Product::~Product()
{
}
