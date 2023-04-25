#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
	char* name;
	char* spieces;

public:
	char* getName();
	char* getSpieces();
	Animal();
	Animal(const char* name, const char* spieces);
	Animal(Animal const& other);
	Animal& operator=(Animal const& other);
	~Animal();

	virtual void talk() = 0;

};

class Cat : public Animal
{

public:	
	Cat(const char* name, const char* spieces) : Animal(name, spieces) {};
	virtual void talk();
};

class Dog : public Animal
{
public:
	Dog(const char* name, const char* spieces) : Animal(name, spieces) {}
	virtual void talk();
};


#endif 

