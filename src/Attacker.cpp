#include "Attacker.h"
#include "Unit/Unit.h"

Attacker::Attacker(Weapon weapon, const int range) :
	weapon(weapon),
	range(range) {}

void Attacker::attack(Attackable &defender) {
    defender.reciveAttack(*this);
}

int Attacker::getDammage() {
    return weapon.getDamage();
}
