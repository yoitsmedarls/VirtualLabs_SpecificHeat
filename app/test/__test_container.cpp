#include <iostream>
#include "Substance.hpp"
#include "Liquid.hpp"
#include "Metal.hpp"
#include "Container.hpp"

int main()
{
    Substance mySubstance = Substance("My Substance", 100, 24, 4231, 1);
    Liquid water = Liquid("Water", 100, 25, 4186, 1, 100, 0);
    Metal aluminum = Metal("Aluminum", 50, 20, 903, 2.7);
    Container myContainer = Container("MyContainer", 5, 7, water, aluminum);

    std::cout << std::endl;

    mySubstance.printProperties();
    std::cout << " Address: " << &mySubstance << "\n"
              << " Size (bytes): " << sizeof(mySubstance) << "\n";
    std::cout << std::endl;

    water.printProperties();
    std::cout << " Address: " << &water << "\n"
              << " Size (bytes): " << sizeof(water) << "\n";
    std::cout << std::endl;

    aluminum.printProperties();
    std::cout << " Address: " << &aluminum << "\n"
              << " Size (bytes): " << sizeof(aluminum) << "\n";
    std::cout << std::endl;

    water.setMass(1000);
    water.setDensity(2);

    aluminum.setMass(4000);
    aluminum.setTemperature(723);

    myContainer.printProperties();
    std::cout << " Address: " << &myContainer << "\n"
              << " Size (bytes): " << sizeof(myContainer) << "\n";
    std::cout << std::endl;

    myContainer.getContainedLiquid()->printProperties();
    std::cout << std::endl;

    myContainer.getContainedMetal()->printProperties();
    std::cout << std::endl;

    return EXIT_SUCCESS;
}