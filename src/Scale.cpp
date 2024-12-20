#include "Scale.hpp"

#include <iostream>

namespace vl
{
    Scale::Scale()
        : m_massReading(0),
          m_loadedBeaker(nullptr)
    {
    }

    Scale::Scale(const Scale &copy)
        : m_massReading(copy.m_massReading),
          m_loadedBeaker(copy.m_loadedBeaker)
    {
    }

    Scale::~Scale()
    {
    }

    Scale &Scale::operator=(const Scale &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    void Scale::addBeaker(std::shared_ptr<Beaker> beaker)
    {
        if (beaker->isInUse == false && beaker->getTotalMass() != 0)
        {
            m_loadedBeaker = beaker;
            m_loadedBeaker->isInUse = true;
            m_massReading = m_loadedBeaker->getTotalMass();
        }
        else
        {
            std::cout << "ERROR: Beaker is empty or is in use!" << std::endl;
        }
    }

    void Scale::removeBeaker()
    {
        if (m_loadedBeaker != nullptr)
        {
            m_loadedBeaker->isInUse = false;
            m_massReading = 0;
            m_loadedBeaker = nullptr;
        }
        else
        {
            std::cout << "ERROR: No loaded beaker." << std::endl;
        }
    }

    double Scale::getMassReading()
    {
        return m_massReading;
    }
}