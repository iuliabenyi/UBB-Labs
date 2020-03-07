#include "Controller.h"
#include "Repository.h"
//#include "Comparator.h"
#include <iostream>
#include "FileManager.h"

using namespace std;

Controller::Controller(bool loadFiles)
{
	this->repo = Repository(loadFiles);
	//this->adoption = vector<Dog>(repo.size());
}


Controller::~Controller()
{
}


bool Controller::add(T e, bool record)
{
	try
	{
		if (Validator::validateDog(e) && !nameExists(e.getName()))
		{
			repo.add(e);
			if(record)
				undoOperations.emplace_back(new UndoAdd(*this, getDogs().size() - 1, getDogs()[getDogs().size() - 1]));
			return true;
		}
	}
	catch (InvalidInputException& e)
	{
		cout << e.what();
	}
	catch (NameAlreadyExistsException& e)
	{
		cout << e.what();
	}

	return false;
}

bool Controller::addAdoption(T e)
{
	if (Validator::validateDog(e) /*&& !nameExists(e.getName())*/)
	{
		bool add = true;
		for (int j = 0; j < adoption.size(); ++j)
		{
			if (adoption[j].getName() == e.getName())
			{
				//cout << dog << endl;
				//cout << v[j] << endl;
				//cout << endl << endl;
				add = false;
				//throw NameAlreadyExistsException();
				FileManager *fm2 = new TextFileManager();
				fm2->writeToFile(this->getAdoptions());
				FileManager *fm3 = new HTMLFileManager();
				fm3->writeToFile(this->getAdoptions());
				return false;
			}
		}
		if (add)
		{
			adoption.emplace_back(e);
			return true;
		}
	}
	return false;
}

bool Controller::remove(string name, bool record)
{
	try
	{
		if (Validator::validateName(name) && repo.search(name) != -1)
		{
			if(record)
				undoOperations.emplace_back(new UndoRemove(*this, getDogs()[repo.search(name)]));
			repo.remove(name);
			
			return true;
		}
	}
	/*
	catch (InvalidInputException& e)
	{
		cout << e.what();
	}*/
	catch (NameNotFoundException& e)
	{
		cout << e.what();
	}

	

	return false;
}

bool Controller::update(string name, string newName, string breed, int age, string pic, bool record)
{
	//undoOperations.emplace_back(new UndoUpdate(*this, getDogs()[getDogs().size() - 1], newName));
	try
	{
		if (Validator::validateDog(Dog(breed, name, age, pic)) && repo.search(name) != -1)
		{
			if(record)
				undoOperations.emplace_back(new UndoUpdate(*this, getDogs()[repo.search(name)], newName));
			repo.update(name, newName, breed, age, pic);
			
			return true;
		}
	}
	catch (NameNotFoundException& e)
	{
		cout << e.what();
	}
	catch (InvalidInputException& e)
	{
		cout << e.what();
	}

	return false;
}

bool Controller::nameExists(string name)
{
	int res = repo.search(name);
	if (res == -1)
		return false;
	//throw NameAlreadyExistsException();

	return true;
}
/*
void Controller::sortWComparator(Comparator<T>& cmp)
{
	for (int i = 0; i < this->getDogs().size() - 1; i++)
		for (int j = i + 1; j < this->getDogs().size(); j++)
			if (cmp.compare(this->getDogs()[i], this->getDogs()[j]) != 0)
			{
				//cout << this->getDogs()[i] << " * \n" << this->getDogs()[j]<<endl<<"-------------------"<<endl;
				/*Dog aux;
				aux = this->getDogs()[i];
				this->getDogs()[i] = this->getDogs()[j];
				this->getDogs()[j] = aux;
				swap(this->getDogs()[i], this->getDogs()[j]);
			}
	for (int i = 0; i < getDogs().size(); ++i)
	{
		cout << getDogs()[i];
	}
	cout << endl;
}*/

vector<Dog> Controller::getFilteredDogs(string breed, int age)
{
	vector<Dog> v;
	//int ok = 0;
	try
	{
		if (repo.searchBreed(breed) != -1 && Validator::validateAge(age))
		{
			for (int i = 0; i < getDogs().size(); i++)
			{
				auto dog = getDogs()[i];
				//cout << dog << endl;
				if (dog.getBreed() == breed && dog.getAge() < age)
				{
					v.emplace_back(dog);
				}
			}
			return v;
		}
	}
	catch (InvalidAgeException& e)
	{
		cout << e.what();
	}
	catch (InvalidBreedException& e)
	{
		cout << e.what();
	}
	return v;
}

int Controller::search(string name) 
{
	for (int i = 0; i < getDogs().size(); ++i) {
		if (this->getDogs()[i].getName() == name) {
			return i;
		}
	}

	return -1;
}

int Controller::searchDog(string &name)
{
	return this->search(name);
}



vector<Dog> &Controller::getDogs()
{
	return repo.getDogs();
}

vector<Dog> Controller::getAdoptions()
{
	return adoption;
}

void Controller::undo()
{
	if (!undoOperations.empty()) {
		if (undoOperations.back()->getType() == "update") {
			redoOperations.emplace_back(new UndoUpdate(*this, undoOperations.back()->getDog(), undoOperations.back()->getNewName()));
		}
		
		undoOperations.back()->undo();

		if (undoOperations.back()->getType() == "add")
			redoOperations.emplace_back(new UndoRemove(*this, undoOperations.back()->getDog()));
		else if (undoOperations.back()->getType() == "remove")
			redoOperations.emplace_back(new UndoAdd(*this, undoOperations.back()->indxDog, undoOperations.back()->getDog()));
	
		undoOperations.pop_back();
	}
}

void Controller::redo()
{
	if (!redoOperations.empty()) {

		redoOperations.back()->undo();
		//string x = "start ";
		//x += redoOperations.back()->getType();
		//system(x.c_str());
		redoOperations.pop_back();
	}
}

