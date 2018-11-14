#include "Barracks.h"
#include "../GlobalConfig.h"

Barracks::Barracks(const int x, const int y) :
		Building(x, y,
				 GlobalConfig.barracksEnergy,
				 GlobalConfig.barracksCost,
				 GlobalConfig.barracksHitPoints,
				 BARRACKS) {}

Barracks::~Barracks() {}
