#pragma once
#include <string>
using namespace std;

class Report
{
public:
	Report(string description, string reporter, int latitude, int longitude, bool validated);
	~Report();
	string getDescription();
	string getReporter();
	pair<int, int> getExactLocation();
	bool getValidated();
	void validate();
	int getCountValidations();

private:
	string description;
	string reporter;
	pair<int, int> exactLocation;
	bool validated;
	int countValidations;
};
