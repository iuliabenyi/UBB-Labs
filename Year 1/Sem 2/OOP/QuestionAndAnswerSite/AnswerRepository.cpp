#include "AnswerRepository.h"
#include <algorithm>


AnswerRepository::AnswerRepository()
{
	ifstream f("answer.txt");
	string nameUser;
	int id;
	string text;
	int idQuestion;
	int votes;
	char separator;

	while (f >> id && f >> separator && f >> idQuestion && f >> separator && getline(f, nameUser, ';') && getline(f, text, ';') && f >> votes)
	{
		auto answer = Answer(id, idQuestion,nameUser,text,votes);
		//Answer answer = Answer(1, 1, "aaa", "aaa", 2);
		answers.emplace_back(answer);
	}
	f.close();
}

vector<Answer> AnswerRepository::getAnswersForQuestion(int questionId) {
	vector<Answer> v;
	for (auto &ans : answers) {
		if (ans.getIDQuestion() == questionId) {
			v.push_back(ans);
		}
	}

	return v;
}

vector<Answer> AnswerRepository::getTopThreeAnswers(int questionId) {
	vector<Answer> v = this->getAnswersForQuestion(questionId);

	if (v.size() > 3) {
		v.erase(v.begin() + 3, v.end());
	}

	sort(v.begin(), v.end(), []( Answer &a1,  Answer &a2) {
		return a1.getVotes() > a2.getVotes();
	});

	return v;
}


AnswerRepository::~AnswerRepository()
{
	// si aici trebuie write to file
}
