#pragma once
#include <iostream>

using namespace std;

class Driver
{
public:
	Driver(string name, string status, int latitude, int longitude, int score) : name{ name }, status{ status }, latitude{ latitude }, longitude{ longitude }, score{ score }{}
	~Driver();

	const string getName() const { return this->name; }
	const string getStatus() const { return this->status; }
	int getLatitude(){ return this->latitude; }
	int getLongitude() { return this->longitude; }
	int getScore() { return this->score; }
	void setStatus(string status) { this->status = status; }
	void setScore(int score) { this->score = score; }
	void setLatitude(int latitude) { this->latitude = latitude; }
	void setLongitude(int longitude) { this->longitude = longitude; }

private:
	string name;
	string status;
	int latitude;
	int longitude;
	int score;
};

