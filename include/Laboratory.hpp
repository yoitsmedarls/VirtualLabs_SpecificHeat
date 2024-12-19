#ifndef ROOM
#define ROOM

#include "Renderable.hpp"
#include <iostream>
#include <string>

class Laboratory : public Renderable
{
private: // Class fields
    double m_ambientTemperature;

public: // Special methods
    Laboratory();
    Laboratory(std::string textureFilePath);
    Laboratory(const Laboratory &copy);
    ~Laboratory();

public: // Operator overloads
    Laboratory &operator=(const Laboratory &copy);

public: // Getters and Setters
public: // Other methods
};

#endif