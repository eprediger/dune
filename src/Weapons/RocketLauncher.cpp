#include "RocketLauncher.h"

RocketLauncher::RocketLauncher() :
	Weapon(GlobalConfig.rocketLauncherDamage/5,
		   GlobalConfig.rocketLauncherShootingRate,
		   GlobalConfig.rocketLauncherBonus) {}

RocketLauncher::~RocketLauncher() {}
