#include <iostream>
#include <string>
#include <cmath> 
#include <vector>
using namespace std;

class Equation
{
private:
	double coeff1, coeff2, coeff3;
	double delta, x1, x2;
	vector<double> vecEq;

public:
	Equation() {}
	Equation(double c1, double c2, double c3);
	~Equation();

	void setCoeff1(double c) { this->coeff1 = c; }
	void setCoeff2(double c) { this->coeff2 = c; }
	void setCoeff3(double c) { this->coeff3 = c; }

	double getCoeff1() { return coeff1; }
	double getCoeff2() { return coeff2; }
	double getCoeff3() { return coeff3; }
	vector<double> getVector() { return vecEq; };

	int calc_delta_eq();

	void calc_solutions_eq();
	string stringMath_eq();

};