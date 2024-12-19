#include "PhysicsManager.hpp"

PhysicsManager &PhysicsManager::Instance()
{
    static PhysicsManager *instance = new PhysicsManager;
    return *instance;
}

void PhysicsManager::addLaboratory(std::shared_ptr<Laboratory> p_laboratory)
{
    m_laboratory = p_laboratory;
}

std::shared_ptr<Laboratory> PhysicsManager::getLaboratory()
{
    return m_laboratory;
}

void PhysicsManager::addHeatSource(std::shared_ptr<HeatSource> p_heatSource)
{
    m_heatSource = p_heatSource;
}

std::shared_ptr<HeatSource> PhysicsManager::getHeatSource()
{
    return m_heatSource;
}

void PhysicsManager::addLiquid(std::shared_ptr<Liquid> p_liquid)
{
    m_liquid = p_liquid;
}

std::shared_ptr<Liquid> PhysicsManager::getLiquid()
{
    return m_liquid;
}

void PhysicsManager::addMetal(std::shared_ptr<Metal> p_metal)
{
    m_metal = p_metal;
}

std::shared_ptr<Metal> PhysicsManager::getMetal()
{
    return m_metal;
}

void PhysicsManager::addBeaker(std::shared_ptr<Beaker> p_beaker)
{
    m_beaker = p_beaker;
}

std::shared_ptr<Beaker> PhysicsManager::getBeaker()
{
    return m_beaker;
}

void PhysicsManager::addCalorimeter(std::shared_ptr<Calorimeter> p_calorimeter)
{
    m_calorimeter = p_calorimeter;
}

std::shared_ptr<Calorimeter> PhysicsManager::getCalorimeter()
{
    return m_calorimeter;
}

void PhysicsManager::UpdateProperties(int framerate)
{
}
