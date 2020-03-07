#include "ProgrammerWindow.h"
#include "Task.h"
#include <qformlayout.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qmessagebox.h>

ProgrammerWindow::ProgrammerWindow(TaskRepository &task, string name, int id, QWidget *parent)
	: QWidget(parent), name(name), id(id), task(task)
{
	ui.setupUi(this);
	this->task.registerObservers(this);
	this->setWindowTitle(this->getName().c_str());
	lw = new QListWidget();

	for (const auto &elem : this->task.getTasks())
		lwItems.emplace_back(new QListWidgetItem(elem.toString().c_str(), lw));
	/*
	sortedTasks = repo.searchTask(this->getID());
	//add the elements from vectorTask
	task.sortTasks();*/


	QFormLayout* layout = new QFormLayout{};
	taskList = new QListWidget{};
	taskList->setSelectionMode(QAbstractItemView::SingleSelection);

	for (auto t : repo.getTasks())
	{
		QString itemInList = QString::fromStdString(t.getDescription() + " " + t.getStatus());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		taskList->addItem(item);

	}

	layout->addWidget(taskList);
	/*QWidget *wnd = new QWidget{};
	wnd->setLayout(layout);
	wnd->show();*/

	QLabel* descrLabel = new QLabel{ "&Description: " };
	QLineEdit* descrTextBox = new QLineEdit{};
	descrLabel->setBuddy(descrTextBox);
	layout->addRow(descrLabel, descrTextBox);

	QPushButton* addButton = new QPushButton{ "Add" };
	layout->addWidget(addButton);
	QObject::connect(addButton, &QPushButton::clicked, [descrTextBox, this]() {
		string descr = descrTextBox->text().toUtf8().constData();

		Task t = Task(descr, string("open"));
		this->task.addTask(t);

		QString itemInList = QString::fromStdString(t.getDescription() + " " + t.getStatus());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		taskList->addItem(item);

		this->getRepo().writeToFile();

	});

	QPushButton* deleteButton = new QPushButton{ "Delete" };
	layout->addWidget(deleteButton);
	//int TLRow = this->taskList->currentIndex().row();
	//auto vec = sortedTasks[TLRow];
	QObject::connect(deleteButton, &QPushButton::clicked, [this]() {
		auto t = this->getRepo().getTasks()[this->getTLRow()];
		this->getRepo().removeTask(t.getDescription());
		this->removeTask(t.getDescription());
		
		if (taskList->count() > 0)
			taskList->clear();
		for (auto t : this->getSortedTasks())
		{
			QString itemInList = QString::fromStdString(t.getDescription() + " " + t.getStatus());
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			taskList->addItem(item);
		}

		this->getRepo().writeToFile();
		
	});
	QPushButton* startButton = new QPushButton{ "Start" };
	layout->addWidget(startButton);
	QObject::connect(startButton, &QPushButton::clicked, [this]() {
		auto t = this->getRepo().getTasks()[this->getTLRow()];
		this->getRepo().getTasks()[this->getTLRow()].setStarted(true);
		string name = "";
		try
		{
			this->getRepo().startTask(t.getDescription());
			QString Qname = QWidget::windowTitle();
			name = Qname.toStdString();
			this->getRepo().getTasks()[this->getTLRow()].setID(this->getRepo().searchID(name));

		}
		catch(notOpenException& e)
		{

			QMessageBox::information(this,e.what(), e.what());
		}

		if (taskList->count() > 0)
			taskList->clear();
		for (auto t : this->getSortedTasks())
		{
			QString itemInList;
			if(t.getStarted())
				itemInList = QString::fromStdString(t.getDescription() + " " + t.getStatus() + " " + name);
			else
				itemInList = QString::fromStdString(t.getDescription() + " " + t.getStatus());
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			taskList->addItem(item);
		}
		this->getRepo().writeToFile();
	});

	QPushButton* doneButton = new QPushButton{ "Done" };
	layout->addWidget(doneButton);
	QObject::connect(doneButton, &QPushButton::clicked, [this]() {
		auto t = this->getRepo().getTasks()[this->getTLRow()];
		string name;
		try
		{
			this->getRepo().doneTask(t.getDescription());
			QString Qname = QWidget::windowTitle();
			name = Qname.toStdString();
		}
		catch (notOpenException& e)
		{

			QMessageBox::information(this, e.what(), e.what());
		}

		if (taskList->count() > 0)
			taskList->clear();
		for (auto t : this->getSortedTasks())
		{
			QString itemInList;
			if (t.getStarted())
				itemInList = QString::fromStdString(t.getDescription() + " " + t.getStatus() + " " + name);
			else
				itemInList = QString::fromStdString(t.getDescription() + " " + t.getStatus());
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			taskList->addItem(item);
		}
		this->getRepo().writeToFile();
	});


	this->setLayout(layout);
	

}

ProgrammerWindow::~ProgrammerWindow()
{
	this->task.unregisterObserver(this);
}

void ProgrammerWindow::update() {
	taskList->clear();
	//lwItems.clear();
	for (const auto &q : task.getTasks()) {
		lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), taskList));
	}
}
