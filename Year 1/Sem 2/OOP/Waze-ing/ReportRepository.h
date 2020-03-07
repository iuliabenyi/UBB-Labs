#pragma once
#include <vector>
#include "Report.h"
#include <fstream>
#include <iostream>
#include "DriverRepository.h"

using namespace std;

class ReportRepository
{
public:
	ReportRepository() {
		ifstream f("report.txt");
		string name;
		string descr;
		int latitude;
		int longitude;
		bool validated;
		char separator;

		while (getline(f, descr, ';') && getline(f, name, ';') && f>>latitude && f>>separator && f>>longitude && f >> separator && f>>validated)
		{
			//auto report = Report(string("r1"), string("n1"), 1, 2, true);
			auto report = Report(descr, name, latitude, longitude, validated);
			
			vec.emplace_back(report);
		}
		f.close();
	}
	~ReportRepository() {
		/*ofstream o("report.txt");
		for (auto &r : getReports())
			o << r.getDescription() << ';' << r.getNameRep() << ';' << r.getLatitude()<< ';' <<r.getLongitude() << ';' <<r.getValidated();
		o.close();*/
	}

	vector<Report> &getReports() { return this->vec; }

	int addReport(Report r);

	Report &getReportByName(string name) {
		for (auto &elem : this->getReports())
			if (elem.getNameRep() == name)
				return elem;
	}

	int validate(string name);

	void setValidated(string name)
	{
		auto r = getReportByName(name);
		r.setValidated(true);
		//system("start aaa");
	}

private:
	vector<Report> vec;
};

