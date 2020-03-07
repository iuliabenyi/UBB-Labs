#pragma once
using namespace std;
#include <vector>
#include "Driver.h"
class DriverRepository
{
public:
	DriverRepository();
	~DriverRepository();

	vector<Driver>getDrivers();
	int findByName(string name);
	Driver getDriverByName(string name);

private:
	vector<Driver> drivers;
};

