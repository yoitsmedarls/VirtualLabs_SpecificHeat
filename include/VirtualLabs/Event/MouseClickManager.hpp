#ifndef MOUSE_CLICK_MANAGER
#define MOUSE_CLICK_MANAGER

#include <vector>
#include <memory>

#include "Clickable.hpp"

class MouseClickManager
{
private:
    std::vector<std::shared_ptr<Clickable>> m_clickables;

private:
    MouseClickManager() {};
    ~MouseClickManager() {};

public:
    static MouseClickManager &Instance();

    void addClickable(std::shared_ptr<Renderable> renderable);
    void checkForEvents(sf::RenderWindow &window);
};

#endif