#include "Attackable.h"

Attackable::Attackable(int life) : life(life){}

int Attackable::getLife() {
    return life;
}

#include <iostream>
void Attackable::reciveAttack(Attacker &attacker) {
    life -= attacker.getDammage();
    std::cout << "Recibe ataque. Vida: " << life << std::endl;
    if (life <= 0) {
        // this->kill;
        std::cout << "Muere!!" << std::endl;
    }
}

//bool Attackable::isDead(Attackable* attackable) {
//    return attackable->life <= 0;
//}

