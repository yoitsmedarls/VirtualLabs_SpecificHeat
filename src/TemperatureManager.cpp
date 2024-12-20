#include "TemperatureManager.hpp"

#include <iostream>
#include <cmath>

namespace vl
{
    TemperatureManager &TemperatureManager::Instance()
    {
        static TemperatureManager *instance = new TemperatureManager;
        return *instance;
    }
    void TemperatureManager::updateTemperatures(std::shared_ptr<Laboratory> laboratory, double framerate)
    {
        double dt = 1.00 / framerate;

        std::cout.precision(4);

        /**
         * Computes the temperature when the hot plate loaded with a beaker with
         * liquid and metal is turned on.
         *
         */
        if (laboratory->getHotPlate()->isHotPlateOn())
        {
            if (!(laboratory->getBeaker()->containsLiquid) ||
                !(laboratory->getBeaker()->containsMetal))
            {
                laboratory->getHotPlate()->turnOffHotPlate();
                return;
            }

            // turn off if boiling
            if (laboratory->getLiquid()->getTemperature() >=
                laboratory->getLiquid()->getBoilingPoint())
            {

                laboratory->getHotPlate()->turnOffHotPlate();
                return;
            }

            /**
             *  q value from the hot plate
             *
             * */
            double q = (laboratory->getHotPlate()->getWattage() *
                        laboratory->getHotPlate()->getEfficiency()) *
                       dt;

            double m_liquid = laboratory->getLiquid()->getMass();
            double c_liquid = laboratory->getLiquid()->getSpecificHeatCapacity();
            double dT_liquid = q / (m_liquid * c_liquid);

            laboratory->getLiquid()->modifyTemperature(dT_liquid);

            /** q = mcdT for metal */
            double m_metal = laboratory->getMetal()->getMass();
            double c_metal = laboratory->getMetal()->getSpecificHeatCapacity();
            double dT_metal = q / (m_metal * c_metal);

            /** Not really physics accurate, but it prevents the metal from
             *  being unusually too hot
             *  */
            if (laboratory->getMetal()->getTemperature() <= laboratory->getLiquid()->getTemperature())
            {
                laboratory->getMetal()->modifyTemperature(dT_metal);
            }
        }

        if (laboratory->getBeaker()->containsLiquid)
        {
            double k = (laboratory->getLiquid()->getVolume() /
                        laboratory->getLiquid()->getSpecificHeatCapacity());

            double T_amb = laboratory->getAmbientTemperature();
            double T_init = laboratory->getLiquid()->getTemperature();

            double dT = -(((T_init - T_amb) / (exp(k * dt)))) / pow(10, 3);

            laboratory->getLiquid()->modifyTemperature(dT);
        }

        if (laboratory->getBeaker()->containsMetal)
        {
            double k = (laboratory->getMetal()->getVolume() /
                        laboratory->getMetal()->getSpecificHeatCapacity());

            double T_amb = laboratory->getAmbientTemperature();
            double T_init = laboratory->getMetal()->getTemperature();

            double dT = -(((T_init - T_amb) / (exp(k * dt)))) / pow(10, 3);

            laboratory->getMetal()->modifyTemperature(dT);
        }

        if (laboratory->getCalorimeter()->containsLiquid &&
            laboratory->getCalorimeter()->containsMetal)
        {
            double k = (laboratory->getMetal()->getVolume() /
                        laboratory->getMetal()->getSpecificHeatCapacity());

            double T_amb = laboratory->getLiquid()->getTemperature();
            double T_init = laboratory->getMetal()->getTemperature();

            double dT = -(((T_init - T_amb) / (exp(k * dt)))) / pow(10, 3);

            laboratory->getMetal()->modifyTemperature(dT);
        }

        system("cls");
        std::cout << "Temperature of Liquid : " << laboratory->getLiquid()->getTemperature() << std::endl;
        std::cout << "Temperature of Metal : " << laboratory->getMetal()->getTemperature() << std::endl;
        std::cout << std::endl;
    }
}