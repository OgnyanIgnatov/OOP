#include <iostream>
#include "milkraisins.h"
#include "raisins.h"
#include "blackchoc.h"
#include "chocolate.h"
#include "milkchoc.h"
#include "blackraisins.h"

int main()
{
    MilkRaisins a(45, 17.5, 5);
    std::cout << a.getID();
    BlackRaisins b("NZ", 55, 9);
    std::cout << b.getID();

    
}


