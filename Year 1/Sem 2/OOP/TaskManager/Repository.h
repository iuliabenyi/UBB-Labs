#pragma once
#include "Programmer.h"
#include "Task.h"
#include "TaskRepository.h"
#include <iostream>
#include <fstream>

using namespace std;

class Repository
{
public:
	Repository() {
		/* fin("programmer.txt");
		string name;
		int id;

		this->sortTasks();

		while (getline(fin, name, ';') && fin >> id)
		{
			auto programmer = Programmer(name, id);
			tRepo.getPRepo().getProgrammers().emplace_back(programmer);
		}
		fin.close();*/
		this->sortTasks();
	}
	~Repository() {
		
	}

	const string getStatus(int indx) const { return tRepo.getStatus(indx); }

	int getID(int indx) { return tRepo.getID(indx); }

	void writeToFile() { return tRepo.writeToFile(); }

	vector<Programmer> getProgrammers() { return this->tRepo.getPRepo().getProgrammers(); };

	vector<Task> searchTask(int id) {
		vector<Task> vectorTasks;
		for (const auto &elem : tRepo.getTasks())
			if (elem.getID() == id)
				vectorTasks.emplace_back(elem);
		return vectorTasks;
	}

	void startTask(string description) { tRepo.startTask(description); }

	void doneTask(string description) { tRepo.doneTask(description); }

	vector<Task> &getTasks() { return this->tRepo.getTasks(); }

	int searchID(string name) { return tRepo.searchID(name); }
	string searchName(int id) { return tRepo.searchName(id); }

	void sortTasks() {
		auto sortRuleLambda = [](const Task& t1, const Task& t2) -> bool
		{/*
			if (t1.getStatus() == t2.getStatus())
				return false;
			if (t1.getStatus() == "in progress" && t2.getStatus() == "open")
				return true;
			if (t1.getStatus() == "closed" && t2.getStatus() == "open")
				return true;
			if (t1.getStatus() == "closed" && t2.getStatus() == "in progress")
				return true;
			return false;*/
			return t1.getStatus() < t2.getStatus();
		};
		std::sort(tRepo.getTasks().begin(), tRepo.getTasks().end(), sortRuleLambda);
	}

	void removeTask(string description) { return this->tRepo.removeTask(description); }

	string getNameFromID(int id) { return tRepo.searchName(id); }

private:
	//vector<Programmer> programmers;
	TaskRepository tRepo;
};

