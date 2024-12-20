#ifndef CALORIMETER
#define CALORIMETER

#include "Container.hpp"

namespace vl
{
    /**
     * @author @yoitsmedarls
     * @brief  A child of the Container class. Calorimeter is an isolated
     *         container with methods for Calorimeter-specific tasks in
     *         the simulation.
     */
    class Calorimeter : public Container
    {
    public: /** Properties ***************************************************/
        double initTemperature;
        bool isIsolated = true;

    public: /** Special member functions **************************************/
        Calorimeter();
        Calorimeter(double diameter,
                    double height);
        Calorimeter(double diameter,
                    double height,
                    std::shared_ptr<Liquid> liquid,
                    std::shared_ptr<Metal> metal);
        Calorimeter(const Calorimeter &copy);
        ~Calorimeter();

    public: /** Operator overloads ********************************************/
        Calorimeter &operator=(const Calorimeter &copy);

    public: /** Getters and Setters *******************************************/
        // get set

    public: /** Other member functions ****************************************/
        // others
    };

} // namespace vl

#endif