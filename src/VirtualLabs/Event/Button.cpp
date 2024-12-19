#include "Button.hpp"

#include <iostream>

Button::Button()
    : Renderable()
{
}

Button::Button(std::string textureFilePath)
    : Renderable(textureFilePath)
{
}

Button::Button(const Button &copy)
    : Renderable(copy)
{
}

Button::~Button()
{
}

Button &Button::operator=(const Button &copy)
{
    std::cout << "Button | Copy assignment operator used...\n";

    if (&copy == this)
    {
        return *this;
    }

    return *this;
}
