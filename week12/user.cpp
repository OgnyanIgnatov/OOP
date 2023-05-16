#include "user.h"
#include <cstring>
#include <utility>
#include <iostream>
#pragma warning(disable: 4996)

int User::id = 0;

void User::free()
{
	delete[] this->name;
	delete[] this->password;
}

void User::copy(const User& other)
{
	this->user_id = id++;
	this->name = new char[strlen(other.name)];
	this->password = new char[strlen(other.password)];

	strcpy(this->name, other.name);
	strcpy(this->password, other.password);
}

void User::move(User&& other)
{
	this->user_id = other.user_id;
	this->name = other.name;
	this->password = other.password;

	other.id = 0;
	other.name = nullptr;
	other.password = nullptr;
}

char* User::encrypt(const char* password)
{
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	for (int i = 0; i < strlen(password); i++)
	{
		char a = password[i] + 1;

		if (password[i] + 1 == '0')
		{
			a = '?';
		}
		if (password[i] + 1 == 'Z')
		{
			a = 'A';
		}
		if (password[i] + 1 == 'z')
		{
			a = 'a';
		}

		this->password[i] = a;
	}

	return this->password;
}

User::User(const char* name, const char* password)
{
	encrypt(password);

	this->user_id = id++;
	this->name = new char[strlen(name) + 1];

	strcpy(this->name, name);

}

User::User(const User& other)
{
	copy(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

User::User(User&& other)
{
	move(std::move(other));
}

User& User::operator=(User&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}
	return *this;
}

char* User::getName()
{
	return this->name;
}

char* User::getPassword()
{
	return this->password;
}

User::~User()
{
	this->id = 0;
	free();
}
