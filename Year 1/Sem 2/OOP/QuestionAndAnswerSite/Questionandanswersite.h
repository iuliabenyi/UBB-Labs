#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Questionandanswersite.h"

class Questionandanswersite : public QMainWindow
{
	Q_OBJECT

public:
	Questionandanswersite(QWidget *parent = Q_NULLPTR);

private:
	Ui::QuestionandanswersiteClass ui;
};
