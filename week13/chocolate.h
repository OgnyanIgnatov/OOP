#include <iostream>
#pragma once


template <typename T>
class Chocolate
{

protected:

	T chocID;
	Chocolate(T id);
public:
	
	T getID();
};


template <typename T>
Chocolate<T>::Chocolate(T id)
{
	std::cout << "choccons" << std::endl;
	this->chocID = id;
}

template<typename T>
inline T Chocolate<T>::getID()
{
	return this->chocID;
}
