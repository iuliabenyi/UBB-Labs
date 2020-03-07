#include "Controller.h"



Controller::Controller()
{
}


Controller::~Controller()
{
}

vector<Driver> Controller::getDrivers()
{
	return this->driversRepo.getDrivers();
}
