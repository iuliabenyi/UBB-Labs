#include "MenuBar.h"



MenuBar::MenuBar()
{
}


MenuBar::~MenuBar()
{
}

void MenuBar::add(const Menu & menu)
{
	this->menus.emplace_back(menu);
}

void MenuBar::print()
{
	for(const auto elem : this->menus)
		elem.print();
}
