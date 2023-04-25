#include <iostream>
#include "animal.h"
#include <cstring>
#pragma warning(disable : 4996)

Animal::Animal()
{
    this->name = nullptr;
    this->spieces = nullptr;
}

Animal::Animal(const char* name, const char* spieces)
{
    delete[] this->name;
    delete[] this->spieces;

    this->name = new char[strlen(name) + 1];
    this->spieces = new char[strlen(spieces) + 1];

    strcpy(this->name, name);
    strcpy(this->spieces, spieces);
}

Animal::Animal(Animal const& other)
{
    if (this != &other)
    {
        delete[] this->name;
        delete[] this->spieces;

        this->name = new char[strlen(other.name) + 1];
        this->spieces = new char[strlen(other.spieces) + 1];

        this->name = other.name;
        this->spieces = other.spieces;
    }
}

Animal& Animal::operator=(Animal const& other)
{
    if (this != &other)
    {
        delete[] this->name;
        delete[] this->spieces;

        this->name = new char[strlen(other.name) + 1];
        this->spieces = new char[strlen(other.spieces) + 1];

        this->name = other.name;
        this->spieces = other.spieces;
    }

    return *this;
}

Animal::~Animal()
{
    delete[] this->name;
    delete[] this->spieces;
}


char* Animal::getName()
{
    return this->name;
}

char* Animal::getSpieces()
{
    return this->spieces;
}


void Cat::talk()
{
    std::cout << this->getName() << " " << this->getSpieces() << std::endl;
}

void Dog::talk()
{
    std::cout << this->getName() << " " << this->getSpieces() << std::endl;
}

int main()
{
    Cat a("garry", "cat");
    Dog b("Kuche", "dog");

    Animal* arr[] = { &a,&b };

    for (int i = 0; i < 2; i++)
    {
        arr[i]->talk();
    }
}


