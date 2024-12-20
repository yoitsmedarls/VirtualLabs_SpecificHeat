#ifndef VIRTUAL_LABS_ENTITY_MANAGER
#define VIRTUAL_LABS_ENTITY_MANAGER

#include <string>
#include <memory>
#include <unordered_map>

#include "Entity.hpp"

namespace vl
{
    class EntityManager
    {
    private:
        std::unordered_map<std::string, std::shared_ptr<vl::Entity>> m_entities;

    private:
        EntityManager() {};
        ~EntityManager() {};

    public:
        static EntityManager &Instance();

        std::shared_ptr<vl::Entity> createEntity(std::string name);
        std::shared_ptr<vl::Entity> getEntity(std::string name);

        void RenderEntities(sf::RenderWindow &window);
    };

} // namespace vl

#endif