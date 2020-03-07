#pragma once
#include "AnswerRepository.h"
#include "QuestionRepository.h"
#include "UserRepository.h"
#include <algorithm>
#include "Observer.h"

class Controller : public Subject
{
public:
	Controller();
	~Controller();

	AnswerRepository &getAnswerRepo() { return answerRepo; }
	QuestionRepository &getQuestionRepo() { return questionRepo; }
	UserRepository &getUserRepo() { return userRepo; }

	int nrAnswers(int idQ) { return answerRepo.nrAnswers(idQ); }

	void sortQuestions();


private:
	AnswerRepository answerRepo;
	QuestionRepository questionRepo;
	UserRepository userRepo;
};

