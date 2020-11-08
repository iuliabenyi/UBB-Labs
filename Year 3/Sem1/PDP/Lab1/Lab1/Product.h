#pragma once
#include<mutex>
class Product
{
private:
	int ID;
	static int currProdID;
	int price;
	int quantity;
	int initQuantity;
	std::mutex mtx;
public:
	Product(int price, int quantity);
	int getID() const;
	int getPrice() const;
	int getQuantity() const;
	int buyQuantity(int quantity);
	~Product();
};

