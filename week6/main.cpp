#include <iostream>
#include "string.h"
#include <cstring>

int String::getLenght()
{
    return strlen(this->str);
}

bool String::empty()
{
    if (this->str == nullptr)
    {
        return 1;
    }
    return 0;
}

const char* String::c_str()
{
    char* arr = new char[getLenght()];
    for (int i = 0; i < getLenght(); i++)
    {
        arr[i] = this->str[i];
    }
    return arr;
}


String::String()
{
    this->str = nullptr;
}

String::String(const char* other)
{
    this->str = new char[strlen(other)];
    strcpy(this->str, other);
}

String::String(String const& other)
{
    strcpy(this->str, other.str);
}

String::String(String&& other)
{
    strcpy(this->str, other.str);
    other.str = nullptr;
}

String::~String()
{
    delete[] this->str;
}

String& String::operator=(const char* other)
{
    if (this->str != other)
    {
        strcpy(this->str, other);
    }
    return *this;
}

String& String::operator=(String const& other)
{
    if (this != &other)
    {
        strcpy(this->str, other.str);
    }
    return *this;
}

String& String::operator=(String&& other)
{
    strcpy(this->str, other.str);
    other.str = nullptr;
    return *this;
}

char String::operator[](int index)
{
    if (index >= this->getLenght() && index < 0)
    {
        return 0;
    }
    return this->str[index];
}

String String::operator+(String& other)
{
    char* arr = new char[getLenght() + other.getLenght()];
    for (int i = 0; i < getLenght();i++)
    {
        arr[i] = this->str[i];
    }
    for (int j = getLenght(); j < other.getLenght(); j++)
    {
        arr[j] = other.str[j - getLenght()];
    }

    String ob;
    ob.str = arr;
    return ob;
}

int main()
{
    std::cout << "Hello World!\n";
}

