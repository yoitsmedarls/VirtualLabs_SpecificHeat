#include "Sprite2DComponent.hpp"

namespace vl
{

    Sprite2DComponent::Sprite2DComponent(std::string name,
                                         std::string textureFilePath)
    {
        m_name = name;
        m_texture.loadFromFile(textureFilePath);
        m_sprite.setTexture(m_texture);
    }

    Sprite2DComponent::Sprite2DComponent(const Sprite2DComponent &copy)
    {
        m_name = copy.m_name;
        m_texture = copy.m_texture;
        m_sprite = copy.m_sprite;
    }

    Sprite2DComponent::~Sprite2DComponent()
    {
    }

    Sprite2DComponent &Sprite2DComponent::operator=(const Sprite2DComponent &copy)
    {
        std::cout << "Sprite2DComponent | Copy assignment operator used...\n";

        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    void Sprite2DComponent::renderComponent(sf::RenderWindow &targetWindow)
    {
        targetWindow.draw(m_sprite);
    }
}
