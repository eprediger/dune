#include "harvester.h"

Harvester::Harvester(int x, int y) :
	Unit(x, y,
		  GlobalConfig.harvesterHitPoints,
		  GlobalConfig.harvesterRange,
		  AssaultRifle(),	//	no, no tiene armas la cosechadora, revisar
		  GlobalConfig.harvesterSpeed) {}

Harvester::~Harvester() {}
