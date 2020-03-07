#include "Window.h"
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>

Window::Window(ReportRepository &reports, string name, string status, int longitude, int latitude, int score, QWidget *parent)
	: QWidget(parent), reports(reports), name(name), longitude(longitude), latitude(latitude), status(status), score(score)
{
	ui.setupUi(this);

	QFormLayout* layout = new QFormLayout{};
	this->setWindowTitle(this->name.c_str());

	Driver currDriver = this->ctrl.getDriverByName(name);
	if (currDriver.getStatus() == "baby")
	{
		this->setStyleSheet("background-color: pink");
	}

	if (currDriver.getStatus() == "regular")
	{
		this->setStyleSheet("background-color: yellow");
	}

	if (currDriver.getStatus() == "advanced")
	{
		this->setStyleSheet("background-color: LightBlue");
	}
	
	Driver d = ctrl.getDriverByName(name);

	int lat = d.getLatitude();
	QString qLat = QString::fromStdString(to_string(lat));
	QLabel* latLabel = new QLabel{ "Latitude: "};
	QLabel* latNrLabel = new QLabel{ qLat };
	latLabel->setBuddy(latNrLabel);
	layout->addRow(latLabel, latNrLabel);
	
	int lng = d.getLongitude();
	QString qLng = QString::fromStdString(to_string(lng));
	QLabel* lngLabel = new QLabel{ "Longitude: " };
	QLabel* lngNrLabel = new QLabel{ qLng };
	lngLabel->setBuddy(lngNrLabel);
	layout->addRow(lngLabel, lngNrLabel);
	

	int scoree = d.getScore();
	QString qScore = QString::fromStdString(to_string(scoree));
	QLabel* scoreLabel = new QLabel{ "Score: " };
	QLabel* scoreNrLabel = new QLabel{ qScore };
	scoreLabel->setBuddy(scoreNrLabel);
	layout->addRow(scoreLabel, scoreNrLabel);


	string statuss = d.getStatus();
	QString qStatus = QString::fromStdString(statuss);
	QLabel* statusLabel = new QLabel{ "Status: " };
	QLabel* statusNrLabel = new QLabel{ qStatus };
	statusLabel->setBuddy(statusNrLabel);
	layout->addRow(statusLabel, statusNrLabel);

	reportList = new QListWidget{};
	for (auto &elem : this->reports.getReports())
		lwItems.emplace_back(new QListWidgetItem(elem.toString().c_str()));

	reportList = new QListWidget{};
	reportList->setSelectionMode(QAbstractItemView::SingleSelection);

	for (auto &r : ctrl.getReportRepo().getReports())
	{
		if ((r.getLatitude() - latitude <= 10 || r.getLatitude() - latitude >= -10) && ( r.getLongitude() - longitude <= 10 || r.getLongitude() - longitude >= -10))
		{
			QString itemInList;
			if (r.getValidated() == 1)
				itemInList = QString::fromStdString(r.getDescription() + " " + r.getNameRep() + " " + to_string(r.getLatitude()) + " " + to_string(r.getLongitude()) + " " + "true");
			else
				itemInList = QString::fromStdString(r.getDescription() + " " + r.getNameRep() + " " + to_string(r.getLatitude()) + " " + to_string(r.getLongitude()) + " " + "false");


			QListWidgetItem *item = new QListWidgetItem{ itemInList };
			reportList->addItem(item);
		}
	}

	layout->addWidget(reportList);


	QLabel* descrLabel = new QLabel{ "Description" };
	QLineEdit* descrTB = new QLineEdit{};
	descrLabel->setBuddy(descrTB);
	layout->addRow(descrLabel, descrTB);

	QLabel* longLabel = new QLabel{ "Longitude" };
	QLineEdit* longTB = new QLineEdit{};
	longLabel->setBuddy(longTB);
	layout->addRow(longLabel, longTB);

	QLabel* latiLabel = new QLabel{ "Latitude" };
	QLineEdit* latiTB = new QLineEdit{};
	latiLabel->setBuddy(latiTB);
	layout->addRow(latiLabel, latiTB);

	QPushButton* addBtn = new QPushButton{ "Add" };
	layout->addWidget(addBtn);
	QObject::connect(addBtn, &QPushButton::clicked, [this, descrTB, longTB, latiTB, name]() {
		string descr = descrTB->text().toUtf8().constData();
		string slongitude = longTB->text().toUtf8().constData();
		int longitude = stoi(slongitude);
		string slatitude = latiTB->text().toUtf8().constData();
		int latitude = stoi(slatitude);
		Report r = Report(descr, name, latitude, longitude, 1);
		//si aici se fute

		this->getCtrl().addReport(r);
		//this->getCtrl().addReport(Report("pula", "numePula", 1, 2, 1));

		if (reportList->count() > 0)
		reportList->clear();
	for (auto r : this->getCtrl().getReportRepo().getReports())
	{
		QString itemInList;
		if (r.getValidated() == 1)
			itemInList = QString::fromStdString(r.getDescription() + " " + r.getNameRep() + " " + to_string(r.getLatitude()) + " " + to_string(r.getLongitude()) + " " + "true");
		else
			itemInList = QString::fromStdString(r.getDescription() + " " + r.getNameRep() + " " + to_string(r.getLatitude()) + " " + to_string(r.getLongitude()) + " " + "false");

		
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		reportList->addItem(item);
	}

		//this->getCtrl().writeToFile();
	});

	QPushButton* validateBtn = new QPushButton{ "Validate" };
	layout->addWidget(validateBtn);
	int ctr = 0;
	QObject::connect(validateBtn, &QPushButton::clicked, [this, name]() {
		auto &r = this->getCtrl().getReportRepo().getReports()[this->getTLRow()];
		//this->getCtrl().validate(r.getNameRep());
			//this->getCtrl().increaseCtr(r.getNameRep());
		//this->ctrl.getReportRepo().setValidated(name);
		r.setValidated(true);
			//system("start aaa");
			if (reportList->count() > 0)
				reportList->clear();
			for (auto r : this->getCtrl().getReportRepo().getReports())
			{
				QString itemInList;
				if(r.getValidated() == 1)
					 itemInList = QString::fromStdString(r.getDescription() + " " + r.getNameRep() + " " + to_string(r.getLatitude()) + " " + to_string(r.getLongitude()) + " " + "true" );
				else
					 itemInList = QString::fromStdString(r.getDescription() + " " + r.getNameRep() + " " + to_string(r.getLatitude()) + " " + to_string(r.getLongitude()) + " " + "false");

				QListWidgetItem* item = new QListWidgetItem{ itemInList };
				reportList->addItem(item);
			}
		
	});
	


	this->setLayout(layout);



}

Window::~Window()
{
}

void Window::populate(int dist)
{
	if (reportList->count() > 0)
		reportList->clear();
	for (auto r : this->getCtrl().getReportRepo().getReports())
		if (r.getNameRep() != this->name && (r.getLatitude() - ctrl.getDriverByName(this->name).getLatitude()) <= dist && abs(r.getLongitude() - ctrl.getDriverByName(this->name).getLongitude()) <= dist)
		{
			QString itemInList = QString::fromStdString(r.getDescription() + " " + r.getNameRep() + " " + to_string(r.getLatitude()) + " " + to_string(r.getLongitude()));
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			reportList->addItem(item);
		}
}