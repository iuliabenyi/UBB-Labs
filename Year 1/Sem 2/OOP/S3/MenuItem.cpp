#include "MenuItem.h"

void MenuItem::print() const
{
	cout << this->text << endl;
}

void MenuItem::clicked()
{
	if(action != NULL)
		action->execute();
}
