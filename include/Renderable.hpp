#ifndef RENDER
#define RENDER

#include <SFML/Graphics.hpp>
#include <string>

class Renderable
{
private: // Class fields
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Text m_text;

public: // Special methods
    Renderable() {};
    Renderable(std::string textureFilePath);
    Renderable(std::string string, sf::Font &font, sf::Color &color, int fontSize);
    Renderable(const Renderable &copy);
    ~Renderable();

public: // Operator overloads
    Renderable &operator=(const Renderable &copy);

public: // Other methods
    sf::Sprite *getSprite();

    void setTextureFromFilePath(std::string textureFilePath);
    void setString(std::string string);

    void setSpriteOrigin(int xIndex, int yIndex);
    sf::Vector2f getSpriteOrigin();

    void setTextOrigin(int xIndex, int yIndex);
    sf::Vector2f getTextOrigin();

    void setTextPosition(int x, int y);
    sf::Vector2f getTextPosition();

    void setSpritePosition(int x, int y);
    sf::Vector2f getSpritePosition();

    void Render(sf::RenderWindow &window);
};

#endif