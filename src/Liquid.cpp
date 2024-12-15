#include "Liquid.hpp"

#include <iostream>

/* Special methods */

Liquid::Liquid()
    : Substance(),
      m_boilingPoint(0),
      m_freezingPoint(0)
{
    std::cout << "Liquid | Default constructed...\n";
}

Liquid::Liquid(std::string name,
               double mass,
               double density,
               double temperature,
               double specificHeatCapacity,
               double boilingPoint,
               double freezingPoint)
    : Substance(name,
                mass,
                density,
                temperature,
                specificHeatCapacity),
      m_boilingPoint(boilingPoint),
      m_freezingPoint(freezingPoint)
{
    std::cout << "Liquid | " << m_name << " constructed...\n";
}

Liquid::Liquid(const Liquid &copy)
    : Substance(copy),
      m_boilingPoint(copy.m_boilingPoint),
      m_freezingPoint(copy.m_freezingPoint)
{
    std::cout << "Liquid | " << m_name << " (copy) constructed...\n";
}
Liquid::~Liquid()
{
    std::cout << "Liquid | " << m_name << " destroyed...\n";
}

/* Operator overloads */

Liquid &Liquid::operator=(const Liquid &copy)
{
    std::cout << "Liquid | Copy assignment operator used...\n";

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