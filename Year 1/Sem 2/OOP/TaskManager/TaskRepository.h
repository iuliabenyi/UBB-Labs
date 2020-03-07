#pragma once
#include "Task.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include "ProgrammerRepository.h"
#include "Observer.h"
#include <cassert>

using namespace std;

class notOpenException
{
public:
	virtual const char* what() const throw()
	{
		return "The task must be open!";
	}
};

class TaskRepository : public Subject
{
public:
	TaskRepository() {
		ifstream f("task.txt");
		string description;
		string status;
		int id;

		while (getline(f, description, ';') && getline(f, status, ';'))
		{
			if (status == "open")
			{
				auto task = Task(description, status);
				tasks.emplace_back(task);
			}
			else
			{
				f >> id;
				auto task = Task(description, status, id);
				tasks.emplace_back(task);
				progID.emplace_back(id);
			}
			
		}

		f.close();
	}

	~TaskRepository() {
		/*ofstream o("task.txt");
		for (const auto &t : tasks)
			if (t.getStatus() == "open")
				o << t.getDescription() << ';' << t.getStatus();
			else
				o << t.getDescription() << ';' << t.getStatus() << ';' << t.getID();
		o.close();*/

	}

	const string getStatus(int indx) const { return tasks[indx].getStatus(); }

	int getID(int indx) { return tasks[indx].getID(); }

	void writeToFile() {
		ofstream o("task.txt");
		for (const auto &t : tasks)
			if (t.getStatus() == "open")
				o << t.getDescription() << ';' << t.getStatus();
			else
				o << t.getDescription() << ';' << t.getStatus() << ';' << t.getID();
		o.close();
	}

	vector<int> &getProgID() { return this->progID; }

	void addTask(Task t) { tasks.push_back(t); this->notify(); };

	int searchIndex(string description) {
		for (int i=0; i<tasks.size(); i++)
			if (tasks[i].getDescription() == description)
				return i;
		return 0;
	}
	
	string searchName(int id){
		for (const auto &elem : pRepo.getProgrammers())
			if (elem.getID() == id)
				return elem.getName();
	}

	int searchID(string name) {
		return 1;
		for (const auto &elem : pRepo.getProgrammers())
			if (elem.getName() == name)
				return elem.getID();
		
	}

	void removeTask(string description) {
		int indx = searchIndex(description);
		tasks.erase(tasks.begin() + indx);
		this->notify();
	}



	void startTask(string description) {
		int indx = searchIndex(description);
		if (this->getTasks()[indx].getStatus() == "open")
		{
			this->getTasks()[indx].setStatus("in progress");
			this->notify();
		}

		else
			throw notOpenException();
	}

	void doneTask(string description) {
		int indx = searchIndex(description);
		if(this->getTasks()[indx].getStatus() == "in progress")
			this->getTasks()[indx].setStatus("closed");
		this->notify();
	}

	vector<Task> &getTasks() { return this->tasks; };
	/*
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
			return false;*//*
			return t1.getStatus() < t2.getStatus();
		};
		std::sort(tasks.begin(), tasks.end(), sortRuleLambda);
	}*/
	/*
	void addTask(Task &t) {
		t.setStatus("open");
		tasks.emplace_back(t);
	}*/

	ProgrammerRepository &getPRepo() { return pRepo; }

private:
	vector<Task> tasks;
	vector<int> progID;
	//vector<Programmer> programmers;
	ProgrammerRepository pRepo;
};



