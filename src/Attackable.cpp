#include "Attackable.h"

Attackable::Attackable(const int life) : life(life) {}

int Attackable::getLife() {
    return life;
}

void Attackable::reciveAttack(Attacker &attacker) {
    life -= attacker.getDamage();
    if (life <= 0) {
        // this->kill;
    }
}

//bool Attackable::isDead(Attackable* attackable) {
//    return attackable->life <= 0;
//}
