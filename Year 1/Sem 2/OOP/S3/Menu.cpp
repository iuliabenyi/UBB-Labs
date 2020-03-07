#include "Menu.h"



Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::add(const MenuItem &menuItem)
{
	menuItems.emplace_back(menuItem);
}

void Menu::print() const
{
	cout << text << endl;
	for (const auto &elem : this->menuItems)
		elem.print();
}
