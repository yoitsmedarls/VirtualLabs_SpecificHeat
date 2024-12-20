#include "Beaker.hpp"

namespace vl
{
    /** Special member functions **********************************************/

    Beaker::Beaker()
        : Container()
    {
    }

    Beaker::Beaker(double diameter,
                   double height)
        : Container(diameter,
                    height)
    {
    }

    Beaker::Beaker(double diameter,
                   double height,
                   std::shared_ptr<Liquid> liquid,
                   std::shared_ptr<Metal> metal)
        : Container(diameter,
                    height,
                    liquid,
                    metal)
    {
    }

    Beaker::Beaker(const Beaker &copy)
        : Container(copy)
    {
    }

    Beaker::~Beaker()
    {
    }

    /** Operator overloads ****************************************************/

    Beaker &Beaker::operator=(const Beaker &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

} // namespace vl
