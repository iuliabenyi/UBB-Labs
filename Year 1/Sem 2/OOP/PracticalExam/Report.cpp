#include "Report.h"



Report::Report(string description, string reporter, int latitude, int longitude, bool validated)
{
	this->description = description;
	this->reporter = reporter;
	this->exactLocation.first = latitude;
	this->exactLocation.second = longitude;
	this->countValidations = 0;
}

Report::~Report()
{
}

string Report::getDescription()
{
	return this->description;
}

string Report::getReporter()
{
	return this->reporter;
}

pair<int, int> Report::getExactLocation()
{
	return this->exactLocation;
}

bool Report::getValidated()
{
	return this->validated;
}

void Report::validate()
{
	this->validated = true;
}

int Report::getCountValidations()
{
	return this->countValidations;
}
