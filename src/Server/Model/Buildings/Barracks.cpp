#include "Barracks.h"
#include "Model/GlobalConfig.h"

Barracks::Barracks(const int x, const int y, int blockWidth, int blockHeight) :
	Building(x, y, blockWidth, blockHeight,
	         GlobalConfig.barracksEnergy,
	         GlobalConfig.barracksCost,
	         GlobalConfig.barracksHitPoints,
	         GlobalConfig.barracksWidth,
	         GlobalConfig.barracksHeight,
	         BARRACKS) {}

Barracks::~Barracks() {}
