#include "raider.h"

Raider::Raider(int x, int y) :
	Unit(x, y,
		  GlobalConfig.raiderHitPoints,
		  GlobalConfig.raiderRange,
		  SmallCannon(),
		  GlobalConfig.raiderSpeed) {}

Raider::~Raider() {}
