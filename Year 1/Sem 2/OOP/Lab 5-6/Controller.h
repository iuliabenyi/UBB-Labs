#pragma once
#include "Validator.h"
#include "Repository.h"
#include "Comparator.h"
#include <string>
#include <vector>
#include <exception>
#include "FileManager.h"

class Controller
{
	public:
		Controller(bool = false);
		~Controller();

		bool add(T e);
		bool addAdoption(T e);
		bool remove(string name);
		bool update(string name, string newName, string breed, int age, string pic);
		bool nameExists(string name);
		void sortWComparator(Comparator<T>& comp);
		vector<Dog> getFilteredDogs(string breed, int age);
		vector<Dog> &getDogs();
		vector<Dog> getAdoptions();
		void setFileManager(FileManager *fm);
		void startFile();
		

	private:
		Repository repo;
		vector<Dog> adoption;
		FileManager *fm;
};

