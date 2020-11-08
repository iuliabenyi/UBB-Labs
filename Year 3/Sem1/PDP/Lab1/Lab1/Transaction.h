#pragma once
#include "Bill.h"
#include<thread>
#include<mutex>

class Transaction
{
private:
	static int quantity;
	static int allMoney;
	static std::mutex mtx;
	
public:
	Transaction();
	static Bill sale(Product* prod, int money);
	~Transaction();
};

