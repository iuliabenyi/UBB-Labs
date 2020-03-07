#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PracticalExam.h"

#include "Observer.h"
#include "Controller.h"

class PracticalExam : public QMainWindow , public Observer
{
	Q_OBJECT

public:
	PracticalExam(Controller &c, string name,QWidget *parent = Q_NULLPTR);
	~PracticalExam() { this->controller.removeObserver(this); }
	void update() override;
private:
	Ui::PracticalExamClass ui;
	Controller& controller;
	string name;
	void populate();
};

