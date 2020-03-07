#include "Tests.h"
#include <assert.h>


Tests::Tests()
{
}


Tests::~Tests()
{
}

void Tests::test()
{
	TaskRepository tRepo;
	Task t1 = Task(string("task1"), string("open"));
	Task t2 = Task(string("task2"), string("in progress"), 2);
	Task t3 = Task(string("task3"), string("closed"), 3);
	Task t4 = Task(string("task4"), string("open"));
	Task t5 = Task(string("task5"), string("in progress"), 1);

	vector<Task> vec = { t1, t2, t3, t4, t5 };

	tRepo.addTask(t1);
	tRepo.addTask(t2);
	tRepo.addTask(t3);
	tRepo.addTask(t4);
	tRepo.addTask(t5);

	assert(vec.size() == 5);

	tRepo.removeTask("task5");
	assert(vec.size() == 5);



}


