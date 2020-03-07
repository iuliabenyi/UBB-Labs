#pragma once
#include "Controller.h"
#include <vector>

class UI
{
	public:
		UI();
		~UI();
		void admMenu();
		void userMenu();
		void run();
		void smth(vector<Dog> v);

	private:
		Controller ctrl;
};

