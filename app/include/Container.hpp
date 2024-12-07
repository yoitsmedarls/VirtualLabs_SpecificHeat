#ifndef CONTAINER
#define CONTAINER

#include "Substance.hpp"
#include "Liquid.hpp"
#include "Metal.hpp"

/**
 * @author @yoitsmedarls
 * @brief  The base class for all objects designed to 'contain' other objects
 *         from the Liquid and Metal class.
 */
class Container
{
protected: // Class fields
    std::string m_name;
    double m_diameter;
    double m_height;
    double m_totalVolume;
    double m_availableVolume;
    double m_topSurfaceArea;
    Liquid *m_liquid;
    Metal *m_metal;

public: // Special methods
    /**
     * @brief   Construct a new Container object.
     * @details Default constructor, initializes every field with 0 or its
     *          equivalent
     */
    Container();

    /**
     * @brief   Construct a new Container object with supplied parameters
     * @details Constructor with arguments for the class fields. This
     *          constructor DOES NOT include parameters for the pointers to
     *          the Liquid and Metal objects inside the Container.
     *
     * @param name
     * @param diameter
     * @param height
     * @param containedLiquid
     * @param containedMetal
     */
    Container(std::string name,
              double diameter,
              double height);

    /**
     * @brief   Construct a new Container object with supplied parameters
     * @details Constructor with arguments for the class fields. This
     *          constructor includes parameters for the pointers to
     *          the Liquid and Metal objects inside the Container
     *
     * @param name
     * @param diameter
     * @param height
     * @param liquid
     * @param metal
     */
    Container(std::string name,
              double diameter,
              double height,
              Liquid &liquid,
              Metal &metal);

    /**
     * @brief   Copy constructor of the Container class.
     * @details Constructs a Container object as a copy of another one.
     *
     * @param copy A pre-existing, pre-initialized Container object that is
     *             passed by reference.
     */
    Container(const Container &copy);

    /**
     * @brief Destroy the Container object
     */
    ~Container();

public: // Operator overloads
    /**
     * @brief   Copy assignment operator of the Container class.
     * @details Handles cases where you assign a blank Container object with
     *          another pre-existing Container object. It prevents extra copies.
     *
     * @param copy
     * @return Container&
     */
    Container &operator=(const Container &copy);

public: // Getters and Setters
    std::string getName();
    double getDiameter();
    double getHeight();
    double getVolume();
    double getTopSurfaceArea();
    Liquid *getContainedLiquid();
    Metal *getContainedMetal();

    void setName(std::string name);
    void setDiameter(double diameter);
    void setHeight(double height);
    void placeObjectInContainer(Liquid &liquid);
    void placeObjectInContainer(Metal &metal);

public: // Other methods
    /**
     * @brief   Calculates topSurfaceArea from the Container's
     *          diameter and height values.
     * @details Updates the topSurfaceArea upon changes to the other
     *          aforementioned fields. Usually called inside other
     *          methods that change the value of fields (i.e. setters).
     */
    void updateTopSurfaceArea();

    /**
     * @brief   Calculates volume from the Container's
     *          diameter and height values.
     * @details Updates the volume changes to the other aforementioned
     *          fields. Usually called inside other methods that change
     *          the value of fields (i.e. setters).
     */
    void updateVolume();

    /**
     * @brief  For debugging. Prints out the properties of the class in the
     *         console for review.
     */
    void printProperties();
};

#endif