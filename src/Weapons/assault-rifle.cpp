#include "assault-rifle.h"

AssaultRifle::AssaultRifle() :
	Weapon(GlobalConfig.assaultRifleDamage,
		   GlobalConfig.assaultRifleShootingRate,
		   GlobalConfig.assaultRifleBonus) {}

AssaultRifle::~AssaultRifle() {}
