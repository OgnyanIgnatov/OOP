#include "chocolate.h"
#include <string>
#pragma once


class BlackChocolate :virtual public Chocolate<std::string>
{

private:
	double cacaoPercentage;
	bool isValid(const std::string ID) const;

public:
	BlackChocolate();
	BlackChocolate(const std::string ID, const double cacaoPercentage);
};
