#include "Metal.hpp"

#include <iostream>
#include <cmath>

/* Special methods */

Metal::Metal()
    : Substance(),
      m_sideLength(0)
{
    std::cout << "Metal | Default constructed..."
              << std::endl;
}

Metal::Metal(std::string name,
             double mass,
             double density,
             double temperature,
             double specificHeatCapacity)
    : Substance(name,
                mass,
                density,
                temperature,
                specificHeatCapacity),
      m_sideLength(std::cbrt(mass / density))
{
    std::cout << "Metal | " << m_name << " constructed..."
              << std::endl;
}

Metal::Metal(const Metal &copy)
    : Substance(copy),
      m_sideLength(copy.m_sideLength)
{
    std::cout << "Metal | " << m_name << " (copy) constructed..."
              << std::endl;
}

Metal::~Metal()
{
    std::cout << "Metal | " << m_name << " destroyed..."
              << std::endl;
}

/* Operator overloads */

Metal &Metal::operator=(const Metal &copy)
{
    std::cout << "Metal | Copy assignment operator used..."
              << std::endl;

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

void Metal::setMass(double mass)
{
    Substance::setMass(mass);
    updateSideLength();
}

void Metal::setDensity(double density)
{
    Substance::setDensity(density);
    updateSideLength();
}

/* Other methods */

void Metal::updateSideLength()
{
    m_sideLength = std::cbrt(m_volume);
}

void Metal::printProperties()
{
    Substance::printProperties();
    std::cout << " SideLength: " << m_sideLength << "\n";
}
