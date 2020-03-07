#include "AdoptionsTableModel.h"



AdoptionsTableModel::AdoptionsTableModel(Controller &ctrl, QObject * parent) : QAbstractTableModel{ parent }, ctrl{ ctrl }
{
}


AdoptionsTableModel::~AdoptionsTableModel()
{
}

int AdoptionsTableModel::rowCount(const QModelIndex & parent) const
{
	return this->ctrl.getDogs().size();
}

int AdoptionsTableModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant AdoptionsTableModel::data(const QModelIndex & index, int role) const
{
	if (index.row() >= this->ctrl.getAdoptions().size()) return QVariant();
	auto dog = this->ctrl.getAdoptions()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:		// first column - name
			return QString::fromStdString(dog.getName());
		case 1:		// second column - breed
			return QString::fromStdString(dog.getBreed());
		case 2:		// third column - age
			return QString::fromStdString(to_string(dog.getAge()));
		case 3:		// fourth column - photo
			return QString::fromStdString(dog.getPic());
		default:
			break;
		}
	}

	return QVariant();
}

QVariant AdoptionsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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
				return QString{ "Breed" };
			case 2:
				return QString{ "Age" };
			case 3:
				return QString{ "Photo" };
			default:
				break;
			}
		}
	}

	return QVariant();

}

bool AdoptionsTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	int row = index.row();
	int col = index.column();

	Dog &dog = this->ctrl.getDogs()[index.row()];

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
			std::string age{ value.toString().toStdString() };
			dog.setAge(stoi(age));
			break;
		}
		case 3:
		{
			std::string photo{ value.toString().toStdString() };
			dog.setPic(photo);
		}
		}
	}

	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags AdoptionsTableModel::flags(const QModelIndex & index) const
{
	int col = index.column();
	if (col == 0)
		return Qt::ItemFlags{};
	return Qt::ItemFlags{};
}
