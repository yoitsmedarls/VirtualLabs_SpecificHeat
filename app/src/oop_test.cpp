#include <iostream>
#include "Liquid.hpp"
#include "Substance.hpp"

int main()
{
    Liquid water = Liquid("Water", 100, 25, 4186, 1, 100, 0);
    Substance mySubstance = Substance("My Substance", 100, 24, 4231, 1);

    std::cout << &water << std::endl;
    std::cout << sizeof(water) << std::endl;
    std::cout << sizeof(mySubstance) << std::endl;

    water.printProperties();
    mySubstance.printProperties();

    return EXIT_SUCCESS;
}