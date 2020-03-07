#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Programmer
{
public:
	Programmer() = default;
	Programmer(string &name, int id) : name{ name }, id{ id } {}
	~Programmer() = default;

	const string getName() const { return this->name; };
	const int getID() const { return this->id; };
	const string toString() const {
		string res;
		res += to_string(id);
		res += " - ";
		res += name;
	}

	//vector<Programmer> &getProgrammers() { return this->programmers; }

	const string getNameFromID(int id) const { 
		for (const auto &elem : programmers)
			if (elem.getID() == id)
				return elem.getName();
	}

private:
	string name;
	int id;
	vector<Programmer> programmers;
};

