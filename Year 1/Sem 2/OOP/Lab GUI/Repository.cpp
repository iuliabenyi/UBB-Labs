#include "Repository.h"
#include "FileManager.h"


/*
Repository::Repository()
{
	this->da = DynamicArray<Dog>(20);
	FileManager::loadFromFile(da);
}*/

Repository::~Repository()
{
}

void Repository::add(Dog e)
{
	v.emplace_back(e);
	if (load)
	{
		FileManager *f = new TextFileManager();
		//FileManager *f = new HTMLFileManager();
		f->writeToFile(v);
		//f->writeToFile(v, "outfile.html");
	}

}

int Repository::search(string e)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].getName() == e)
			return i;
	}

	return -1;
	//throw NameNotFoundException();
}

int Repository::searchBreed(string e)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].getBreed() == e)
			return i;
	}

	throw InvalidBreedException();
}

void Repository::remove(string name)
{
	int eIndex = search(name);
	if (eIndex != -1)
		v.erase(v.begin() + eIndex);
	/*
	v.erase(v.begin() + name);
	//da.deleteElement(da.searchElement(name));*/
	FileManager *f = new TextFileManager();
	//FileManager *f = new HTMLFileManager();
	f->writeToFile(v);
	//f->writeToFile(v, "outfile.html");
}


void Repository::update(string name, string newName, string breed, int age, string pic)
{
	int eIndex = search(name);
	if (eIndex != -1)
	{
		v[eIndex] = Dog(breed, newName, age, pic);
	}
	else
		throw NameNotFoundException();

	/*
	v.updateElement(v.searchElement(name), breed, newName, age, pic);*/
	//FileManager *f = new HTMLFileManager();
	FileManager *f = new TextFileManager();
	f->writeToFile(v);
	//f->writeToFile(v, "outfile.html");
}
/*
int Repository::search(string e)
{
	return v.searchElement(e);
}
*/

int Repository::size()
{
	return v.size();
}

vector<Dog> &Repository::getDogs()
{
	return v;
}

Repository::Repository(bool loadFiles) : load{ loadFiles }
{
	//this->v = DynamicArray<Dog>(20);
	if (loadFiles)
	{
		FileManager::loadFromFile(v);
		//FileManager *f = new HTMLFileManager();
		//f->exportHTML(v);
	}

}

//DynamicArray Repository::getAdoptions()
//{
//	return adoption;
//}