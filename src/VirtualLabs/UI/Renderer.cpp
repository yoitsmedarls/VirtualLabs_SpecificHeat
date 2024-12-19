#include "Renderer.hpp"

Renderer &Renderer::Instance()
{
    static Renderer *instance = new Renderer;
    return *instance;
}

void Renderer::addRenderable(std::string name, std::shared_ptr<Renderable> renderable)
{
    m_renderables.insert(std::make_pair(name, renderable));
}

void Renderer::RenderAll(sf::RenderWindow &window)
{
    for (auto it = m_renderables.begin(); it != m_renderables.end(); it++)
    {
        it->second->Render(window);
    }
}
