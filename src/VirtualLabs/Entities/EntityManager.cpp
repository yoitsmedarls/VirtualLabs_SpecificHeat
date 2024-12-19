#include "EntityManager.hpp"

namespace vl
{
    EntityManager &EntityManager::Instance()
    {
        static EntityManager *instance = new EntityManager;
        return *instance;
    }

    std::shared_ptr<Entity> EntityManager::createEntity(std::string name)
    {
        std::shared_ptr<Entity> entity = std::make_shared<Entity>(name);
        m_entities.insert(std::make_pair(name, entity));

        return entity;
    }

    std::shared_ptr<Entity> EntityManager::getEntity(std::string name)
    {
        return m_entities[name];
    }

    void EntityManager::RenderEntities(sf::RenderWindow &window)
    {
        for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        {
            it->second->renderAllComponents(window);
        }
    }
}