#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "Driver.h"
#include <string>

using namespace std;

class DriverRepository
{
public:
	DriverRepository() {
		ifstream f("drivers.txt");
		string name;
		int latitude;
		int longitude;
		string status;
		char separator;
		int score;

		while (getline(f, name, ';') && getline(f, status, ';') && f >> latitude && f >> separator && f >> longitude && f >> separator && f >> score)
		{
			auto driver = Driver(name, status, latitude, longitude, score);
			vec.emplace_back(driver);
		}
		f.close();
	}
	~DriverRepository() {
		ofstream o("drivers.txt");
		for (auto &d : getDrivers())
			o << d.getName() << ';' << d.getStatus() << ';' << d.getLatitude() << ';' << d.getLongitude() << ';' << d.getScore();
		o.close();
	}

	vector<Driver> &getDrivers() { return this->vec; }

private:
	vector<Driver> vec;
};

