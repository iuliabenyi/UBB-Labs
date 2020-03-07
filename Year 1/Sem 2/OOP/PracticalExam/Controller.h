#pragma once
#include "DriverRepository.h"
#include "ReportRepository.h"
#include "Observer.h"
class Controller : public Subject
{
public:
	Controller();
	~Controller();
	//void changeStarted(string description)
	//{
	//	int i = this->taskRepo.findTask(description);
	//	this->taskRepo.getTasks()[i].setStarted();
	//	this->notify();
	//}
	vector<Driver> getDrivers();
	DriverRepository getDriversRepo() { return this->driversRepo; }
	ReportRepository getReportsRepo() { return this->reportsRepo; }
private:
	DriverRepository driversRepo;
	ReportRepository reportsRepo;
};

