#ifndef __ATTACKER_H__
#define __ATTACKER_H__

#include "Weapons/Weapon.h"

class Attackable;

class Attacker {
protected:
    const Weapon& weapon;
    const int range;
    int actual_frec;
public:
    Attacker(const Weapon& weapon, const int range);

    virtual void attack(Attackable &defender);

};

#endif //__ATTACKER_H__
