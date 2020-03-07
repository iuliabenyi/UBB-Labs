#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerr.h"

class TaskManagerr : public QMainWindow
{
	Q_OBJECT

public:
	TaskManagerr(QWidget *parent = Q_NULLPTR);

private:
	Ui::TaskManagerrClass ui;
};
