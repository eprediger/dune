#include "HeavyInfantry.h"
#include "../Weapons/Weapons.h"
#include "../GlobalConfig.h"

HeavyInfantry::HeavyInfantry(int x, int y) 
		:OffensiveUnit(x, y, GlobalConfig.heavyInfantryHitPoints, GlobalConfig.heavyInfantryRange,
					  Weapons::rocketLauncher, GlobalConfig.heavyInfantrySpeed, GlobalConfig.heavyInfantryCost)
		,rocket(nullptr){}

HeavyInfantry::~HeavyInfantry() {}

bool HeavyInfantry::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks() || terrain == Summit();
}

void HeavyInfantry::shoot(Attackable& defender){
	this->rocket = new Rocket(pos,defender.getClosestPosition(pos)); 
}

bool HeavyInfantry::shotARocket(){
	return (this->rocket!=nullptr);
}

Rocket* HeavyInfantry::viewRocket(){
	return this->rocket;
}

Rocket* HeavyInfantry::getRocket(){
	Rocket* aux = this->rocket;
	this->rocket = nullptr;
	return aux;
}
 

void HeavyInfantry::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getInfantryBonus();
}
