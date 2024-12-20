// #include <iostream>
// #include "Substance.hpp"
// #include "Liquid.hpp"
// #include "Metal.hpp"

// int main()
// {
//     Substance mySubstance = Substance("My Substance", 100, 24, 4231, 1);
//     Liquid water = Liquid("Water", 100, 25, 4186, 1, 100, 0);
//     Metal aluminum = Metal("Aluminum", 50, 20, 903, 2.7);

//     mySubstance.printProperties();
//     std::cout << " Address: " << &mySubstance << "\n"
//               << " Size (bytes): " << sizeof(mySubstance) << "\n";

//     water.printProperties();
//     std::cout << " Address: " << &water << "\n"
//               << " Size (bytes): " << sizeof(water) << "\n";

//     aluminum.printProperties();
//     std::cout << " Address: " << &aluminum << "\n"
//               << " Size (bytes): " << sizeof(aluminum) << "\n";

//     return EXIT_SUCCESS;
// }