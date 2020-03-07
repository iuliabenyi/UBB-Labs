#pragma once
#include "Dog.h"
#include <QMainWindow>
#include <iostream>
#include <QWidget>
#include <QListView>
#include "Controller.h"
#include <QListWidget>
#include "AdoptionsTableModel.h"
//#include <QListModel>

using namespace std;

Controller ctrl{ true };
QListWidget* dogsList;
QListWidget* listAdopt;
AdoptionsTableModel* tableModel;

/*
namespace Ui {
	class MainW;
}

class mainW : public QMainWindow
{
	Q_OBJECT

public:
	mainW(Controller &ctrl, QWidget* parent = 0);
	~mainW();

	QListView* vectorToListView(QWidget *wdg, const vector<Dog> &vec);

private:

	Ui::MainW* ui;
	Controller ctrl;
	QWidget widget;

};*/

void populateDogsList();
void populateAdoptionList();

/*QListView* buildListViewFromVector();*/