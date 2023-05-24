#pragma once
#include "chocolate.h"

class MilkChocolate : virtual public Chocolate<int>
{

private:

protected:
	double milkPercentage;
public:
	MilkChocolate(int ID, const double milkPercentage);

};
