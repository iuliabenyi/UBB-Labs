#pragma once

//#include "DynamicArray.h"
#include "Dog.h"
#include <string>
#include <vector>

using namespace std;

class FileManager
{
public:
	FileManager() = default;
	virtual ~FileManager() = default;

	static void loadFromFile(vector<Dog>& vec);

	virtual void writeToFile(const vector<Dog>& vec) = 0;

	virtual void startFile() = 0;
	/*
	static void loadFromFile(vector<Dog> &v);
	static void writeToFile(vector<Dog> &v);
	void exportHTML(const vector<Dog>& vec);*/
};

class TextFileManager : public FileManager {
public:
	TextFileManager() = default;

	void writeToFile(const vector<Dog>& vec) override;
	void startFile() override;
};

class HTMLFileManager : public FileManager {
public:
	HTMLFileManager() = default;

	void writeToFile(const vector<Dog>& vec) override;
	void startFile() override;
};
