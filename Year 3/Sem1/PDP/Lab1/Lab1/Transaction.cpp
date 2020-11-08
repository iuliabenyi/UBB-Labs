#include "Transaction.h"
#include<iostream>
#include<string>
#include<Windows.h>

Transaction::Transaction()
{
}


Bill Transaction::sale(Product* product, int quantity) {
	Bill* bill = new Bill();

	bill->addMoney(product->buyQuantity(quantity));
	bill->addProducts(product);
	if (product->getQuantity() != 0)
		std::cout << "\t\t" << product->getQuantity() << " products left\n\n";
	else
		std::cout << "\t\tOut of stock!\n\n";
	Sleep(1000);
	return *bill;
}

Transaction::~Transaction()
{
}
