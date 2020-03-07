#pragma once
#include <iostream>

using namespace std;

class User
{
public:
	User(string name) : name{ name } {}
	~User();

	const string getName() const { return this->name; }

private:
	string name;
};

