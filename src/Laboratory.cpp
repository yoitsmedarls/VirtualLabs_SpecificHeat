#include "Laboratory.hpp"

#include <iostream>

namespace vl
{
    /** Special member functions **********************************************/

    Laboratory::Laboratory()
        : m_beaker(nullptr),
          m_calorimeter(nullptr),
          m_hotPlate(nullptr),
          m_scale(nullptr),
          m_beakerLiquid(nullptr),
          m_metal(nullptr)
    {
    }

    Laboratory::Laboratory(const Laboratory &copy)
        : m_ambientTemperature(copy.m_ambientTemperature),
          m_beaker(copy.m_beaker),
          m_calorimeter(copy.m_calorimeter),
          m_hotPlate(copy.m_hotPlate),
          m_scale(copy.m_scale),
          m_beakerLiquid(copy.m_beakerLiquid),
          m_metal(copy.m_metal)
    {
    }

    Laboratory::~Laboratory()
    {
    }

    /** Operator overloads ****************************************************/

    Laboratory &Laboratory::operator=(const Laboratory &copy)
    {
        if (&copy == this)
        {
            return *this;
        }

        return *this;
    }

    /** Getters and Setters ***************************************************/

    std::shared_ptr<Beaker> Laboratory::getBeaker()
    {
        if (m_beaker != nullptr)
        {
            return m_beaker;
        }
        else
        {
            // std::cout << "ERROR: Beaker is null" << std::endl;
            return m_beaker;
        }
    }
    double Laboratory::getAmbientTemperature()
    {
        return m_ambientTemperature;
    }
    std::shared_ptr<Beaker> Laboratory::CreateBeaker()
    {
        std::shared_ptr<Beaker> beaker =
            std::make_shared<Beaker>();
        m_beaker = beaker;

        return beaker;
    }
    std::shared_ptr<Beaker> Laboratory::CreateBeaker(double diameter,
                                                     double height)
    {
        std::shared_ptr<Beaker> beaker =
            std::make_shared<Beaker>(diameter,
                                     height);
        m_beaker = beaker;

        return beaker;
    }

    std::shared_ptr<Calorimeter> Laboratory::getCalorimeter()
    {
        if (m_calorimeter != nullptr)
        {
            return m_calorimeter;
        }
        else
        {
            // std::cout << "ERROR: Calorimeter is null" << std::endl;
            return m_calorimeter;
        }
    }
    std::shared_ptr<Calorimeter> Laboratory::CreateCalorimeter()
    {

        std::shared_ptr<Calorimeter> calorimeter =
            std::make_shared<Calorimeter>();
        m_calorimeter = calorimeter;

        return calorimeter;
    }
    std::shared_ptr<Calorimeter> Laboratory::CreateCalorimeter(double diameter,
                                                               double height)
    {

        std::shared_ptr<Calorimeter> calorimeter =
            std::make_shared<Calorimeter>(diameter,
                                          height);
        m_calorimeter = calorimeter;

        return calorimeter;
    }

    std::shared_ptr<HotPlate> Laboratory::getHotPlate()
    {
        if (m_hotPlate != nullptr)
        {
            return m_hotPlate;
        }
        else
        {
            // std::cout << "ERROR: HotPlate is null" << std::endl;
            return m_hotPlate;
        }
    }
    std::shared_ptr<HotPlate> Laboratory::CreateHotPlate()
    {

        std::shared_ptr<HotPlate> hotPlate =
            std::make_shared<HotPlate>();
        m_hotPlate = hotPlate;

        return hotPlate;
    }
    std::shared_ptr<HotPlate> Laboratory::CreateHotPlate(int wattage,
                                                         double efficiency)
    {

        std::shared_ptr<HotPlate> hotPlate =
            std::make_shared<HotPlate>(wattage,
                                       efficiency);
        m_hotPlate = hotPlate;

        return hotPlate;
    }

    std::shared_ptr<Scale> Laboratory::getScale()
    {
        if (m_scale != nullptr)
        {
            return m_scale;
        }
        else
        {
            // std::cout << "ERROR: Scale is null" << std::endl;
            return m_scale;
        }
    }
    std::shared_ptr<Scale> Laboratory::CreateScale()
    {

        std::shared_ptr<Scale> scale =
            std::make_shared<Scale>();
        m_scale = scale;

        return scale;
    }

    std::shared_ptr<Thermometer> Laboratory::getThermometer()
    {
        if (m_thermometer != nullptr)
        {
            return m_thermometer;
        }
        else
        {
            // std::cout << "ERROR: Thermometer is null" << std::endl;
            return m_thermometer;
        }
    }
    std::shared_ptr<Thermometer> Laboratory::CreateThermometer()
    {

        std::shared_ptr<Thermometer> thermometer =
            std::make_shared<Thermometer>();
        m_thermometer = thermometer;

        return thermometer;
    }

    std::shared_ptr<Liquid> Laboratory::getBeakerLiquid()
    {
        if (m_beakerLiquid != nullptr)
        {
            return m_beakerLiquid;
        }
        else
        {
            // std::cout << "ERROR: Liquid is null" << std::endl;
            return m_beakerLiquid;
        }
    }
    std::shared_ptr<Liquid> Laboratory::CreateBeakerLiquid()
    {
        checkForContainers();

        std::shared_ptr<Liquid> liquid =
            std::make_shared<Liquid>();
        m_beakerLiquid = liquid;

        return liquid;
    }
    std::shared_ptr<Liquid> Laboratory::CreateBeakerLiquid(double mass,
                                                           double density,
                                                           double temperature,
                                                           double specificHeatCapacity,
                                                           double boilingPoint,
                                                           double freezingPoint)
    {
        checkForContainers();

        std::shared_ptr<Liquid> liquid =
            std::make_shared<Liquid>(mass,
                                     density,
                                     temperature,
                                     specificHeatCapacity,
                                     boilingPoint,
                                     freezingPoint);
        m_beakerLiquid = liquid;

        return liquid;
    }

    std::shared_ptr<Liquid> Laboratory::getCalorimeterLiquid()
    {
        if (m_calorimeterLiquid != nullptr)
        {
            return m_calorimeterLiquid;
        }
        else
        {
            // std::cout << "ERROR: Liquid is null" << std::endl;
            return m_calorimeterLiquid;
        }
    }

    std::shared_ptr<Liquid> Laboratory::CreateCalorimeterLiquid()
    {
        checkForContainers();

        std::shared_ptr<Liquid> liquid =
            std::make_shared<Liquid>();
        m_calorimeterLiquid = liquid;

        return liquid;
    }

    std::shared_ptr<Liquid> Laboratory::CreateCalorimeterLiquid(double mass,
                                                                double density,
                                                                double temperature,
                                                                double specificHeatCapacity,
                                                                double boilingPoint,
                                                                double freezingPoint)
    {
        checkForContainers();

        std::shared_ptr<Liquid> liquid =
            std::make_shared<Liquid>(mass,
                                     density,
                                     temperature,
                                     specificHeatCapacity,
                                     boilingPoint,
                                     freezingPoint);
        m_calorimeterLiquid = liquid;

        return liquid;
    }

    std::shared_ptr<Metal> Laboratory::getMetal()
    {
        if (m_metal != nullptr)
        {
            return m_metal;
        }
        else
        {
            // std::cout << "ERROR: Metal is null" << std::endl;
            return m_metal;
        }
    }
    std::shared_ptr<Metal> Laboratory::CreateMetal()
    {
        checkForContainers();

        std::shared_ptr<Metal> metal =
            std::make_shared<Metal>();
        m_metal = metal;

        return metal;
    }
    std::shared_ptr<Metal> Laboratory::CreateMetal(double mass,
                                                   double density,
                                                   double temperature,
                                                   double specificHeatCapacity)
    {
        checkForContainers();

        std::shared_ptr<Metal> metal =
            std::make_shared<Metal>(mass,
                                    density,
                                    temperature,
                                    specificHeatCapacity);
        m_metal = metal;

        return metal;
    }

    void Laboratory::checkForContainers()
    {
        if (m_beaker == nullptr && m_calorimeter == nullptr)
        {
            // std::cout << "ERROR: Create a container for the Substance first!" << std::endl;
        }

    } // namespace vl
}