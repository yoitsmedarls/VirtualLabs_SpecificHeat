#ifndef SUBSTANCE
#define SUBSTANCE

#include <string>

/**
 * @author @yoitsmedarls
 * @brief  The base class for all objects designed to be 'placed' or
 *         'put inside' objects from (or derived from) the Container class.
 */
class Substance
{
protected: // Class fields
    std::string m_name;
    double m_mass;
    double m_density;
    double m_volume;
    double m_temperature;
    double m_specificHeatCapacity;

public: // Special methods
    /**
     * @brief   Construct a new Substance object.
     * @details Serves as the default constructor. It initializes every field
     *          with 0 or its equivalent.
     */
    Substance();

    /**
     * @brief   Construct a new Substance object with supplied parameters
     * @details Constructor with arguments for the class fields. Since the
     *          object has just been constructed, it is not contained in a
     *          Container by default.
     *
     * @param name                 Give the substance a name for identification
     *                             purposes. Used in debugging.
     * @param mass                 Substances must have a mass.
     * @param density              The mass and density values supplied in this
     *                             constructor is used to calculate volume.
     * @param temperature          Key parameter given that the simulated
     *                             experiment is a specific heat experiment.
     * @param specificHeatCapacity Refer to https://en.wikipedia.org/wiki/Table_of_specific_heat_capacities
     *                             for the specific heat capacity of your chosen
     *                             substance.
     */
    Substance(std::string name,
              double mass,
              double density,
              double temperature,
              double specificHeatCapacity);

    /**
     * @brief   Copy constructor of the Substance class.
     * @details Constructs a Substance object as a copy of another one.
     *
     * @param copy A pre-existing, pre-initialized Substance object that is
     *             passed by reference.
     */
    Substance(const Substance &copy);

    /**
     * @brief Destroy the Substance object.
     */
    ~Substance();

public: // Operator overloads
    /**
     * @brief   Copy assignment operator of the Substance class.
     * @details Handles cases where you assign a blank Substance object with
     *          another pre-existing Substance object. It prevents extra copies.
     *
     * @param copy
     * @return Substance&
     */
    Substance &operator=(const Substance &copy);

public: // Getters and Setters
    std::string getName();
    double getMass();
    double getDensity();
    double getVolume();
    double getTemperature();
    double getSpecificHeatCapacity();

    void setName(std::string name);
    void setMass(double mass);
    void setDensity(double density);
    void setTemperature(double temperature);
    void setSpecificHeatCapacity(double specificHeatCapacity);

public: // Other methods
    /**
     * @brief   Calculates volume from the Substance's mass and density values.
     * @details Updates the volume of the Substance upon changes to the other
     *          aforementioned fields. Usually called inside other methods that
     *          change the value of fields (i.e. setters).
     */
    void updateVolume();

    /**
     * @brief  For debugging. Prints out the properties of the class in the
     *         console for review.
     */
    void printProperties();
};

#endif