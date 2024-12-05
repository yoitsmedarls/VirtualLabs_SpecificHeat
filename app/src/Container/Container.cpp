#include "Container.hpp"

#include <iostream>
#include <cmath>

/* Special methods */

Container::Container()
    : m_name(""),
      m_diameter(0),
      m_height(0),
      m_volume(0),
      m_topSurfaceArea(0),
      m_liquid(nullptr),
      m_metal(nullptr)
{
    std::cout << "Container | Default constructor called..." << std::endl;
}

Container::Container(const std::string name, const double diameter,
                     const double height)
    : m_name(name),
      m_diameter(diameter),
      m_height(height),
      m_volume((M_PI * pow((diameter / 2), 2)) * height),
      m_topSurfaceArea(M_PI * pow((diameter / 2), 2)),
      m_liquid(nullptr),
      m_metal(nullptr)
{
    std::cout << "Container | Constructor without pointers called..." << std::endl;
}

Container::Container(const std::string name, const double diameter,
                     const double height, Liquid &liquid,
                     Metal &metal)
    : m_name(name),
      m_diameter(diameter),
      m_height(height),
      m_volume((M_PI * pow((diameter / 2), 2)) * height),
      m_topSurfaceArea(M_PI * pow((diameter / 2), 2)),
      m_liquid(&liquid),
      m_metal(&metal)
{
    std::cout << "Container | Constructor with pointers called..." << std::endl;
}

Container::Container(const Container &copy)
    : m_name(copy.m_name),
      m_diameter(copy.m_diameter),
      m_height(copy.m_height),
      m_volume(copy.m_volume),
      m_topSurfaceArea(copy.m_topSurfaceArea),
      m_liquid(copy.m_liquid),
      m_metal(copy.m_metal)
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

    return *this;
}

/* Getters */

std::string Container::getName()
{
    return m_name;
}

double Container::getDiameter()
{
    return m_diameter;
}

double Container::getHeight()
{
    return m_height;
}

double Container::getVolume()
{
    return m_volume;
}

double Container::getTopSurfaceArea()
{
    return m_topSurfaceArea;
}

Liquid *Container::getContainedLiquid()
{
    return m_liquid;
}

Metal *Container::getContainedMetal()
{
    return m_metal;
}

/* Setters */

void Container::setName(std::string name)
{
    m_name = name;
}

void Container::setDiameter(double diameter)
{
    m_diameter = diameter;
    updateVolumeAndTopSurfaceArea();
}

void Container::setHeight(double height)
{
    m_height = m_height;
    updateVolumeAndTopSurfaceArea();
}

void Container::placeObjectInContainer(Liquid &liquid)
{
    m_liquid = &liquid;
}
void Container::placeObjectInContainer(Metal &metal)
{
    m_metal = &metal;
}

/* Other methods */

void Container::updateVolumeAndTopSurfaceArea()
{
    m_topSurfaceArea = M_PI * pow((m_diameter / 2), 2);
    m_volume = m_topSurfaceArea * m_height;
}

bool Container::hasLiquid()
{
    if (m_liquid == nullptr)
    {
        return false;
    }

    return true;
}

bool Container::hasMetal()
{
    if (m_metal == nullptr)
    {
        return false;
    }

    return true;
}

void Container::printProperties()
{
    std::cout << m_name << " Properties:" << "\n"
              << " Name: " << m_name << "\n"
              << " Diameter: " << m_diameter << "\n"
              << " Height: " << m_height << "\n"
              << " Volume: " << m_volume << "\n"
              << " TopSurfaceArea: " << m_topSurfaceArea << "\n"
              << " Liquid: " << m_liquid << "\n"
              << " Metal: " << m_metal << "\n";
}