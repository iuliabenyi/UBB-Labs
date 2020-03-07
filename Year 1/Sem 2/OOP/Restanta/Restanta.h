#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Restanta.h"

class Restanta : public QMainWindow
{
	Q_OBJECT

public:
	Restanta(QWidget *parent = Q_NULLPTR);

private:
	Ui::RestantaClass ui;
};
