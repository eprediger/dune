#include "Attacker.h"
#include "Unit/Unit.h"

Attacker::Attacker(const Weapon &weapon, const int range) :
	weapon(weapon),
	range(range) {}

void Attacker::attack(Attackable &defender) {
    defender.reciveAttack(weapon);
}

int Attacker::getDammage() {
    return weapon.getDammage();
}
