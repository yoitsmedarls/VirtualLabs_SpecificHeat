#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>
#include <memory>
#include <cmath>

#include "TemperatureManager.hpp"
#include "Renderable.hpp"
#include "Renderer.hpp"
#include "__main.h"

// Dimensions for the initial window launch
#define INIT_WINDOW_WIDTH 1366
#define INIT_WINDOW_HEIGHT 768

// Allowance given to accommodate the desktop taskbar
#define TASKBAR_SIZE 48

// Framerate for the simulation
#define FRAMERATE_LIMIT 24

int metalState = 1;
double initialTemperature = 25;
double recordedTemperature = 0;
double recordedSpecificHeat = 0;
double metalTemperature = 0;

int main()
{
    std::string userInput = "";

    do
    {
        userInput = "";
        system("cls");
        std::cout << std::endl
                  << "Welcome!" << "\n"
                  << "This is the VirtualLabs Specific Heat Experiment Simulation." << "\n"
                  << "Instructions:" << "\n"
                  << " - Follow the shown controls on the next screen" << "\n"
                  << " - Heat the beaker first in the hot plate" << "\n"
                  << " - Once the heating is finished, remove the beaker from the hot plate and place the metal in the calorimeter" << "\n"
                  << " - Once the temperature settles (or at least close to settles) record the temperature" << "\n"
                  << " - After recording the temperature, calculate the experimental specific heat." << "\n"
                  << "\n"
                  << "Type 'continue' to proceed with the simulation, or 'exit' to close the program" << "\n"
                  << ": ";
        std::cin >> userInput;

        if (userInput == "Continue" || userInput == "continue")
        {
            break;
        }
        if (userInput == "Exit" || userInput == "exit")
        {
            return EXIT_SUCCESS;
        }

    } while (true);

    system("cls");

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
    auto beakerWater = laboratory->CreateBeakerLiquid(100, 1, initialTemperature, 4.186, 100, 0);
    auto calorimeterWater = laboratory->CreateCalorimeterLiquid(100, 1, initialTemperature, 4.186, 100, 0);
    auto aluminum = laboratory->CreateMetal(40, 2.7, 22, 0.9);

    beaker->addLiquid(beakerWater);
    beaker->addMetal(aluminum);

    calorimeter->addLiquid(calorimeterWater);

    /**************************************************************************/
    // auto r_button1 = Renderer::Instance().createRenderable("BeakerOptionsPane", "../assets/images/button_5.png");

    // auto sample = Renderer::Instance().createRenderable();

    sf::Font font;
    font.loadFromFile("../assets/fonts/virtual-labs_font.ttf");
    sf::Color textColor = sf::Color(50, 40, 50);
    int fontSize = 16;

    auto r_waterInfo = Renderer::Instance().createRenderable("Water: " + std::to_string(laboratory->getBeakerLiquid()->getTemperature()) + " C\n" +
                                                                 "      " + std::to_string(laboratory->getBeakerLiquid()->getMass()) + " g",
                                                             font,
                                                             textColor,
                                                             fontSize);
    r_waterInfo->setTextOrigin(1, 0);
    r_waterInfo->setTextPosition(950, 216);

    auto r_metalInfo = Renderer::Instance().createRenderable("Metal: " + std::to_string(laboratory->getMetal()->getTemperature()) + " C\n" +
                                                                 "       " + std::to_string(laboratory->getMetal()->getMass()) + " g",
                                                             font,
                                                             textColor,
                                                             fontSize);
    r_metalInfo->setTextOrigin(1, 0);
    r_metalInfo->setTextPosition(950, 272);

    auto r_waterAndMetalInfoPane = Renderer::Instance().createRenderable("../assets/images/info_pane.png");
    r_waterAndMetalInfoPane->setSpriteOrigin(1, 2);
    r_waterAndMetalInfoPane->setSpritePosition(950, 340);

    auto r_beaker = Renderer::Instance().createRenderable("../assets/images/beaker_water_metal.png");
    r_beaker->setSpriteOrigin(1, 1);
    r_beaker->setSpritePosition(940, 480);

    auto r_calorimeter = Renderer::Instance().createRenderable("../assets/images/calorimeter.png");
    r_calorimeter->setSpriteOrigin(1, 1);
    r_calorimeter->setSpritePosition(660, 480);

    auto r_hotplate = Renderer::Instance().createRenderable("../assets/images/hot_plate_off.png");
    r_hotplate->setSpriteOrigin(1, 1);
    r_hotplate->setSpritePosition(340, 500);

    auto r_laboratory = Renderer::Instance().createRenderable("../assets/images/background.png");

    /**************************************************************************/

    // Indicates program startup
    std::cout << "Launching window..." << std::endl;

    std::cout << std::endl
              << "VIRTUAL LABS CONTROLS:" << "\n"
              << "\n"
              << "For hot plate:" << "\n"
              << " Q - Place beaker on hot plate" << "\n"
              << " W - Remove beaker from hot plate" << "\n"
              << " E - Turn on hot plate (heat beaker)" << "\n"
              << " R - Turn off hot plate" << "\n"
              << "\n"
              << "For Calorimeter:" << "\n"
              << " A - Move metal to calorimeter" << "\n"
              << " S - Move metal to beaker" << "\n"
              << " D - Record calorimeter water temperature" << "\n"
              << " F - Calculate experimental specific heat" << "\n"
              << std::endl;

    /**************************************************************************/

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

            // Handles user keypresses
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Q:
                    placeBeakerOnHotPlate(hotplate,
                                          beaker,
                                          r_waterInfo,
                                          r_metalInfo,
                                          r_waterAndMetalInfoPane,
                                          r_beaker, r_hotplate);
                    break;

                case sf::Keyboard::W:
                    removeBeakerOnHotPlate(hotplate,
                                           r_waterInfo,
                                           r_metalInfo,
                                           r_waterAndMetalInfoPane,
                                           r_beaker, r_hotplate);
                    break;

                case sf::Keyboard::E:
                    if (beaker->isInUse)
                    {
                        hotplate->turnOnHotPlate();
                        r_hotplate->setTextureFromFilePath("../assets/images/hot_plate_on.png");
                    }
                    break;

                case sf::Keyboard::R:
                    hotplate->turnOffHotPlate();
                    r_hotplate->setTextureFromFilePath("../assets/images/hot_plate_off.png");
                    break;

                case sf::Keyboard::A:
                    metalState = 0;
                    beaker->removeContainedMetal();
                    calorimeter->addMetal(aluminum);
                    metalTemperature = aluminum->getTemperature();
                    r_beaker->setTextureFromFilePath("../assets/images/beaker_water.png");
                    r_waterInfo->setTextPosition(r_calorimeter->getSpritePosition().x, r_calorimeter->getSpritePosition().y - 284);
                    r_metalInfo->setTextPosition(r_calorimeter->getSpritePosition().x, r_calorimeter->getSpritePosition().y - 228);
                    r_waterAndMetalInfoPane->setSpritePosition(r_calorimeter->getSpritePosition().x, r_calorimeter->getSpritePosition().y - 160);

                    break;

                case sf::Keyboard::S:
                    metalState = 1;
                    calorimeter->removeContainedMetal();
                    beaker->addMetal(aluminum);
                    r_beaker->setTextureFromFilePath("../assets/images/beaker_water_metal.png");
                    r_waterInfo->setTextPosition(r_beaker->getSpritePosition().x + 10, r_beaker->getSpritePosition().y - 264);
                    r_metalInfo->setTextPosition(r_beaker->getSpritePosition().x + 10, r_beaker->getSpritePosition().y - 208);
                    r_waterAndMetalInfoPane->setSpritePosition(r_beaker->getSpritePosition().x + 10, r_beaker->getSpritePosition().y - 140);

                    break;

                case sf::Keyboard::D:
                    recordedTemperature = calorimeterWater->getTemperature();
                    std::cout << "Temperature of water in calorimeter: \n"
                              << " " << recordedTemperature << " C\n"
                              << std::endl;

                    break;

                case sf::Keyboard::F:
                    recordedTemperature = calorimeterWater->getTemperature();
                    recordedSpecificHeat = ((calorimeterWater->getSpecificHeatCapacity() *
                                             calorimeterWater->getMass() *
                                             fabs(recordedTemperature - initialTemperature)) /
                                            (aluminum->getMass() * (fabs(metalTemperature - recordedTemperature)))) *
                                           1000;

                    std::cout.precision(4);
                    std::cout << "Mass of water             : " << calorimeterWater->getMass() / 1000 << " kg\n"
                              << "Mass of metal             : " << aluminum->getMass() / 1000 << " kg\n"
                              << "Init. Temperature (Water) : " << initialTemperature << " C\n"
                              << "Init. Temperature (Metal) : " << metalTemperature << " C\n"
                              << "Final Temperature         : " << recordedTemperature << " C\n"
                              << std::endl
                              << "Metal Specific Heat       : " << recordedSpecificHeat << " J/KgC\n"
                              << std::endl;
                    break;

                default:

                    break;
                }
                break;

            default:
                break;
            }
        }

        window.clear();

        vl::TemperatureManager::Instance().updateTemperatures(laboratory, FRAMERATE_LIMIT);

        updateWaterAndMetalInfoText(r_waterInfo, laboratory, r_metalInfo);

        if ((!(laboratory->getBeaker()->containsLiquid) || !(laboratory->getBeaker()->containsMetal)) ||
            (laboratory->getBeakerLiquid()->getTemperature() >= laboratory->getBeakerLiquid()->getBoilingPoint()))
        {
            r_hotplate->setTextureFromFilePath("../assets/images/hot_plate_off.png");
        }

        Renderer::Instance().RenderAll(window);

        window.display();
    }

    return 0;
}

void removeBeakerOnHotPlate(std::shared_ptr<vl::HotPlate> hotplate,
                            std::shared_ptr<Renderable> r_waterInfo,
                            std::shared_ptr<Renderable> r_metalInfo,
                            std::shared_ptr<Renderable> r_waterAndMetalInfoPane,
                            std::shared_ptr<Renderable> r_beaker,
                            std::shared_ptr<Renderable> r_hotplate)
{
    hotplate->removeBeaker();
    hotplate->turnOffHotPlate();

    r_beaker->setSpritePosition(940, 480);
    if (metalState == 1)
    {
        r_waterInfo->setTextPosition(r_beaker->getSpritePosition().x + 10, r_beaker->getSpritePosition().y - 264);
        r_metalInfo->setTextPosition(r_beaker->getSpritePosition().x + 10, r_beaker->getSpritePosition().y - 208);
        r_waterAndMetalInfoPane->setSpritePosition(r_beaker->getSpritePosition().x + 10, r_beaker->getSpritePosition().y - 140);
    }
    r_hotplate->setTextureFromFilePath("../assets/images/hot_plate_off.png");
}
void placeBeakerOnHotPlate(std::shared_ptr<vl::HotPlate> hotplate,
                           std::shared_ptr<vl::Beaker> beaker,
                           std::shared_ptr<Renderable> r_waterInfo,
                           std::shared_ptr<Renderable> r_metalInfo,
                           std::shared_ptr<Renderable> r_waterAndMetalInfoPane,
                           std::shared_ptr<Renderable> r_beaker,
                           std::shared_ptr<Renderable> r_hotplate)
{
    hotplate->addBeaker(beaker);

    r_beaker->setSpritePosition(322, 320);
    if (metalState == 1)
    {
        r_waterInfo->setTextPosition(r_beaker->getSpritePosition().x + 10, r_beaker->getSpritePosition().y - 264);
        r_metalInfo->setTextPosition(r_beaker->getSpritePosition().x + 10, r_beaker->getSpritePosition().y - 208);
        r_waterAndMetalInfoPane->setSpritePosition(r_beaker->getSpritePosition().x + 10, r_beaker->getSpritePosition().y - 140);
    }
}
void updateWaterAndMetalInfoText(std::shared_ptr<Renderable> r_waterInfo,
                                 std::shared_ptr<vl::Laboratory> laboratory,
                                 std::shared_ptr<Renderable> r_metalInfo)
{
    switch (metalState)
    {
    case 0:
        r_waterInfo->setString("Water: " + std::to_string(laboratory->getCalorimeterLiquid()->getTemperature()) + " C\n" +
                               "      " + std::to_string(laboratory->getCalorimeterLiquid()->getMass()) + " g");
        break;

    case 1:
        r_waterInfo->setString("Water: " + std::to_string(laboratory->getBeakerLiquid()->getTemperature()) + " C\n" +
                               "      " + std::to_string(laboratory->getBeakerLiquid()->getMass()) + " g");
        break;

    default:
        break;
    }

    r_metalInfo->setString("Metal: " + std::to_string(laboratory->getMetal()->getTemperature()) + " C\n" +
                           "       " + std::to_string(laboratory->getMetal()->getMass()) + " g");
}