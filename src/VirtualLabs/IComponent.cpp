#include "IComponent.hpp"

namespace vl
{
    IComponent::IComponent()
    {
    }

    IComponent::IComponent(const IComponent &copy)
    {
    }

    IComponent &IComponent::operator=(const IComponent &copy)
    {
        std::cout << "RenderComponent | Copy assignment operator used...\n";

        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }
}
