#pragma warning(disable: 4996)
#include "calendar.h"
#include <iostream>
#include "main.h"
#include <fstream>
#include <cstring>

User::User()
{
	this->username = nullptr;
	this->password = nullptr;
}

User::User(char* username, char* password)
{
	this->username = new char[strlen(username)];
	strcpy(this->username, username);
	this->username = new char[strlen(password)];
	strcpy(this->password, password);
}

User::User(User& const other)
{
	this->username = new char[strlen(other.username)];
	strcpy(this->username, other.username);
	this->username = new char[strlen(other.password)];
	strcpy(this->password, other.password);
}

User::~User()
{
	delete[] this->username;
	delete[] this->password;
}

User::User(User&& other)
{
	strcpy(this->username, other.username);
	other.username = nullptr;
	strcpy(this->username, other.password);
	other.password = nullptr;
}

User& User::operator=(User& other)
{
	strcpy(this->username, other.username);
	strcpy(this->username, other.username);

	return *this;
}

User& User::operator=(User&& other)
{
	if (this != &other)
	{
		strcpy(this->username, other.username);
		other.username = nullptr;
		strcpy(this->username, other.password);
		other.password = nullptr;
	}

	return *this;
}

void User::addUser(char* fileName)
{
	std::ofstream file(fileName, std::ofstream::app);

	file << this->username << " " << this->password << std::endl;
	
	file.close();
}

User User::readUser(char* fileName)
{
	std::ifstream file(fileName);

	User user;

	file.read((char*)&user, sizeof(user));

	file.close();

	return user;
}

int main()
{
	
}