#include "UserRepository.h"



UserRepository::UserRepository()
{
	ifstream f("user.txt");
	string name;

	while (getline(f, name, ';'))
	{
		auto user = User(name);
		users.emplace_back(user);
	}
	f.close();
}


UserRepository::~UserRepository()
{
	ofstream o("user.txt");
	for (auto &u : getUsers())
		o << u.getName() << ';';
	o.close();
}
