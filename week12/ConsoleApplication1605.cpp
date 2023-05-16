#include <iostream>
#include "user.h"
#pragma warning(disable: 4996)


int main()
{
    char o[] = "1234";
    User a("Pesho", o);
    char* b = a.getName();
    char* c = a.getPassword();
    for (int i = 0; i < strlen(a.getName()); i++)
    {
        std::cout << b[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << c[i];
    }
    
}

