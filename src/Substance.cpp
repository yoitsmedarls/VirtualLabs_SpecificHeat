#include "Substance.hpp"

#include <iostream>

/* Special methods */

Substance::Substance()
    : m_name(""),
      m_mass(0),
      m_density(0),
      m_volume(0),
      m_temperature(0),
      m_specificHeatCapacity(0)
{
    std::cout << "Substance | Default constructed...\n";
}

Substance::Substance(std::string name,
                     double mass,
                     double density,
                     double temperature,
                     double specificHeatCapacity)
    : m_name(name),
      m_mass(mass),
      m_density(density),
      m_volume(mass / density),
      m_temperature(temperature),
      m_specificHeatCapacity(specificHeatCapacity)
{
    std::cout << "Substance | " << m_name << " constructed... \n";
}

Substance::Substance(const Substance &copy)
    : m_name(copy.m_name),
      m_mass(copy.m_mass),
      m_density(copy.m_density),
      m_volume(copy.m_volume),
      m_temperature(copy.m_temperature),
      m_specificHeatCapacity(copy.m_specificHeatCapacity)
{
    std::cout << "Substance | " << m_name << " (copy) constructed...\n";
}

Substance::~Substance()
{
    std::cout << "Substance | " << m_name << " destroyed...\n";
}

/* Operator overloads */

Substance &Substance::operator=(const Substance &copy)
{
    std::cout << "Substance | Copy assignment operator used...\n";

    if (&copy == this)
    {
        return *this;
    }

    return *this;
}

/* Getters */

std::string Substance::getName()
{
    return m_name;
}

double Substance::getMass()
{
    return m_mass;
}

double Substance::getDensity()
{
    return m_density;
}

double Substance::getVolume()
{
    return m_volume;
}

double Substance::getTemperature()
{
    return m_temperature;
}

double Substance::getSpecificHeatCapacity()
{
    return m_specificHeatCapacity;
}

/* Setters */

void Substance::setName(std::string name)
{
    m_name = name;
}

void Substance::setMass(double mass)
{
    m_mass = mass;
    updateVolume();
}

void Substance::setDensity(double density)
{
    m_density = density;
    updateVolume();
}

void Substance::setTemperature(double temperature)
{
    m_temperature = temperature;
}

void Substance::setSpecificHeatCapacity(double specificHeatCapacity)
{
    m_specificHeatCapacity = specificHeatCapacity;
}

/* Other methods */

void Substance::updateVolume()
{
    m_volume = m_mass / m_density;
}

void Substance::printProperties()
{
    std::cout << m_name << " Properties:" << "\n"
              << " Mass: " << m_mass << "\n"
              << " Density: " << m_density << "\n"
              << " Volume: " << m_volume << "\n"
              << " Temperature: " << m_temperature << "\n"
              << " SpecificHeatCapacity: " << m_specificHeatCapacity << "\n";
}
