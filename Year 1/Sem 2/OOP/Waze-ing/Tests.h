#pragma once
#include "Controller.h"
#include <assert.h>

class Tests
{
public:
	Tests();
	~Tests();

	void test() {
		Controller c;
		assert(c.addReport(Report("a", "b", 1, 1, 1)) == 1);
	}

};

