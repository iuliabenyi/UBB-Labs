#pragma once
#include "MenuItem.h"
#include <vector>

class Menu :public MenuItem
{
public:
	Menu() : MenuItem("", nullptr) {}
	~Menu();

	Menu(const string &text, Action *action) : MenuItem(text, action), text(text) {}

	void add(const MenuItem &menuItem);
	void print() const override;

private:
	vector<MenuItem> menuItems;
	string text;
	
};

