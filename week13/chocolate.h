#pragma once


template <typename T>
class Chocolate
{

protected:

	T chocID;
	Chocolate(T id);
public:
	
};


template <typename T>
Chocolate<T>::Chocolate(T id)
{
	this->chocID = id;
}