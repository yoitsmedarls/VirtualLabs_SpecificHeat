#include "Laboratory.hpp"

Laboratory::Laboratory()
    : Renderable(),
      m_ambientTemperature(0)
{
}

Laboratory::Laboratory(std::string textureFilePath)
    : Renderable(textureFilePath)
{
}

Laboratory::Laboratory(const Laboratory &copy)
    : Renderable(copy),
      m_ambientTemperature(copy.m_ambientTemperature)
{
}

Laboratory::~Laboratory()
{
}

Laboratory &Laboratory::operator=(const Laboratory &copy)
{
    std::cout << "Laboratory | Copy assignment operator used...\n";

    if (&copy == this)
    {
        return *this;
    }

    return *this;
}
