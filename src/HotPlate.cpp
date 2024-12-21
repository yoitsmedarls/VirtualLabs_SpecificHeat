#include "HotPlate.hpp"

#include <iostream>

namespace vl
{
    HotPlate::HotPlate()
        : m_wattage(0),
          m_isOn(false),
          m_efficiency(0),
          m_loadedBeaker(nullptr)
    {
    }

    HotPlate::HotPlate(int wattage,
                       double efficiency)
        : m_wattage(wattage),
          m_efficiency(efficiency),
          m_isOn(false),
          m_loadedBeaker(nullptr)
    {
    }

    HotPlate::HotPlate(const HotPlate &copy)
        : m_wattage(copy.m_wattage),
          m_efficiency(copy.m_efficiency),
          m_isOn(copy.m_isOn),
          m_loadedBeaker(copy.m_loadedBeaker)
    {
    }

    HotPlate::~HotPlate()
    {
    }

    HotPlate &HotPlate::operator=(const HotPlate &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    int HotPlate::getWattage()
    {
        return m_wattage;
    }

    void HotPlate::setWattage(int wattage)
    {
        m_wattage = wattage;
    }

    double HotPlate::getEfficiency()
    {
        return m_efficiency;
    }

    void HotPlate::setEfficiency(double efficiency)
    {
        m_efficiency = efficiency;
    }

    std::shared_ptr<Beaker> HotPlate::getLoadedBeaker()
    {
        return m_loadedBeaker;
    }

    void HotPlate::addBeaker(std::shared_ptr<Beaker> beaker)
    {
        if (beaker->isInUse == false && beaker->getTotalMass() != 0)
        {
            m_loadedBeaker = beaker;
            m_loadedBeaker->isInUse = true;
        }
        else
        {
            // std::cout << "ERROR: Beaker is empty or is in use!" << std::endl;
        }
    }
    void HotPlate::removeBeaker()
    {
        if (m_loadedBeaker != nullptr)
        {
            m_loadedBeaker->isInUse = false;
            m_loadedBeaker = nullptr;
        }
        else
        {
            // std::cout << "ERROR: No loaded beaker." << std::endl;
        }
    }

    bool HotPlate::isHotPlateOn()
    {
        return m_isOn;
    }
    void HotPlate::turnOffHotPlate()
    {
        m_isOn = false;
    }
    void HotPlate::turnOnHotPlate()
    {
        if (m_loadedBeaker != nullptr &&
            m_loadedBeaker->getContainedLiquid() != nullptr &&
            m_loadedBeaker->getContainedLiquid() != nullptr)
        {
            m_isOn = true;
        }
        else
        {
            // std::cout << "ERROR: No loaded beaker to heat!" << std::endl;
        }
    }
}