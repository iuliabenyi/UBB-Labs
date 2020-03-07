#pragma once
#include <iostream>
#include <string>

using namespace std;

class Answer
{
public:
	Answer(int id, int idQuestion, string nameUser, string text, int votes) : id{ id }, idQuestion{ idQuestion }, nameUser{ nameUser }, text{ text }, votes{ votes } {}
	~Answer();

	int getID() { return id; }
	int getIDQuestion() { return idQuestion; }
	const string getNameUser() const { return nameUser; }
	const string getText() const { return text; }
	int getVotes() { return votes; }

	const string toString() {
		string res;
		res += nameUser;
		res += " ";
		res += text;
		res += " ";
		res += to_string(votes);

		return res;

	}
	 

private:
	int id;
	int idQuestion;
	string nameUser;
	string text;
	int votes;
};

