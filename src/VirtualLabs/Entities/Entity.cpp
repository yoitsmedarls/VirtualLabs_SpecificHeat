#include "Entity.hpp"

namespace vl
{
    Entity::Entity(std::string name)
    {
        m_name = name;
    }

    Entity::Entity(const Entity &copy)
    {
    }

    Entity::~Entity()
    {
    }

    Entity &Entity::operator=(const Entity &copy)
    {
        std::cout << "Entity | Copy assignment operator used...\n";

        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    void Entity::addSprite2DComponent(std::string name,
                                      std::string textureFilePath)
    {
        std::shared_ptr<Sprite2DComponent> sprite2DComponent =
            std::make_shared<Sprite2DComponent>(name, textureFilePath);

        m_components.push_back(sprite2DComponent);
    }

    void Entity::renderAllComponents(sf::RenderWindow &window)
    {
        for (int i = 0; i < m_components.size(); i++)
        {
            m_components.at(i)->renderComponent();
        }
    }
}
