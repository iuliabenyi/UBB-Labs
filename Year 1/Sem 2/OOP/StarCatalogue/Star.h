#pragma once
#include <iostream>
#include <string>

using namespace std;

class Star
{
public:
	Star(string name, string constellation, int RA, int dec, int diameter) : name{ name }, constellation{ constellation }, RA{ RA }, dec{ dec }, diameter{ diameter } {}
	~Star();

	const string getName() const { return name; }
	const string getConstellation() const { return constellation; }
	int getRa() { return RA; }
	int getDec() { return dec; }
	int getDiameter() { return diameter; }

	const string toString() const {
		string res;
		res += name;
		res += " ";
		res += constellation;
		res += " "; 
		res += to_string(RA);
		res += " "; 
		res += to_string(dec);
		res += " "; 
		res += to_string(diameter);
		res += " ";

		return res;
	}

private:
	string name;
	string constellation;
	int RA;
	int dec;
	int diameter;
};

