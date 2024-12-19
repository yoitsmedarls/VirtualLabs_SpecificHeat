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

    void Entity::addRenderComponent(std::string name,
                                    std::string textureFilePath)
    {
        std::shared_ptr<RenderComponent> RenderComponent =
            std::make_shared<RenderComponent>(name, textureFilePath);

        m_components.push_back(RenderComponent);
    }

    void Entity::renderAllComponents(sf::RenderWindow &window)
    {
        for (int i = 0; i < m_components.size(); i++)
        {
            m_components.at(i)->renderComponent();
        }
    }
}
