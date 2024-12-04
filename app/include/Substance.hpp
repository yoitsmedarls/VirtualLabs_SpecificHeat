#ifndef SUBSTANCE
#define SUBSTANCE

#include <string>

/**
 * @author @yoitsmedarls
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
    /**
     * @brief   Construct a new Substance object.
     * @details Serves as the default constructor. It initializes every field with 0 or its equivalent.
     */
    Substance();

    /**
     * @brief   Construct a new Substance object with supplied parameters
     * @details Constructor with arguments for the class fields.Since the object has just been constructed,
     *          it is not contained in a Container by default.
     *
     * @param name                 Give the substance a name for identification purposes. Used in debugging.
     * @param mass                 Substances must have a mass.
     * @param temperature          Key parameter given that the simulated experiment is a specific heat experiment.
     * @param specificHeatCapacity Refer to
     *                             @link https://en.wikipedia.org/wiki/Table_of_specific_heat_capacities @endlink
     *                             for the specific heat capacity of your chosen substance.
     * @param density              The mass and density values supplied in this constructor is used to calculate volume.
     */
    Substance(std::string name, double mass, double temperature, double specificHeatCapacity, double density);

    /**
     * @brief Copy constructor. Constructs a Substance object as a copy of another one.
     *
     * @param copy A pre-existing, pre-initialized Substance object that is passed by reference.
     */
    Substance(const Substance &copy);

    /**
     * @brief Destroy the Substance object
     *
     */
    ~Substance();

public: // Operator overloads
    /**
     * @brief   Copy assignment operator.
     * @details Handles cases where you assign a blank Substance object with another
     *          pre-existing Substance object. It prevents extra copies.
     *
     * @param copy
     * @return Substance&
     */
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
    /**
     * @brief A method that checks if the Substance is in a Container
     *
     * @return true if the Substance is contained within a Container object
     * @return false if not
     */
    bool isSubstanceContained();

    /**
     * @brief   Calculates volume from the Substance's mass and density values.
     * @details Updates the volume of the Substance upon changes to the other aforementioned fields.
     *          Usually called inside other methods that change the value of fields (i.e. setters).
     */
    void updateVolume();

    /**
     * @brief  For debugging. Prints out the properties of the class in the console
     *
     */
    void printProperties();
};

#endif