#include "DriverRepository.h"
#include <fstream>
#include <string>


DriverRepository::DriverRepository()
{
	ifstream f("drivers.txt");
	string name;
	string status;
	string latitude, longitude;
	string score;
	int id;

	while (getline(f, name, ';') && getline(f, status, ';') && getline(f, latitude, ';') && getline(f, longitude, ';') && getline(f, score, ';'))
	{
		int lat = stoi(latitude);
		int lon = stoi(longitude);
		int scoreInt = stoi(score);
		auto driver = Driver(name, status, lat, lon, scoreInt);
		drivers.emplace_back(driver);
	}

	f.close();
}


DriverRepository::~DriverRepository()
{
}

vector<Driver> DriverRepository::getDrivers()
{
	return this->drivers;
}

int DriverRepository::findByName(string name)
{
	for (int i = 0; i < this->drivers.size(); i++)
		if (this->drivers[i].getName() == name)
			return i;
	return -1;
}

Driver DriverRepository::getDriverByName(string name)
{
	return this->drivers[this->findByName(name)];
}
