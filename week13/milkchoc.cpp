#include "milkchoc.h"

MilkChocolate::MilkChocolate() : Chocolate(-1)
{
	this->milkPercentage = -1;
}

MilkChocolate::MilkChocolate(int ID, const double milkPercantage) : Chocolate(ID)
{
	this->milkPercentage = milkPercantage;
}