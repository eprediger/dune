#ifndef __ATTACKER_H__
#define __ATTACKER_H__

#include "Weapon.h"

class Attackable;

class Attacker {
protected:
    Weapon weapon;
    const int range;
public:
    Attacker(Weapon weapon, const int range);

    virtual void attack(Attackable &defender);

    virtual int getDamage();
};

#endif //__ATTACKER_H__
