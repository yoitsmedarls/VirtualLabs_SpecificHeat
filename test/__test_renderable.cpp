#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <memory>

#include "PhysicsManager.hpp"
#include "Renderer.hpp"

// Dimensions for the initial window launch
#define WINDOW_HEIGHT 768
#define WINDOW_WIDTH 1366

// Allowance given to accommodate the desktop taskbar
#define TASKBAR_SIZE 48

// Framerate for the simulation
#define FRAMERATE_LIMIT 60

int main()
{
    // Creates a non-resizeable window with specified dimensions and title
    sf::RenderWindow window = sf::RenderWindow(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "Virtual Labs: Specific Heat",
        sf::Style::Titlebar | sf::Style::Close);

    // Centers the window on the screen (accounting for the taskbar)
    window.setPosition(sf::Vector2i(
        ((sf::VideoMode::getDesktopMode().width - window.getSize().x) / 2),
        ((sf::VideoMode::getDesktopMode().height - window.getSize().y) / 2) -
            TASKBAR_SIZE));

    // Adds a framerate limit to the window
    window.setFramerateLimit(FRAMERATE_LIMIT);

    // Prints out valuable information to the console
    std::cout << std::endl
              << "WINDOW SETUP INFORMATION:\n"
              << "  Position: \n"
              << "    x: " << window.getPosition().x << "\n"
              << "    y: " << window.getPosition().y << "\n"
              << "  Size: " << "\n"
              << "    width: " << window.getSize().x << "px" << "\n"
              << "    height: " << window.getSize().y << "px" << "\n"
              << std::endl;

    std::shared_ptr<Laboratory> lab = std::make_shared<Laboratory>("../assets/images/background.png");
    lab->setOrigin(1, 1);
    lab->setPositionRelativeToWindow(1, 1, window);

    // std::shared_ptr<Liquid> water = std::make_shared<Liquid>("Water", "../assets/images/water.png", 100, 1, 25, 4.186, 100, 0);
    // water->setOrigin(0, 1);
    // water->setPositionRelativeToWindow(0, 1, window);

    // std::shared_ptr<Metal> aluminum = std::make_shared<Metal>("Aluminum", "../assets/images/metal.png", 50, 2.7, 20, 0.903);
    // aluminum->setOrigin(2, 1);
    // aluminum->setPositionRelativeToWindow(2, 1, window);

    // std::shared_ptr<Container> myContainer = std::make_shared<Container>("MyContainer", 5, 7);
    // water->setOrigin(0, 0);

    PhysicsManager::Instance().addLaboratory(lab);
    // PhysicsManager::Instance().addLiquid(water);
    // PhysicsManager::Instance().addMetal(aluminum);

    // First line gets to be in front
    // Renderer::Instance().addRenderable(lab);
    // Renderer::Instance().addRenderable(aluminum);
    // Renderer::Instance().addRenderable(water);

    // Indicates program startup
    std::cout
        << "Launching window..." << std::endl;

    // Starts the program loop
    while (window.isOpen())
    {
        // Event handler
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            // Closes the program
            case sf::Event::Closed:
                window.close();
                std::cout << "...Window closed" << std::endl;
                exit(EXIT_SUCCESS);
                break;

            // Handles mouse button clicks
            case sf::Event::MouseButtonPressed:
                std::cout << "MouseClick: ";
                switch (event.mouseButton.button)
                {
                case sf::Mouse::Button::Left:
                    std::cout << "LMB\n";
                    break;
                case sf::Mouse::Button::Right:
                    std::cout << "RMB\n";
                    break;
                case sf::Mouse::Button::Middle:
                    std::cout << "MMB\n";
                    break;

                default:
                    std::cout << "?\n";
                    break;
                }
                break;

            // Handles user keypresses
            case sf::Event::KeyPressed:
                std::cout << "KeyPress: ";
                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    std::cout << "W\n";
                    break;
                case sf::Keyboard::A:
                    std::cout << "A\n";
                    break;
                case sf::Keyboard::S:
                    std::cout << "S\n";
                    break;
                case sf::Keyboard::D:
                    std::cout << "D\n";
                    break;

                default:
                    std::cout << "?\n";
                    break;
                }
                break;

            default:
                break;
            }
        }

        window.clear();

        PhysicsManager::Instance().UpdateProperties(FRAMERATE_LIMIT);
        Renderer::Instance().RenderAll(window);

        window.display();
    }

    return 0;
}