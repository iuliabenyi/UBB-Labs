#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StarCatalogue.h"

class StarCatalogue : public QMainWindow
{
	Q_OBJECT

public:
	StarCatalogue(QWidget *parent = Q_NULLPTR);

private:
	Ui::StarCatalogueClass ui;
};
