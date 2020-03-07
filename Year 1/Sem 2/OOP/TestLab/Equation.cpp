#include "Equation.h"


Equation::Equation(double c1, double c2, double c3) : coeff1{ c1 }, coeff2{ c2 }, coeff3{ c3 }
{
	calc_solutions_eq();
}


Equation::~Equation()
{
}

int Equation::calc_delta_eq()
{
	// b patrat - 4ac
	return coeff2 * coeff2 - 4 * coeff1 * coeff3;
}

void Equation::calc_solutions_eq()
{
	delta = calc_delta_eq();
	int minusB = -coeff2;

	x1 = (minusB + sqrt(delta)) / (2 * coeff1);
	x2 = (minusB - sqrt(delta)) / (2 * coeff1);
}

string Equation::stringMath_eq()
{
	string result = "";
	result += to_string(coeff1);
	result += "*x^2 ";

	// Daca e -, se afiseaza automat
	// Daca e +, nu se afiseaza automat, trebuie sa-l adaugam noi
	if (coeff2 > 0)
		result += "+";

	result += to_string(coeff2);
	result += "*x ";

	if (coeff3 > 0)
		result += "+";

	result += to_string(coeff3);

	return result;
}

