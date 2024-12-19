#include <iostream>
#include "HeatSource.hpp"
#include "Container.hpp"

HeatSource::HeatSource()
{
}

HeatSource::~HeatSource()
{
}

void HeatSource::heatContainer(Container &container)
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
