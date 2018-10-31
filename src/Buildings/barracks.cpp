#include "barracks.h"
#include "../GlobalConfig.h"

Barracks::Barracks() :
	Building(GlobalConfig.barracksEnergy,
			 GlobalConfig.barracksCost,
			 GlobalConfig.barracksHitPoints) {}

Barracks::~Barracks() {}
