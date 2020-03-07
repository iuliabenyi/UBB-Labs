#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Observer
{
public:
	//Observer();
	virtual void update() = 0;
	virtual ~Observer() {}

};

class Subject {
private:
	vector<Observer*> observers;

public:
	virtual ~Subject() {}

	void registerObservers(Observer* obs)
	{
		this->observers.push_back(obs);
	}

	void unregisterObserver(Observer* obs)
	{
		this->observers.erase(std::find(this->observers.begin(), this->observers.end(), obs));
	}

	void notify()
	{
		for (auto obs : observers)
			obs->update();
	}

};

