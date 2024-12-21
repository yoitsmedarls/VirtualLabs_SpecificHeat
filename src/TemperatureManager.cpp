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

        /**
         * Computes the temperature when the hot plate loaded with a beaker with
         * liquid and metal is turned on.
         *
         */
        if (laboratory->getHotPlate()->isHotPlateOn() == true)
        {
            if (!(laboratory->getBeaker()->containsLiquid) ||
                !(laboratory->getBeaker()->containsMetal))
            {
                laboratory->getHotPlate()->turnOffHotPlate();
                return;
            }

            // turn off if boiling
            if (laboratory->getBeakerLiquid()->getTemperature() >=
                laboratory->getBeakerLiquid()->getBoilingPoint())
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

            double m_liquid = laboratory->getBeakerLiquid()->getMass();
            double c_liquid = laboratory->getBeakerLiquid()->getSpecificHeatCapacity();

            /** q = mcdT for metal */
            double m_metal = laboratory->getMetal()->getMass();
            double c_metal = laboratory->getMetal()->getSpecificHeatCapacity();

            double dT_liquid = (q / (m_liquid * c_liquid));
            double dT_metal = (q / (m_metal * c_metal)) * 0.25;

            laboratory->getBeakerLiquid()->modifyTemperature(dT_liquid);

            /** Not really physics accurate, but it prevents the metal from
             *  being unusually too hot
             *  */
            if (laboratory->getMetal()->getTemperature() <= laboratory->getBeakerLiquid()->getTemperature())
            {
                laboratory->getMetal()->modifyTemperature(dT_metal);
            }
        }

        if (laboratory->getBeaker()->containsLiquid &&
            laboratory->getBeakerLiquid()->getTemperature() > laboratory->getAmbientTemperature())
        {
            double k = (laboratory->getBeakerLiquid()->getVolume() /
                        laboratory->getBeakerLiquid()->getSpecificHeatCapacity());

            double T_amb = laboratory->getAmbientTemperature();
            double T_init = laboratory->getBeakerLiquid()->getTemperature();

            double dT = -(((T_init - T_amb) / (exp(k * dt)))) / pow(10, 4);

            laboratory->getBeakerLiquid()->modifyTemperature(dT);
        }

        if (laboratory->getBeaker()->containsMetal &&
            laboratory->getMetal()->getTemperature() > laboratory->getAmbientTemperature())
        {
            double k = (laboratory->getMetal()->getVolume() /
                        laboratory->getMetal()->getSpecificHeatCapacity());

            double T_amb = laboratory->getAmbientTemperature();
            double T_init = laboratory->getMetal()->getTemperature();

            double dT = -(((T_init - T_amb) / (exp(k * dt)))) / pow(10, 4);

            laboratory->getMetal()->modifyTemperature(dT * 2);
        }

        if (laboratory->getBeaker()->containsMetal &&
            laboratory->getMetal()->getTemperature() < laboratory->getBeakerLiquid()->getTemperature())
        {
            double k = (laboratory->getMetal()->getVolume() /
                        laboratory->getMetal()->getSpecificHeatCapacity());

            double T_amb = laboratory->getBeakerLiquid()->getTemperature();
            double T_init = laboratory->getMetal()->getTemperature();

            double dT = -(((T_init - T_amb) / (exp(k * dt)))) / pow(10, 4);

            laboratory->getMetal()->modifyTemperature(dT);
            laboratory->getBeakerLiquid()->modifyTemperature((-dT) * 0.3);
        }

        if (laboratory->getCalorimeter()->containsLiquid &&
            laboratory->getCalorimeter()->containsMetal)
        {
            if (laboratory->getCalorimeterLiquid()->getTemperature() < laboratory->getMetal()->getTemperature())
            {
                double k = (laboratory->getMetal()->getVolume() /
                            laboratory->getMetal()->getSpecificHeatCapacity());

                double T_amb = laboratory->getCalorimeterLiquid()->getTemperature();
                double T_init = laboratory->getMetal()->getTemperature();

                double dT = -(((T_init - T_amb) / (exp(k * dt)))) / pow(10, 3);

                laboratory->getMetal()->modifyTemperature(dT * 1.3);
                laboratory->getCalorimeterLiquid()->modifyTemperature((-dT) * 0.115);
            }
            else
            {
                double k = (laboratory->getMetal()->getVolume() /
                            laboratory->getMetal()->getSpecificHeatCapacity());

                double T_amb = laboratory->getCalorimeterLiquid()->getTemperature();
                double T_init = laboratory->getMetal()->getTemperature();

                double dT = -(((T_init - T_amb) / (exp(k * dt)))) / pow(10, 3);

                laboratory->getMetal()->modifyTemperature(-(dT * 1.3));
                laboratory->getCalorimeterLiquid()->modifyTemperature(dT * 0.115);
            }
        }
    }
}