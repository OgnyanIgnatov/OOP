#include "chocolate.h"
#include <iostream>
#pragma once

template <typename T>
class RaisinsChoc :virtual public Chocolate<T>
{
	
protected:
	double raisinsPercentage;
public:

	RaisinsChoc(T id, const double raisinsPercentage);
	
};

template<typename T>
RaisinsChoc<T>::RaisinsChoc(T id, const double raisinsPercentage) :Chocolate<T>::Chocolate(id)
{
	std::cout << "raisins" << std::endl;
	this->raisinsPercentage = raisinsPercentage;
}
