#include "Substance.hpp"

#include <iostream>

/* Special methods */

Substance::Substance()
    : m_name(""),
      m_mass(0),
      m_temperature(0),
      m_specificHeatCapacity(0),
      m_density(0),
      m_volume(0),
      m_isContained(false)
{
    std::cout << "Substance | Default constructor called..." << std::endl;
}

Substance::Substance(std::string name, double mass, double temperature, double specificHeatCapacity, double density)
    : m_name(name),
      m_mass(mass),
      m_temperature(temperature),
      m_specificHeatCapacity(specificHeatCapacity),
      m_density(density),
      m_volume(mass / density),
      m_isContained(false)
{
    std::cout << "Substance | Constructor called..." << std::endl;
}

Substance::Substance(const Substance &copy)
    : m_name(copy.m_name),
      m_mass(copy.m_mass),
      m_temperature(copy.m_temperature),
      m_specificHeatCapacity(copy.m_specificHeatCapacity),
      m_density(copy.m_density),
      m_volume(copy.m_volume),
      m_isContained(copy.m_isContained)
{
    std::cout << "Substance | Copy constructor called..." << std::endl;
}

Substance::~Substance()
{
    std::cout << "Substance | Destructor called..." << std::endl;
}

/* Operator overloads */

Substance &Substance::operator=(const Substance &copy)
{
    std::cout << "Substance | Copy assignment operator used..." << std::endl;

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

double Substance::getTemperature()
{
    return m_temperature;
}

double Substance::getSpecificHeatCapacity()
{
    return m_specificHeatCapacity;
}

double Substance::getDensity()
{
    return m_density;
}

double Substance::getVolume()
{
    return m_volume;
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

void Substance::setTemperature(double temperature)
{
    m_temperature = temperature;
}

void Substance::setSpecificHeatCapacity(double specificHeatCapacity)
{
    m_specificHeatCapacity = specificHeatCapacity;
}

void Substance::setDensity(double density)
{
    m_density = density;
    updateVolume();
}

/* Other methods */

bool Substance::isSubstanceContained()
{
    return m_isContained;
}

void Substance::updateVolume()
{
    m_volume = m_mass / m_density;
}

void Substance::printProperties()
{
    std::cout << m_name << " Properties:" << "\n"
              << " Mass: " << m_mass << "\n"
              << " Temperature: " << m_temperature << "\n"
              << " SpecificHeatCapacity: " << m_specificHeatCapacity << "\n"
              << " Density: " << m_density << "\n"
              << " Volume: " << m_volume << "\n"
              << " IsContained: " << m_isContained << "\n";
}
