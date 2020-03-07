#include "TableModel.h"



TableModel::TableModel(Session &s, QObject *parent) :
	QAbstractTableModel{parent}, s{s}
{
}


TableModel::~TableModel()
{
}

int TableModel::rowCount(const QModelIndex & parent) const
{
	return this->s.getStars().size();
}

int TableModel::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant TableModel::data(const QModelIndex & index, int role) const
{
	if (index.row() >= this->s.getStars().size()) return QVariant();
	auto star = this->s.getStars()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:		
			return QString::fromStdString(star.getName());
		case 1:		
			return QString::fromStdString(star.getConstellation());
		case 2:	
			return QString::fromStdString(to_string(star.getRa()));
		case 3:		
			return QString::fromStdString(to_string(star.getDec()));
		case 4:
			return QString::fromStdString(to_string(star.getDiameter()));
		default:
			break;
		}
	}

	return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Name" };
			case 1:
				return QString{ "Constellation" };
			case 2:
				return QString{ "Right Ascension" };
			case 3:
				return QString{ "Declination" };
			case 4:
				return QString{ "Diameter" };
			default:
				return QString{ "Not found" };
				break;
			}
		}
	}
	return QString{ "Not found" };
}

bool TableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	int row = index.row();
	int col = index.column();

	Star &star = this->s.getStars()[index.row()];

	if (role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		}
	}

	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex & index) const
{
	int col = index.column();
	if (col == 0)
		return Qt::ItemFlags{};
	return Qt::ItemFlags{};
}

bool TableModel::insertRows(int row, int count, const QModelIndex &parent)
{
	beginInsertRows(parent, row, row + count - 1);
	//emit dataChanged(this->index(0, 0), this->index(row, 4));
	endInsertRows();
	return true;
}
