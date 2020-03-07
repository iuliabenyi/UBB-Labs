#pragma once
#include "Programmer.h"
#include <iostream>
#include<fstream>

using namespace std;

class ProgrammerRepository
{
public:
	ProgrammerRepository() {
		ifstream f("programmer.txt");
		string name;
		int id;

		while (getline(f, name, ';') && f >> id)
		{
			auto prog = Programmer(name, id);
			programmers.emplace_back(prog);
		}
		f.close();
	}
	//~ProgrammerRepository();

	vector<Programmer> &getProgrammers() { return this->programmers; }



private:
	vector<Programmer> programmers;
};

