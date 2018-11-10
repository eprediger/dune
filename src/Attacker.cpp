#include "Attacker.h"
#include "Unit/Unit.h"

Attacker::Attacker(const Weapon &weapon, const int range) :
	weapon(weapon),
	range(range),
	actual_frec(0){}

void Attacker::attack(Attackable &defender) {
    if (actual_frec++ == 250/weapon.getFrecuency()) {
        defender.reciveAttack(weapon);
        actual_frec = 0;
    }
}

