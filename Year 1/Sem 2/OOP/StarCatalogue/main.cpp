#include "StarCatalogue.h"
#include <QtWidgets/QApplication>
#include "main.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	for (auto &elem : s.getAstronomers())
		windowVec.emplace_back(new Window(s, elem.getName().c_str(), elem.getConstellation().c_str()));
	
	for (auto &elem : windowVec)
		elem->show();
		



	return a.exec();
}
