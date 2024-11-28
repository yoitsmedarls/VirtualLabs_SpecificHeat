#ifndef METAL
#define METAL

#include "Substance.hpp"

class Metal : public Substance
{
private: // Class fields
    double m_sideLength;

public: // Special methods
    /// @brief Default constructor
    Metal();

    /// @brief Constructor with arguments for the class fields
    Metal(double mass, double temperature, double specificHeatCapacity, double sideLength);

    /// @brief Copy constructor
    /// @param copy
    Metal(const Metal &copy);

    /// @brief Destructor
    ~Metal();

public: // Operator overloads
    /// @brief Copy assignment operator
    /// @param copy
    /// @return
    Metal &operator=(const Metal &copy);

public: // Getters and Setters
    double getSideLength();

    void setLength(double length);
    void setWidth(double width);
    void setHeight(double height);

public: // Other methods
    void updateMetalVolume();
};

#endif