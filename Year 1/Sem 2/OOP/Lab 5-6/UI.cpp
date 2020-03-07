#include "UI.h"
#include "Dog.h"
#include <iostream>
#include <string>
#include "FileManager.h"

using namespace std;

UI::UI()
{
	ctrl = Controller(true);
}


UI::~UI()
{
}

void UI::admMenu()
{
	cout << "\nADMINISTRATOR MENU\n";
	cout << "\t1. Add a dog\n";
	cout << "\t2. Remove a dog\n";
	cout << "\t3. Update a dog\n";
	cout << "\t4. Show all dogs\n";
	cout << "\t0. Exit\n";
}

void UI::userMenu()
{
	cout << "\nUSER MENU\n";
	cout << "\t1. Available dogs\n";
	cout << "\t2. Dogs of a given breed, age less than a given number\n";
	cout << "\t3. Adoption list\n";
	cout << "\t4. Show all dogs\n";
	cout << "\t0. Exit\n";
}

void UI::run()
{
	int mode, cmd = 1, fileM;
	//FileManager *f = new HTMLFileManager();
	//f->exportHTML(ctrl.getDogs());
	//cout << "1. CSV\n2. HTML\nChoose file: ";
	//cin >> fileM;
	//ctrl = Controller(fileM, true);
	cout << "1. Administrator\n2. User\nChoose mode: ";
	cin >> mode;
	
	if (mode == 1)
	{
		admMenu();
		while (cmd != 0)
		{
			cout << "Enter a command: ";
			cin >> cmd;
			if (cmd == 1)
			{
				string breed, name, pic;
				int age;
				cout << "Breed: ";
				cin >> breed;
				cout << "Name: ";
				cin >> name;
				cout << "Age: ";
				cin >> age;
				cout << "Photo: ";
				cin >> pic;
				ctrl.add(Dog(breed, name, age, pic));
				cout << endl;
			}
			else if (cmd == 2)
			{
				string name;
				cout << "Name: ";
				cin >> name;
				ctrl.remove(name);
				cout << endl;
			}
			else if (cmd == 3)
			{
				string name, newName, newBreed, newPic;
				int newAge;
				cout << "Dog's name to change: ";
				cin >> name;
				cout << "New name: ";
				cin >> newName;
				cout << "New age: ";
				cin >> newAge;
				cout << "New breed: ";
				cin >> newBreed;
				cout << "New pic: ";
				cin >> newPic;

				ctrl.update(name, newName, newBreed, newAge, newPic);
				
				cout << endl;
			}
			else if (cmd == 4)
			{
				for (int i = 0; i < this->ctrl.getDogs().size(); ++i)
				{
					cout << this->ctrl.getDogs()[i];
				}
				cout << endl;
			}
		}


	}
	else if (mode == 0)
		exit(0);
	else if (mode == 2)
	{
		FileManager *fm;
		int op;
		cout << "1. CSV\n2. HTML\nChoose file: ";
		cin >> op;
		if (op == 1)
		{
			//system("start file.txt");
			//trebe trimis in controller op si in repository
			//fm = new TextFileManager();
			ctrl.setFileManager(new TextFileManager());
		}
		else if (op == 2)
		{
			//system("start outfile.html");
			//fm = new HTMLFileManager();
			ctrl.setFileManager(new HTMLFileManager());
		}
		else
			ctrl.setFileManager(new TextFileManager());

		//ctrl.setFileManager(fm);


		int cmd = 1;
		while (cmd != 0)
		{
			userMenu();
			cout << "Command: ";
			cin >> cmd;
			
			if (cmd == 1)
			{
				this->smth(ctrl.getDogs());
				cout << endl;
			}
			else if (cmd == 2)
			{
				string breed;
				int age;
				cout << "Give the breed: ";
				cin >> breed;
				cout << "Give the age: ";
				cin >> age;

				this->smth(ctrl.getFilteredDogs(breed, age));
				cout << endl;
			}
				
			else if (cmd == 3)
			{
				/*
				for (int i = 0; i < this->ctrl.getAdoptions().size(); ++i)
				{
					cout << this->ctrl.getAdoptions()[i];h
				}
				cout << endl;*/


			}
				
			else if (cmd == 4)
			{
				ctrl.startFile();
				//for (int i = 0; i < this->ctrl.getDogs().size(); ++i)
				//{
					//ctrl.startFile()
					//cout << this->ctrl.getDogs()[i];
					//system("start outfile.html");
				//}
				//cout << endl;
			}
				
			else if (cmd != 0)
				cout << "Invalid input!";
		}
		

		/*
		int cmd2 = 1;
		while (cmd2 != 0) 
		{
			userMenu();
			cout << "Enter command: ";
			cin >> cmd2;
			for (int i = 0; i < this->ctrl.getDogs().getSize(); i++)
			{
				if (cmd2 == 1)
					return;
				else if (cmd2 == 2)
					return;
				else if (cmd2 == 0)
					break;
				else 
					cout << "Invalid input!";
			}
			
		}*/
	}

	else	
	{
		cout << "Invalid input!";
	}
}

void UI::smth(vector<Dog> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		auto dog = v[i];
		cout << "Breed: " << dog.getBreed() << "   Name: " << dog.getName() << "   Age: " << dog.getAge() << "   Pic: " << dog.getPic() << endl;


		int choice;

		cout << "\n1. Adopt";
		cout << "\n2. Next";
		cout << "\n0. Exit";
		cout << "\n\nEnter command: ";
		cin >> choice;
		if (choice == 1)
		{
			ctrl.addAdoption(dog);
			if (i == v.size() - 1)
				i = -1;
		}
		else if (choice == 2)
		{
			if (i == v.size() - 1)
				i = -1;
			continue;
		}
		else if (choice == 0)
		{
			break;
		}
		else
		{
			cout << "Invalid input!\n";
			i--;
		}
	}
}