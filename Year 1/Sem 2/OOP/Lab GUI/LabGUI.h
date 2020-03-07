#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LabGUI.h"

class LabGUI : public QMainWindow
{
	Q_OBJECT

public:
	LabGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::LabGUIClass ui;
};
