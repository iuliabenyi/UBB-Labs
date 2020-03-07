#include "Test_lab.h"
#include "main.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <qmessagebox.h>
#include <qradiobutton.h>
#include <algorithm>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	QFormLayout* formLayout = new QFormLayout{};

	QHBoxLayout* hbox = new QHBoxLayout{};

	QLabel* label = new QLabel{ "" };
	formLayout->addWidget(label);

	QListWidget* eqList = new QListWidget{};

	eqList->setSelectionMode(QAbstractItemView::SingleSelection);
	populateList();
	formLayout->addWidget(eqList);

	hbox->addLayout(formLayout);

	QWidget *wnd = new QWidget{};
	wnd->setLayout(hbox);
	wnd->show();



	return a.exec();
}

void populateList()
{
	if (eqList->count() > 0)
		eqList->clear();

	for (auto e : ctrl.getVector())
	{
		QString itemInList = QString::fromStdString(ctrl.stringMath());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		eqList->addItem(item);
	}

	if (ctrl.getVector().size() > 0)
		eqList->setCurrentRow(0);
}
