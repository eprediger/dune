#include "Attacker.h"
#include "Unity.h"

Attacker::Attacker(Weapon weapon) : weapon(weapon){}

void Attacker::attack(Attackable &defender) {
    defender.reciveAttack(*this);
}

int Attacker::getDammage() {
    return weapon.getDammage();
}

