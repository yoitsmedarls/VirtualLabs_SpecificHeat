#include "RenderableComponent.hpp"

namespace vl
{

    RenderableComponent::RenderableComponent(std::string textureFilePath)
    {
        m_texture.loadFromFile(textureFilePath);
        m_sprite.setTexture(m_texture);
    }

    RenderableComponent::RenderableComponent(const RenderableComponent &copy)
    {
        m_texture = copy.m_texture;
        m_sprite = copy.m_sprite;
    }

    RenderableComponent::~RenderableComponent()
    {
    }

    RenderableComponent &RenderableComponent::operator=(const RenderableComponent &copy)
    {
        std::cout << "RenderableComponent | Copy assignment operator used...\n";

        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    void RenderableComponent::render(sf::RenderWindow &targetWindow)
    {
        targetWindow.draw(m_sprite);
    }
}
