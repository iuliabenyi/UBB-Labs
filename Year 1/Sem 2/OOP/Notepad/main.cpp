#include "Notepad.h"
#include <QtWidgets/QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MainWindow* wnd = new MainWindow("New Text Document");

	
	wnd->show();


	return a.exec();
}
