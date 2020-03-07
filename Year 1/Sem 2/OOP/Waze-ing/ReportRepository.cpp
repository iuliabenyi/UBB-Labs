#include "ReportRepository.h"


/*
ReportRepository::ReportRepository()
{
}


ReportRepository::~ReportRepository()
{
}
*/

int ReportRepository::addReport(Report r)
{
	if (r.getDescription() == "")
	{
		//system("start aaa");
		return -1;
	}
	vec.emplace_back(r);
	//system("start bbb");
	return 1;

}

int ReportRepository::validate(string name)
{
	Report r = this->getReportByName(name);
	//if (r.getCtr() >= 2)
	//{
	//Report r = this->getReportByName(name);
	r.validate();
		return 1;
		
	//}
	
	return -1;

}
