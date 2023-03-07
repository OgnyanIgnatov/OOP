#include <iostream>
#include "set.h"

Set::Set()
{	
	int capacity;
	int* arr = new int[capacity];
};

void Set::resizeArr()
{
	this->capacity *= 2;
	int* copyArr = new int[this->capacity];
	for (int i = 0; i < this->capacity/2; i++)
	{
		copyArr[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = copyArr;
}

bool Set::addElement(const int element)
{
	bool a = false;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == element)
		{
			return a;
		}
	}

	if (!a)
	{
		a = true;
		
	}
}

bool Set::deleteElement(const int element)
{
	bool a = false;

	for (int i = 0; i < capacity; i++)
	{
		if (arr[i] == element)
		{
			delete arr[i];
			return !a;
		}
	}

	return a;
}













int main()
{

}
