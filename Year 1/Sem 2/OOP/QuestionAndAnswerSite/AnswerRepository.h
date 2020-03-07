#pragma once
#include <fstream>
#include <vector>
#include "Answer.h"
#include"Observer.h"
#include <string>

class AnswerRepository : public Subject
{
public:
	AnswerRepository();
	vector<Answer> getAnswersForQuestion(int questionId);
	vector<Answer> getTopThreeAnswers(int questionId);
	~AnswerRepository();

	vector<Answer> &getAnswers() { return answers; }

	int nrAnswers(int idQ) {
		int ctr = 0;
		for (auto &elem : answers)
			if (elem.getIDQuestion() == idQ)
				ctr++;
		return ctr;
	}

	int addAnswer(Answer &a) {
		if (a.getText() == "")
			return -1;
		answers.emplace_back(a);
		//system("start aaa");
		this->notify();
		return 1;

	}

	void writeToFile() {
		ofstream o("answer.txt");
		for (auto &a : getAnswers())
			o << a.getID() << ';' << a.getIDQuestion() << ';' << a.getNameUser() << ';' << a.getText() << ';' << a.getVotes() << endl;
		o.close();
	}

private:
	vector<Answer> answers;
};

