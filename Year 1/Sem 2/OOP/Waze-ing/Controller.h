#pragma once
#include "DriverRepository.h"
#include "ReportRepository.h"

class Controller
{
public:
	Controller();
	~Controller();

	DriverRepository &getDriverRepo() { return this->driverRepo; }
	ReportRepository &getReportRepo() { return this->reportRepo; }

	Driver getDriverByName(string name);

	int addReport(Report r);

	void writeToFile() {
		ofstream o("report.txt");
		for (auto &r : reportRepo.getReports())
			o << r.getDescription() << ';' << r.getNameRep() << ';' << r.getLatitude() << ';' << r.getLongitude() << ';' << r.getValidated();
		o.close();
	}

	void increaseCtr(string descr) { this->reportRepo.validate(descr); }

	void setValidated(string name) { this->getReportRepo().setValidated(name); }

	int validate(string name) { return this->getReportRepo().validate(name); }

private:
	DriverRepository driverRepo;
	ReportRepository reportRepo;
};

