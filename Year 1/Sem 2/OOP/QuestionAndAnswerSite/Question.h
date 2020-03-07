#pragma once
#include <iostream>
#include <string>

using namespace std;

class Question
{
public:
	Question(int id, string description, string nameUser) : id{id}, description{description}, nameUser{nameUser}{}
	~Question();

	int getID() { return this->id;}
	const string getDescription() const { return description; }
	const string getNameUser() const { return nameUser; }

	const string toString() {
		string res;
		res += to_string(id);
		res += " ";
		res += description;
		res += " ";
		res += nameUser;
		return res;
	}

private:
	int id;
	string description;
	string nameUser;
};

