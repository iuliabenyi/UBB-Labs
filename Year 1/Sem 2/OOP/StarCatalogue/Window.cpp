#include "Window.h"
#include <qformlayout.h>
#include <qcheckbox.h>
#include <qlist.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qplaintextedit.h>
#include <qlistwidget.h>

Window::Window(Session &s, string name, string constellation, QWidget *parent)
	: QWidget(parent), s(s), name(name), constellation(constellation)
{
	ui.setupUi(this);
	QFormLayout* layout = new QFormLayout{};
	this->setWindowTitle(name.c_str());

	QCheckBox* checkBox = new QCheckBox{"Stars in my constellation"};
	layout->addWidget(checkBox);
	
	this->starsList = new QTableView{};
	this->model = new TableModel{s};
	starsList->setModel(this->model);
	layout->addWidget(starsList);
	for (auto &elem : this->getSession().getStars())
	{
		//model->appendRow(new QStandardItem(elem.toString().c_str()));
		QList<QStandardItem*> itemss;
		itemss.append(new QStandardItem(elem.getName().c_str()));
		itemss.append(new QStandardItem(elem.getConstellation().c_str()));
		itemss.append(new QStandardItem(to_string(elem.getRa()).c_str()));
		itemss.append(new QStandardItem(to_string(elem.getDec()).c_str()));
		itemss.append(new QStandardItem(to_string(elem.getDiameter()).c_str()));
		//model->appendRow(itemss);
	}
		
	
	QObject::connect(checkBox, &QCheckBox::clicked, [this, constellation, checkBox] {

		//this->model->clear();
		
		for (auto &elem : this->getSession().getStars())
		{
			if (checkBox->isChecked())
			{
				if (elem.getConstellation() == constellation)
				{
					

					//model->appendRow(new QStandardItem(elem.toString().c_str()));
					QList<QStandardItem*> itemss;
					itemss.append(new QStandardItem(elem.getName().c_str()));
					itemss.append(new QStandardItem(elem.getConstellation().c_str()));
					itemss.append(new QStandardItem(to_string(elem.getRa()).c_str()));
					itemss.append(new QStandardItem(to_string(elem.getDec()).c_str()));
					itemss.append(new QStandardItem(to_string(elem.getDiameter()).c_str()));
					//model->appendRow(itemss);
					
					//model->insertRow(NULL);
					//model->setData(model->index)
				}
			}
			else
			{
				//model->appendRow(new QStandardItem(elem.toString().c_str()));
				QList<QStandardItem*> itemss;
				itemss.append(new QStandardItem(elem.getName().c_str()));
				itemss.append(new QStandardItem(elem.getConstellation().c_str()));
				itemss.append(new QStandardItem(to_string(elem.getRa()).c_str()));
				itemss.append(new QStandardItem(to_string(elem.getDec()).c_str()));
				itemss.append(new QStandardItem(to_string(elem.getDiameter()).c_str()));
				//model->appendRow(itemss);
			}

			
		}
		
	});

	
	
	
	QLabel* nameLabel = new QLabel{ "Name" };
	QLineEdit* nameTB = new QLineEdit{};
	nameLabel->setBuddy(nameTB);
	layout->addRow(nameLabel, nameTB);

	QLabel* raLabel = new QLabel{ "Right Ascension" };
	QLineEdit* raTB = new QLineEdit{};
	raLabel->setBuddy(raTB);
	layout->addRow(raLabel, raTB);

	QLabel* decLabel = new QLabel{ "Declination" };
	QLineEdit* decTB = new QLineEdit{};
	decLabel->setBuddy(decTB);
	layout->addRow(decLabel, decTB);

	QLabel* diamLabel = new QLabel{ "Diameter" };
	QLineEdit* diamTB = new QLineEdit{};
	diamLabel->setBuddy(diamTB);
	layout->addRow(diamLabel, diamTB);

	QPushButton* addBtn = new QPushButton{ "Add" };
	QObject::connect(addBtn, &QPushButton::clicked, [nameTB, raTB, decTB, diamTB, this]() {
		string constellation = this->constellation;
		string name = nameTB->text().toUtf8().constData();
		int ra = stoi(raTB->text().toUtf8().constData());
		int dec = stoi(decTB->text().toUtf8().constData());
		int diam = stoi(diamTB->text().toUtf8().constData());
		Star star = Star(name, constellation, ra, dec, diam);
		if (this->getSession().addStar(star) == 1)
		{
			QList<QStandardItem*> itemss;
			itemss.append(new QStandardItem(star.getName().c_str()));
			itemss.append(new QStandardItem(star.getConstellation().c_str()));
			itemss.append(new QStandardItem(to_string(star.getRa()).c_str()));
			itemss.append(new QStandardItem(to_string(star.getDec()).c_str()));
			itemss.append(new QStandardItem(to_string(star.getDiameter()).c_str()));
			//model->appendRow(itemss);
			model->insertRows(this->getSession().getStars().size() - 1, 1);
		}
		this->getSession().writeStars();
	});

	layout->addWidget(addBtn);

	QLabel* searchLabel = new QLabel{ "SEARCH" };
	layout->addWidget(searchLabel);

	QLabel* searchNameLabel = new QLabel{ "Name " };
	QLineEdit* searchNameTextEdit = new QLineEdit{};
	searchNameLabel->setBuddy(searchNameTextEdit);
	layout->addRow(searchNameLabel, searchNameTextEdit);

	QLabel* searchRALabel = new QLabel{ "Right Ascension " };
	QLineEdit* searchRATextEdit = new QLineEdit{};
	searchRALabel->setBuddy(searchRATextEdit);
	layout->addRow(searchRALabel, searchRATextEdit); 
	
	QLabel* searchDeclinationLabel = new QLabel{ "Declination " };
	QLineEdit* searchDeclinationTextEdit = new QLineEdit{};
	searchDeclinationLabel->setBuddy(searchDeclinationTextEdit);
	layout->addRow(searchDeclinationLabel, searchDeclinationTextEdit);

	QListWidget* lw = new QListWidget(this);
	for (auto &q : this->getSession().getStars())
		lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
	connect(searchNameTextEdit, &QLineEdit::textChanged, this, [this, searchNameTextEdit, lw] {
		lw->clear();
		this->lwItems.clear();
		string input = searchNameTextEdit->text().toUtf8().constData();

		for (int i = 0; i < this->getSession().sortByMatchingCharacters(input).size(); ++i) {
			auto s = this->getSession().sortByMatchingCharacters(input)[i];
			lwItems.emplace_back(new QListWidgetItem(s.toString().c_str(), lw));
		}

	}); 

	connect(searchRATextEdit, &QLineEdit::textChanged, this, [this, searchRATextEdit, lw] {
		lw->clear();
		this->lwItems.clear();
		string input = searchRATextEdit->text().toUtf8().constData();

		for (int i = 0; i < this->getSession().sortByMatchingCharactersRA(input).size(); ++i) {
			auto s = this->getSession().sortByMatchingCharactersRA(input)[i];
			lwItems.emplace_back(new QListWidgetItem(s.toString().c_str(), lw));
		}

	});

	connect(searchDeclinationTextEdit, &QLineEdit::textChanged, this, [this, searchDeclinationTextEdit, lw] {
		lw->clear();
		this->lwItems.clear();
		string input = searchDeclinationTextEdit->text().toUtf8().constData();

		for (int i = 0; i < this->getSession().sortByMatchingCharactersDec(input).size(); ++i) {
			auto s = this->getSession().sortByMatchingCharactersDec(input)[i];
			lwItems.emplace_back(new QListWidgetItem(s.toString().c_str(), lw));
		}

	});

	layout->addWidget(lw);
	

	this->setLayout(layout);
}

Window::~Window()
{
}
