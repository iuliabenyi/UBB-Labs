#include "Controller.h"
#include <fstream>
#include <iostream>

using namespace std;

Controller::Controller()
{
	/*ifstream f("fisier.txt");
	int c1, c2, c3;
	while (f >> c1 >> c2 >> c3)
	{
		auto equationObj = Equation(c1, c2, c3);
		equations[currentIndex].getVector().emplace_back(equationObj);
	}*/
	Equation(1, -2, -3);
}


Controller::~Controller()
{
}

int Controller::calc_delta()
{
	return equations[currentIndex].calc_delta_eq();
}

void Controller::calc_solutions()
{
	equations[currentIndex].calc_solutions_eq();
}

string Controller::stringMath()
{
	return equations[currentIndex].stringMath_eq();
}


