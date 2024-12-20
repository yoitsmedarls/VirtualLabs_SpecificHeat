#include "Calorimeter.hpp"

namespace vl
{
    /** Special member functions **********************************************/

    Calorimeter::Calorimeter()
        : Container()
    {
    }

    Calorimeter::Calorimeter(double diameter,
                             double height)
        : Container(diameter,
                    height)
    {
    }

    Calorimeter::Calorimeter(double diameter,
                             double height,
                             std::shared_ptr<Liquid> liquid,
                             std::shared_ptr<Metal> metal)
        : Container(diameter,
                    height,
                    liquid,
                    metal)
    {
    }

    Calorimeter::Calorimeter(const Calorimeter &copy)
        : Container(copy)
    {
    }

    Calorimeter::~Calorimeter()
    {
    }

    /** Operator overloads ****************************************************/

    Calorimeter &Calorimeter::operator=(const Calorimeter &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

} // namespace vl
