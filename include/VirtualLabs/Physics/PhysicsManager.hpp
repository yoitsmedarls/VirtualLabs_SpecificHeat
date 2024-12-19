#ifndef VIRTUAL_LABS_ENTITY_MANAGER
#define VIRTUAL_LABS_ENTITY_MANAGER

#include <string>
#include <memory>
#include <unordered_map>

#include "Laboratory.hpp"
#include "HeatSource.hpp"
#include "Substance.hpp"
#include "Liquid.hpp"
#include "Metal.hpp"
#include "Container.hpp"
#include "Beaker.hpp"
#include "Calorimeter.hpp"

class PhysicsManager
{
private:
    std::shared_ptr<Laboratory> m_laboratory;
    std::shared_ptr<HeatSource> m_heatSource;
    std::shared_ptr<Liquid> m_liquid;
    std::shared_ptr<Metal> m_metal;
    std::shared_ptr<Beaker> m_beaker;
    std::shared_ptr<Calorimeter> m_calorimeter;

private:
    PhysicsManager() {};
    ~PhysicsManager() {};

public:
    static PhysicsManager &Instance();

    void addLaboratory(std::shared_ptr<Laboratory> p_laboratory);
    std::shared_ptr<Laboratory> getLaboratory();

    void addHeatSource(std::shared_ptr<HeatSource> p_heatSource);
    std::shared_ptr<HeatSource> getHeatSource();

    void addLiquid(std::shared_ptr<Liquid> p_liquid);
    std::shared_ptr<Liquid> getLiquid();

    void addMetal(std::shared_ptr<Metal> p_metal);
    std::shared_ptr<Metal> getMetal();

    void addBeaker(std::shared_ptr<Beaker> p_beaker);
    std::shared_ptr<Beaker> getBeaker();

    void addCalorimeter(std::shared_ptr<Calorimeter> p_calorimeter);
    std::shared_ptr<Calorimeter> getCalorimeter();

    void UpdateProperties(int framerate);
};

#endif