#pragma once

#include <QWidget>
#include <TaskRepository.h>
#include "ui_ProgrammerWindow.h"
#include <qlistwidget.h>
#include "ProgrammerRepository.h"
#include "Repository.h"
#include "Observer.h"

class ProgrammerWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	ProgrammerWindow(TaskRepository &task, string name, int id, QWidget *parent = Q_NULLPTR);
	~ProgrammerWindow();

	const string getName() const{ return this->name; }
	int getID() { return this->id; }
	
	vector<Task> &getSortedTasks() { return this->repo.getTasks(); }
	int getTLRow() { return this->taskList->currentIndex().row(); }
	
	int searchIndex(string description) {
		for (int i = 0; i < repo.getTasks().size(); i++)
			if (repo.getTasks()[i].getDescription() == description)
				return i;
		return 0;
	}

	void removeTask(string description) {
		int indx = searchIndex(description);
		repo.getTasks().erase(repo.getTasks().begin() + indx);
	}

	string searchNameById(int id) {
		for (const auto &elem : programmer.getProgrammers())
			if (elem.getID() == id)
				return elem.getName();
	}


	Repository &getRepo() { return this->repo; }
	void update() override;
	

private:
	Ui::ProgrammerWindow ui;
	TaskRepository &task;
	ProgrammerRepository programmer;
	string name;
	int id;

	QListWidget *lw;
	vector<QListWidgetItem*> lwItems;
	Repository repo;
	

	//vector<Task> sortedTasks;

	QListWidget* taskList;


};
