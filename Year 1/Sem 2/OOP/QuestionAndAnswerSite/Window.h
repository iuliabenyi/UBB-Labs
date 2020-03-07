#pragma once

#include <QWidget>
#include "ui_Window.h"
#include "Controller.h"
#include <qlistwidget.h>

class Window : public QWidget, public Observer
{
	Q_OBJECT

public:
	Window(Controller &ctrl, QuestionRepository &questions, string name, QWidget *parent = Q_NULLPTR);
	~Window();

	Controller &getController() { return ctrl; }

	void update() override;


private:
	Ui::Window ui;
	Controller ctrl;
	string name;
	QuestionRepository &questions;

	QListWidget* questionList;
	QListWidget* answerList;
	vector<QListWidgetItem*> answerListItems;
	vector<QListWidgetItem*> lwItems;
	
};
