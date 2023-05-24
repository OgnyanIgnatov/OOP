#include "milkraisins.h"
#include <iostream>

bool MilkRaisins::isValid(int ID)
{
	int a = 0;
	while (ID/=10 != 0)
	{
		a += ID % 10;
		a *= 10;
		ID /= 10;
	}
	a /= 10;
	std::cout << a % 100 << std::endl;
	if (a % 100 == 54)
	{
		return true;
	}

	return false;

}



MilkRaisins::MilkRaisins(int ID, double milkPercentage, double raisinsPercentage):Chocolate(-1), MilkChocolate(-1,-1), RaisinsChoc(-1, -1)
{	
	std::cout << "milkraisins" << std::endl;
	if (isValid(ID))
	{
		this->chocID = ID;
		this->milkPercentage = milkPercentage;
		this->raisinsPercentage = raisinsPercentage;
	}
	else throw "invalid id";
	
	
}
