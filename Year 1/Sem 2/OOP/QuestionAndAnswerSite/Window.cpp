#include "Window.h"
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include<qlineedit.h>
#include <qspinbox.h>

Window::Window(Controller &ctrl, QuestionRepository &questions, string name, QWidget *parent)
	: QWidget(parent), questions(questions), name(name), ctrl(ctrl)
{
	ui.setupUi(this);
	QFormLayout* layout = new QFormLayout{};
	this->setWindowTitle(this->name.c_str());
	questions.addObserver(this);
	
	//ctrl.sortQuestions();
	
	questionList = new QListWidget{};
	for (auto &elem : this->ctrl.getQuestionRepo().getQuestions())
		lwItems.emplace_back(new QListWidgetItem(elem.toString().c_str(), questionList));
			
	// il ai si mai sus initializat ???
	//questionList = new QListWidget{};
	questionList->setSelectionMode(QAbstractItemView::SingleSelection);
	
	/*
	for (auto &q : ctrl.getQuestionRepo().getQuestions())
	{
		QString itemInList = QString::fromStdString(q.getDescription());

		QListWidgetItem *item = new QListWidgetItem{ itemInList };
		//questionList->addItem(item);
	}
	*/

	layout->addWidget(questionList);

	QLabel* textLabel = new QLabel{ "Add a question" };
	QLineEdit* textTB = new QLineEdit{};
	textLabel->setBuddy(textTB);
	layout->addRow(textLabel, textTB);
	int ct = 5;
	QPushButton* addBtn = new QPushButton{ "Add a quesion" };
	layout->addWidget(addBtn);
	QObject::connect(addBtn, &QPushButton::clicked, [this, textTB, &ct]() {
		string text = textTB->text().toUtf8().constData();
		//ct++;
		Question q = Question(this->questions.getQuestions()[this->questions.getQuestions().size() - 1].getID() + 1, text, QWidget::windowTitle().toStdString());
		this->questions.addQuestion(q);
		// aici ai nevoie doar de add in repo, ca observeru ar trebui sa repopuleze lista automat, uite si la mine
		
		//unde-l adaugi in repo?
		//return;
		

		
		
		//if (this->getController().getQuestionRepo().addQuestion(q) == 1)////
		{
			//if (questionList->count() > 0)
				//questionList->clear();
			//for (auto r : this->getController().getQuestionRepo().getQuestions())
			{
				//QString itemInList;
				//itemInList = QString::fromStdString(r.getDescription());


				//QListWidgetItem* item = new QListWidgetItem{ itemInList };
				//questionList->addItem(item);
			}
		}
			
	});

	QLabel* answerLabel = new QLabel{ "Add an answer " };
	QLineEdit* answerTB = new QLineEdit{};
	answerLabel->setBuddy(answerTB);
	layout->addRow(answerLabel, answerTB);
	int ctr = 6;
	QPushButton* answerBtn = new QPushButton{ "Add answer" };
	layout->addWidget(answerBtn);
	QObject::connect(answerBtn, &QPushButton::clicked, [this, answerTB, &ctr]() {
		string text = answerTB->text().toUtf8().constData();
		auto question = this->questions.getQuestions()[this->questionList->currentIndex().row()];
		++ctr;
		// nu e ok ctr aici, trebuie sa modifici
		// in: this->answersRepo.getAnswers()[this->answersRepo.getAnswers().size() - 1].getID() + 1
		// adica faci id-ul ultimului answer din lista + 1, e cel mai usor asa 
		// apoi doar salvezi aici in answer repo raspunsul
		// si nu mai populezi nimic
		// si faci update-ul sa-si faca treaba, ca o sa se apeleze automat cand face notify answers repo
		Answer a = Answer(ctr, question.getID(), QWidget::windowTitle().toStdString(), text, 0);


		//ctr++;
		//if (this->getController().getAnswerRepo().addAnswer(a) == 1)
		{
			//system("start aaa");
			//if (questionList->count() > 0)
				//questionList->clear();
			//for (auto r : this->getController().getQuestionRepo().getQuestions())
			{
				//QString itemInList;
				//itemInList = QString::fromStdString(r.getDescription());


				//QListWidgetItem* item = new QListWidgetItem{ itemInList };
				//questionList->addItem(item);
			}
		}

		this->getController().getAnswerRepo().writeToFile();

	});


	answerList = new QListWidget{};
	connect(questionList, &QListWidget::clicked, this, [this]() {
		QModelIndex index = this->questionList->currentIndex();
		this->answerList->clear();
		this->answerListItems.clear();

		//for ( auto &ans : this->ctrl.getAnswerRepo().getAnswersForQuestion(this->ctrl.getQuestionRepo().getQuestions()[index.row()].getID())) {
			//this->answerListItems.push_back(new QListWidgetItem(ans.toString().c_str(), this->answerList));
			//if (ans.getNameUser() == this->name) {
				//this->answerListItems.back()->setBackground(QBrush(QColor(Qt::GlobalColor::yellow)));
			//}
		//}
	});
	layout->addWidget(answerList);

	QLabel* spLabel = new QLabel{"Current value "};
	layout->addWidget(spLabel);
	QSpinBox* sb = new QSpinBox{};
	layout->addWidget(sb);
	QObject::connect(sb, SIGNAL(valueChanged(int)), SLOT(setValue(int)));



	this->setLayout(layout);

}

Window::~Window()
{
	questions.removeObserver(this);
}

void Window::update()
{
	questionList->clear();
	lwItems.clear();
	for (auto &elem : questions.getQuestions())
		lwItems.emplace_back(new QListWidgetItem(elem.toString().c_str(), questionList));

	// o sa fie apelat acest update, care ar trebui sa updateze questions + answers
	// deocamdata updateaza doar questions
	// aici, mai jos, scrii cum e la answers, doar ca pt questions, intelegi tu
	// ca sa repopulezi si answers

	// answerList->clear()... etc etc, intelegi tu
}
