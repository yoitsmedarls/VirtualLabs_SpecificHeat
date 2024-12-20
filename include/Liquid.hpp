#ifndef LIQUID
#define LIQUID

#include "Substance.hpp"

namespace vl
{
    /**
     * @author @yoitsmedarls
     * @brief A child of the Substance class that defines the liquids that
     *        will be placed inside of containers (i.e. water).
     */
    class Liquid : public Substance
    {
    private: /** Properties ***************************************************/
        double m_boilingPoint;
        double m_freezingPoint;

    public: /** Special member functions **************************************/
        /**
         * @brief   Construct a new Liquid object.
         * @details Serves as the default constructor. It initializes every
         *          field with 0 or its equivalent.
         */
        Liquid();

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
         * @param boilingPoint         Unique to the Liquid class. Used for the
         *                             simulation of heating the liquid in a
         *                             Container using a HotPlate.
         * @param freezingPoint        Not really useful for the simulation,
         *                             but who cares :P
         */
        Liquid(double mass,
               double density,
               double temperature,
               double specificHeatCapacity,
               double boilingPoint,
               double freezingPoint);

        /**
         * @brief   Copy constructor of the Liquid class.
         * @details Constructs a Liquid object as a copy of another one.
         *
         * @param copy A pre-existing, pre-initialized Liquid object that is
         *             passed by reference.
         */
        Liquid(const Liquid &copy);

        /**
         * @brief Destroy the Substance object.
         */
        ~Liquid();

    public: /** Operator overloads ********************************************/
        /**
         * @brief   Copy assignment operator of the Liquid class.
         * @details Handles cases where you assign a blank Liquid object
         *          with another pre-existing Liquid object.
         *          It prevents extra copies.
         *
         * @param copy
         * @return Liquid&
         */
        Liquid &operator=(const Liquid &);

    public: /** Getters and Setters *******************************************/
        double getBoilingPoint();
        void setBoilingPoint(double boilingPoint);

        double getFreezingPoint();
        void setFreezingPoint(double freezingPoint);
    };

} // namespace vl

#endif