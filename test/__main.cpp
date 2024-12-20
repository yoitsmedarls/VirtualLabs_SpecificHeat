#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <memory>

#include "TemperatureManager.hpp"
#include "Renderable.hpp"
#include "Renderer.hpp"

// Dimensions for the initial window launch
#define INIT_WINDOW_WIDTH 1366
#define INIT_WINDOW_HEIGHT 768

// Allowance given to accommodate the desktop taskbar
#define TASKBAR_SIZE 48

// Framerate for the simulation
#define FRAMERATE_LIMIT 24

int main()
{
    // Creates a centered window with an FPS limit
    sf::RenderWindow window(
        sf::VideoMode(INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT),
        "Virtual Labs: Specific Heat");
    window.setPosition(sf::Vector2i(
        ((sf::VideoMode::getDesktopMode().width - window.getSize().x) / 2),
        ((sf::VideoMode::getDesktopMode().height - window.getSize().y) / 2) - TASKBAR_SIZE));
    window.setFramerateLimit(FRAMERATE_LIMIT);

    /**************************************************************************/

    auto laboratory = std::make_shared<vl::Laboratory>();
    auto beaker = laboratory->CreateBeaker(5, 7);
    auto calorimeter = laboratory->CreateCalorimeter(13.4, 16);
    auto hotplate = laboratory->CreateHotPlate(500, 0.8);
    auto scale = laboratory->CreateScale();
    auto water = laboratory->CreateLiquid(100, 1, 25, 4.186, 100, 0);
    auto aluminum = laboratory->CreateMetal(44, 2.7, 22, 0.9);

    /**************************************************************************/

    auto r_beaker = Renderer::Instance().createRenderable("Beaker", "../assets/images/beaker_empty.png");
    r_beaker->setOrigin(1, 1);
    r_beaker->setPosition(940, 480);

    auto r_calorimeter = Renderer::Instance().createRenderable("Calorimeter", "../assets/images/calorimeter.png");
    r_calorimeter->setOrigin(1, 1);
    r_calorimeter->setPosition(500, 480);

    auto r_hotplate = Renderer::Instance().createRenderable("Hot Plate", "../assets/images/hot_plate.png");
    r_hotplate->setOrigin(1, 1);
    r_hotplate->setPosition(200, 500);

    auto r_scale = Renderer::Instance().createRenderable("Scale", "../assets/images/weighing_scale.png");
    r_scale->setOrigin(1, 1);
    r_scale->setPosition(1200, 550);

    auto r_laboratory = Renderer::Instance().createRenderable("Laboratory", "../assets/images/background.png");

    /**************************************************************************/

    // Indicates program startup
    std::cout << "Launching window..." << std::endl;

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
                    r_beaker->setTextureFromFilePath("../assets/images/beaker_empty.png");

                    break;
                case sf::Mouse::Button::Right:
                    std::cout << "RMB\n";
                    r_beaker->setTextureFromFilePath("../assets/images/beaker_water.png");

                    break;
                case sf::Mouse::Button::Middle:
                    std::cout << "MMB\n";
                    r_beaker->setTextureFromFilePath("../assets/images/beaker_water_metal.png");

                    break;

                default:
                    std::cout << "?\n";
                    break;
                }
                break;

            // Handles user keypresses
            case sf::Event::KeyReleased:
                std::cout << "KeyPress: ";
                switch (event.key.code)
                {
                case sf::Keyboard::Q:
                    std::cout << "Q\n";
                    beaker->addLiquid(water);
                    beaker->addMetal(aluminum);

                    break;

                case sf::Keyboard::W:
                    std::cout << "W\n";
                    beaker->removeContainedLiquid();
                    beaker->removeContainedMetal();

                    break;

                case sf::Keyboard::E:
                    std::cout << "E\n";
                    calorimeter->addLiquid(water);
                    calorimeter->addMetal(aluminum);

                    break;
                case sf::Keyboard::R:
                    std::cout << "R\n";
                    calorimeter->removeContainedLiquid();
                    calorimeter->removeContainedMetal();

                    break;

                case sf::Keyboard::T:
                    std::cout << "T\n";
                    hotplate->addBeaker(beaker);

                    break;

                case sf::Keyboard::Y:
                    std::cout << "Y\n";
                    hotplate->turnOnHotPlate();
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

        vl::TemperatureManager::Instance().updateTemperatures(laboratory, FRAMERATE_LIMIT);
        Renderer::Instance().RenderAll(window);

        window.display();
    }

    return 0;
}