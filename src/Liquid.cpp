#include "Liquid.hpp"

namespace vl
{
    /** Special member functions **********************************************/

    Liquid::Liquid()
        : Substance(),
          m_boilingPoint(0),
          m_freezingPoint(0)
    {
    }

    Liquid::Liquid(double mass,
                   double density,
                   double temperature,
                   double specificHeatCapacity,
                   double boilingPoint,
                   double freezingPoint)
        : Substance(mass,
                    density,
                    temperature,
                    specificHeatCapacity),
          m_boilingPoint(boilingPoint),
          m_freezingPoint(freezingPoint)
    {
    }

    Liquid::Liquid(const Liquid &copy)
        : Substance(copy),
          m_boilingPoint(copy.m_boilingPoint),
          m_freezingPoint(copy.m_freezingPoint)
    {
    }
    Liquid::~Liquid()
    {
    }

    /** Operator overloads ****************************************************/

    Liquid &Liquid::operator=(const Liquid &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    /** Getters and Setters ***************************************************/

    double Liquid::getBoilingPoint()
    {
        return m_boilingPoint;
    }
    void Liquid::setBoilingPoint(double boilingPoint)
    {
        m_boilingPoint = boilingPoint;
    }

    double Liquid::getFreezingPoint()
    {
        return m_freezingPoint;
    }
    void Liquid::setFreezingPoint(double freezingPoint)
    {
        m_freezingPoint = freezingPoint;
    }

} // namespace vl