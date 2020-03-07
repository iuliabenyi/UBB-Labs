#include "PracticalExam.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//PracticalExam w;
	//w.show();
	Controller ctrl{};
	vector<PracticalExam*> vector;
	for (auto &elem : ctrl.getDrivers())
	{
		/*TM t1(ctrl, elem.getName().c_str());*/


		vector.emplace_back(new PracticalExam(ctrl, elem.getName()));
	}


	for (auto &elem : vector)
	{


		ctrl.addObserver(elem);
	}


	for (auto &elem : vector)
	{


		elem->show();
	}



	return a.exec();
}
