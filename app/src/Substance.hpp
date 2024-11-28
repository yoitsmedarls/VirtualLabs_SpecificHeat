#ifndef SUBSTANCE
#define SUBSTANCE

#include <string>

/** @author @yoitsmedarls
 * @brief The base class for all objects designed to be 'placed' or 'put inside'
 * objects from (or derived from) the Container class.
 */
class Substance
{
protected: // Class fields
    std::string m_name;
    double m_mass;
    double m_temperature;
    double m_specificHeatCapacity;
    double m_density;
    double m_volume;
    bool m_isContained;

public: // Special methods
    /// @brief Default constructor
    Substance();

    /// @brief Constructor with arguments for the class fields
    Substance(std::string name, double mass, double temperature, double specificHeatCapacity, double density);

    /// @brief Copy constructor
    /// @param copy
    Substance(const Substance &copy);

    /// @brief Destructor
    ~Substance();

public: // Operator overloads
    /// @brief Copy assignment operator
    /// @param copy
    /// @return
    Substance &operator=(const Substance &copy);

public: // Getters and Setters
    std::string getName();
    double getMass();
    double getTemperature();
    double getSpecificHeatCapacity();
    double getDensity();
    double getVolume();

    void setName(std::string name);
    void setMass(double mass);
    void setTemperature(double temperature);
    void setSpecificHeatCapacity(double specificHeatCapacity);
    void setDensity(double density);

public: // Other methods
    /// @brief A method that checks if the Substance is in a Container
    /// @return True if contained within a Container. Otherwise, False
    bool isSubstanceContained();

    void updateVolume();
    void printProperties();
};

#endif