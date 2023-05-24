#include "chocolate.h"
#include <string>
#pragma once


class BlackChocolate :virtual public Chocolate<std::string>
{

private:
	
	bool isValid(const std::string ID) const;

protected:
	double cacaoPercentage;
public:
	BlackChocolate(const std::string ID, const double cacaoPercentage);
};
