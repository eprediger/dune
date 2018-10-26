#ifndef __ATTACKER_H__
#define __ATTACKER_H__

#include "Weapon.h"

class Attackable;

class Attacker {
protected:
    Weapon weapon;
public:
    Attacker(Weapon weapon);

    virtual void attack(Attackable &defender);

    virtual int getDammage();

};

#endif //__ATTACKER_H__
