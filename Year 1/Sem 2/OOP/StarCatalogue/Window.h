#pragma once

#include <QWidget>
#include "ui_Window.h"
#include "Session.h"
#include <qtableview.h>
#include <qtablewidget.h>
#include <qstandarditemmodel.h>
#include <qlistwidget.h>
#include "TableModel.h"

class Window : public QWidget
{
	Q_OBJECT

public:
	Window(Session &s, string name, string constellation, QWidget *parent = Q_NULLPTR);
	~Window();

	Session &getSession() { return s; }


private:
	Ui::Window ui;
	Session &s;
	string name;
	string constellation;
	vector<QListWidgetItem*> lwItems;

	QTableView* starsList;
	//QStandardItemModel* model;
	TableModel* model;
	//QList<QStandardItem*> itemss;
	vector<QStandardItem*> items;

	


};
