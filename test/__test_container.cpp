#include <iostream>
#include "Substance.hpp"
#include "Liquid.hpp"
#include "Metal.hpp"
#include "Container.hpp"

int main()
{
    Liquid water = Liquid("Water", 100, 1, 25, 4.186, 100, 0);
    Metal aluminum = Metal("Aluminum", 50, 2.7, 20, 0.903);
    Container myContainer = Container("MyContainer", 5, 7);

    std::cout << std::endl;

    water.printProperties();
    std::cout << " Address: " << &water << "\n"
              << " Size (bytes): " << sizeof(water) << "\n";
    std::cout << std::endl;

    aluminum.printProperties();
    std::cout << " Address: " << &aluminum << "\n"
              << " Size (bytes): " << sizeof(aluminum) << "\n";
    std::cout << std::endl;

    myContainer.printProperties();
    std::cout << " Address: " << &myContainer << "\n"
              << " Size (bytes): " << sizeof(myContainer) << "\n";
    std::cout << std::endl;

    myContainer.placeObjectInContainer(water);
    myContainer.placeObjectInContainer(aluminum);

    myContainer.getContainedLiquid()->printProperties();
    std::cout << std::endl;

    myContainer.getContainedMetal()->printProperties();
    std::cout << std::endl;

    myContainer.printProperties();
    std::cout << " Address: " << &myContainer << "\n"
              << " Size (bytes): " << sizeof(myContainer) << "\n";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}