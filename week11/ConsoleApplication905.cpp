#include <iostream>
#include "myvector.h"

int main()
{
    MyVector<double> arr;

    arr.addElement(5.5);
    arr.addElement(5.7);
    arr.addElement(4.2);
    arr.addElement(9.3);

    arr.apply(addOne);

    for (int i = 0; i < 4; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;

    
}


