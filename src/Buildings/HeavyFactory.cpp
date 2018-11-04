#include "HeavyFactory.h"

HeavyFactory::HeavyFactory() :
	Building(GlobalConfig.heavyFactoryEnergy,
			 GlobalConfig.heavyFactoryCost,
			 GlobalConfig.heavyFactoryHitPoints) {}

HeavyFactory::~HeavyFactory() {}
