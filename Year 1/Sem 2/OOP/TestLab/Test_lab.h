#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test_lab.h"

class Test_lab : public QMainWindow
{
	Q_OBJECT

public:
	Test_lab(QWidget *parent = Q_NULLPTR);

private:
	Ui::Test_labClass ui;
};
