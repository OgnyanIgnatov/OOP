#include "milkchoc.h"
#include <iostream>


MilkChocolate::MilkChocolate(int ID, const double milkPercantage) : Chocolate(ID)
{
	std::cout << "milkchoccon" << std::endl;
	this->milkPercentage = milkPercantage;
}
