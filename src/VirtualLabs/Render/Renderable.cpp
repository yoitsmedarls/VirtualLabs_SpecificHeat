#include "Renderable.hpp"

#include <iostream>

Renderable::Renderable(std::string textureFilePath)
{
    m_texture.loadFromFile(textureFilePath);
    m_sprite.setTexture(m_texture);
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

sf::Sprite *Renderable::getRenderable()
{
    return &m_sprite;
}

void Renderable::setAnchor(int xIndex, int yIndex)
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

void Renderable::setPositionRelativeToWindow(int xIndex, int yIndex, sf::RenderWindow &window)
{
    int xPosition;
    int yPosition;

    switch (xIndex)
    {
    case 0:
        xPosition = 0;
        break;

    case 1:
        xPosition = window.getSize().x / 2;
        break;

    case 2:
        xPosition = window.getSize().x;
        break;

    default:
        break;
    }

    switch (yIndex)
    {
    case 0:
        yPosition = 0;
        break;

    case 1:
        yPosition = window.getSize().y / 2;
        break;

    case 2:
        yPosition = window.getSize().y;
        break;

    default:
        break;
    }

    m_sprite.setPosition(xPosition, yPosition);
}

void Renderable::Render(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}