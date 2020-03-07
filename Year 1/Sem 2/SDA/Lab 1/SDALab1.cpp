// SDALab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DAIterator.h"
#include "DynamicArray.h"
#include <exception>
#include <iostream>
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"
#include <iostream>

using namespace std;

int main()
{
	DynamicArray da(4);
	da.runTests();
	da.runExtendedTests();

	Set s1 = Set();
	s1.runTests();
	s1.runExtendedTests();

	Set s;



	for (int i = 0; i < 10; i++) {
		s.add(i);
	}

	SetIterator it = s.iterator();

	while (it.valid()) {
		cout << it.getCurrent() << " ";
		it.next();
	}

	cout << endl;
	it.previous();
	while (it.valid())
	{
		cout << it.getCurrent() << " ";
		it.previous();
	}

	return 0;
}