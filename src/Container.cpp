#include "Container.hpp"

#include <iostream>
#include <cmath>

namespace vl
{
    /** Special member functions **********************************************/

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
    }

    Container::Container(double diameter,
                         double height)
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

    Container::Container(double diameter,
                         double height,
                         std::shared_ptr<Liquid> liquid,
                         std::shared_ptr<Metal> metal)
        : m_diameter(diameter),
          m_height(height),
          m_totalMass(liquid->getMass() + metal->getMass()),
          m_totalVolume((M_PI * pow((diameter / 2), 2)) * height),
          m_availableVolume(m_totalVolume),
          m_topSurfaceArea(M_PI * pow((diameter / 2), 2))
    {
        addLiquid(liquid);
        addMetal(metal);
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

    /** Operator overloads ****************************************************/

    Container &Container::operator=(const Container &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    /** Getters and Setters ***************************************************/

    double Container::getDiameter()
    {
        return m_diameter;
    }
    void Container::setDiameter(double diameter)
    {
        m_diameter = diameter;
        updateTopSurfaceArea();
        updateVolume();
    }

    double Container::getHeight()
    {
        return m_height;
    }
    void Container::setHeight(double height)
    {
        m_height = m_height;
        updateTopSurfaceArea();
        updateVolume();
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
        if (m_liquid != nullptr)
        {
            return m_liquid;
        }
        else
        {
            // std::cout << "ERROR: Container contains no liquid." << std::endl;
        }
    }
    void Container::addLiquid(std::shared_ptr<Liquid> liquid)
    {
        if (liquid->isinContainer == false && m_availableVolume > liquid->getVolume())
        {
            m_liquid = liquid;
            m_liquid->isinContainer = true;
            containsLiquid = true;
            m_totalMass += liquid->getMass();
            m_availableVolume -= liquid->getVolume();
        }
        else
        {
            // std::cout << "ERROR: Cannot place Liquid inside Container." << std::endl;
        }
    }
    void Container::removeContainedLiquid()
    {
        if (m_liquid != nullptr)
        {
            m_totalMass -= m_liquid->getMass();
            m_liquid->isinContainer = false;
            containsLiquid = false;
            m_availableVolume += m_liquid->getVolume();
            m_liquid = nullptr;
        }
        else
        {
            // std::cout << "ERROR: Container does not have a liquid." << std::endl;
        }
    }

    std::shared_ptr<Metal> Container::getContainedMetal()
    {
        if (m_metal != nullptr)
        {
            return m_metal;
        }
        else
        {
            // std::cout << "ERROR: Container contains no metal." << std::endl;
        }
    }
    void Container::addMetal(std::shared_ptr<Metal> metal)
    {
        if (metal->isinContainer == false && m_availableVolume > metal->getVolume())
        {
            m_metal = metal;
            m_metal->isinContainer = true;
            containsMetal = true;
            m_totalMass += metal->getMass();
            m_availableVolume -= metal->getVolume();
        }
        else
        {
            // std::cout << "ERROR: Cannot place Metal inside Container." << std::endl;
        }
    }
    void Container::removeContainedMetal()
    {
        if (m_metal != nullptr)
        {
            m_totalMass -= m_metal->getMass();
            m_metal->isinContainer = false;
            containsMetal = false;
            m_availableVolume += m_metal->getVolume();
            m_metal = nullptr;
        }
        else
        {
            // std::cout << "ERROR: Container does not have a metal." << std::endl;
        }
    }

    /** Other member functions ************************************************/

    void Container::updateTopSurfaceArea()
    {
        m_topSurfaceArea = M_PI * pow((m_diameter / 2), 2);
    }

    void Container::updateVolume()
    {
        m_totalVolume = M_PI * pow((m_diameter / 2), 2) * m_height;
    }

} // namespace vl