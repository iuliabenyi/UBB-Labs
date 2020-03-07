#include "Wazeing.h"
#include <QtWidgets/QApplication>
#include "main.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Controller ctrl;
	Tests t;
	t.test();

	for (auto &elem : dr.getDrivers())
	{
		windowVec.emplace_back(new Window(rr, elem.getName(), elem.getStatus(), elem.getLongitude(), elem.getLatitude(), elem.getScore()));
	}

	//windowVec.emplace_back(new Window(rr, "name1", 1, 2));
	
	for (auto &elem : windowVec)
		elem->show();



	return a.exec();
}
