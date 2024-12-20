#ifndef HOT_PLATE
#define HOT_PLATE

#include "Beaker.hpp"

namespace vl
{
    class HotPlate
    {
    private: // Class fields
        int m_wattage;
        double m_efficiency;
        bool m_isOn;
        std::shared_ptr<Beaker> m_loadedBeaker;

    public: // Special methods
        HotPlate();
        HotPlate(int wattage, double efficiency);
        HotPlate(const HotPlate &copy);
        ~HotPlate();

    public: // Operator overloads
        HotPlate &operator=(const HotPlate &copy);

    public: // Getters and Setters
        int getWattage();
        void setWattage(int wattage);

        double getEfficiency();
        void setEfficiency(double efficiency);

        std::shared_ptr<Beaker> getLoadedBeaker();
        void addBeaker(std::shared_ptr<Beaker> beaker);
        void removeBeaker();

    public: // Other methods
        bool isHotPlateOn();
        void turnOffHotPlate();
        void turnOnHotPlate();
    };
}
#endif