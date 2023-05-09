#pragma once

int INIT_CAP = 8;

template <class T>
class MyVector
{
	int capacity;
	int count;
	T* arr;

	void free();
	void copy(const MyVector& other);
	void move(MyVector&& other); 

public:
	MyVector();
	MyVector(const MyVector& other);
	MyVector<T>& operator=(const MyVector& other);
	~MyVector();

	MyVector(MyVector&& other);
	MyVector<T>& operator=(MyVector&& other);

	T& operator[](const int index);

	void resize();
	void addElement(const T& element);

	template <typename R>
	void apply(R(*func)(T&));

	friend std::ostream& operator<<(std::ostream& os, const MyVector<T>& el);
};

double addOne(double& a)
{
	return ++a;
}

template<class T>
void MyVector<T>::free()
{
	delete[] arr;
}

template <class T>
void MyVector<T>::copy(const MyVector& other)
{
	this->capacity = other.capacity;
	this->count = other.count;

	this->arr = new T[capacity];

	for (int i = 0; i < count; i++)
	{
		this->arr[i] = other.arr[i];
	}


}

template <class T>
void MyVector<T>::move(MyVector&& other)
{
	this->capacity = other.capacity;
	this->count = other.count;
	this->arr = other.arr;

	other.arr = nullptr;
}

template <class T>
MyVector<T>::MyVector()
{
	capacity = INIT_CAP;
	count = 0;
	arr = new T[INIT_CAP];
}

template <class T>
MyVector<T>::MyVector(const MyVector& other)
{
	copy(other);
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	if (this != &other)
	{
		this->free();
		this->copy(other);
	}

	return *this;
}

template <class T>
MyVector<T>::~MyVector()
{
	delete[] this->arr;
}

template <class T>
MyVector<T>::MyVector(MyVector&& other)
{
	move(std::move(other));
}

template <class T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other)
{
	if (this != &other)
	{
		this->free();
		this->move(std::move(other));
	}
	return *this;
}

template<class T>
T& MyVector<T>::operator[](const int index)
{
	return this->arr[index];
}

template <class T>
void MyVector<T>::resize()
{
	if (count == capacity)
	{
		capacity *= 2;

		T* newArr = new T[capacity];

		for (int i = 0; i < count; i++)
		{
			newArr[i] = this->arr[i];
		}

		this->free();
		this->arr = newArr;

	}

}

template <class T>
void MyVector<T>::addElement(const T& element)
{
	if (count == capacity)
	{
		this->resize();
	}

	this->arr[count] = element;
	count++;
}

template<class T>
template<typename R>
void MyVector<T>::apply(R(*func)(T&))
{
	for (int i = 0; i < count; i++)
	{
		func(arr[i]);
	}
}

template <class T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& el)
{
	for (int i = 0; i < el.count; i++)
	{
		os << el.arr[i];
	}

	return os;
}

