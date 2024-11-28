#include "Substance.hpp"

#include <iostream>

/* Special methods */

Substance::Substance() : m_name(""), m_mass(0), m_temperature(0), m_specificHeatCapacity(0), m_density(0), m_volume(0), m_isContained(false)
{
    std::cout << "Substance | Default constructor called..." << std::endl;
}

Substance::Substance(std::string name, double mass, double temperature, double specificHeatCapacity, double density)
{
    std::cout << "Substance | Constructor called..." << std::endl;

    this->m_name = name;
    this->m_mass = mass;
    this->m_temperature = temperature;
    this->m_specificHeatCapacity = specificHeatCapacity;
    this->m_density = density;
    this->m_volume = mass / density;
    this->m_isContained = false;
}

Substance::Substance(const Substance &copy)
{
    std::cout << "Substance | Copy constructor called..." << std::endl;

    this->m_name = copy.m_name;
    this->m_mass = copy.m_mass;
    this->m_temperature = copy.m_temperature;
    this->m_specificHeatCapacity = copy.m_specificHeatCapacity;
    this->m_density = copy.m_density;
    this->m_volume = copy.m_volume;
    this->m_isContained = copy.m_isContained;
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
    return this->m_name;
}

double Substance::getMass()
{
    return this->m_mass;
}

double Substance::getTemperature()
{
    return this->m_temperature;
}

double Substance::getSpecificHeatCapacity()
{
    return this->m_specificHeatCapacity;
}

double Substance::getDensity()
{
    return this->m_density;
}

double Substance::getVolume()
{
    return this->m_volume;
}

/* Setters */

void Substance::setName(std::string name)
{
    this->m_name = name;
}

void Substance::setMass(double mass)
{
    this->m_mass = mass;
}

void Substance::setTemperature(double temperature)
{
    this->m_temperature = temperature;
}

void Substance::setSpecificHeatCapacity(double specificHeatCapacity)
{
    this->m_specificHeatCapacity = specificHeatCapacity;
}

void Substance::setDensity(double density)
{
    this->m_density = density;
}

bool Substance::isSubstanceContained()
{
    return this->m_isContained;
}

void Substance::updateVolume()
{
    this->m_volume = this->m_mass / this->m_density;
}

void Substance::printProperties()
{
    std::cout << this->m_name << " Properties:" << "\n"
              << " Mass: " << this->m_mass << "\n"
              << " Temperature: " << this->m_temperature << "\n"
              << " SpecificHeatCapacity: " << this->m_specificHeatCapacity << "\n"
              << " Density: " << this->m_density << "\n"
              << " Volume: " << this->m_volume << "\n"
              << " IsContained: " << this->m_isContained << "\n"
              << std::endl;
}
