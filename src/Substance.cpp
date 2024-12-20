#include "Substance.hpp"

namespace vl
{
    /** Special member functions **********************************************/

    Substance::Substance()
        : m_mass(0),
          m_density(0),
          m_volume(0),
          m_temperature(0),
          m_specificHeatCapacity(0),
          isinContainer(false)
    {
    }

    Substance::Substance(double mass,
                         double density,
                         double temperature,
                         double specificHeatCapacity)
        : m_mass(mass),
          m_density(density),
          m_volume(mass / density),
          m_temperature(temperature),
          m_specificHeatCapacity(specificHeatCapacity),
          isinContainer(false)
    {
    }

    Substance::Substance(const Substance &copy)
        : m_mass(copy.m_mass),
          m_density(copy.m_density),
          m_volume(copy.m_volume),
          m_temperature(copy.m_temperature),
          m_specificHeatCapacity(copy.m_specificHeatCapacity),
          isinContainer(copy.isinContainer)
    {
    }

    Substance::~Substance()
    {
    }

    /** Operator overloads ****************************************************/

    Substance &Substance::operator=(const Substance &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    /** Getters and Setters ***************************************************/

    double Substance::getMass()
    {
        return m_mass;
    }
    void Substance::setMass(double mass)
    {
        m_mass = mass;
        updateVolume();
    }

    double Substance::getDensity()
    {
        return m_density;
    }
    void Substance::setDensity(double density)
    {
        m_density = density;
        updateVolume();
    }

    double Substance::getVolume()
    {
        return m_volume;
    }

    double Substance::getTemperature()
    {
        return m_temperature;
    }
    void Substance::modifyTemperature(double deltaTemperature)
    {
        m_temperature += deltaTemperature;
    }

    void Substance::setTemperature(double temperature)
    {
        m_temperature = temperature;
    }

    double Substance::getSpecificHeatCapacity()
    {
        return m_specificHeatCapacity;
    }
    void Substance::setSpecificHeatCapacity(double specificHeatCapacity)
    {
        m_specificHeatCapacity = specificHeatCapacity;
    }

    /** Other member functions ************************************************/

    void Substance::updateVolume()
    {
        m_volume = m_mass / m_density;
    }

} // namespace vl