#ifndef RENDERER
#define RENDERER

#include <vector>
#include <memory>

#include "Renderable.hpp"

class Renderer
{
private:
    std::vector<std::shared_ptr<Renderable>> m_renderables;

private:
    Renderer() {};
    ~Renderer() {};

public:
    static Renderer &Instance();

    void addRenderable(std::shared_ptr<Renderable> renderable);
    void RenderAll(sf::RenderWindow &window);
};

#endif