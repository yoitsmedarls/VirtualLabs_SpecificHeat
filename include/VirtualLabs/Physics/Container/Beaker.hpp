#ifndef BEAKER
#define BEAKER

#include "Container.hpp"
#include "HeatSource.hpp"
#include "Laboratory.hpp"

/**
 * @author @yoitsmedarls
 * @brief  A child of the Container class. Beaker is a non-isolated container
 *         with methods for Beaker-specific tasks in the simulation.
 */
class Beaker : public Container
{
private:
    HeatSource *m_heatSource;
    Laboratory *m_room;

public: // Special methods
    Beaker();
    Beaker(const Beaker &copy);
    ~Beaker();

public: // Operator overloads
    Beaker &operator=(const Beaker &copy);

public: // Getters and Setters
public: // Other methods
};

#endif