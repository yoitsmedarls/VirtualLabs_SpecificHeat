#ifndef METAL
#define METAL

#include "Substance.hpp"

/** @author @yoitsmedarls
 * @brief A child of the Substance class that defines the liquids that will be placed
 * inside of containers (i.e. water).
 */
class Metal : public Substance
{
private: // Class fields
    double m_sideLength;
    bool m_isSubmerged;

public: // Special methods
    /// @brief Default constructor, initializes every field with 0 or its equivalent
    Metal();

    /// @brief Constructor with arguments for the class fields. Since the object has just been constructed,
    /// it is not contained in a Container by default.
    Metal(std::string name, double mass, double temperature, double specificHeatCapacity, double density);

    /// @brief Copy constructor. Handles cases where you pass a Liquid object to the Liquid constructor.
    /// @param copy
    Metal(const Metal &copy);

    /// @brief Destructor
    ~Metal();

public: // Operator overloads
    /// @brief Copy assignment operator. Handles cases where you assign a blank Metal object with another
    /// pre-existing Metal object. It prevents extra copies.
    /// @param copy
    /// @return
    Metal &operator=(const Metal &copy);

public: // Getters and Setters
    double getSideLength();

    void setDensity(double density);
    void setMass(double volume);

public: // Other methods
    /// @brief A method that checks if the Metal is submerged in a Liquid in a Container
    /// @return True if contained in a Container with a Liquid. Otherwise, False
    bool isMetalSubmerged();

    /// @brief Updates the sideLength field when changes to the mass or density of the Metal object is made.
    void updateSideLength();

    /// @brief A method-override of the one from the parent class. Just adds extra lines to the log
    /// for the new fields in the Metal class.
    void printProperties();
};

#endif