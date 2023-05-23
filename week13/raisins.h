#include "chocolate.h"
#pragma once

template <typename T>
class RaisinsChoc :virtual public Chocolate<T>
{
	
protected:
	T chocID;
	double raisinsPercentage;
	RaisinsChoc(T id, const double raisinsPercentage);
	
};

template<typename T>
RaisinsChoc<T>::RaisinsChoc(T id, const double raisinsPercentage) :Chocolate(id)
{
	this->raisinsPercentage = raisinsPercentage;
}
