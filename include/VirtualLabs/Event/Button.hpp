#ifndef BUTTON
#define BUTTON

#include "Renderable.hpp"
#include "Clickable.hpp"

class Button : public Clickable, public Renderable
{
private: // Class fields
public:  // Special methods
    Button();
    Button(std::string textureFilePath);
    Button(const Button &copy);
    ~Button();

public: // Operator overloads
    Button &operator=(const Button &copy);

public: // Getters and Setters
public: // Other methods
};

#endif