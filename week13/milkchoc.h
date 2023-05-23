#pragma once
#include "chocolate.h"

class MilkChocolate : virtual public Chocolate<int>
{

private:
	double milkPercentage;
	
public:
	MilkChocolate();
	MilkChocolate(int ID, const double milkPercentage);

};
