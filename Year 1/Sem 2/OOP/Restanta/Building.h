#pragma once
#include <iostream> 
#include <string>

using namespace std;
class Building
{
public:
	Building(int id, string description, int year, string sector, int x, int y) : id{ id }, description{ description }, year{ year }, sector{ sector }, x{ x }, y{ y } {}
	~Building();

	int getID() { return id; }
	const string getDescription() const { return description; }
	int getYear() { return year; }
	const string getSector() const { return sector; }
	int getX() { return x; }
	int getY() { return y; }

	void setDescr(string descr) { this->description = descr; }

	string toString()
	{
		string res;
		res += to_string(id).c_str();
		res += " ";
		res += description;
		res += " "; 
		res += to_string(year).c_str();
		res += " "; 
		res += sector;
		res += " "; 
		res += to_string(x).c_str();
		res += " "; 
		res += to_string(y).c_str();
		res += " ";

		return res;
	}

private:
	int id;
	string description;
	int year;
	string sector;
	int x;
	int y;
};

