#include "Window.h"
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qformlayout.h>

Window::Window(Session &s, string name, string sector, QWidget *parent)
	: QWidget(parent), s(s), name(name), sector(sector)
{
	ui.setupUi(this);
	s.addObserver(this);

	s.sortBuildings(sector);

	QFormLayout* layout = new QFormLayout{};
	this->setWindowTitle(this->name.c_str());

	
	buildingList = new QListWidget{};
	for (auto &elem : this->getSession().getBuildings())
		lwItems.emplace_back(new QListWidgetItem(elem.toString().c_str(), buildingList));
		
	buildingList = new QListWidget{};
	buildingList->setSelectionMode(QAbstractItemView::SingleSelection);

	for (auto b : s.getBuildings())
	{
		QString itemInList = QString::fromStdString(b.getDescription() + " " + b.getSector());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		buildingList->addItem(item);

		if (b.getSector() == sector)
			//this->lwItems.back()->setBackground(QBrush(QColor(Qt::GlobalColor::green)));
			//this->lwItems.back()->setBackground(Qt::green);
		{
			item->setBackgroundColor("light green");
			this->buildingList->addItem(item);
		}

	}

	layout->addWidget(buildingList);

	QLabel* idLabel = new QLabel{ "ID" };
	QLineEdit* idTB = new QLineEdit{};
	idLabel->setBuddy(idTB);
	layout->addRow(idLabel, idTB);

	QLabel* dLabel = new QLabel{ "Description" };
	QLineEdit* dTB = new QLineEdit{};
	dLabel->setBuddy(dTB);
	layout->addRow(dLabel, dTB);

	QLabel* yrLabel = new QLabel{ "Year" };
	QLineEdit* yrTB = new QLineEdit{};
	yrLabel->setBuddy(yrTB);
	layout->addRow(yrLabel, yrTB);

	QLabel* xLabel = new QLabel{ "X" };
	QLineEdit* xTB = new QLineEdit{};
	xLabel->setBuddy(xTB);
	layout->addRow(xLabel, xTB);

	QLabel* yLabel = new QLabel{ "Y" };
	QLineEdit* yTB = new QLineEdit{};
	yLabel->setBuddy(yTB);
	layout->addRow(yLabel, yTB);

	QPushButton* addBtn = new QPushButton{"Add"};
	layout->addWidget(addBtn);
	QObject::connect(addBtn, &QPushButton::clicked, [idTB, dTB, xTB,yTB, yrTB, this]() {
		int id = stoi(idTB->text().toUtf8().constData());
		string descr = dTB->text().toUtf8().constData();
		int year = stoi(yrTB->text().toUtf8().constData());
		int x = stoi(xTB->text().toUtf8().constData());
		int y = stoi(yTB->text().toUtf8().constData());

		if (this->getSession().addBuilding(Building(id, descr, year, this->getSector(), x, y), this->getSector()))
		{

			if (buildingList->count() > 0)
				buildingList->clear();
			for (auto b : this->getSession().getBuildings())
			{
				QString itemInList;
				itemInList = QString::fromStdString(b.getDescription() + " " + b.getSector());
				QListWidgetItem* item = new QListWidgetItem{ itemInList };
				buildingList->addItem(item);
			}
		}
	
	});

	QLabel* newDLabel = new QLabel{ "New Description" };
	QLineEdit* newDTB = new QLineEdit{};
	newDLabel->setBuddy(newDTB);
	layout->addRow(newDLabel, newDTB);

	QPushButton* updateBtn = new QPushButton{ "Update" };
	layout->addWidget(updateBtn);
	QObject::connect(updateBtn, &QPushButton::clicked, [idTB, dTB, xTB, yTB, yrTB, newDTB, this]() {
		int id = stoi(idTB->text().toUtf8().constData());
		//string descr = dTB->text().toUtf8().constData();
		//int year = stoi(yrTB->text().toUtf8().constData());
		//int x = stoi(xTB->text().toUtf8().constData());
		//int y = stoi(yTB->text().toUtf8().constData());
		string newDescr = newDTB->text().toUtf8().constData();

		//if (this->getSession().updateBuilding(Building(id, descr, year, this->getSector(), x, y), newDescr, this->getSector()) == 1)
		//if(this->getSession().findSector(this->getName()) == this->getSector())
			this->getSession().updateBuilding(id, newDescr);
	
			//system("start aaa");
		if (buildingList->count() > 0)
			buildingList->clear();
		for (auto b : this->getSession().getBuildings())
		{

			QString itemInList;
			itemInList = QString::fromStdString(b.getDescription() + " " + b.getSector());
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			buildingList->addItem(item);
		}
	
		
		
	});


	this->setLayout(layout);
}

Window::~Window()
{
}

void Window::update()
{
	buildingList->clear();
	lwItems.clear();
	for (auto &elem : getSession().getBuildings())
		lwItems.emplace_back(new QListWidgetItem(QString::fromStdString(elem.getDescription() + " " + elem.getSector()), buildingList));
}
