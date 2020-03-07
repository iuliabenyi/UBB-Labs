#include "Controller.h"



Controller::Controller()
{
}


Controller::~Controller()
{
}

void Controller::sortQuestions()
{
	return;
	for (int i = 0; i < questionRepo.getQuestions().size() - 1; i++)
		for (int j = i + 1; j < questionRepo.getQuestions().size(); j++)
		{
			int answersi = nrAnswers(questionRepo.getQuestions()[i].getID());
			int answersj = nrAnswers(questionRepo.getQuestions()[j].getID());
			//int answersi = 0, answersj = 0;

			if (answersi < answersj)
			{
				swap(questionRepo.getQuestions()[i], questionRepo.getQuestions()[j]);

			}
		}
}

