#include "Driver.h"


Driver::Driver(string name, string status, int latitude, int longitude, int score)
{
	this->name = name;
	this->status = status;
	this->score = score;
	this->currLocation.first = latitude;
	this->currLocation.second = longitude;
}

string Driver::getName()
{
	return this->name;
}

string Driver::getStatus()
{
	return this->status;
}

int Driver::getScore()
{
	return this->score;
}

pair<int, int> Driver::getCurrLocation()
{
	return this->currLocation;
}

void Driver::increaseScore()
{
	this->score++;
}

Driver::~Driver()
{
}

void Driver::updateLocation(int newLatitude, int newLongitude)
{
	this->currLocation.first = newLatitude;
	this->currLocation.second = newLongitude;
}

int Driver::getLatitude()
{
	return this->currLocation.first;
}

int Driver::getLongitude()
{
	return this->currLocation.second;
}
