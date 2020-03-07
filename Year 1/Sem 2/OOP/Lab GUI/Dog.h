#pragma once

#include <fstream>
#include <string>

using namespace std;

class Dog {
public:
	// This is needed to initialize an array of Dogs in class DynamicArray
	Dog() = default;
	Dog(string breed, string name, int age, string pic);
	~Dog() = default;

	string getBreed() const;
	string getName() const;
	int getAge() const;
	string getPic() const;

	void setBreed(string breed);
	void setName(string name);
	void setAge(int age);
	void setPic(string pic);


private:
	string breed;
	string name;
	int age;
	string pic;
};

istream& operator >> (istream& in, Dog& dog);
ostream& operator << (ostream& out, const Dog& dog);