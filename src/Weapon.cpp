#include "Weapon.h"

Weapon::Weapon(int damage, int frecuency, int bonus) :
	damage(damage),
	frecuency(frecuency),
	bonus(bonus) {}

Weapon::~Weapon() {}

int Weapon::getDamage() {
    return damage;
}
