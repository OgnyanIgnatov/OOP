#include "user.h"
#include <cstring>

User::User()
{
    this->username = nullptr;
}

User::User(const char* username)
{
    delete[] this->username;
    this->username = new char[strlen(username) + 1];

    strcpy(this->username, username);
}

User::User(const User& other)
{
    if (this != &other)
    {
        delete[] this->username;
        this->username = new char[strlen(other.username) + 1];


        strcpy(this->username, other.username);
    }
}

User::User(User&& other)
{
    if (this != &other)
    {
        delete[] this->username;
        this->username = new char[strlen(other.username) + 1];


        strcpy(this->username, other.username);


        other.username = nullptr;
    }
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        delete[] this->username;
        this->username = new char[strlen(other.username) + 1];


        strcpy(this->username, other.username);
    }

    return *this;
}

User& User::operator=(User&& other)
{
    if (this != &other)
    {
        delete[] this->username;
        this->username = new char[strlen(other.username) + 1];


        strcpy(this->username, other.username);


        other.username = nullptr;
    }
    return *this;
}

User::~User()
{
    delete[] this->username;
}


