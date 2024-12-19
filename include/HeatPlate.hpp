#ifndef HEAT_PLATE
#define HEAT_PLATE

#include "Container.hpp"
#include "Renderable.hpp"

class HeatPlate : public Renderable
{
private: // Class fields
    int m_wattage;

public: // Special methods
    HeatPlate();
    HeatPlate(int wattage, std::string textureFilePath);
    HeatPlate(const HeatPlate &copy);
    ~HeatPlate();

public: // Operator overloads
    HeatPlate &operator=(const HeatPlate &copy);

public: // Getters and Setters
public: // Other methods
    void heatContainer(Container &container);
};

#endif