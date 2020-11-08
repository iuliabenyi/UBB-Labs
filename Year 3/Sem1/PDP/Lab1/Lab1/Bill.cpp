#include "Bill.h"

int Bill::currID = 0;

std::mutex mtx;

Bill::Bill()
{
	this->money = 0;
	this->products = new std::vector<Product*>();
	mtx.lock();
	this->ID = currID++; //mtx
	mtx.unlock();
}

int Bill::getMoney() const
{
	return this->money;
}

int Bill::getQuantity() const
{
	return this->quantity;
}

void Bill::addMoney(int money)
{
	this->money += money;
}

void Bill::addProducts(Product* product) { 
	if (!products->empty()) {
		for (std::vector<Product*>::iterator it = products->begin(); it != products->end(); ++it) {
			if (*it == product) {
				this->quantity += product->getQuantity();
				return;
			}
		}
		this->products->push_back(product);
		this->quantity += product->getQuantity();
	}
	else {
		this->products->push_back(product);
		this->quantity += product->getQuantity();
	}
}

Bill::~Bill()
{
}
