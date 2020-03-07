#include "Restanta.h"
#include <QtWidgets/QApplication>
#include "main.h"
#include <qformlayout.h>
#include "Test.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Test t;
	t.test();
	
	for (auto &elem : s.getEthnologists())
	{
		windows.emplace_back(new Window(s, elem.getName(), elem.getSector()));
		//system("start aaa");
	}
	
	for (auto &elem : windows)
		elem->show();
	/*
	QWidget* widg = new QWidget{};
	widg->show();*/


	return a.exec();
}
