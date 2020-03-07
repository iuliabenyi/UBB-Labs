#pragma once
#include "Dog.h"

typedef Dog T;

class Validator
{
public:
	Validator();
	~Validator();

	static bool validateDog(T e);
	static bool validateName(string name);
	static bool validateAge(int age);
	static bool validatePic(string pic);
};

class InvalidInputException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invalid input!";
	}
};

class InvalidAgeException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invalid age!";
	}
};
