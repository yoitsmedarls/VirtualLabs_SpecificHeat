#include "Metal.hpp"

#include <iostream>
#include <cmath>

/* Special methods */

Metal::Metal()
    : Substance(),
      m_sideLength(0),
      m_isSubmerged(false)
{
    std::cout << "Metal | Default constructor called..." << std::endl;
}

Metal::Metal(std::string name, double mass, double temperature, double specificHeatCapacity, double density)
    : Substance(name, mass, temperature, specificHeatCapacity, density),
      m_sideLength(std::cbrt(mass / density)),
      m_isSubmerged(false)
{
    std::cout << "Metal | Constructor called..." << std::endl;
}

Metal::Metal(const Metal &copy)
    : Substance(copy),
      m_sideLength(copy.m_sideLength),
      m_isSubmerged(copy.m_isSubmerged)
{
    std::cout << "Metal | Copy constructor called..." << std::endl;
}

Metal::~Metal()
{
    std::cout << "Metal | Destructor called..." << std::endl;
}

/* Operator overloads */

Metal &Metal::operator=(const Metal &copy)
{
    std::cout << "Metal | Copy assignment operator used..." << std::endl;

    if (&copy == this)
    {
        return *this;
    }

    return *this;
}

/* Getters */

double Metal::getSideLength()
{
    return m_sideLength;
}

void Metal::setDensity(double density)
{
    Substance::setDensity(density);
    updateSideLength();
}

void Metal::setMass(double mass)
{
    Substance::setMass(mass);
    updateSideLength();
}

/* Other methods */

bool Metal::isMetalSubmerged()
{
    return m_isSubmerged;
}

void Metal::updateSideLength()
{
    m_sideLength = std::cbrt(m_volume);
}

void Metal::printProperties()
{
    Substance::printProperties();
    std::cout << " SideLength: " << m_sideLength << "\n"
              << " IsSubmerged: " << m_isSubmerged << "\n";
}
