#pragma once
#include <iostream>

using namespace std;

class Astronomer
{
public:
	Astronomer(string name, string constellation) : name{ name }, constellation{ constellation } {}
	~Astronomer();

	const string getName() const { return name; }
	const string getConstellation() const { return constellation; }

private:
	string name;
	string constellation;
};

