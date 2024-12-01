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
    /// @brief Default constructor, initializes every field with 0 or its equivalent
    Substance();

    /// @brief Constructor with arguments for the class fields. Since the object has just been constructed,
    /// it is not contained in a Container by default.
    Substance(std::string name, double mass, double temperature, double specificHeatCapacity, double density);

    /// @brief Copy constructor. Handles cases where you pass a Substance object to the Substance constructor.
    /// @param copy
    Substance(const Substance &copy);

    /// @brief Destructor
    ~Substance();

public: // Operator overloads
    /// @brief Copy assignment operator. Handles cases where you assign a blank Substance object with another
    /// pre-existing Substance object. It prevents extra copies.
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

    /// @brief Updates the volume of the Substance upon changes to other fields.
    /// Usually called inside other methods that change the value of fields (i.e. setters)
    void updateVolume();

    /// @brief For debugging. Prints out the properties of the class in the console
    void printProperties();
};

#endif