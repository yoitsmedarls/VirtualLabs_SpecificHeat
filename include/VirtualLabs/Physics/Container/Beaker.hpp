#ifndef BEAKER
#define BEAKER

#include "Container.hpp"
#include "HeatPlate.hpp"
#include "Laboratory.hpp"

/**
 * @author @yoitsmedarls
 * @brief  A child of the Container class. Beaker is a non-isolated container
 *         with methods for Beaker-specific tasks in the simulation.
 */
class Beaker : public Container, public Renderable
{
private:
public: // Special methods
    Beaker();
    Beaker(std::string textureFilePath,
           double diameter,
           double height);
    Beaker(std::string textureFilePath,
           double diameter,
           double height,
           std::shared_ptr<Liquid> liquid,
           std::shared_ptr<Metal> metal);
    Beaker(const Beaker &copy);
    ~Beaker();

public: // Operator overloads
    Beaker &operator=(const Beaker &copy);

public: // Getters and Setters
public: // Other methods
};

#endif