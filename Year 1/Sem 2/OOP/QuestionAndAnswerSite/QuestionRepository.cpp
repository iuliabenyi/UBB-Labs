#include "QuestionRepository.h"
#include <algorithm>


QuestionRepository::QuestionRepository()
{
	ifstream f("question.txt");
	string nameUser;
	int id;
	string descr;
	char separator;

	while (f>>id && f>>separator && getline(f, descr, ';') && getline(f, nameUser))
	{
		auto question = Question(id, descr, nameUser);
		//Question question = Question(1, "aaa", "aaa");
		questions.emplace_back(question);
	}
	f.close();
}

vector<Question> QuestionRepository::sortByMatchingCharacters(string input) {
	vector<Question> v = questions;
	sort(v.begin(), v.end(), [this, input](const Question &q1, const Question &q2) {
		return matchingCharacters(input, q1.getDescription()) > matchingCharacters(input, q2.getDescription());
	});

	return v;
}

QuestionRepository::~QuestionRepository()
{
	ofstream o("question.txt");
	for (auto &q : getQuestions())
		o << q.getID() << ';' << q.getDescription() << ';' << q.getNameUser() << endl;
	o.close();
}
