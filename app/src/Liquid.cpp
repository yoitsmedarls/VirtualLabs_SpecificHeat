#include "Liquid.hpp"

#include <iostream>

/* Special methods */

Liquid::Liquid()
{
    std::cout << "Liquid | Default constructor called..." << std::endl;
}

Liquid::Liquid(std::string name, double mass, double temperature, double specificHeatCapacity,
               double density, double boilingPoint, double freezingPoint)
    : Substance(name, mass, temperature, specificHeatCapacity, density)
{
    std::cout << "Liquid | Constructor called..." << std::endl;

    this->m_boilingPoint = boilingPoint;
    this->m_freezingPoint = freezingPoint;
}

Liquid::Liquid(const Liquid &copy)
{
    std::cout << "Liquid | Copy constructor called..." << std::endl;

    this->m_boilingPoint = copy.m_boilingPoint;
    this->m_freezingPoint = copy.m_freezingPoint;
}
Liquid::~Liquid()
{
    std::cout << "Liquid | Destructor called..." << std::endl;
}

/* Operator overloads */

Liquid &Liquid::operator=(const Liquid &copy)
{
    std::cout << "Liquid | Copy assignment operator used..." << std::endl;

    if (&copy == this)
    {
        return *this;
    }
}

/* Getters */

double Liquid::getBoilingPoint()
{
    return this->m_boilingPoint;
}

double Liquid::getFreezingPoint()
{
    return this->m_freezingPoint;
}

/* Setters */

void Liquid::setBoilingPoint(double boilingPoint)
{
    this->m_boilingPoint = boilingPoint;
}
void Liquid::setFreezingPoint(double freezingPoint)
{
    this->m_freezingPoint = freezingPoint;
}

void Liquid::printProperties()
{
    std::cout << this->m_name << " Properties:" << "\n"
              << " Mass: " << this->m_mass << "\n"
              << " Temperature: " << this->m_temperature << "\n"
              << " SpecificHeatCapacity: " << this->m_specificHeatCapacity << "\n"
              << " Density: " << this->m_density << "\n"
              << " Volume: " << this->m_volume << "\n"
              << " IsContained: " << this->m_isContained << "\n"
              << " Boiling Point: " << this->m_boilingPoint << "\n"
              << " Freezing Point: " << this->m_freezingPoint << "\n"
              << std::endl;
}

/* Other methods */
