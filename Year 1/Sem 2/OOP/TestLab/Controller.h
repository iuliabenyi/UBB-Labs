#pragma once
#include "Equation.h"

class Controller
{
public:
	Controller();
	~Controller();

	int calc_delta();

	void calc_solutions();
	string stringMath();

	vector<Equation> getVector() { return equations; };

private:
	//Equation equation;
	vector<Equation> equations;
	int currentIndex = 0;
};

