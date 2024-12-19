#ifndef ENTITY
#define ENTITY

#include <vector>
#include <string>
#include <memory>
#include "IComponent.hpp"
#include "Sprite2DComponent.hpp"

namespace vl
{
    class Entity
    {
    private: // Class fields
        std::string m_name;
        std::vector<std::shared_ptr<IComponent>> m_components;

    public: // Special methods
        Entity(std::string name);
        Entity(const Entity &copy);
        ~Entity();

    public: // Operator overloads
        Entity &operator=(const Entity &copy);

    public: // Getters and Setters
        void addSprite2DComponent(std::string name,
                                  std::string textureFilePath);
        void renderAllComponents(sf::RenderWindow &window);

    public: // Other methods
    };

} // namespace vl

#endif