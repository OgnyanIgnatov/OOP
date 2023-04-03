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

int Inventory::getSalty()
{
	return this->salty;
}

int Inventory::getSweet()
{
	return this->sweet;
}

int Inventory::getDrinks()
{
	return this->drinks;
}

int VendingMachine::getID()
{
	return this->id;
}

char* VendingMachine::getAddress()
{
	return this->address;
}

Inventory VendingMachine::getInventory()
{
	return this->inventory;
}

char** VendingMachine::getWarningMessages()
{
	return this->warningMessages;
}

VendingMachine::VendingMachine()
{
	id = ID++;
	address = nullptr;
	inventory.salty = 0;
	inventory.sweet = 0;
	inventory.drinks = 0;
	capacity = 10;
	warningMessages = { nullptr };
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

void VendingController::resize()
{
	capacity *= 2;
	VendingMachine* copy = new VendingMachine[capacity];
	for (int i = 0; i < capacity; i++)
	{
		copy[i] = this->vendingMachineList[i];
	}
	delete[] vendingMachineList;
	vendingMachineList = copy;
}

VendingController::VendingController()
{
	capacity = 10;
	numMachines = 0;
	vendingMachineList = new VendingMachine[capacity];
}

VendingController::VendingController(int capacity, int numMachines)
{
	this->capacity = capacity;
	this->numMachines = numMachines;
	vendingMachineList = new VendingMachine[this->capacity];
}

VendingController::VendingController(VendingController const& other)
{
	this->capacity = other.capacity;
	this->numMachines = other.numMachines;
	for (int i = 0; i < capacity; i++)
	{
		this->vendingMachineList[i] = other.vendingMachineList[i];
	}

}

VendingController::~VendingController()
{
	delete[] vendingMachineList;
}

void VendingController::addVendingMachine(VendingMachine machine)
{
	if (this->numMachines == this->capacity)
	{
		this->resize();
	}

	for (int i = 0; i < this->numMachines; i++)
	{
		if (i == machine.getID() && vendingMachineList[i].getID() != machine.getID())
		{
			vendingMachineList[i] = machine;
		}
	}
}

char* VendingController::getAddressOfMachine(int machineID)
{
		for (int i = 0; i < numMachines; i++)
		{
			if (vendingMachineList[i].getID() == machineID)
			{
				return vendingMachineList[i].getAddress();
			}
		}

		return;
}


Inventory VendingController::getInventoryOfMachine(int machineID)
{
	for (int i = 0; i < numMachines; i++)
	{
		if (vendingMachineList[i].getID() == machineID)
		{
			return vendingMachineList[i].getInventory();
		}
	}

	return;
}

void VendingController::sellProductInMachine(int machineID, char* product)
{
	for (int i = 0; i < numMachines; i++)
	{
		if (vendingMachineList[i].getID() == machineID)
		{
			if (product[1] == 'a')
			{
				vendingMachineList[i].getInventory().changeSalty(-1);
			}
			if (product[1] == 'w')
			{
				vendingMachineList[i].getInventory().changeSweets(-1);
			}
			if (product[0] == 'd')
			{
				vendingMachineList[i].getInventory().changeDrinks(-1);
			}
		}
	}
}

void VendingController::restockProductInMachine(int machineID, char* product)
{
	for (int i = 0; i < numMachines; i++)
	{
		if (vendingMachineList[i].getID() == machineID)
		{
			if (product[1] == 'a')
			{
				vendingMachineList[i].getInventory().changeSalty(1);
			}
			if (product[1] == 'w')
			{
				vendingMachineList[i].getInventory().changeSweets(1);
			}
			if (product[0] == 'd')
			{
				vendingMachineList[i].getInventory().changeDrinks(1);
			}
		}
	}
}

void VendingController::seeWarningMsgForMachine(int machineID)
{
	for (int i = 0; i < numMachines; i++)
	{
		if (vendingMachineList[i].getID() == machineID)
		{
			for(int j=0;j<)
		}
	}
}


int main()
{

}
