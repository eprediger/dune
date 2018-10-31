#include "rocket-launcher.h"

RocketLauncher::RocketLauncher() :
	Weapon(GlobalConfig.rocketLauncherDamage,
		   GlobalConfig.rocketLauncherShootingRate,
		   GlobalConfig.rocketLauncherBonus) {}

RocketLauncher::~RocketLauncher() {}
