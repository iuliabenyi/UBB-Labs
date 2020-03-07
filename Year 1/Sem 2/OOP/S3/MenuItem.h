#pragma once
#include <iostream>
#include <string>
#include "Action.h"

using namespace std;

class MenuItem
{
public:
	MenuItem(const string &text, Action *action) : action{ action }, text{ text } {}

	virtual void print() const;
	void clicked();

private:
	string text;
	Action *action;
};

