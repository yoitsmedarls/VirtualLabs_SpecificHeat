// #include "Metal.hpp"

// #include <iostream>

// /* Special methods */

// Metal::Metal()
// {
//     std::cout << "Metal | Default constructor called..." << std::endl;
// }

// Metal::Metal(double mass, double temperature, double specificHeatCapacity,
//              double length, double width, double height)
//     : Substance(mass, temperature, specificHeatCapacity)
// {
//     std::cout << "Metal | Constructor called..." << std::endl;

//     m_length = length;
//     m_width = width;
//     m_height = height;
//     m_volume = length * width * height;
// }

// Metal::Metal(const Metal &copy)
// {
//     std::cout << "Metal | Copy constructor called..." << std::endl;
// }

// Metal::~Metal()
// {
//     std::cout << "Metal | Destructor called..." << std::endl;
// }

// /* Operator overloads */

// Metal &Metal::operator=(const Metal &copy)
// {
//     std::cout << "Metal | Copy assignment operator used..." << std::endl;

//     if (&copy == this)
//     {
//         return *this;
//     }
// }

// /* Getters */

// double Metal::getLength()
// {
//     return m_length;
// }

// double Metal::getWidth()
// {
//     return m_width;
// }

// double Metal::getHeight()
// {
//     return m_height;
// }

// double Metal::getVolume()
// {
//     return m_volume;
// }

// /* Setters */

// void Metal::setLength(double length)
// {
//     m_length = length;
//     updateMetalVolume();
// }

// void Metal::setWidth(double width)
// {
//     m_width = width;
//     updateMetalVolume();
// }

// void Metal::setHeight(double height)
// {
//     m_height = m_height;
//     updateMetalVolume();
// }

// /* Other methods */

// void Metal::updateMetalVolume()
// {
//     m_volume = m_length * m_width * m_height;
// }
