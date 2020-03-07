// SDA_Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Heap.h"

int main()
{
	/*
	list<int> mylist{ 1, 2, 3, 4, 5 , 6, 7, 8, 9, 10, 11, 12, 13, 14};
	// h = Heap(mylist);
	Heap h = Heap(mylist);
	for (int i = 0; i < 5; i++)
	{
		
		h.remove();
		//h.printEl();
		cout << endl << endl;
		mylist = h.returnInList(mylist);
	}
	for (auto it = mylist.begin(); it != mylist.end(); ++it)
	{
		cout << *it << " ";
	}
	*/
		/*
	h.remove();
	cout << endl;
	h.printEl();
	cout << endl << endl << endl;
	h.remove();
	cout << endl;
	h.printEl();
	cout << endl << endl << endl;
	h.remove();
	cout << endl;
	h.printEl();
	cout << endl << endl << endl;
	h.remove();
	cout << endl;
	h.printEl();
	*/


	Heap pulaMea = Heap();
	pulaMea.addElem(5);
	pulaMea.addElem(546);
	pulaMea.addElem(75);
	pulaMea.addElem(48);
	pulaMea.addElem(9);
	pulaMea.printEl();




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
