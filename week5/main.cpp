#include <iostream>
#include "vendingmachine.h"
#include <cstring>

int ID = 0;

void Inventory::changeSalty(int quantity)
{
	this->salty += quantity;
}

void Inventory::changeSweets(int quantity)
{
	this->sweet += quantity;
}

void Inventory::changeDrinks(int quantity)
{
	this->drinks += quantity;
}

void Inventory::print()
{
	std::cout << "Salty: " << this->salty << std::endl
		<< "Sweet: " << this->sweet << std::endl
		<< "Drinks: " << this->drinks << std::endl;
				
}


VendingMachine::VendingMachine()
{
	 id = ID++;
	 address = new char[100];
	 inventory.salty = 0;
	 inventory.sweet = 0;
	 inventory.drinks = 0;
	 capacity = 10;
	 warningMessages = new char* [capacity];
	 numWarningMsgs = 0;
}

VendingMachine::VendingMachine(char* address, Inventory inventory)
{
	id = ID++;
	this->address = new char[strlen(address)];
	strcpy(this->address, address);
	this->inventory.salty = inventory.salty;
	this->inventory.sweet = inventory.sweet;
	this->inventory.drinks = inventory.drinks;
	capacity = 10;
	warningMessages = new char* [capacity];
	numWarningMsgs = 0;
}

VendingMachine::VendingMachine(VendingMachine const& other)
{
	this->id = other.id;
	strcpy(this->address, other.address);
	this->inventory = other.inventory;
	for (int i = 0; i < 10; i++)
	{
		strcpy(this->warningMessages[i], other.warningMessages[i]);
	}
	this->numWarningMsgs = other.numWarningMsgs;
	this->capacity = other.capacity;
}

VendingMachine::VendingMachine(VendingMachine&& other)
{
	this->id = other.id;
	other.id = -1;
	strcpy(this->address, other.address);
	other.address = nullptr;
	this->inventory = other.inventory;
	other.inventory.salty = 0;
	other.inventory.sweet = 0;
	other.inventory.drinks = 0;
	for (int i = 0; i < 10; i++)
	{
		strcpy(this->warningMessages[i], other.warningMessages[i]);
		other.warningMessages[i] = nullptr;
	}
	other.warningMessages = nullptr;
	this->numWarningMsgs = other.numWarningMsgs;
	this->capacity = other.capacity;
}

VendingMachine& VendingMachine::operator=(VendingMachine const& other)
{
	if (this != &other)
	{
		this->id = other.id;
		strcpy(this->address, other.address);
		this->inventory = other.inventory;
		for (int i = 0; i < 10; i++)
		{
			strcpy(this->warningMessages[i], other.warningMessages[i]);
		}
		this->numWarningMsgs = other.numWarningMsgs;
		this->capacity = other.capacity;
	}
	return *this;
}

VendingMachine::~VendingMachine()
{
	delete[] this->address;
	for (int i = 0; i < 10; i++)
	{
		delete[] warningMessages[i];
	}
	delete[] warningMessages;
}


int main()
{
	
}
