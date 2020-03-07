#pragma once
#include "Session.h"
#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel
{
public:
	TableModel(Session &s, QObject *parent = NULL);
	~TableModel();

	int rowCount(const QModelIndex& parent = QModelIndex{}) const override;							
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override;						
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;				
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;	
	Qt::ItemFlags flags(const QModelIndex & index) const override;

	bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex()) override;


private:
	Session &s;
};

