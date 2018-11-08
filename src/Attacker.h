#ifndef __ATTACKER_H__
#define __ATTACKER_H__

#include "Weapons/Weapon.h"

class Attackable;

class Attacker {
protected:
    const Weapon& weapon;
    const int range;
public:
    Attacker(const Weapon& weapon, const int range);

    virtual void attack(Attackable &defender);

    virtual int getDammage();
};

#endif //__ATTACKER_H__
