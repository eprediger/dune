#include "Attackable.h"

Attackable::Attackable(const int life) : life(life) {}

int Attackable::getLife() {
    return life;
}

int Attackable::getInitialLife(){
    return initial_life; 
}
#include <iostream>
void Attackable::reciveAttack(const Weapon &weapon) {
    life -= weapon.getDammage();
    this->reciveBonusDammage(weapon);
    std::cout << "Recibe ataque. Vida: " << life << std::endl;
    if (life <= 0) {
        // this->kill;
        std::cout << "Muere!!" << std::endl;
    }
}

//bool Attackable::isDead(Attackable* attackable) {
//    return attackable->life <= 0;
//}
