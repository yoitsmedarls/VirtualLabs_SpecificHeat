#ifndef HEAT_SOURCE
#define HEAT_SOURCE

#include "Container.hpp"

class HeatSource
{
public:
    int m_wattage;
    int m_efficiency;

public:
    HeatSource(/* args */);
    ~HeatSource();

public:
    void heatContainer(Container &container);
};

#endif