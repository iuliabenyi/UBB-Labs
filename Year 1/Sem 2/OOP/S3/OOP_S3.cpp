// OOP_S3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MenuBar.h"

int main()
{
	MenuBar menuBar;
	Menu fileMenu("File", nullptr);
	Menu aboutMenu("About", nullptr);
	Menu newSubmenu("New", nullptr);
	Menu exitSubmenu("Exit", new ExitAction);

	fileMenu.add(newSubmenu);
	fileMenu.add(exitSubmenu);
	
	Menu textSubmenu("Text", new CreateAction);
	Menu cppSubmenu("C++", new CreateAction);

	newSubmenu.add(textSubmenu);
	newSubmenu.add(cppSubmenu);

	menuBar.add(fileMenu);
	menuBar.add(aboutMenu);
	menuBar.print();

	fileMenu.clicked();
	cout << "\n";
	newSubmenu.clicked();
	cout << "\n";
	cppSubmenu.clicked();

	exitSubmenu.clicked();

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
