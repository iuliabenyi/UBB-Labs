#include "Controller.h"
#include "Repository.h"
//#include "Comparator.h"
#include <iostream>

using namespace std;

Controller::Controller(bool loadFiles)
{
	this->repo = Repository(loadFiles);
	//this->adoption = vector<Dog>(repo.size());
}


Controller::~Controller()
{
}


bool Controller::add(T e)
{
	try
	{
		if (Validator::validateDog(e) && !nameExists(e.getName()))
		{
			repo.add(e);
			FileManager *fm2 = new TextFileManager();
			fm2->writeToFile(this->getDogs());
			fm2 = new HTMLFileManager();
			fm2->writeToFile(this->getDogs());

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
				return false;
			}
		}
		if (add)
		{
			adoption.emplace_back(e);
			FileManager *fm2 = new TextFileManager();
			fm2->writeToFile(this->getAdoptions());
			fm2 = new HTMLFileManager();
			fm2->writeToFile(this->getAdoptions());
			return true;
		}
	}
	return false;
}

bool Controller::remove(string name)
{	
	try
	{
		if (Validator::validateName(name) && repo.search(name) != -1)
		{
			repo.remove(name);
			FileManager *fm2 = new TextFileManager();
			fm2->writeToFile(this->getDogs());
			fm2 = new HTMLFileManager();
			fm2->writeToFile(this->getDogs());
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

bool Controller::update(string name, string newName, string breed, int age, string pic)
{
	try
	{
		if (Validator::validateDog(Dog(breed, name, age, pic)) && repo.search(name) != -1)
		{
			repo.update(name, newName, breed, age, pic);
			FileManager *fm2 = new TextFileManager();
			fm2->writeToFile(this->getDogs());
			fm2 = new HTMLFileManager();
			fm2->writeToFile(this->getDogs());
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
}

bool Controller::nameExists(string name)
{
	int res = repo.search(name);
	if (res == -1)
		return false;
		//throw NameAlreadyExistsException();

	return true;
}

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
				this->getDogs()[j] = aux;*/
				swap(this->getDogs()[i], this->getDogs()[j]);
			}
	/*for (int i = 0; i < getDogs().size(); ++i)
	{
		cout << getDogs()[i];
	}
	cout << endl;*/
}

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

vector<Dog> &Controller::getDogs()
{
	return repo.getDogs();
}

vector<Dog> Controller::getAdoptions()
{
	return adoption;
}

void Controller::setFileManager(FileManager * fm)
{
	this->fm = fm;
}

void Controller::startFile()
{
	fm->startFile();
}
