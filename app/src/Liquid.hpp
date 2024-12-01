#ifndef LIQUID
#define LIQUID

#include "Substance.hpp"

/** @author @yoitsmedarls
 * @brief A child of the Substance class that defines the liquids that will be placed
 * inside of containers (i.e. water).
 */
class Liquid : public Substance
{
private: // Class fields
    double m_boilingPoint;
    double m_freezingPoint;

public: // Special methods
    /// @brief Default constructor, initializes every field with 0 or its equivalent
    Liquid();

    /// @brief Constructor with arguments for the class fields. Since the object has just been constructed,
    /// it is not contained in a Container by default.
    Liquid(std::string name, double mass, double temperature, double specificHeatCapacity, double density,
           double boilingPoint, double freezingPoint);

    /// @brief Copy constructor. Handles cases where you pass a Liquid object to the Liquid constructor.
    /// @param copy
    Liquid(const Liquid &copy);

    /// @brief Destructor
    ~Liquid();

public: // Operator overloads
    /// @brief Copy assignment operator. Handles cases where you assign a blank Liquid object with another
    /// pre-existing Liquid object. It prevents extra copies.
    /// @param copy
    /// @return
    inline Liquid &operator=(const Liquid &);

public: // Getters and Setters
    double getBoilingPoint();
    double getFreezingPoint();

    void setBoilingPoint(double boilingPoint);
    void setFreezingPoint(double freezingPoint);

public: // Other methods
    /// @brief A method-override of the one from the parent class. Just adds extra lines to the log
    /// for the new fields in the Liquid class.
    void printProperties();
};

#endif