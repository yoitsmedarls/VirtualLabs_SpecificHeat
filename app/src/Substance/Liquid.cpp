#include "Liquid.hpp"

#include <iostream>

/* Special methods */

Liquid::Liquid()
    : Substance(),
      m_boilingPoint(0),
      m_freezingPoint(0)
{
    std::cout << "Liquid | Default constructor called..." << std::endl;
}

Liquid::Liquid(std::string name, double mass, double temperature, double specificHeatCapacity, double density,
               double boilingPoint, double freezingPoint)
    : Substance(name, mass, temperature, specificHeatCapacity, density),
      m_boilingPoint(boilingPoint),
      m_freezingPoint(freezingPoint)
{
    std::cout << "Liquid | Constructor called..." << std::endl;
}

Liquid::Liquid(const Liquid &copy)
    : Substance(copy),
      m_boilingPoint(copy.m_boilingPoint),
      m_freezingPoint(copy.m_freezingPoint)
{
    std::cout << "Liquid | Copy constructor called..." << std::endl;
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

    return *this;
}

/* Getters */

double Liquid::getBoilingPoint()
{
    return m_boilingPoint;
}

double Liquid::getFreezingPoint()
{
    return m_freezingPoint;
}

/* Setters */

void Liquid::setBoilingPoint(double boilingPoint)
{
    m_boilingPoint = boilingPoint;
}
void Liquid::setFreezingPoint(double freezingPoint)
{
    m_freezingPoint = freezingPoint;
}

/* Other methods */

void Liquid::printProperties()
{
    Substance::printProperties();
    std::cout << " BoilingPoint: " << m_boilingPoint << "\n"
              << " FreezingPoint: " << m_freezingPoint << "\n";
}