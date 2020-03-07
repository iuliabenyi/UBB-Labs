#include "Dog.h"
#include <iostream>

Dog::Dog(string breed, string name, int age, string pic) : breed(breed), name(name), age(age), pic(pic)
{}

string Dog::getBreed() const
{
	return this->breed;
}

string Dog::getName() const
{
	return this->name;
}

int Dog::getAge() const
{
	return this->age;
}

string Dog::getPic() const
{
	return this->pic;
}

void Dog::setBreed(string breed)
{
	this->breed = breed;
}

void Dog::setName(string name)
{
	this->name = name;
}

void Dog::setAge(int age)
{
	this->age = age;
}

void Dog::setPic(string pic)
{
	this->pic = pic;
}

istream& operator >> (istream& in, Dog& dog) {
	string name;
	int age;
	string breed;
	string photo;

	string line;
	in >> line;

	size_t pos = line.find(",");
	name = line.substr(0, pos);
	line.erase(0, pos + 1);

	pos = line.find(",");

	age = atoi(line.substr(0, pos).c_str());
	line.erase(0, pos + 1);

	pos = line.find(",");

	breed = line.substr(0, pos);
	line.erase(0, pos + 1);

	photo = line;

	dog.setName(name);
	dog.setAge(age);
	dog.setBreed(breed);
	dog.setPic(photo);

	//cout << dog.getBreed() << " " << dog.getName() << " " << dog.getAge() << " " << dog.getPic()<<endl;

	return in;
}

ostream& operator << (ostream& out, const Dog& dog)
{
	out << "Name: " << dog.getName() << " - " << "Age: " << dog.getAge() << " - " << "Breed: " << dog.getBreed() << " - " << "Photo: " << dog.getPic() << endl;
	return out;
}


