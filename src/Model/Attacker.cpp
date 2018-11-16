#include "Attacker.h"
#include "Unit/Unit.h"

Attacker::Attacker(const Weapon &weapon, const int range) :
	weapon(weapon),
	range(range),
	actual_frec(0),
    shooting(false){}

void Attacker::attack(Attackable &defender) {
    shooting = false;
    if (actual_frec++ == 250/weapon.getFrecuency()) {
        defender.reciveAttack(weapon);
        shooting = true;
        actual_frec = 0;
    }
}

const Weapon& Attacker::getWeapon(){
    return weapon;
}

bool Attacker::isShooting(){
    return shooting;    
}