#include <iostream>
#include "HeatPlate.hpp"
#include "Container.hpp"

HeatPlate::HeatPlate()
    : Renderable(),
      m_wattage(0)
{
}

HeatPlate::HeatPlate(int wattage,
                     std::string textureFilePath)
    : Renderable(textureFilePath),
      m_wattage(m_wattage)
{
}

HeatPlate::HeatPlate(const HeatPlate &copy)
    : Renderable(copy),
      m_wattage(copy.m_wattage)
{
}

HeatPlate::~HeatPlate()
{
}

HeatPlate &HeatPlate::operator=(const HeatPlate &copy)
{
    if (&copy == this)
    {
        return *this;
    }

    return *this;
}

void HeatPlate::heatContainer(Container &container)
{
    if (container.getContainedLiquid() == nullptr)
    {
        std::cout << "Container does not contain a liquid..." << std::endl;
        return;
    }
    if (container.getContainedMetal() == nullptr)
    {
        std::cout << "Container does not contain a Metal..." << std::endl;
        return;
    }
}
