#ifndef RENDERER
#define RENDERER

#include <memory>
#include <unordered_map>

#include "Renderable.hpp"

class Renderer
{
private:
    std::unordered_map<std::string, std::shared_ptr<Renderable>> m_renderables;

private:
    Renderer() {};
    ~Renderer() {};

public:
    static Renderer &Instance();

    void addRenderable(std::string name, std::shared_ptr<Renderable> renderable);
    void RenderAll(sf::RenderWindow &window);
};

#endif