#include "blackchoc.h"
#include <iostream>

bool BlackChocolate::isValid(const std::string ID) const
{
	for (int i = 0; i < ID.size(); i++)
	{
		const char* a = &ID[i];
		if (a < "A" || a > "z")
		{
			return false;
		}
	}
	return true;

}

BlackChocolate::BlackChocolate(const std::string ID, const double cacaoPercantage) : Chocolate("Default")
{
	std::cout << "blackchoccons" << std::endl;
	if (isValid(ID))
	{
		this->chocID = ID;
	}
	this->cacaoPercentage = cacaoPercantage;
}
