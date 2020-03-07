#include "PracticalExam.h"
#include <string>
PracticalExam::PracticalExam(Controller & c, string name,QWidget *parent)
	: QMainWindow(parent), controller(c), name(name)
{
	ui.setupUi(this);
	//this->setObjectName(QString::fromStdString(name).c_str());
	this->setWindowTitle(QString::fromStdString(name));

	Driver actualDriver = this->controller.getDriversRepo().getDriverByName(name);
	if (actualDriver.getStatus() == "baby")
	{
		this->setStyleSheet("background-color: lightgreen");
	}
	
	if (actualDriver.getStatus() == "regular")
	{
		this->setStyleSheet("background-color: yellow");
	}

	if (actualDriver.getStatus() == "advanced")
	{
		this->setStyleSheet("background-color: blue");
	}

	int latitude = actualDriver.getLatitude();
	QString latitudeStr;
	latitudeStr.setNum(latitude);
	int longitude = actualDriver.getLongitude();
	QString longitudeStr;
	longitudeStr.setNum(longitude);

	QString scoreStr;
	scoreStr.setNum(actualDriver.getScore());

	this->ui.latitudeTB->setText(latitudeStr);
	this->ui.longitudeTB->setText(longitudeStr);
	this->ui.scoreLabel->setText(scoreStr);

	std::string s = actualDriver.getStatus(); 
	QString q = QString::fromLocal8Bit(s.c_str());
	this->ui.statusLabel->setText(q);


	this->populate();
	//this->ui.taskList->setSelectionMode(QAbstractItemView::SingleSelection);
	//QObject::connect(this->ui.button, &QPushButton::clicked, [this]() {
	//	auto t = this->controller.getTasks()[this->ui.taskList->currentIndex().row()];
	//	this->controller.changeStarted(t.getDescription());
	//	//t.setStarted();

	//	if (this->ui.taskList->count() > 0)
	//		this->ui.taskList->clear();

	//	this->update();

	//});

}
void PracticalExam::update()
{
	this->populate();
}

void PracticalExam::populate()
{
	/*this->ui.taskList->clear();
	for (auto &task : this->controller.getTasks())
	{
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(task.toString()) };
		this->ui.taskList->addItem(item);
	}*/
}
