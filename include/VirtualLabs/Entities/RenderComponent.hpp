#ifndef SPRITE_2D_COMPONENT
#define SPRITE_2D_COMPONENT

#include <SFML/Graphics.hpp>
#include <string>

#include "IComponent.hpp"

namespace vl
{
    class RenderComponent : public IComponent
    {
    private: // Class fields
        std::string m_name;
        sf::Texture m_texture;
        sf::Sprite m_sprite;

    public: // Special methods
        RenderComponent(std::string name,
                        std::string textureFilePath);

        RenderComponent(const RenderComponent &copy);

        ~RenderComponent();

    public: // Operator overloads
        RenderComponent &operator=(const RenderComponent &copy);

    public: // Getters and Setters
    public: // Other methods
        void renderComponent(sf::RenderWindow &targetWindow);
    };
}

#endif