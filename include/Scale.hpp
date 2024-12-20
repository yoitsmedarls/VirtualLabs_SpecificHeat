#ifndef SCALE
#define SCALE

#include <string>
#include <memory>

#include "Beaker.hpp"

namespace vl
{
    class Scale
    {
    private: // Class fields
        double m_massReading;
        std::shared_ptr<Beaker> m_loadedBeaker;

    public: // Special methods
        Scale();
        Scale(const Scale &copy);
        ~Scale();

    public: // Operator overloads
        Scale &operator=(const Scale &copy);

    public: // Getters and Setters
        void addBeaker(std::shared_ptr<Beaker> beaker);
        void removeBeaker();
        double getMassReading();

    public: // Other methods
    };

}
#endif