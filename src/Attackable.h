#ifndef __ATTACKABLE_H__
#define __ATTACKABLE_H__

#include "Attacker.h"

class Attackable {
protected:
    int life;
public:
    Attackable(const int life);

    virtual int getLife();

    virtual void reciveAttack(const Weapon &weapon);

    virtual void reciveBonusDammage(const Weapon &weapon) = 0;
};

#endif //__ATTACKABLE_H__
