#include "Renderer.hpp"

Renderer &Renderer::Instance()
{
    static Renderer *instance = new Renderer;
    return *instance;
}

std::shared_ptr<Renderable> Renderer::createRenderable(std::string textureFilePath)
{
    std::shared_ptr<Renderable> renderable =
        std::make_shared<Renderable>(textureFilePath);

    m_renderables.push_back(renderable);

    return renderable;
}

std::shared_ptr<Renderable> Renderer::createRenderable(std::string string,
                                                       sf::Font &font,
                                                       sf::Color &color,
                                                       int fontSize)
{
    std::shared_ptr<Renderable> renderable =
        std::make_shared<Renderable>(string,
                                     font,
                                     color,
                                     fontSize);

    m_renderables.push_back(renderable);

    return renderable;
}

void Renderer::RenderAll(sf::RenderWindow &window)
{
    for (int i = m_renderables.size() - 1; i >= 0; i--)
    {
        m_renderables[i]->Render(window);
    }
}
