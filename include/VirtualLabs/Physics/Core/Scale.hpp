#ifndef SCALE
#define SCALE

#include "Renderable.hpp"
#include "Beaker.hpp"
#include "Liquid.hpp"
#include "Metal.hpp"
#include <string>
#include <memory>

class Scale : public Renderable
{
private: // Class fields
    double m_massReading;
    std::shared_ptr<Beaker> m_loadedBeaker;

public: // Special methods
    Scale();
    Scale(std::string textureFilePath);
    Scale(const Scale &copy);
    ~Scale();

public: // Operator overloads
    Scale &operator=(const Scale &copy);

public: // Getters and Setters
    void addBeaker(std::shared_ptr<Beaker> beaker);
    double getMassReading();

public: // Other methods
};

#endif