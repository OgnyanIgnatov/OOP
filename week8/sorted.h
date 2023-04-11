#ifndef SORTED_H
#define SORTED_H

template <typename T>
class Sorted
{
	T* arr;
	int capacity;
	int size;

public:
	void resize();
	Sorted();
	Sorted(Sorted<T>& other);
	~Sorted();
	Sorted<T>& operator=(Sorted<T>& other);
	Sorted(Sorted<T>&& other);
	Sorted<T>& operator=(Sorted<T>&& other);
	bool add(T& elem);
	bool remove(T& elem);
	void print();

};

template <typename T>
void Sorted<T>::resize()
{
	this->capacity *= 2;
	T* copyArr = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		copyArr[i] = this->arr[i];
	}

	delete[] this->arr;
	this->arr = copyArr;
}

template <typename T>
Sorted<T>::Sorted()
{
	this->capacity = 4;
	this->size = 0;
	this->arr = new T[capacity];
}

template <typename T>
Sorted<T>::Sorted(Sorted<T>& other)
{
	this->capacity = other.capacity;
	this->size = other.size;

	this->arr = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

template <typename T>
Sorted<T>::~Sorted()
{
	delete[] this->arr;
}

template <typename T>
Sorted<T>& Sorted<T>::operator=(Sorted<T>& other)
{
	if(this != &other)
	{
		this->capacity = other.capacity;
		this->size = other.size;

		this->arr = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}
	
	return this;

}

template <typename T>
Sorted<T>::Sorted(Sorted<T>&& other)
{
	this->capacity = other.capacity;
	this->size = other.size;

	this->arr = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = other.arr[i];
	}

	delete[] other.arr;
}

template <typename T>
Sorted<T>& Sorted<T>::operator=(Sorted<T>&& other)
{
	if (this != &other)
	{
		this->capacity = other.capacity;
		this->size = other.size;

		this->arr = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = other.arr[i];
		}

		delete[] other.arr;
	}

	return this;
}

template <typename T>
bool Sorted<T>::add(T& elem)
{
	if (this->size == this->capacity)
	{
		this->resize();
	}

	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] == elem)
		{
			return false;
		}
		std::cout << "in for" << std::endl;
	}

	this->arr[this->size] = elem;
	this->size++;
	return true;
}

template <typename T>
bool Sorted<T>::remove(T& elem)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] == elem)
		{
			for (int j = i + 1; j < this->size; j++)
			{
				this->arr[j - 1] = this->arr[j];
			}
			this->size--;
			return true;
		}
	}
	return false; 
}

template <typename T>
void Sorted<T>::print()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << std::endl;
	}
}


#endif
