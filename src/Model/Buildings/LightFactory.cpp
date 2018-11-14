#include "LightFactory.h"

LightFactory::LightFactory(const int x, const int y) :
        Building(x, y,
                 GlobalConfig.lightFactoryEnergy,
                 GlobalConfig.lightFactoryCost,
                 GlobalConfig.lightFactoryHitPoints,
                 LIGHT_FACTORY) {}

LightFactory::~LightFactory() {}
