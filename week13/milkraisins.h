#include "raisins.h"
#include "milkchoc.h"
#include "chocolate.h"

#pragma once

class MilkRaisins :public MilkChocolate, public RaisinsChoc<int>
{
private:
	bool isValid(int ID);
public:
	MilkRaisins(int ID, double milkPercentage, double raisinsPercentage);
};
