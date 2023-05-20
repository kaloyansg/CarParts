#include <iostream>
#include "CarPart.h"
#include <array>
#include "Tire.h"
#include "Engine.h"
#include "Accumulator.h"

int main()
{
    /*try
    {
        CarPart a;
        a.print();

        CarPart b("Kolio", "Mnogo dobur");
        b.print();

        CarPart c = b;
        c.print();

        c = a;
        c.print();
    }
    catch (const std::bad_alloc& badAllocExeption)
    {
        std::cout << "Not enough memory!" << std::endl;
    }
    catch (const char* errorr)
    {
        std::cout << errorr << std::endl;
    }*/

    Accumulator a;
    std::cout << a <<std::endl;

    int array[4];
    for (size_t i = 0; i < 4; i++)
    {
        array[i] = i + 1;
    }
    Accumulator b("Kolio", "Mnogo dobur", 8, array, 4);
    std::cout << b << std::endl;

    Accumulator c = b;
    std::cout << c << std::endl;

    a = b;
    std::cout << a << std::endl;

    return 0;
}
