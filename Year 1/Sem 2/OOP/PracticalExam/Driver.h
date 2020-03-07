#pragma once
#include <string>
using namespace std;
class Driver
{
public:
	Driver(string name, string status, int latitude, int longitude, int score);
	string getName();
	string getStatus();
	int getScore();
	pair<int, int> getCurrLocation();
	void increaseScore();
	~Driver();
	void updateLocation(int newLatitude, int  newLongitude);
	int getLatitude();
	int getLongitude();

private:
	string name;
	string status;
	int score;
	pair<int, int> currLocation;
};

