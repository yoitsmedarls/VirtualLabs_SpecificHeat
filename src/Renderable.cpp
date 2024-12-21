#include "Renderable.hpp"

#include <iostream>

Renderable::Renderable(std::string textureFilePath)
{
    m_texture.loadFromFile(textureFilePath);
    m_sprite.setTexture(m_texture);
}

Renderable::Renderable(std::string string, sf::Font &font, sf::Color &color, int fontSize)
{
    m_text.setString(string);
    m_text.setFont(font);
    m_text.setFillColor(color);
    m_text.setCharacterSize(fontSize);
}

Renderable::Renderable(const Renderable &copy)
    : m_texture(copy.m_texture),
      m_sprite(copy.m_sprite)
{
}

Renderable::~Renderable()
{
}

Renderable &Renderable::operator=(const Renderable &copy)
{
    if (&copy == this)
    {
        return *this;
    }

    return *this;
}

sf::Sprite *Renderable::getSprite()
{
    return &m_sprite;
}

void Renderable::setTextureFromFilePath(std::string textureFilePath)
{
    m_texture.loadFromFile(textureFilePath);
    m_sprite.setTexture(m_texture);
}

void Renderable::setString(std::string string)
{
    m_text.setString(string);
}

void Renderable::setSpriteOrigin(int xIndex, int yIndex)
{
    int xAnchor;
    int yAnchor;

    switch (xIndex)
    {
    case 0:
        xAnchor = 0;
        break;

    case 1:
        xAnchor = m_texture.getSize().x / 2;
        break;

    case 2:
        xAnchor = m_texture.getSize().x;
        break;

    default:
        break;
    }

    switch (yIndex)
    {
    case 0:
        yAnchor = 0;
        break;

    case 1:
        yAnchor = m_texture.getSize().y / 2;
        break;

    case 2:
        yAnchor = m_texture.getSize().y;
        break;

    default:
        break;
    }

    m_sprite.setOrigin(xAnchor, yAnchor);
}

sf::Vector2f Renderable::getSpriteOrigin()
{
    return m_sprite.getOrigin();
}

void Renderable::setTextOrigin(int xIndex, int yIndex)
{
    int xAnchor;
    int yAnchor;

    switch (xIndex)
    {
    case 0:
        xAnchor = 0;
        break;

    case 1:
        xAnchor = m_text.getGlobalBounds().getSize().x / 2;
        break;

    case 2:
        xAnchor = m_text.getGlobalBounds().getSize().x;
        break;

    default:
        break;
    }

    switch (yIndex)
    {
    case 0:
        yAnchor = 0;
        break;

    case 1:
        yAnchor = m_text.getGlobalBounds().getSize().y / 2;
        break;

    case 2:
        yAnchor = m_text.getGlobalBounds().getSize().y;
        break;

    default:
        break;
    }

    m_text.setOrigin(xAnchor, yAnchor);
}

sf::Vector2f Renderable::getTextOrigin()
{
    return m_text.getOrigin();
}

void Renderable::setTextPosition(int x, int y)
{
    m_text.setPosition(x, y);
}

sf::Vector2f Renderable::getTextPosition()
{
    return m_text.getPosition();
}

void Renderable::setSpritePosition(int x, int y)
{
    m_sprite.setPosition(x, y);
}

sf::Vector2f Renderable::getSpritePosition()
{
    return m_sprite.getPosition();
}

void Renderable::Render(sf::RenderWindow &window)
{
    if (m_sprite.getTexture() != nullptr)
    {
        window.draw(m_sprite);
    }

    if (m_text.getString() != "")
    {
        window.draw(m_text);
    }
}