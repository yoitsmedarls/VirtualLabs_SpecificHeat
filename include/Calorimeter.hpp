#ifndef CALORIMETER
#define CALORIMETER

/**
 * @author @yoitsmedarls
 * @brief  A child of the Container class. Calorimeter is an isolated container
 *         with methods for Calorimeter-specific tasks in the simulation.
 */
class Calorimeter
{
private: // Class fields
public:  // Special methods
    Calorimeter();
    Calorimeter();
    Calorimeter(const Calorimeter &copy);
    ~Calorimeter();

public: // Operator overloads
    Calorimeter &operator=(const Calorimeter &copy);

public: // Getters and Setters
public: // Other methods
};

#endif