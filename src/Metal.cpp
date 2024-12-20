#include "Metal.hpp"

#include <cmath>

namespace vl
{
    /** Special member functions **********************************************/

    Metal::Metal()
        : Substance(),
          m_sideLength(0)
    {
    }

    Metal::Metal(double mass,
                 double density,
                 double temperature,
                 double specificHeatCapacity)
        : Substance(mass,
                    density,
                    temperature,
                    specificHeatCapacity),
          m_sideLength(std::cbrt(mass / density))
    {
    }

    Metal::Metal(const Metal &copy)
        : Substance(copy),
          m_sideLength(copy.m_sideLength)
    {
    }

    Metal::~Metal()
    {
    }

    /** Operator overloads ****************************************************/

    Metal &Metal::operator=(const Metal &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    /** Getters and Setters ***************************************************/

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

    /** Other member functions ************************************************/

    void Metal::updateSideLength()
    {
        m_sideLength = std::cbrt(m_volume);
    }

} // namespace vl