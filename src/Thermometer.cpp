#include "Thermometer.hpp"

namespace vl
{
    Thermometer::Thermometer()
    {
    }

    Thermometer::Thermometer(const Thermometer &copy)
    {
    }

    Thermometer::~Thermometer()
    {
    }

    Thermometer &Thermometer::operator=(const Thermometer &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }
}