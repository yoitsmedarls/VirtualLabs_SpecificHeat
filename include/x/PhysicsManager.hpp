#ifndef PHYSICS_MANAGER
#define PHYSICS_MANAGER

#include <string>
#include <memory>
#include <unordered_map>

#include "Laboratory.hpp"
#include "HotPlate.hpp"
#include "Scale.hpp"
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

    std::shared_ptr<HotPlate> m_HotPlate;
    std::shared_ptr<Scale> m_scale;

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

    void addHotPlate(std::shared_ptr<HotPlate> p_HotPlate);
    std::shared_ptr<HotPlate> getHotPlate();

    void addScale(std::shared_ptr<Scale> p_scale);
    std::shared_ptr<Scale> getScale();

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