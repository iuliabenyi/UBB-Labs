#include "Controller.h"



Controller::Controller()
{
}


Controller::~Controller()
{
}

Driver Controller::getDriverByName(string name)
{
	for (auto &elem : this->getDriverRepo().getDrivers())
		if (elem.getName() == name)
			return elem;
	return Driver("a", "a", 0, 0, 0);
}

int Controller::addReport(Report r)
{
	Driver d = this->getDriverByName(r.getNameRep());
	/*if (d.getLatitude() - 20 < r.getLatitude() || d.getLatitude() + 20 > r.getLatitude())
	{
		return -1;
	}
	if (d.getLongitude() - 20 < r.getLongitude() || d.getLongitude() + 20 > r.getLongitude())
	{
		return -1;
	}*/
	if (this->reportRepo.addReport(r) == 1)
	{
		//system("start aaa");
		return 1;
		
	}
	//system("start ddd");
	return -1;
}
