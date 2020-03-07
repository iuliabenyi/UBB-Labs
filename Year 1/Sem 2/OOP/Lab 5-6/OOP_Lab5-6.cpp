// OOP_Lab5-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "UI.h"
#include "Tests.h"
#include "DynamicArray.h"
#include "Comparator.h"
#include <iostream>
#include <crtdbg.h>
using namespace std;

int fileM;

int main()
{
	
	/*
	DynamicArray<Dog> da;
	Dog d1 = Dog("BREED", "NAME", 6, "PIC");
	Dog d2 = Dog("BREEDD", "NAMEE", 9, "PICC");


	da = da + d1;
	cout << "Size1: " << da.getSize() << endl;

	da = d2 + da;
	cout << "Size2: " << da.getSize() << endl << endl;*/

	Dog d1 = Dog("BREED1", "NAME1", 6, "PIC");
	Dog d2 = Dog("BREED4", "NAME4", 9, "PICC");
	Dog d3 = Dog("BREED2", "NAME2", 4, "PICCC");
	Dog d4 = Dog("BREED7", "NAME7", 10, "PICCCC");

	//Comparator cmp = CompareAscendingByName();
	/*
	CompareAscendingByName c3;
	cout << c3.compare(d1, d2);
	cout << endl;
	CompareAscendingByAge c4;
	cout << c4.compare(d3, d4);
	cout << endl;*/
	/*
	Controller c = Controller();
	c.add(d1);
	c.add(d2);
	c.add(d3);
	c.add(d4);
	CompareAscendingByAge c1;
	c.sortWComparator(c1);
	for (int i = 0; i < c.getDogs().size(); ++i)
	{
		cout << c.getDogs()[i];
	}
	cout << endl;
	cout << endl << endl << endl;
	
	CompareAscendingByName c2;
	c.sortWComparator(c2);
	for (int i = 0; i < c.getDogs().size(); ++i)
	{
		cout << c.getDogs()[i];
	}
	cout << endl;*/

	/*
	Tests tests = Tests();
	tests.runAll();*/
	//{
	/*int fileM;*/
		//cout << "1. CSV\n2. HTML\nChoose file: ";
		//cin >> fileM;
		UI ui = UI();
		ui.run();
	//}
	_CrtDumpMemoryLeaks();


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
