#include "MainWindow.h"

MainWindow::MainWindow(string name, QWidget *parent)
	: QWidget(parent), name(name)
{
	ui.setupUi(this);

	QFormLayout* layout = new QFormLayout{};
	this->setWindowTitle(name.c_str());


	
	menubar->addMenu(fileMenu);

	layout->addWidget(menubar);
	this->setLayout(layout);

}

MainWindow::~MainWindow()
{
}
