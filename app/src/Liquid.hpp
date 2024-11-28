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
    /// @brief Default constructor
    Liquid();

    /// @brief Constructor with arguments for the class fields
    Liquid(std::string name, double mass, double temperature, double specificHeatCapacity,
           double density, double boilingPoint, double freezingPoint);

    /// @brief Copy constructor
    /// @param copy
    Liquid(const Liquid &copy);

    /// @brief Destructor
    ~Liquid();

public: // Operator overloads
    /// @brief Copy assignment operator
    /// @param copy
    /// @return
    inline Liquid &operator=(const Liquid &);

public: // Getters and Setters
    double getBoilingPoint();
    double getFreezingPoint();

    void setBoilingPoint(double boilingPoint);
    void setFreezingPoint(double freezingPoint);

public: // Other methods
    void printProperties();
};

#endif