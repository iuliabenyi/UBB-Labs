#pragma once
#include <iostream>

using namespace std;

class Action
{
public:
	virtual void execute() = 0;
};

class CreateAction : public Action
{
public:
	void execute() override
	{
		cout << "Create file";
	}
};

class ExitAction : public Action
{
public:
	void execute() override
	{
		cout << "Exit application";
	}
};

