#pragma once

#include <QWidget>
#include "ui_Window.h"
#include "Session.h"
#include <qlistwidget.h>
#include "Observer.h"

class Window : public QWidget, public Observer
{
	Q_OBJECT

public:
	Window(Session &s, string name, string sector, QWidget *parent = Q_NULLPTR);
	~Window();

	Session &getSession() { return s; }

	string getSector() { return sector; }

	string getName() { return name; }

	void update() override;

	

private:
	Ui::Window ui;
	Session &s;

	string name;
	string sector;

	QListWidget* ethnologistList;
	QListWidget* buildingList;
	vector<QListWidgetItem*> lwItems;
};
