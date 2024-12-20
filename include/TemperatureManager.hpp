#ifndef TEMPERATURE_MANAGER
#define TEMPERATURE_MANAGER

#include <unordered_map>
#include <string>
#include <memory>

#include "Laboratory.hpp"

namespace vl
{
    class TemperatureManager
    {
    private:
        TemperatureManager() {};
        ~TemperatureManager() {};

    public:
        static TemperatureManager &Instance();

        void updateTemperatures(std::shared_ptr<Laboratory> laboratory, double framerate);
    };
}
#endif