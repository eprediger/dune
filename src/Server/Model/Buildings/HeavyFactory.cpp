#include "HeavyFactory.h"

HeavyFactory::HeavyFactory(const int x, const int y, int blockWidth, int blockHeight) :
        Building(x, y, blockWidth, blockHeight,
                 GlobalConfig.heavyFactoryEnergy,
                 GlobalConfig.heavyFactoryCost,
                 GlobalConfig.heavyFactoryHitPoints, 
                 GlobalConfig.heavyFactoryWidth,
                 GlobalConfig.heavyFactoryHeight,
                 HEAVY_FACTORY)
{}

HeavyFactory::~HeavyFactory() {}
