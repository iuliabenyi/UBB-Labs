#pragma once
#include "Programmer.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Task
{
public:
	Task() = default;
	Task(string &description, string &status, int progID) : description{ description }, status{ status }, progID{ progID }, started{ false } {}
	Task(string &description, string &status) : description{ description }, status{ status }, started{ false } {}
	~Task() = default;

	const string getDescription() const { return this->description; };
	const string getStatus() const { return this->status; };
	const int getID() const { return this->progID; };
	void setStatus(string status) { this->status = status; };
	void setDescription(string descr) { this->description = descr; }
	void setID(int id) { this->progID = id; }
	bool getStarted() { return this->started; }
	void setStarted(bool started) {this->started = started; }

	const string toString() const {
		string res;
		res += description;
		res += " - ";
		res += status;
		return res;
	}

	int compare(Task t1, Task t2) {
		if (t1.getStatus() == t2.getStatus())
			return 0;
		if (t1.getStatus() == "in progress" && t2.getStatus() == "open")
			return -1;
		if (t1.getStatus() == "closed" && t2.getStatus() == "open")
			return -1;
		if (t1.getStatus() == "closed" && t2.getStatus() == "in progress")
			return -1;
		return 0;
	}


private:
	string description;
	string status;
	int progID;
	bool started;
};

