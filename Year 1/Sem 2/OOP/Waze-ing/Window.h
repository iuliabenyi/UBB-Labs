#pragma once

#include <QWidget>
#include "ui_Window.h"
#include "Controller.h"
#include <qlistwidget.h>
#include "ReportRepository.h"
#include "qformlayout.h"

class Window : public QWidget
{
	Q_OBJECT

public:
	Window(ReportRepository &reports, string name, string status, int longitude, int latitude, int score, QWidget *parent = Q_NULLPTR);
	~Window();

	Controller &getCtrl() { return this->ctrl; }
	void populate(int dist);
	int getTLRow() { return this->reportList->currentIndex().row(); }


private:
	Ui::Window ui;
	ReportRepository &reports;
	DriverRepository drivers;
	Controller ctrl;
	string name;
	string status;
	int longitude;
	int latitude;
	int score;



	QListWidget* reportList;
	vector<QListWidgetItem*> lwItems;

};
