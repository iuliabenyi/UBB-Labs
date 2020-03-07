#pragma once
#include <vector> 
#include <iostream>

using namespace std;

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Subject
{
private:
	vector<Observer*> observers;
public:
	void addObserver(Observer* obs) { this->observers.push_back(obs); }
	void removeObserver(Observer *obs) { this->observers.erase(find(this->observers.begin(), this->observers.end(), obs)); }
	void notify()
	{
		for (auto &elem : observers)
			elem->update();
	}
};

