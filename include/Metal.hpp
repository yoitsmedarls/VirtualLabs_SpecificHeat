#ifndef METAL
#define METAL

#include "Substance.hpp"

namespace vl
{
    /**
     * @author @yoitsmedarls
     * @brief  A child of the Substance class that defines the metals that
     *         will be placed inside of containers (i.e. aluminum).
     */
    class Metal : public Substance
    {
    private: /** Properties ***************************************************/
        double m_sideLength;

    public: /** Special member functions **************************************/
        /**
         * @brief   Construct a new Liquid object.
         * @details Serves as the default constructor. It initializes every
         *          field with 0 or its equivalent.
         */
        Metal();

        /**
         * @brief   Construct a new Liquid object with supplied parameters
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
        Metal(double mass,
              double density,
              double temperature,
              double specificHeatCapacity);

        /**
         * @brief   Copy constructor of the Metal class.
         * @details Constructs a Metal object as a copy of another one.
         *
         * @param copy A pre-existing, pre-initialized Metal object that is
         *             passed by reference.
         */
        Metal(const Metal &copy);

        /**
         * @brief Destroy the Metal object
         */
        ~Metal();

    public: /** Operator overloads ********************************************/
        /**
         * @brief   Copy assignment operator of the Metal class.
         * @details Handles cases where you assign a blank Metal object with
         *          another pre-existing Metal object. It prevents extra copies.
         *
         * @param copy
         * @return Metal&
         */
        Metal &operator=(const Metal &copy);

    public: /** Getters and Setters *******************************************/
        double getSideLength();

        void setMass(double volume);

        void setDensity(double density);

    public: /** Other member functions ****************************************/
        /**
         * @brief   Calculates sideLength from the Metal's volume.
         * @details Updates the sideLength field when changes to the mass
         *          or density of the Metal object is made. Usually called
         *          inside other methods that change the value of fields
         *          (i.e. setters).
         */
        void updateSideLength();
    };

} // namespace vl

#endif