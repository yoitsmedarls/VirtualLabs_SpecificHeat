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

    std::shared_ptr<Renderable> createRenderable(std::string name, std::string textureFilePath);
    void RenderAll(sf::RenderWindow &window);
};

#endif