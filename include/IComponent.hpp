#ifndef COMPONENT
#define COMPONENT

#include <iostream>

class IComponent
{
private: // Class fields
public:  // Special methods
    IComponent();
    IComponent(const IComponent &copy);
    virtual ~IComponent() {};

public: // Operator overloads
    IComponent &operator=(const IComponent &copy);

public: // Getters and Setters
public: // Other methods
};

#endif