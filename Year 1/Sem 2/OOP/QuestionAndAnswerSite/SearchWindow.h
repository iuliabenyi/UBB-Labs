#pragma once

#include <QWidget>
#include "ui_SearchWindow.h"
#include <qlistwidget.h>
#include <qplaintextedit.h>
#include "QuestionRepository.h"
#include "Controller.h"


class SearchWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	SearchWindow(Controller& ctrl, QuestionRepository &qrepo, QWidget *parent = Q_NULLPTR);
	~SearchWindow();

	void update() override;

private:
	Ui::SearchWindow ui;
	QListWidget* lw;
	vector<QListWidgetItem*> lwItems;
	Controller ctrl;
	QuestionRepository &qrepo;
	QPlainTextEdit* searchTextEdit;
	
	
};
