#include "ReportRepository.h"

#include <fstream>
#include <string>

ReportRepository::ReportRepository()
{
	ifstream f("reports.txt");
	string description;
	string reporter;
	string latitude, longitude;
	string validated;
	int id;

	while (getline(f, description, ';') && getline(f, reporter, ';') && getline(f, latitude, ';') && getline(f, longitude, ';') && getline(f, validated, ';'))
	{
		int lat = stoi(latitude);
		int lon = stoi(longitude);

		bool val;
		if (validated == "true")
			val = true;
		else
			val = false;

		auto report = Report(description, reporter, lat, lon, val);
		reports.emplace_back(report);
	}

	f.close();
}


ReportRepository::~ReportRepository()
{
}

vector<Report> ReportRepository::getReports()
{
	return this->reports;
}
