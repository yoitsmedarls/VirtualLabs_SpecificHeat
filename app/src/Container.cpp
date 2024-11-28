#include "VirtualLabs/Container.hpp"

#include <iostream>
#include <cmath>

/* Special methods */

Container::Container()
{
    std::cout << "Container | Default constructor called..." << std::endl;
}

Container::Container(double diameter, double height, Liquid &containedLiquid, Metal &containedMetal)
{
    std::cout << "Container | Constructor called..." << std::endl;

    m_diameter = diameter;
    m_height = height;
    m_containedLiquid = containedLiquid;
    m_containedMetal = containedMetal;
}

Container::Container(const Container &copy)
{
    std::cout << "Container | Copy constructor called..." << std::endl;
}

Container::~Container()
{
    std::cout << "Container | Destructor called..." << std::endl;
}

/* Operator overloads */

Container &Container::operator=(const Container &copy)
{
    std::cout << "Container | Copy assignment operator used..." << std::endl;

    if (&copy == this)
    {
        return *this;
    }
}

/* Getters */

double Container::getDiameter()
{
    return 0.0;
}

double Container::getHeight()
{
    return 0.0;
}

double Container::getVolume()
{
    return 0.0;
}

double Container::getTopSurfaceArea()
{
    return 0.0;
}

Liquid Container::getContainedLiquid()
{
    return Liquid();
}

Metal Container::getContainedMetal()
{
    return Metal();
}

/* Setters */

void Container::setDiameter()
{
}

void Container::setHeight()
{
}

void Container::setContainedLiquid()
{
}

void Container::setContainedMetal()
{
}

/* Other methods */

void Container::updateVolumeAndTopSurfaceArea()
{
    m_topSurfaceArea = M_PI * pow((m_diameter / 2), 2);
    m_volume = m_topSurfaceArea * m_height;
}
