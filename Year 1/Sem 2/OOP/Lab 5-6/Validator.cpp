#include "Validator.h"
#include "Dog.h"
#include <string>


Validator::Validator()
{
}


Validator::~Validator()
{
}

bool Validator::validateDog(T e)
{
	if (validateAge(e.getAge()) && validateName(e.getName()) && validatePic(e.getPic()))
		return true;
	
	throw InvalidInputException();
}

bool Validator::validateName(string name)
{
	if (name == "")
		throw InvalidInputException();
	return true;
}

bool Validator::validateAge(int age)
{
	if (age < 0 || age > 20)
		throw InvalidAgeException();
	return true;
}

bool Validator::validatePic(string pic)
{
	if (pic == "")
		return false;
	return true;
}



