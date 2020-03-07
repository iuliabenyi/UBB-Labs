#include "FileManager.h"

void FileManager::loadFromFile(vector<Dog> & v)
{
	ifstream in("file.txt");
	Dog dog;
	while (in >> dog)
	{
		v.emplace_back(dog);
	}
}

void TextFileManager::writeToFile(const vector<Dog> &vec) {
	ofstream out("file.txt");
	for (const auto& Dog : vec) {
		string output;
		output += Dog.getName() + ",";
		output += to_string(Dog.getAge()) + ",";
		output += Dog.getBreed() += ",";
		output += Dog.getPic();
		out << output << endl;
	}
}

void TextFileManager::startFile()
{
	printf("textfile opened");
	system("start file.txt");
}

void HTMLFileManager::writeToFile(const vector<Dog> &vec) {
	ofstream out("outfile.html");
	out << "<!DOCTYPE html>" << endl;
	out << "<html>" << endl;
	out << "<head><title>Pet list</title></head>" << endl;
	out << "<body style=\"background-color:powderblue;\"><table border=\"1\">" << endl;

	out << "<tr>" << endl;
	out << "<td>Breed</td>" << endl;
	out << "<td>Name</td>" << endl;
	out << "<td>Age</td>" << endl;
	out << "<td>Photo</td>" << endl;
	out << "</tr>" << endl;

	for (const auto& Dog : vec) {
		out << "<tr>" << endl;
		out << "<td>" << Dog.getName() << "</td>" << endl;
		out << "<td>" << Dog.getAge() << "</td>" << endl;
		out << "<td>" << Dog.getBreed() << "</td>" << endl;
		out << "<td>" << Dog.getPic() << "</td>" << endl;
		out << "</tr>" << endl;
	}

	out << "</table>" << endl;
	out << "</body>" << endl;
	out << "</html>" << endl;
}

void HTMLFileManager::startFile()
{
	printf("htmlfile opened");
	system("start outfile.html");
}
