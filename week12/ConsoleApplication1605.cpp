#include <iostream>
#include "user.h"
#pragma warning(disable: 4996)


int main()
{
    User a("Pesho", "1234");
    char* b = a.getName();
    char* c = a.getPassword();
    for (int i = 0; i < 5; i++)
    {
        std::cout << b[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << c[i];
    }

}
