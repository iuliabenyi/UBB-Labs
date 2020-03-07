#pragma once
#include <fstream>
#include <vector>
#include "Question.h"
#include <string>
#include "Observer.h"


class QuestionRepository : public Subject
{
public:
	QuestionRepository();
	vector<Question> sortByMatchingCharacters(string input);
	~QuestionRepository();

	vector<Question> &getQuestions() { return questions; }

	int matchingCharacters(string s1, string s2) {
		int len = s1.size() > s2.size() ? s2.size() : s1.size();
		int cnt = 0;
		for (int i = 0; i < len; ++i) {
			if (s1[i] == s2[i]) {
				++cnt;
			}
		}

		return cnt; 
	}

	int addQuestion(Question q) {
		if (q.getDescription() == "")
			return -1;
		questions.emplace_back(q);
		this->notify();
		return 1;
	}

private:
	vector<Question> questions;
};

