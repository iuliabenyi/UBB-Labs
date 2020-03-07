#include "SearchWindow.h"
#include <qformlayout.h>

SearchWindow::SearchWindow(Controller& ctrl, QuestionRepository &qrepo, QWidget *parent)
	: QWidget(parent), ctrl(ctrl), qrepo{ qrepo }
{
	ui.setupUi(this);
	this->setWindowTitle("Search");
	QFormLayout* layout = new QFormLayout{};

	qrepo.addObserver(this);
 	

	searchTextEdit = new QPlainTextEdit(this);
	layout->addWidget(searchTextEdit);
	lw = new QListWidget(this);
	for (auto &q : this->ctrl.getQuestionRepo().getQuestions())
		lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));

	connect(searchTextEdit, &QPlainTextEdit::textChanged, this, [this]() {
		this->lw->clear();
		this->lwItems.clear();

		string input = this->searchTextEdit->toPlainText().toUtf8().constData();

		//for (int i = 0; i < this->ctrl.getQuestionRepo().sortByMatchingCharacters(input).size(); ++i) {
	//		if (i == 0) {
			//	auto q = this->ctrl.getQuestionRepo().sortByMatchingCharacters(input)[i];
			//	lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));

				//for (int j = 0; j < this->ctrl.getAnswerRepo().getTopThreeAnswers(q.getID()).size(); ++j) {
					//string itemStr = "\t" + this->ctrl.getAnswerRepo().getTopThreeAnswers(q.getID())[j].toString();
					//lwItems.emplace_back(new QListWidgetItem(itemStr.c_str(), lw));
				//}
		//	}
			//else {
				//auto q = this->ctrl.getQuestionRepo().sortByMatchingCharacters(input)[i];
				//lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
		//	}
		//}

	});
	layout->addWidget(lw);

	this->setLayout(layout);

}

SearchWindow::~SearchWindow()
{
	qrepo.removeObserver(this);
}

void SearchWindow::update()
{
	lw->clear();
	lwItems.clear();
	for (auto &elem : qrepo.getQuestions())
		lwItems.emplace_back(new QListWidgetItem(elem.toString().c_str(), lw));
}
