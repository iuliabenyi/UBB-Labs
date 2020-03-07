#include "TaskManagerr.h"
#include <QtWidgets/QApplication>
#include "main.h"
#include <ProgrammerWindow.h>
#include "Repository.h"
#include <vector>
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include "Tests.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo;

	Tests t;
	t.test();
	
	for (const auto &elem : repo.getProgrammers())
	{
		//ProgrammerWindow pw(tr, elem.getName().c_str());
		progVec.emplace_back(new ProgrammerWindow(tr, elem.getName().c_str(), elem.getID()));
		//pw.show();
	}

	for (auto &elem : progVec)
	{
		
		
		elem->show();
	}
	
	return a.exec();
}

