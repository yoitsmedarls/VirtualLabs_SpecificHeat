#ifndef CONTAINER
#define CONTAINER

#include "Substance.hpp"
#include "Liquid.hpp"
#include "Metal.hpp"

/**
 * @author @yoitsmedarls
 * @brief The base class for all objects designed to 'contain' other objects
 * from the Liquid and Metal class.
 */
class Container
{
protected: // Class fields
    std::string m_name;
    double m_diameter;
    double m_height;
    double m_volume;
    double m_topSurfaceArea;
    Liquid *m_liquid;
    Metal *m_metal;
    bool m_hasLiquid;
    bool m_hasMetal;

public: // Special methods
    /// @brief Default constructor, initializes every field with 0 or its equivalent
    Container();

    /// @brief Constructor with arguments for the class fields.
    Container(std::string name, double diameter, double height, Liquid &containedLiquid, Metal &containedMetal);

    /// @brief Copy constructor. Handles cases where you pass a Container object to the Container constructor.
    /// @param copy
    Container(const Container &copy);

    /// @brief Destructor
    ~Container();

public: // Operator overloads
    /// @brief Copy assignment operator. Handles cases where you assign a blank Container object with another
    /// pre-existing Container object. It prevents extra copies.
    /// @param copy
    /// @return
    Container &operator=(const Container &copy);

public: // Getters and Setters
    std::string getName();
    double getDiameter();
    double getHeight();
    double getVolume();
    double getTopSurfaceArea();
    Liquid getContainedLiquid();
    Metal getContainedMetal();

    void setName(std::string name);
    void setDiameter(double diameter);
    void setHeight(double height);
    void placeObjectInContainer(Liquid &liquid);
    void placeObjectInContainer(Metal &metal);

public: // Other methods
    void updateVolumeAndTopSurfaceArea();
    bool containsLiquid();
    bool containsMetal();
    void printProperties();
};

#endif