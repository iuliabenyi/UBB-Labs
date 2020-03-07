#pragma once
#include "Star.h"
#include "Astronomer.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
class Session
{
public:
	Session() {
		readAstronomers();
		readStars();
	}
	~Session() {
		writeStars();
	}

	vector<Astronomer> &getAstronomers() { return astronomers; }
	vector<Star> &getStars() { return stars; }
	
	void readStars() {
		ifstream f("star.txt");
		string name;
		string constellation;
		int RA;
		int dec;
		char separator;
		int diameter;

		while (getline(f, name, ';') && getline(f, constellation, ';') && f >> RA && f >> separator && f >> dec && f >> separator && f >> diameter && f>>separator)
			stars.emplace_back(Star(name, constellation, RA, dec, diameter));

	}

	void writeStars() {
		ofstream o("star.txt");
		for (auto &elem : getStars())
			o << elem.getName() << ';' << elem.getConstellation() << ';' << elem.getRa() << ';' << elem.getDec() << ';' << elem.getDiameter() << ';';
		o.close();
	}

	void readAstronomers() {
		ifstream f("astronomer.txt");
		string name;
		string constellation;

		while (getline(f, name, ';') && getline(f, constellation))
			astronomers.emplace_back(Astronomer(name, constellation));

	}

	int addStar(Star star)
	{
		if (star.getName() == "")
			return -1;
		for (auto &elem : stars)
			if (elem.getName() == star.getName())
				return -1;
		stars.emplace_back(star);
		return 1;
	}

	int matchingCharacters(string s1, string s2) {
		int len = s1.size() > s2.size() ? s2.size() : s1.size();
		int cnt = 0;
		for (int i = 0; i < len; ++i) {
			if (s1[i] == s2[i]) {
				++cnt;
			}
		}

		return cnt;
	}

	vector<Star> sortByMatchingCharacters(string input) {
		vector<Star> s = stars;
		sort(s.begin(), s.end(), [this, input](const Star &s1, const Star &s2) {
			return matchingCharacters(input, s1.getName()) > matchingCharacters(input, s2.getName());
		});

		return s;
	}

	vector<Star> sortByMatchingCharactersRA(string input) {
		vector<Star> s;
		if (input == "")
			return s;
		for (Star &st : stars)
			if (st.getRa() == stoi(input))
				s.emplace_back(st);
		return s;
	}

	vector<Star> sortByMatchingCharactersDec(string input) {
		vector<Star> s;
		if (input == "")
			return s;
		for (Star &st : stars)
			if (st.getDec() == stoi(input))
				s.emplace_back(st);
		return s;
	}


private:
	vector<Astronomer> astronomers;
	vector<Star> stars;

};

