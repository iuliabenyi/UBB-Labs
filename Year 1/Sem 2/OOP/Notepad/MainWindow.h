#pragma once

#include <QWidget>
#include <iostream>
#include "ui_MainWindow.h"
#include "qformlayout.h"
#include <qmenu.h>
#include <qmenubar.h>
#include <qlabel.h>

using namespace std;


class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(string name, QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
	Ui::MainWindow ui;
	string name;

	QMenuBar* menubar;
	QMenu* fileMenu;
	
};
