#ifndef SPRITE_2D_COMPONENT
#define SPRITE_2D_COMPONENT

#include <SFML/Graphics.hpp>
#include <string>

#include "IComponent.hpp"

namespace vl
{
    class RenderableComponent : public IComponent
    {
    private: // Class fields
        sf::Texture m_texture;
        sf::Sprite m_sprite;

    public: // Special methods
        RenderableComponent(std::string textureFilePath);
        RenderableComponent(const RenderableComponent &copy);
        ~RenderableComponent();

    public: // Operator overloads
        RenderableComponent &operator=(const RenderableComponent &copy);

    public: // Getters and Setters
    public: // Other methods
        void render(sf::RenderWindow &targetWindow);
    };
}

#endif