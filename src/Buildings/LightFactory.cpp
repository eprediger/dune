#include "LightFactory.h"

LightFactory::LightFactory() :
	Building(GlobalConfig.lightFactoryEnergy,
			 GlobalConfig.lightFactoryCost,
			 GlobalConfig.lightFactoryHitPoints) {}

LightFactory::~LightFactory() {}
