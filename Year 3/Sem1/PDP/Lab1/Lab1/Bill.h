#pragma once
#include <vector>
#include "Product.h"

struct elemAndQuant {
	Product* el;
	int quantity;
};

class Bill
{
private:
	int ID;
	static int currID;
	int money;
	int quantity;
	std::vector<Product*>* products;
	//std::mutex mtx;
public:
	Bill();
	int getMoney() const;
	int getQuantity() const;
	void addMoney(int money);
	void addProducts(Product* product);
	
	~Bill();
};

