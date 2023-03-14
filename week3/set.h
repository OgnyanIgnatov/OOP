#ifndef SET_H
#define SET_H



class Set
{
	int numElements;
	int capacity;
	int* arr;
	void resizeArr();
	void copy(int const* arr, int numElements, int capacity);

public:

	Set();
	Set(Set const& other);
	~Set();
	Set operator=(Set const& other);
	bool addElement(const int element);
	bool deleteElement(const int element);
	void print();
	void setUnion(Set const& other);
	void setIntersection(Set const& other);
};



#endif
