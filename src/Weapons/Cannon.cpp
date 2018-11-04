#include "Cannon.h"

Cannon::Cannon() :
	Weapon(GlobalConfig.cannonDamage,
		   GlobalConfig.cannonShootingRate,
		   GlobalConfig.cannonBonus) {}

Cannon::~Cannon() {}
