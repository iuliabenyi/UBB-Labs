#pragma once
//#include "DynamicArray.h"
#include <vector>
//#include <>
#include "Dog.h"

using namespace std;

class Repository
{
public:
	//Repository();
	~Repository();


	void add(Dog e);
	int search(string e);
	int searchBreed(string e);
	void remove(string name);
	void update(string name, string newName, string breed, int age, string pic);
	//int search(string e);
	int size();
	//DynamicArray<Dog> getDogs();
	vector<Dog> &getDogs();
	Repository(bool loadFiles = false);
	//DynamicArray getAdoptions();

private:
	//DynamicArray<Dog> da;
	vector<Dog> v;
	bool load;
};


class NameNotFoundException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Name not found!";
	}
};

class NameAlreadyExistsException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invalid input!";
	}
};

class NameDoesNotExistException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Name already exists!";
	}
};

class InvalidBreedException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invalid breed!";
	}
};



