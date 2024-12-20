#ifndef SUBSTANCE
#define SUBSTANCE

#include <string>

namespace vl
{
    /**
     * @author @yoitsmedarls
     * @brief  The base class for all objects designed to be 'placed' or
     *         'put inside' objects from (or derived from) the Container class.
     */
    class Substance
    {
    protected: /** Properties *************************************************/
        double m_mass;
        double m_density;
        double m_volume;
        double m_temperature;
        double m_specificHeatCapacity;

    public: /** Public properties *********************************************/
        bool isinContainer;

    public: /** Special member functions **************************************/
        /**
         * @brief   Construct a new Substance object.
         * @details Serves as the default constructor. It initializes every
         *          field with 0 or its equivalent.
         */
        Substance();

        /**
         * @brief   Construct a new Substance object with supplied parameters
         * @details Constructor with arguments for the class fields. Since the
         *          object has just been constructed, it is not contained in a
         *          Container by default.
         *
         * @param mass                 Substances must have a mass.
         * @param density              The mass and density values supplied
         *                             in this constructor is used to
         *                             calculate volume.
         * @param temperature          Key parameter given that the simulated
         *                             experiment is a specific heat experiment.
         * @param specificHeatCapacity Refer to https://en.wikipedia.org/wiki/Table_of_specific_heat_capacities
         *                             for the specific heat capacity of your
         *                             chosen substance.
         */
        Substance(double mass,
                  double density,
                  double temperature,
                  double specificHeatCapacity);

        /**
         * @brief   Copy constructor of the Substance class.
         * @details Constructs a Substance object as a copy of another one.
         *
         * @param copy A pre-existing, pre-initialized Substance object that
         *             is passed by reference.
         */
        Substance(const Substance &copy);

        /**
         * @brief Destroy the Substance object.
         */
        ~Substance();

    public: /** Operator overloads ********************************************/
        /**
         * @brief   Copy assignment operator of the Substance class.
         * @details Handles cases where you assign a blank Substance object
         *          with another pre-existing Substance object. It prevents
         *          extra copies.
         *
         * @param copy
         * @return Substance&
         */
        Substance &operator=(const Substance &copy);

    public: /** Getters and Setters *******************************************/
        double getMass();
        void setMass(double mass);

        double getDensity();
        void setDensity(double density);

        double getVolume();

        double getTemperature();
        void modifyTemperature(double deltaTemperature);
        void setTemperature(double temperature);

        double getSpecificHeatCapacity();
        void setSpecificHeatCapacity(double specificHeatCapacity);

    public: /** Other member functions ****************************************/
        /**
         * @brief   Calculates volume from the mass and density values.
         * @details Updates the volume of the Substance upon changes to the
         *          other aforementioned fields. Usually called inside other
         *          methods that change the value of the fields (i.e. setters).
         */
        void updateVolume();
    };

} // namespace vl

#endif