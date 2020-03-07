#pragma once
#include <fstream>
#include <vector>
#include "User.h"
#include <string>

class UserRepository
{
public:
	UserRepository();
	~UserRepository();

	vector<User> &getUsers() { return  users; }

private:
	vector<User> users;
};

