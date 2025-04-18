#include <iostream>
#include "set.h"
int const INITIAL_CAPACITY = 10;

void Set::copy(int const* arr, int numElements, int capacity)
{
	this->capacity = capacity;
	this->numElements = numElements;

	if (this->arr != nullptr)
	{
		delete[] this->arr;
	}
	this->arr = new int[this->capacity];
	for (int i = 0; i < this->numElements; i++)
	{
		this->arr[i] = arr[i];
	}
}

Set::Set()
{
	this->numElements = 0;
	this->capacity = INITIAL_CAPACITY;
	this->arr = new int[this->capacity];
};

Set::Set(Set const& other)
{
	this->copy(other.arr, other.numElements, other.capacity);
}

Set Set::operator=(Set const& other)
{
	if (this != &other)
	{
		this->copy(other.arr, other.numElements, other.capacity);
	}

	return *this;
}

Set::~Set()
{
	delete[] this->arr;
}

void Set::resizeArr()
{
	this->capacity *= 2;
	int* copyArr = new int[this->capacity];
	for (int i = 0; i < this->capacity / 2; i++)
	{
		copyArr[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = copyArr;
}

bool Set::addElement(const int element)
{
	if (this->numElements == this->capacity)
	{
		this->resizeArr();
	}

	for (int i = 0; i < this->numElements; i++)
	{
		if (arr[i] == element)
		{
			return false;
		}
	}
	this->arr[this->numElements] = element;
	this->numElements--;
	return true;
}

bool Set::deleteElement(const int element)
{
	for (int i = 0; i < capacity; i++)
	{
		if (arr[i] == element)
		{
			for (int j = i + 1; j < this->numElements; i++)
			{
				this->arr[j - 1] = this->arr[j];
			}
			this->numElements--;
		}
	}

	return false;
}

void Set::setUnion(Set const& other)
{
	for (int i = 0; i < this->numElements; i++)
	{
		this->addElement(other.arr[i]);
	}
}

void Set::setIntersection(Set const& other)
{
	for (int i = 0; i < this->numElements; i++)
	{
		int j = 0;
		while (j < other.numElements && this->arr[i] != other.arr[j])
		{
			j++;
		}
		if (j == other.numElements)
		{
			this->deleteElement(this->arr[i]);
			i--;
		}
	}
}

void Set::print()
{
	for (int i = 0; i < this->numElements; i++)
	{
		std::cout << this->arr[i] << " ";
	}
	std::cout << std::endl;
}


int main()
{

}
