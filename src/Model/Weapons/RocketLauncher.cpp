#include "RocketLauncher.h"
#include "../GlobalConfig.h"

RocketLauncher::RocketLauncher() :
	Weapon(GlobalConfig.rocketLauncherDamage,
		   GlobalConfig.rocketLauncherShootingRate,
		   GlobalConfig.rocketLauncherBonus) {}

RocketLauncher::~RocketLauncher() {}

int RocketLauncher::getInfantryBonus() const {
	return 0;
}

int RocketLauncher::getVehicleBonus() const {
	return 0;
}

int RocketLauncher::getBuildingBonus() const {
	return 0;
}
