#ifndef SPRITE_2D_COMPONENT
#define SPRITE_2D_COMPONENT

#include <SFML/Graphics.hpp>
#include <string>

#include "IComponent.hpp"

class Sprite2DComponent : public IComponent
{
private: // Class fields
    std::string m_name;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

public: // Special methods
    Sprite2DComponent();

    Sprite2DComponent(std::string name,
                      std::string textureFilePath);

    Sprite2DComponent(const Sprite2DComponent &copy);

    ~Sprite2DComponent();

public: // Operator overloads
    Sprite2DComponent &operator=(const Sprite2DComponent &copy);

public: // Getters and Setters
public: // Other methods
    void renderToWindow(sf::RenderWindow &targetWindow);
};

#endif