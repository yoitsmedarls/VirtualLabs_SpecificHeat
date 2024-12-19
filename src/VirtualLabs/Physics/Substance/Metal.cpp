#include "Metal.hpp"

#include <iostream>
#include <cmath>

/* Special methods */

Metal::Metal()
    : Substance(),
      Renderable(),
      m_sideLength(0)
{
    std::cout << "Metal | Default constructed...\n";
}

Metal::Metal(std::string name,
             std::string textureFilePath,
             double mass,
             double density,
             double temperature,
             double specificHeatCapacity)
    : Substance(name,
                mass,
                density,
                temperature,
                specificHeatCapacity),
      Renderable(textureFilePath),
      m_sideLength(std::cbrt(mass / density))
{
    std::cout << "Metal | " << m_name << " constructed...\n";
}

Metal::Metal(const Metal &copy)
    : Substance(copy),
      Renderable(copy),
      m_sideLength(copy.m_sideLength)
{
    std::cout << "Metal | " << m_name << " (copy) constructed...\n";
}

Metal::~Metal()
{
    std::cout << "Metal | " << m_name << " destroyed...\n";
}

/* Operator overloads */

Metal &Metal::operator=(const Metal &copy)
{
    std::cout << "Metal | Copy assignment operator used...\n";

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
