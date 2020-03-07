#pragma once
#include "Building.h"
#include "Ethnologist.h"
#include <vector>
#include <fstream>
#include "Observer.h"
#include <algorithm>
#include <string>

class Session : public Subject
{
public:
	Session();
	~Session();

	vector<Building> &getBuildings() { return buildings; }
	vector<Ethnologist> &getEthnologists() { return ethnologists; }

	void readBuildings()
	{
		ifstream f("building.txt");
		int id;
		string description;
		int year;
		string sector;
		int x;
		int y;
		char separator;
		while (f >> id && f >> separator && getline(f, description, ';') && f >> year && f >> separator && getline(f, sector, ';') && f >> x && f >> separator && f >> y && f >> separator)
			buildings.emplace_back(Building(id, description, year, sector, x, y));
	}

	void readEthnologists()
	{
		ifstream f("ethnologist.txt");
		string name;
		string sector;
		while (getline(f, name, ';') && getline(f, sector, ';'))
			ethnologists.emplace_back(Ethnologist(name, sector));
	}

	int sortBuildings(string sector)
	{
		/*
			Sorts the buildings in the file
			Output:
				-returns the sorted buildings
				-o if they were not sorted
		*/
		
		sort(getBuildings().begin(), getBuildings().end(), [](const Building &o1, const Building &o2) {
			return o1.getSector() < o2.getSector();
		});
		/*
		sort(getBuildings().begin(), getBuildings().end(), [sector](const Building &s1, const Building &s2) {
			if (s1.getSector() == s2.getSector()) {
				if (s1.getSector() == sector)
					return s1;
				else if (s2.getSector() == sector)
					return s2;

				return s1; 
			}

			return s1.getSector() > s2.getSector();
		});*/
		return 0;
	}

	int searchID(int id)
	{
		for (auto &elem : buildings)
			if (elem.getID() == id)
				return -1;
		return 1;
	}

	int addBuilding(Building &b, string sector)
	{
		/*
			Adds a new builing
			Input:
				-b: the building
				-sector: the sector from the ethnologist
			Output:
				-1 if the building was added, -1 otherwise
		*/
		if (b.getSector() != sector)
			return -1;
		if (b.getDescription() == "")
			return -1;
		if (searchID(b.getID()) == -1)
			return -1;
		if (b.getYear() < 0 || b.getYear() > 1970)
			return -1;
		/*for (auto &elem : buildings)
			if (elem.getSector() == sector)
				if (elem.getX() - 100 < b.getX() || elem.getX() + 100 > b.getX() || elem.getY() - 100 < b.getY() || elem.getY() + 100 > b.getY())
					return -1;*/
		buildings.emplace_back(b);
		this->notify();
		return 1;
	}

	int updateBuilding(int id, string newDesc)
	{
		/*
		if (b.getSector() == sector)
		{
			b.setDescr(descr);
			//system("start aaa");
			return 1;
		}
		return -1;*/

		for( auto &elem : buildings)
			if (id == elem.getID())
			{
				elem.setDescr(newDesc);
				
				this->notify();
				return 1;
			}
		return -1;
	}

	string findSector(string name)
	{
		for (auto &elem : ethnologists)
			if (elem.getName() == name)
				return elem.getSector();
	}



private:
	vector<Building> buildings;
	vector<Ethnologist> ethnologists;
};

