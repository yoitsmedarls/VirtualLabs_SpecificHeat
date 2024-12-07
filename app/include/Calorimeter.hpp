#ifndef CALORIMETER
#define CALORIMETER

#include "Container.hpp"

/**
 * @author @yoitsmedarls
 * @brief  A child of the Container class. Calorimeter is an isolated container
 *         with methods for Calorimeter-specific tasks in the simulation.
 */
class Calorimeter : public Container
{
private:
public:
    Calorimeter(/* args */);
    ~Calorimeter();
};

#endif