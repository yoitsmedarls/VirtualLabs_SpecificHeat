#ifndef RENDER
#define RENDER

#include <SFML/Graphics.hpp>
#include <string>

class Renderable
{
private: // Class fields
    sf::Texture m_texture;
    sf::Sprite m_sprite;

public: // Special methods
    Renderable() {};
    Renderable(std::string textureFilePath);
    Renderable(const Renderable &copy);
    ~Renderable();

public: // Operator overloads
    Renderable &operator=(const Renderable &copy);

public: // Other methods
    sf::Sprite *getRenderable();
    void setAnchor(int xIndex, int yIndex);
    void setPositionRelativeToWindow(int xIndex, int yIndex, sf::RenderWindow &window);

    void Render(sf::RenderWindow &window);
};

#endif