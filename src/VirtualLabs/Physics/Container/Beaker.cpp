#include "Beaker.hpp"

Beaker::Beaker()
    : Renderable(),
      Container()
{
}

Beaker::Beaker(std::string textureFilePath,
               double diameter,
               double height)
    : Renderable(textureFilePath),
      Container(diameter,
                height)
{
}

Beaker::Beaker(std::string textureFilePath,
               double diameter,
               double height,
               std::shared_ptr<Liquid> liquid,
               std::shared_ptr<Metal> metal)
    : Renderable(textureFilePath),
      Container(diameter,
                height,
                liquid,
                metal)
{
}

Beaker::Beaker(const Beaker &copy)
    : Renderable(copy),
      Container(copy)
{
}

Beaker::~Beaker()
{
}

Beaker &Beaker::operator=(const Beaker &copy)
{
    if (&copy == this)
    {
        return *this;
    }

    return *this;
}
