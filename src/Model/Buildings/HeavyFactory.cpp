#include "HeavyFactory.h"

HeavyFactory::HeavyFactory(const int x, const int y) :
        Building(x, y,
                 GlobalConfig.heavyFactoryEnergy,
                 GlobalConfig.heavyFactoryCost,
                 GlobalConfig.heavyFactoryHitPoints,
                 HEAVY_FACTORY) {}

HeavyFactory::~HeavyFactory() {}
