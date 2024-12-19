#include "RenderComponent.hpp"

namespace vl
{

    RenderComponent::RenderComponent(std::string name,
                                     std::string textureFilePath)
    {
        m_name = name;
        m_texture.loadFromFile(textureFilePath);
        m_sprite.setTexture(m_texture);
    }

    RenderComponent::RenderComponent(const RenderComponent &copy)
    {
        m_name = copy.m_name;
        m_texture = copy.m_texture;
        m_sprite = copy.m_sprite;
    }

    RenderComponent::~RenderComponent()
    {
    }

    RenderComponent &RenderComponent::operator=(const RenderComponent &copy)
    {
        std::cout << "RenderComponent | Copy assignment operator used...\n";

        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    void RenderComponent::renderComponent(sf::RenderWindow &targetWindow)
    {
        targetWindow.draw(m_sprite);
    }
}
