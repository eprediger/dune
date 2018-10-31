#include "small-cannon.h"

SmallCannon::SmallCannon() :
	Weapon(GlobalConfig.smallCannonDamage,
		   GlobalConfig.smallCannonShootingRate,
		   GlobalConfig.smallCannonBonus) {}

SmallCannon::~SmallCannon() {}
