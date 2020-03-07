#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Wazeing.h"

class Wazeing : public QMainWindow
{
	Q_OBJECT

public:
	Wazeing(QWidget *parent = Q_NULLPTR);

private:
	Ui::WazeingClass ui;
};
