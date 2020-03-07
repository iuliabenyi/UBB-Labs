#include <Windows.h>
#include "LabGUI.h"
#include "main.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <qmessagebox.h>
#include <qradiobutton.h>
#include <algorithm>
#include <Winuser.h>
#include <qtableview.h>
#include "FileManager.h"
#include <QLinearGradient>
#include <QPalette>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/*
	QGridLayout *gridLayoutTest = new QGridLayout{};
	QFormLayout* testLayout = new QFormLayout{};
	QRadioButton* sortedBtn = new QRadioButton("Sorted");
	QRadioButton* shuffledBtn = new QRadioButton("Shuffled");
	gridLayoutTest->addWidget(sortedBtn, 0, 0);
	gridLayoutTest->addWidget(shuffledBtn, 0, 1);
	QWidget* rButtonsDogs = new QWidget{};
	rButtonsDogs->setLayout(gridLayoutTest);
	testLayout->addWidget(rButtonsDogs);
	dogsList = new QListWidget{};
	dogsList->setSelectionMode(QAbstractItemView::SingleSelection);
	populateDogsList();
	testLayout->addWidget(dogsList);
	QWidget *wnd2 = new QWidget{};
	wnd2->setLayout(testLayout);
	wnd2->show();

	QObject::connect(sortedBtn, &QRadioButton::clicked, []() {
		vector<Dog> sortedvec = ctrl.getDogs();
		sort(sortedvec.begin(), sortedvec.end(),
			[](const Dog & a, const Dog & b) -> bool
		{
			return a.getName() < b.getName();
		});

		dogsList->clear();

		for (auto d : sortedvec)
		{
			QString itemInList = QString::fromStdString(d.getName() + ", " + to_string(d.getAge()) + ", " + d.getBreed() + ", " + d.getPic());
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			dogsList->addItem(item);
		}

	});

	QObject::connect(shuffledBtn, &QRadioButton::clicked, []() {
		vector<Dog> shuffledvec = ctrl.getDogs();
		std::random_shuffle(shuffledvec.begin(), shuffledvec.end());

		dogsList->clear();

		for (auto d : shuffledvec)
		{
			QString itemInList = QString::fromStdString(d.getName() + ", " + to_string(d.getAge()) + ", " + d.getBreed() + ", " + d.getPic());
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			dogsList->addItem(item);
		}
	});

	return a.exec();*/


	QHBoxLayout* hbox = new QHBoxLayout();

	QFormLayout* formLayoutLeft = new QFormLayout{};

	QLabel* dogsLabel = new QLabel{ "All dogs:" };
	formLayoutLeft->addWidget(dogsLabel);

	dogsList = new QListWidget{};
	dogsList->setSelectionMode(QAbstractItemView::SingleSelection);
	populateDogsList();
	formLayoutLeft->addWidget(dogsList);
	
	QLineEdit* nameTextBox = new QLineEdit{};
	QLabel* nameLabel = new QLabel{ "&Name: " };
	nameLabel->setBuddy(nameTextBox);

	QLineEdit* ageTextBox = new QLineEdit{};
	QLabel* ageLabel = new QLabel{ "&Age:" };
	ageLabel->setBuddy(ageTextBox);

	QLineEdit* breedTextBox = new QLineEdit{};
	QLabel* breedLabel = new QLabel{ "&Breed:" };
	breedLabel->setBuddy(breedTextBox);

	QLineEdit* picTextBox = new QLineEdit{};
	QLabel* picLabel = new QLabel{ "&Photo:" };
	picLabel->setBuddy(picTextBox);

	QLineEdit* newNameTextBox = new QLineEdit{};
	QLabel* newNameLabel = new QLabel{ "&New name: " };
	newNameLabel->setBuddy(newNameTextBox);


	formLayoutLeft->addRow(nameLabel, nameTextBox);
	formLayoutLeft->addRow(ageLabel, ageTextBox);
	formLayoutLeft->addRow(breedLabel, breedTextBox);
	formLayoutLeft->addRow(picLabel, picTextBox);
	formLayoutLeft->addRow(newNameLabel, newNameTextBox);

	QGridLayout *gridLayoutDogs = new QGridLayout{};
	QWidget* buttonsDogs = new QWidget{};


	QPushButton *addDogBtn = new QPushButton("Add");
	gridLayoutDogs->addWidget(addDogBtn, 0, 0);
	QObject::connect(addDogBtn, &QPushButton::clicked, [nameTextBox, ageTextBox, breedTextBox, picTextBox]() {
		string name = nameTextBox->text().toUtf8().constData();
		int age = ageTextBox->text().toInt();
		string breed = breedTextBox->text().toUtf8().constData();
		string photo = picTextBox->text().toUtf8().constData();
		Dog d = Dog(breed, name, age, photo);
		ctrl.add(d);
		populateDogsList();
	});

	/*
	QPushButton *deleteDogBtn = new QPushButton("Delete");
	gridLayoutDogs->addWidget(deleteDogBtn, 0, 1);
	QObject::connect(deleteDogBtn, &QPushButton::clicked, [nameTextBox]() {
		string name = nameTextBox->text().toUtf8().constData();
		ctrl.remove(name);
		populateDogsList();
	});*/

	QPushButton *deleteDogBtn = new QPushButton("Delete");
	gridLayoutDogs->addWidget(deleteDogBtn, 0, 1);
	QObject::connect(deleteDogBtn, &QPushButton::clicked, [nameTextBox]() {
		auto dog = ctrl.getDogs()[dogsList->currentIndex().row()];
		string name = dog.getName();
		ctrl.remove(name);
		populateDogsList();
	});
	
	
	QPushButton *updateDogBtn = new QPushButton("Update");
	gridLayoutDogs->addWidget(updateDogBtn, 0, 2);
	QObject::connect(updateDogBtn, &QPushButton::clicked, [nameTextBox, ageTextBox, breedTextBox, picTextBox, newNameTextBox]() {
		string name = nameTextBox->text().toUtf8().constData();
		int age = ageTextBox->text().toInt();
		string breed = breedTextBox->text().toUtf8().constData();
		string photo = picTextBox->text().toUtf8().constData();
		string newName = newNameTextBox->text().toUtf8().constData();
		Dog d = Dog(breed, name, age, photo);
		ctrl.update(name, newName, breed, age, photo);
		populateDogsList();
	});
	
	
	QPushButton *undoDogBtn = new QPushButton("Undo");
	gridLayoutDogs->addWidget(undoDogBtn, 1, 0);
	QObject::connect(undoDogBtn, &QPushButton::clicked, []() {
		ctrl.undo();
		populateDogsList();
	});

	QPushButton *redoDogBtn = new QPushButton("Redo");
	gridLayoutDogs->addWidget(redoDogBtn, 1, 1);
	QObject::connect(redoDogBtn, &QPushButton::clicked, []() {
		ctrl.redo();
		populateDogsList();
	});


	buttonsDogs->setLayout(gridLayoutDogs);
	formLayoutLeft->addWidget(buttonsDogs);

	QFormLayout *formLayoutCenter = new QFormLayout{};
	QGridLayout *gridLayoutCenter = new QGridLayout{};

	QLinearGradient linearGrad(0, 0, 0, 100);
	linearGrad.setColorAt(0, Qt::blue);
	linearGrad.setColorAt(1, Qt::yellow);
	QBrush brush(linearGrad);

	QPalette pal;
	pal.setBrush(QPalette::Window, linearGrad);

	QPushButton *adoptDogBtn = new QPushButton("Adopt");

	//adoptDogBtn->setAutoFillBackground(true);
	//adoptDogBtn->setPalette(pal);
	//adoptDogBtn->update();

	QString qss = QString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))");
	adoptDogBtn->setStyleSheet(qss);

	gridLayoutCenter->addWidget(adoptDogBtn, 0, 0);
	QObject::connect(adoptDogBtn, &QPushButton::clicked, []() {
		auto dog = ctrl.getDogs()[dogsList->currentIndex().row()];
		ctrl.addAdoption(dog);
		populateAdoptionList();
	});

		QWidget* adoptButton = new QWidget{};
		adoptButton->setLayout(gridLayoutCenter);
		formLayoutCenter->addWidget(adoptButton);
	

	QFormLayout *formLayoutRight = new QFormLayout{};

	QLabel* adoptedLabel = new QLabel{ "Adopted:" };
	formLayoutRight->addWidget(adoptedLabel);

	listAdopt = new QListWidget();
	listAdopt->setFixedHeight(300);
	formLayoutRight->addWidget(listAdopt);

	QGridLayout *gridLayoutAdopt = new QGridLayout{};
	QWidget* buttonsAdopt = new QWidget{};
	buttonsAdopt->setLayout(gridLayoutAdopt);
	formLayoutRight->addWidget(buttonsAdopt);
	
	QGridLayout *gridLayoutAdopt2 = new QGridLayout{};

	QWidget* buttonNext = new QWidget{};
	QPushButton *nextBtn = new QPushButton("Next");
	gridLayoutAdopt2->addWidget(nextBtn, 0, 0);
	QObject::connect(nextBtn, &QPushButton::clicked, []() {
		if (listAdopt->currentIndex().row() + 1 < ctrl.getAdoptions().size())
			listAdopt->setCurrentRow(listAdopt->currentIndex().row() + 1);
		else
			listAdopt->setCurrentRow(0);
	});
	buttonNext->setLayout(gridLayoutAdopt2);
	formLayoutRight->addWidget(buttonNext);

	QWidget* buttonHTML = new QWidget{};
	QPushButton *htmlBtn = new QPushButton("View in HTML");
	gridLayoutAdopt2->addWidget(htmlBtn, 0, 1);
	QObject::connect(htmlBtn, &QPushButton::clicked, []() {
		FileManager *fm3 = new HTMLFileManager();
		fm3->writeToFile(ctrl.getAdoptions());
		system("start outfile.html");
	});
	buttonHTML->setLayout(gridLayoutAdopt2);
	formLayoutRight->addWidget(buttonHTML);

	QWidget *wnd = new QWidget{};

	QTableView *tableView = new QTableView(wnd);
	AdoptionsTableModel *tableModel = new AdoptionsTableModel(ctrl);
	tableView->setModel(tableModel);

	QWidget* buttonView = new QWidget{};
	QPushButton *viewBtn = new QPushButton("View the adoption list");
	gridLayoutAdopt2->addWidget(viewBtn, 1, 0);
	QObject::connect(viewBtn, &QPushButton::clicked, [tableView]() {
		QFormLayout* adoptLayout = new QFormLayout{};
		AdoptionsTableModel *tableModel = new AdoptionsTableModel(ctrl);
		tableView->setModel(tableModel);
		adoptLayout->addWidget(tableView);
		QWidget *wnd2 = new QWidget{};
		wnd2->setLayout(adoptLayout);
		wnd2->show();
	});
	buttonView->setLayout(gridLayoutAdopt2);
	formLayoutRight->addWidget(buttonView);


	hbox->addLayout(formLayoutLeft);
	hbox->addLayout(formLayoutCenter);
	hbox->addLayout(formLayoutRight);

	
	wnd->setLayout(hbox);
	wnd->show();	
	
	//while (true) {
	if (::GetKeyState(0x11) & 0x8000)  // is ctrl pressed?  
	{
		if (::GetKeyState(0x5A) & 0x8000)  // is z also pressed?  
		{
			ctrl.undo();
			/*
			std::cout << "Shift G pressed" << std::endl;*/
			//break;
		}
		//else std::cout << "Shift..." << std::endl;
	}

	if (GetKeyState('A') & 0x8000) {
		ctrl.undo();
	}

	//}

	return a.exec();
}

#include "FileManager.h"

void populateDogsList() 
{
	//QListWidget* dogsList;
	if (dogsList->count() > 0)
		dogsList->clear();

	for (auto d : ctrl.getDogs())
	{
		QString itemInList = QString::fromStdString(d.getName() + ", " + to_string(d.getAge()) + ", " + d.getBreed() + ", " + d.getPic());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		dogsList->addItem(item);
	}

	if (ctrl.getDogs().size() > 0)
		dogsList->setCurrentRow(0);
		
}

void populateAdoptionList()
{
	//QListWidget* dogsList;
	if (listAdopt->count() > 0)
		listAdopt->clear();

	for (auto d : ctrl.getAdoptions())
	{
		QString itemInList = QString::fromStdString(d.getName() + ", " + to_string(d.getAge()) + ", " + d.getBreed() + ", " + d.getPic());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		listAdopt->addItem(item);
	}

	if (ctrl.getAdoptions().size() > 0)
		listAdopt->setCurrentRow(0);

}

