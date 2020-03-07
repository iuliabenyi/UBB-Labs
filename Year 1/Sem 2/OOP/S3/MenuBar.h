#pragma once
#include "Menu.h"

class MenuBar : public Menu
{
public:
	MenuBar();
	~MenuBar();

	void add(const Menu &menu);

	void print();

private:
	vector<Menu> menus;
};

