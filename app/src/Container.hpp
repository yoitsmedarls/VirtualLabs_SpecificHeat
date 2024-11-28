#ifndef CONTAINER
#define CONTAINER

#include "Substance.hpp"
#include "Liquid.hpp"
#include "Metal.hpp"

class Container
{
protected: // Class fields
    double m_diameter;
    double m_height;
    double m_volume;
    double m_topSurfaceArea;
    Liquid m_containedLiquid;
    Metal m_containedMetal;

public: // Special methods
    /// @brief Default constructor
    Container();

    /// @brief Constructor with arguments for the class fields
    Container(double diameter, double height, Liquid &containedLiquid, Metal &containedMetal);

    /// @brief Copy constructor
    /// @param copy
    Container(const Container &copy);

    /// @brief Destructor
    ~Container();

public: // Operator overloads
    /// @brief Copy assignment operator
    /// @param copy
    /// @return
    Container &operator=(const Container &copy);

public: // Getters and Setters
    double getDiameter();
    double getHeight();
    double getVolume();
    double getTopSurfaceArea();
    Liquid getContainedLiquid();
    Metal getContainedMetal();

    void setDiameter();
    void setHeight();
    void setContainedLiquid();
    void setContainedMetal();

public: // Other methods
    void updateVolumeAndTopSurfaceArea();
};

#endif