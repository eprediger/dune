#include "LightFactory.h"

LightFactory::LightFactory(const int x, const int y, int blockWidth, int blockHeight) :
	Building(x, y, blockWidth, blockHeight,
	         GlobalConfig.lightFactoryEnergy,
	         GlobalConfig.lightFactoryCost,
	         GlobalConfig.lightFactoryHitPoints,
	         GlobalConfig.lightFactoryWidth,
	         GlobalConfig.lightFactoryHeight,
	         LIGHT_FACTORY)
{}
LightFactory::~LightFactory() {}
