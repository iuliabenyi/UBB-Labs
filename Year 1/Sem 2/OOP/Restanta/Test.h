#pragma once
#include "Session.h"
#include <assert.h>
class Test
{
public:
	Test();
	~Test();

	void test()
	{
		Building b = Building(100, "d1", 1000, "s1", 1, 2);
		Session s;
		assert(s.addBuilding(b, b.getSector()) == 1);
		assert(s.addBuilding(b, b.getSector()) == -1);

		Building b2 = Building(101, "d1", 1000, "s2", 1, 2);
		Building b3 = Building(102, "d1", 1000, "s1", 1, 2);
		Building b4 = Building(103, "d1", 1000, "s2", 1, 2);

		s.addBuilding(b, b.getSector());
		s.addBuilding(b2, b2.getSector());
		s.addBuilding(b3, b3.getSector());
		s.addBuilding(b4, b4.getSector());
		assert(s.sortBuildings(b.getSector()) != -1);
	}
};

