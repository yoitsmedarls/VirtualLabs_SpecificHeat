#ifndef ROOM
#define ROOM

#include <string>
#include <memory>

#include "Beaker.hpp"
#include "Calorimeter.hpp"
#include "HotPlate.hpp"
#include "Scale.hpp"
#include "Thermometer.hpp"

namespace vl
{
    /**
     * @author @yoitsmedarls
     * @brief
     *
     */
    class Laboratory
    {
    protected: /** Properties *************************************************/
        const double m_ambientTemperature = 25;
        std::shared_ptr<Beaker> m_beaker;
        std::shared_ptr<Calorimeter> m_calorimeter;
        std::shared_ptr<HotPlate> m_hotPlate;
        std::shared_ptr<Scale> m_scale;
        std::shared_ptr<Thermometer> m_thermometer;
        std::shared_ptr<Liquid> m_beakerLiquid;
        std::shared_ptr<Liquid> m_calorimeterLiquid;
        std::shared_ptr<Metal> m_metal;

    public: /** Special member functions **************************************/
        Laboratory();
        ~Laboratory();
        Laboratory(const Laboratory &copy);

    public: /** Operator overloads ********************************************/
        Laboratory &operator=(const Laboratory &copy);

    public: /** Getters and Setters *******************************************/
        double getAmbientTemperature();

        std::shared_ptr<Beaker> getBeaker();
        std::shared_ptr<Beaker> CreateBeaker();
        std::shared_ptr<Beaker> CreateBeaker(double diameter,
                                             double height);

        std::shared_ptr<Calorimeter> getCalorimeter();
        std::shared_ptr<Calorimeter> CreateCalorimeter();
        std::shared_ptr<Calorimeter> CreateCalorimeter(double diameter,
                                                       double height);

        std::shared_ptr<HotPlate> getHotPlate();
        std::shared_ptr<HotPlate> CreateHotPlate();
        std::shared_ptr<HotPlate> CreateHotPlate(int wattage,
                                                 double efficiency);

        std::shared_ptr<Scale> getScale();
        std::shared_ptr<Scale> CreateScale();

        std::shared_ptr<Thermometer> getThermometer();
        std::shared_ptr<Thermometer> CreateThermometer();

        std::shared_ptr<Liquid> getBeakerLiquid();
        std::shared_ptr<Liquid> CreateBeakerLiquid();
        std::shared_ptr<Liquid> CreateBeakerLiquid(double mass,
                                                   double density,
                                                   double temperature,
                                                   double specificHeatCapacity,
                                                   double boilingPoint,
                                                   double freezingPoint);

        std::shared_ptr<Liquid> getCalorimeterLiquid();
        std::shared_ptr<Liquid> CreateCalorimeterLiquid();
        std::shared_ptr<Liquid> CreateCalorimeterLiquid(double mass,
                                                        double density,
                                                        double temperature,
                                                        double specificHeatCapacity,
                                                        double boilingPoint,
                                                        double freezingPoint);

        std::shared_ptr<Metal> getMetal();
        std::shared_ptr<Metal> CreateMetal();
        std::shared_ptr<Metal> CreateMetal(double mass,
                                           double density,
                                           double temperature,
                                           double specificHeatCapacity);

    public: /** Other member functions ****************************************/
        void checkForContainers();
    };
}
#endif