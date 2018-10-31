#include "Attacker.h"
#include "Unity.h"

Attacker::Attacker(Weapon weapon, const int range) :
	weapon(weapon),
	range(range) {}

void Attacker::attack(Attackable &defender) {
    defender.reciveAttack(*this);
}

int Attacker::getDamage() {
    return weapon.getDamage();
}
