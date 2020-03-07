#pragma once
#include <iostream> 

using namespace std;

class Ethnologist
{
public:
	Ethnologist(string name, string sector) : name{ name }, sector{ sector } {}
	~Ethnologist();

	const string getName() const { return name; }
	const string getSector() const { return sector; }



private:
	string name;
	string sector;
};

