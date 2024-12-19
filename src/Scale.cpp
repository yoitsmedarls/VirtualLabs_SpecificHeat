#include "Scale.hpp"

Scale::Scale()
    : Renderable(),
      m_massReading(0),
      m_loadedBeaker(nullptr)
{
}

Scale::Scale(std::string textureFilePath)
    : Renderable(textureFilePath),
      m_massReading(0),
      m_loadedBeaker(nullptr)
{
}

Scale::Scale(const Scale &copy)
    : Renderable(copy),
      m_massReading(copy.m_massReading),
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
    m_loadedBeaker = beaker;
    m_massReading = beaker->getTotalMass();
}

double Scale::getMassReading()
{
    return 0.0;
}
