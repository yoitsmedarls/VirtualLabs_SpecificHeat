#include "Container.hpp"

#include <iostream>
#include <cmath>

/* Special methods */

Container::Container()
    : m_diameter(0),
      m_height(0),
      m_totalMass(0),
      m_totalVolume(0),
      m_availableVolume(0),
      m_topSurfaceArea(0),
      m_liquid(nullptr),
      m_metal(nullptr)
{
    std::cout << "Container | Default constructed...\n";
}

Container::Container(const double diameter,
                     const double height)
    : m_diameter(diameter),
      m_height(height),
      m_totalMass(0),
      m_totalVolume((M_PI * pow((diameter / 2), 2)) * height),
      m_availableVolume(m_totalVolume),
      m_topSurfaceArea(M_PI * pow((diameter / 2), 2)),
      m_liquid(nullptr),
      m_metal(nullptr)
{
}

Container::Container(const double diameter,
                     const double height,
                     std::shared_ptr<Liquid> liquid,
                     std::shared_ptr<Metal> metal)
    : m_diameter(diameter),
      m_height(height),
      m_totalVolume((M_PI * pow((diameter / 2), 2)) * height),
      m_availableVolume(m_totalVolume),
      m_topSurfaceArea(M_PI * pow((diameter / 2), 2))
{
    addLiquid(liquid);
    addMetal(metal);

    m_totalMass = liquid->getMass() + metal->getMass();
}

Container::Container(const Container &copy)
    : m_diameter(copy.m_diameter),
      m_height(copy.m_height),
      m_totalMass(copy.m_totalMass),
      m_totalVolume(copy.m_totalVolume),
      m_availableVolume(copy.m_availableVolume),
      m_topSurfaceArea(copy.m_topSurfaceArea),
      m_liquid(copy.m_liquid),
      m_metal(copy.m_metal)
{
}

Container::~Container()
{
}

/* Operator overloads */

Container &Container::operator=(const Container &copy)
{
    std::cout << "Container | Copy assignment operator used...\n";

    if (&copy == this)
    {
        return *this;
    }

    return *this;
}

/* Getters */

double Container::getDiameter()
{
    return m_diameter;
}

double Container::getHeight()
{
    return m_height;
}

double Container::getTotalMass()
{
    return m_totalMass;
}

double Container::getTotalVolume()
{
    return m_totalVolume;
}

double Container::getAvailableVolume()
{
    return m_availableVolume;
}

double Container::getTopSurfaceArea()
{
    return m_topSurfaceArea;
}

std::shared_ptr<Liquid> Container::getContainedLiquid()
{
    try
    {
        if (m_liquid == nullptr)
        {
            throw std::logic_error("ERROR: Container contains no liquid.");
        }
    }
    catch (const std::exception &error)
    {
        std::cout << error.what() << '\n';
        exit(EXIT_FAILURE);
    }

    return m_liquid;
}

std::shared_ptr<Metal> Container::getContainedMetal()
{
    try
    {
        if (m_metal == nullptr)
        {
            throw std::logic_error("ERROR: Container contains no metal.");
        }
    }
    catch (const std::exception &error)
    {
        std::cout << error.what() << '\n';
        exit(EXIT_FAILURE);
    }

    return m_metal;
}

/* Setters */

void Container::setDiameter(double diameter)
{
    m_diameter = diameter;
    updateTopSurfaceArea();
    updateVolume();
}

void Container::setHeight(double height)
{
    m_height = m_height;
    updateTopSurfaceArea();
    updateVolume();
}

void Container::addLiquid(std::shared_ptr<Liquid> liquid)
{
    try
    {
        if (m_availableVolume < liquid->getVolume())
        {
            throw std::logic_error("ERROR: Cannot place " + liquid->getName() +
                                   " inside Container, not enough room.");
        }
    }
    catch (const std::exception &error)
    {
        std::cout << error.what() << '\n';
        exit(EXIT_FAILURE);
    }

    m_liquid = liquid;
    m_availableVolume -= liquid->getVolume();
}
void Container::addMetal(std::shared_ptr<Metal> metal)
{
    try
    {
        if (m_availableVolume < metal->getVolume())
        {
            throw std::logic_error("ERROR: Cannot place " + metal->getName() +
                                   " inside Container, not enough room.");
        }
    }
    catch (const std::exception &error)
    {
        std::cout << error.what() << '\n';
        exit(EXIT_FAILURE);
    }

    m_metal = metal;
    m_availableVolume -= metal->getVolume();
}

/* Other methods */

void Container::updateTopSurfaceArea()
{
    m_topSurfaceArea = M_PI * pow((m_diameter / 2), 2);
}

void Container::updateVolume()
{
    m_totalVolume = M_PI * pow((m_diameter / 2), 2) * m_height;
}

void Container::printProperties()
{
    std::cout << "Container Properties:" << "\n"
              << " Diameter: " << m_diameter << "\n"
              << " Height: " << m_height << "\n"
              << " Total Volume: " << m_totalVolume << "\n"
              << " Available Volume: " << m_availableVolume << "\n"
              << " TopSurfaceArea: " << m_topSurfaceArea << "\n"
              << " Liquid: " << m_liquid << "\n"
              << " Metal: " << m_metal << "\n";
}