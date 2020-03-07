#include "Questionandanswersite.h"
#include "main.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	//Controller &ctrl;

	for (auto &elem : ur.getUsers())
	{
		windowVec.emplace_back(new Window(ctrl, qr, elem.getName()));
	}

	//windowVec.emplace_back(new Window(rr, "name1", 1, 2));

	for (auto &elem : windowVec)
		elem->show();

	SearchWindow searchWnd(ctrl, qr);
	searchWnd.show();

	return a.exec();
}
