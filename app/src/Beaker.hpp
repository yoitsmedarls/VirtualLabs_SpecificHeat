#ifndef BEAKER
#define BEAKER

#include "Container.hpp"
#include "Room.hpp"
#include "HeatPlate.hpp"

class Beaker : public Container
{
private: // Class fields
    Room *pm_room;
    HeatPlate *pm_heatPlate;

public: // Special methods
    /// @brief Default constructor
    Beaker();

    /// @brief Constructor with arguments for the class fields
    Beaker(double diameter, double height, double volume, double topSurfaceArea,
           Liquid containedLiquid, Metal containedMetal,
           Room &room, HeatPlate &heatPlate);

    /// @brief Copy constructor
    /// @param copy
    Beaker(const Beaker &copy);

    /// @brief Destructor
    ~Beaker();

public: // Operator overloads
    /// @brief Copy assignment operator
    /// @param copy
    /// @return
    Beaker &operator=(const Beaker &copy);

public: // Getters and Setters
    Room *getRoomAddress();
    HeatPlate *getHeatPlateAddress();

    void setRoom(Room &room);
    void setHeatPlate(HeatPlate &heatPlate);

public: // Other methods
};

#endif