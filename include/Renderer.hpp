#ifndef RENDERER
#define RENDERER

#include <memory>
#include <vector>

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

    std::shared_ptr<Renderable> createRenderable(std::string textureFilePath);

    std::shared_ptr<Renderable> createRenderable(std::string string,
                                                 sf::Font &font,
                                                 sf::Color &color,
                                                 int fontSize);
    void RenderAll(sf::RenderWindow &window);
};

#endif