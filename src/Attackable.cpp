#include "Attackable.h"

Attackable::Attackable(int life) : life(life){}

int Attackable::getLife() {
    return life;
}

void Attackable::reciveAttack(Attacker &attacker) {
    life -= attacker.getDammage();
    if (life <= 0) {
        // this->kill;
    }
}

//bool Attackable::isDead(Attackable* attackable) {
//    return attackable->life <= 0;
//}

