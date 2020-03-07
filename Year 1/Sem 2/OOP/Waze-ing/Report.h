#pragma once
#include <iostream>
#include <string>

using namespace std;

class Report
{
public:
	Report(string description, string nameRep, int latitude, int longitude, bool validated, int ctr = 0) : description{ description }, nameRep{ nameRep }, latitude{ latitude }, longitude{ longitude }, validated{ validated } {}
	~Report();

	const string getDescription() const { return this->description; }
	const string getNameRep() const { return this->nameRep; }
	int getLatitude() { return this->latitude; }
	int getLongitude() { return this->longitude; }
	bool getValidated() { return this->validated; }

	void setLatitude(int lat) { this->latitude = lat; }
	void setLongitude(int longitude) { this->longitude = longitude; }
	void setValidated(bool validated) { this->validated = validated; }

	void increaseCtr() { this->ctr + 1; }
	int getCtr() { return this->ctr; }

	void validate() {
		ctr += 1;
		if (ctr >= 2)
			this->validated = true;
	}

	const string toString() const {
		string res;
		res += description;
		res += " - ";
		res += nameRep;
		res += " - ";
		res += to_string(latitude);
		res += " - ";
		res += to_string(longitude);
		res += " - ";
		res += to_string(validated);
		return res;
	}


private:
	string description;
	string nameRep;
	int latitude;
	int longitude;
	bool validated;
	int ctr;
};

