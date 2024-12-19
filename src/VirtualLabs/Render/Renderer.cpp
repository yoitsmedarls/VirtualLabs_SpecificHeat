#include "Renderer.hpp"

Renderer &Renderer::Instance()
{
    static Renderer *instance = new Renderer;
    return *instance;
}

void Renderer::addRenderable(std::shared_ptr<Renderable> renderable)
{
    m_renderables.push_back(renderable);
}

void Renderer::RenderAll(sf::RenderWindow &window)
{
    for (int i = m_renderables.size() - 1; i >= 0; i--)
    {
        m_renderables[i]->Render(window);
    }
}
