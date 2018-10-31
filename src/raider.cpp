#include "raider.h"

Raider::Raider(int x, int y) :
	Unity(x, y,
		  GlobalConfig.raiderHitPoints,
		  GlobalConfig.raiderRange,
		  SmallCannon(),
		  GlobalConfig.raiderSpeed) {}

Raider::~Raider() {}
