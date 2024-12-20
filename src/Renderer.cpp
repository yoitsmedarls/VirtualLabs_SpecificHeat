#include "Renderer.hpp"

Renderer &Renderer::Instance()
{
    static Renderer *instance = new Renderer;
    return *instance;
}

std::shared_ptr<Renderable> Renderer::createRenderable(std::string name, std::string textureFilePath)
{
    std::shared_ptr<Renderable> renderable = std::make_shared<Renderable>(textureFilePath);
    m_renderables.insert(std::make_pair(name, renderable));

    return renderable;
}

void Renderer::RenderAll(sf::RenderWindow &window)
{
    for (auto it = m_renderables.begin(); it != m_renderables.end(); it++)
    {
        it->second->Render(window);
    }
}
