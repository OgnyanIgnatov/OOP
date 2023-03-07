#ifndef SET_H
#define SET_H



class Set
{
	int capacity;
	int* arr;


public:

	Set();
	void resizeArr();
	bool addElement(const int element);
	bool deleteElement(const int element);
	void print();
	void setUnion(const Set other);
	void setIntersection(const Set other);
};



#endif
