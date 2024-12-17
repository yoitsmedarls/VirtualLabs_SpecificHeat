#ifndef ENTITY
#define ENTITY

#include <vector>
#include <string>
#include <memory>
#include "IComponent.hpp"
#include "Sprite2DComponent.hpp"

class Entity
{
private: // Class fields
    std::string m_name;
    std::vector<IComponent> m_components;

public: // Special methods
    Entity();
    Entity();
    Entity(const Entity &copy);
    ~Entity();

public: // Operator overloads
    Entity &operator=(const Entity &copy);

public: // Getters and Setters
    void addComponent(Sprite2DComponent &);

public: // Other methods
};

#endif