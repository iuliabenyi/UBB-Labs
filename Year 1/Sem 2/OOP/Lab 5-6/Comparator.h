#pragma once
#include "Dog.h"

template <class T>
class Comparator {
public:
	virtual bool compare(const T &d1, const T &d2) const = 0;
};

//template <class T>
class CompareAscendingByName : public Comparator<Dog> {
public:
	bool compare(const Dog &d1, const Dog &d2) const override {
		return d1.getName() > d2.getName();
	}
};

//template <class T>
class CompareAscendingByAge : public Comparator<Dog> {
public:
	bool compare(const Dog &d1, const Dog &d2) const override {
		return d1.getAge() > d2.getAge();
	}
};