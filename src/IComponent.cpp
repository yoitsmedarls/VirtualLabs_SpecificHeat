#include "IComponent.hpp"

IComponent::IComponent()
{
}

IComponent::IComponent(const IComponent &copy)
{
}

IComponent &IComponent::operator=(const IComponent &copy)
{
    std::cout << "Sprite2DComponent | Copy assignment operator used...\n";

    if (&copy == this)
    {
        return *this;
    }

    return *this;
}
