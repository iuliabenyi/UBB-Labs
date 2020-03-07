#pragma once
using namespace std;
#include <vector>
#include "Report.h"
class ReportRepository
{
public:
	ReportRepository();
	~ReportRepository();
	vector<Report> getReports();
private:
	vector<Report> reports;
};

