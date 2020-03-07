#include "Tests.h"
#include <assert.h>

#include "DynamicArray.h"
#include <iostream>
Tests::Tests()
{
}

void Tests::testDynamicArray()
{
	DynamicArray<Dog> d = DynamicArray<Dog>();
	assert(d.getCapacity() == 10);
	Dog d1 = Dog("abc", "aaa", 12, "ph1");
	d.add(d1);
	assert(d.getSize() == 1);

	d.deleteElement(0);
	assert(d.getSize() == 0);

	d.add(d1);
	assert(d[0].getAge() == d1.getAge());

	DynamicArray<Dog> dv2 = DynamicArray<Dog>(d);
	assert(dv2.getSize() == 1);

	DynamicArray<Dog> dv3 = DynamicArray<Dog>();
	Dog dog1 = Dog("abc", "aaa", 12, "ph1");
	Dog d2 = Dog("fsd", "aaa", 12, "ph1");
	Dog d3 = Dog("afsdfdsbc", "aaa", 12, "ph1");
	Dog d4 = Dog("aebc", "aaa", 12, "ph1");
	Dog d5 = Dog("adsbc", "aaa", 12, "ph1");
	Dog d6 = Dog("abaaac", "aaa", 12, "ph1");
	Dog d7 = Dog("abvvc", "aaa", 12, "ph1");
	Dog d8 = Dog("abccc", "aaa", 12, "ph1");
	Dog d9 = Dog("abwwc", "aaa", 12, "ph1");
	Dog d10 = Dog("aqwbc", "aaa", 12, "ph1");
	Dog d11 = Dog("abcre", "aaa", 12, "ph1");
	dv3.add(dog1);
	dv3.add(d2);
	dv3.add(d3);
	dv3.add(d4);
	dv3.add(d5);
	dv3.add(d6);
	dv3.add(d7);
	dv3.add(d8);
	dv3.add(d9);
	dv3.add(d10);
	dv3.add(d11);

	DynamicArray<Dog> dv4 = DynamicArray<Dog>();
	dv4 = dv3;

	assert(dv4.getSize() == 11);
	const string str1 = "aaa";
	int i = dv4.searchElement(str1);
	//	cout << i;
	assert(i == 0);

	dv4.updateElement(0, "bbc", "aaa", 12, "ph1");
	assert(dv4[0].getName() == "aaa");


	assert(dv4.getArray()[0].getAge() == 12);
	DynamicArray<Dog> dv5 = DynamicArray<Dog>();
	dv5.add(Dog("asa", "asda", 12, "asdsa"));
	dv4 = dv4 + dv5;
	assert(dv4.getSize() == 12);
	//dv4 = dv4 + Dog("22", "34f", 1, "fre");
	//dv4 = Dog("22", "34f", 1, "fre") + dv4;

	dv4.deleteElement(10);
	assert(dv4.getSize() == 11);
	assert(dv4.searchElement("sdsdwefrege") == -1);
}

void Tests::testController()
{
	Controller c = Controller();
	Repository r = Repository();

	Dog d1 = Dog("fsd", "aada", 12, "ph1");
	Dog d2 = Dog("afsdfdsbc", "argergaa", 12, "ph1");
	Dog d3 = Dog("aebc", "name2", 12, "ph1");
	Dog d4 = Dog("adsbc", "sf", 12, "ph1");
	Dog d5 = Dog("abaaac", "32", 12, "ph1");
	Dog d6 = Dog("abvvc", "6543", 12, "ph1");
	Dog d7 = Dog("abccc", "134", 12, "ph1");
	Dog d8 = Dog("abwwc", "name22", 12, "ph1");
	Dog d9 = Dog("aqwbc", "54", 12, "ph1");
	Dog d10 = Dog("abcre", "123", 12, "ph1");
	c.add(d1);
	c.add(d2);
	c.add(d3);
	c.add(d4);
	c.add(d5);
	c.add(d6);
	c.add(d7);
	c.add(d8);
	c.add(d9);
	c.add(d10);
	c.add(d1);

	try
	{
		r.searchBreed("name2");
	}
	catch (InvalidBreedException& e)
	{
		assert(true);
	}

	try
	{
		r.add(d1);
		r.searchBreed("fsd");
	}
	catch (InvalidBreedException& e)
	{
		assert(false);
	}

	cout << d1;

	assert(c.add(d1) == false);
	
	assert(c.remove("efihowi") == false);
	c.remove("wgwrgvsd");
	try
	{
		c.remove("NaMeEeE");
	}
	catch (NameNotFoundException& e)
	{
		assert(true);
	}
	
	assert(c.nameExists("name2") != -1);
	assert(c.getDogs().size() == 10);
	c.addAdoption(d1);
	assert(c.addAdoption(d1) == false);
	
	c.addAdoption(d1);

	c.addAdoption(d2);
	assert(c.getAdoptions().size() == 2);



	c.remove("123");
	assert(c.getDogs().size() == 9);

	assert(c.update("name2", "newName", "breeeed", 4, "picccc") == 1);
	/*
	try
	{
		c.update("name2", "newName2", "br", 5555, "pics");
	}
	catch (InvalidInputException& e)
	{
		assert(true);
	}*/
	
	try
	{
		c.update("nameeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", "newName2", "br", 5555, "pics");
	}
	catch (NameNotFoundException& e)
	{
		assert(true);
	}
	catch (InvalidInputException& e)
	{
		assert(true);
	}
	catch(InvalidAgeException& e)
	{
		assert(true);
	}
	/*
	catch (InvalidBreedException& e)
	{
		assert(true);
	}*/

	assert(c.getDogs()[2].getName() == "newName");
	


}

void Tests::testDog()
{
	Dog dog1 = Dog("abc", "aaa", 12, "ph1");
	assert(dog1.getName() == "aaa");
	assert(dog1.getBreed() == "abc");
	assert(dog1.getAge() == 12);
	assert(dog1.getPic() == "ph1");

	dog1.setAge(10);
	dog1.setBreed("breed");
	dog1.setName("ana");
	dog1.setPic("photo");


	assert(dog1.getName() == "ana");
	assert(dog1.getBreed() == "breed");
	assert(dog1.getAge() == 10);
	assert(dog1.getPic() == "photo");



}

void Tests::testRepo()
{
	Repository r = Repository();
	r.add(Dog("breed", "name", 1, "photo"));
	assert(r.size() == 1);
}




void Tests::runAll()
{
	testDog();
	testDynamicArray();
	testController();
	testRepo();

	Validator::validatePic("");
	/*
	try
	{
		Validator::validateDog(Dog("aaab", "bbbc", 77777, "picd"));
	}
	catch (InvalidInputException& e)
	{
		assert(true);
	}*/
	
}

Tests::~Tests()
{
}
